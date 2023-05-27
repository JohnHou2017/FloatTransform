/***************************************************************************
                          Float2SEF.c  -  description
                             -------------------
    begin                : November 2005
    copyright            : (C) 2005 by John Jiyang Hou
    email                : jyhou69@hotmail.com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "libNumber.h"

int Float2S(double IeeeDoubleFloat, unsigned char * S)
{
if(IeeeDoubleFloat < 0 ) *S = 0x80;
else *S = 0;
return 0;
}

int SingleFloat2SEF(int MethodNo, int FloatType, double IeeeDoubleFloat, unsigned char * S, int * E, unsigned long * F)
{

Float2S(IeeeDoubleFloat, S);

double fraction;

switch(MethodNo)
{
	case BYMULTIPLE:
		Float2EF1(FloatType, IeeeDoubleFloat, E, &fraction);
		break;
	case BYLOG:
		Float2EF2(FloatType, IeeeDoubleFloat, E, &fraction);		
		break;
}

SingleFrac2Long(FloatType, fraction, F);

return 0;
}

int DoubleFloat2SEF(int MethodNo, int FloatType, double IeeeDoubleFloat, unsigned char * S, int * E, unsigned long * L1, unsigned long * L2)
{

Float2S(IeeeDoubleFloat, S);

double fraction;

switch(MethodNo)
{
	case BYMULTIPLE:
		Float2EF1(FloatType, IeeeDoubleFloat, E, &fraction);
		break;
	case BYLOG:
		Float2EF2(FloatType, IeeeDoubleFloat, E, &fraction);		
		break;
}

DoubleFrac2Long(FloatType, fraction, L1, L2);

return 0;
}

int SingleFrac2Long(int FloatType, double fraction, unsigned long * F)
{
if( fraction < 0 || fraction > 1.0 ) return -1;

double F1;

switch(FloatType)
{
	case IEEE_SINGLE_FLOAT:
		F1 = 8388608.0;		// 2^23

		break;
	case IBM_SINGLE_FLOAT:
	case VAX_SINGLE_FLOAT:
		F1 = 16777216.0;		// 2^24

		break;
}

double M = fraction * F1;
	
*F = (unsigned long) M;

return 0;
}

int DoubleFrac2Long(int FloatType, double fraction, unsigned long * L1, unsigned long * L2)
{
if( fraction < 0 || fraction > 1.0 ) return -1;

double F1,F2;

switch(FloatType)
{
	case IEEE_DOUBLE_FLOAT:
		F2 = 4294967296.0;		// 2^32
		F1 = 4503599627370496.0;	// 2^52

		break;
	case IBM_DOUBLE_FLOAT:
		F2 = 4294967296.0;		// 2^32
		F1 = 72057594037927936.0;	// 2^56

		break;
}

double M = fraction * F1;
	
*L1 = (unsigned long) ( M / F2 );
*L2 = (unsigned long) ( M - (*L1) * F2);

return 0;
}


int Float2EF1(int FloatType, double IeeeDoubleFloat, int * exponent, double * fraction)
{
/*
 * C >= 0
 *
 * Formula: V = ( -1 ) ^ S * ( C + F ) * A ^ ( E - B )
 *
 * G is the fraction value when all fraction bits are 1 
 *
 * Formula: 1/2 + 1/4 + ... + 1/2^n = 1.0 - 1/2^n
 *
 * Ieee and Ibm fraction bits start from 1/2, Vax fraction bits start from 1/4
 * 
 * 0 < F < G
 * C < C + F < C + G
 *
 * Ieee: G = 1.0-1/2^(23 or 52)   
 * Ibm: G = 1.0-1/2^(24 or 56), 
 * Vax: G = 0.5 - 1/2^(24)
 *
 * DB = E - B
 *
 * 1. V < C			DB < 0
 * 2. V = C			DB < 0
 * 3. C < V < C + G		DB = 0, F = V - C
 * 4. V = C + G		DB > 0
 * 5. V > C + G		DB > 0
 */

double A, C, G;
double V, F;
int E, B;

switch(FloatType)
{
	case IEEE_SINGLE_FLOAT:
		A = 2.0; // base
		B = 127; // exponent offset
		C = 1.0; // fraction offset
		G = 1.0 - pow ( 0.5, 23.0 );
		break;
	case IEEE_DOUBLE_FLOAT:
		A = 2.0; 
		B = 1023; 
		C = 1.0; 
		G = 1.0 - pow ( 0.5, 52.0 );
		break;
	case IBM_SINGLE_FLOAT:
		A = 16.0;
		B = 64;
		C = 0;
		G = 1.0 - pow ( 0.5, 24.0 );
		break;
	case IBM_DOUBLE_FLOAT:
		A = 16.0;
		B = 64;
		C = 0;
		G = 1.0 - pow ( 0.5, 56.0 );
		break;
	case VAX_SINGLE_FLOAT: 
		A = 2.0;
		B = 128;
		C = 0.5;
		G = 0.5 - pow ( 0.5, 24.0 );
		break;
}

V = IeeeDoubleFloat;

if ( V == 0 ) return -1;

if ( V < 0 ) V = ( -1.0 ) * V;

int i;

if ( V <= C )
{
	for( i = 1; ; i++ )
	{
		V *= A;
		if ( V >= C ) break;
	}
	E = B - i;
	F = V - C;
}
else if ( V >= C + G )
{
	for( i = 1; ; i++ )
	{
		V /= A;
		if ( V <= C + G ) break;
	}
	E = B + i;
	F = V - C;
}
else 
{
	E = B;
	F = V - C;
}

*exponent = E;
*fraction = F;

return 0;
}

int Float2EF2(int FloatType, double IeeeDoubleFloat, int * exponent, double * fraction)
{
/*
 * C >= 0
 *
 * Formula: V = ( -1 ) ^ S * ( C + F ) * A ^ ( E - B )
 *
 * 0 < F < 1.0
 * C < C + F < C + 1.0 
 *
 * DB = E - B
 *
 * 1. V < C			DB < 0
 * 2. V = C			DB < 0
 * 3. C < V < C + 1.0	DB = 0, F = V - C
 * 4. V = C + 1.0		DB > 0
 * 5. V > C + 1.0		DB > 0
 */

const double D = 0.69314718055994529;	// log2

double A, C;
double V, F;
int E, B;
double exp;

V = IeeeDoubleFloat;

if ( V == 0 ) return -1;

if ( V < 0 ) V = ( -1.0 ) * V;

switch(FloatType)
{
	case IEEE_SINGLE_FLOAT:
		A = 2.0; // base
		B = 127; // exponent offset
		C = 1.0; // fraction offset
		exp = ( log ( V ) / D ) + (double) B; // exponent double expresion

		break;
	case IEEE_DOUBLE_FLOAT:
		A = 2.0; 
		B = 1023; 
		C = 1.0; 
		exp = ( log ( V ) / D ) + (double) B; 

		break;
	case IBM_SINGLE_FLOAT:
	case IBM_DOUBLE_FLOAT:
		A = 16.0;
		B = 64;
		C = 0;
		exp = ( log ( V ) / D * 0.25 + 1.0 ) + (double) B;

		break;
	case VAX_SINGLE_FLOAT:
		A = 2.0;
		B = 128;
		C = 0.5;
		exp = ( log ( V ) / D + 1.0 ) + (double) B;

		break;
}

E = (int) exp;

F = ( V / pow ( A , double ( E - B ) ) ) - C;	

*exponent = E;
*fraction = F;

return 0;
}
