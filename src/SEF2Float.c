/***************************************************************************
                          SEF2Float.c  -  description
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

int SingleSEF2Float(int FloatType, unsigned char S, int E, unsigned long F, float * IeeeSingleFloat)
{
float ret=0;

double M, F1, A, B, C, D, D2, e23, e24;

switch(FloatType)
{
	case IEEE_SINGLE_FLOAT:
		
		A = 2.0;
		B = 127.0;
		C = 1.0;	
		D2 = -126.0;
		e23 = 8388608.0;		// 2^23

		M = (double) F / e23;
		
		if ( S == 0) F1 = 1.0;
		else F1 = -1.0;		

		if ( 0 < E && E < 255 ) ret = F1 * ( C + M ) * pow ( A, E - B ) ;	
	    else if ( E == 0 && F != 0 ) ret = F1 * M * pow ( A, D2 );
		else if ( E == 0 && F == 0 && S == 1 ) ret = -0;
    	else if ( E == 0 && F == 0 && S == 0 ) ret = 0;	
		else if ( E == 255 && F != 0) return -1; // Not a number
		else if ( E == 255 && F == 0 && S == 1 ) return -2; // -Infinity
		else if ( E == 255 && F == 0 && S == 0 ) return -3; // Infinity	

		break;

	case IBM_SINGLE_FLOAT:
		
		A = 16.0;
		B = 64.0;
		D = 0.69314718055994529;	// log2
		e24 = 16777216.0;		// 2^24

		M = (double) F / e24;
		
		if ( S == 0) F1 = 1.0;
		else F1 = -1.0;

		if ( S == 0 && E == 0 && F == 0 ) ret = 0;
		else ret = F1 * M * pow ( A, E - B ) ;	

		break;

	case VAX_SINGLE_FLOAT:
		
		A = 2.0;
		B = 128.0;
		C = 0.5;	
		e24 = 16777216.0;		// 2^24

		M = (double) F / e24;	
		
		if ( S == 0 ) F1 = 1.0;
		else F1 = -1.0;

		if ( 0 < E ) ret = F1 * ( C + M ) * pow ( A, E - B ) ;	
    		else if ( E == 0 && S == 0 ) ret = 0; 
		else if ( E == 0 && S == 1 ) return -1; // reserved

		break;
}

*IeeeSingleFloat = ret;

return 0;
}

int DoubleSEF2Float(int FloatType, unsigned char S, int E, unsigned long L1, unsigned long L2, double * IeeeDoubleFloat)
{
double ret;

double F1, M, M1, M2, A, B, C, D1, D2, e20, e24, e52, e56;

switch(FloatType)
{
	case IEEE_DOUBLE_FLOAT:

		e20 = 1048576.0;			// 2^20
		e52 = 4503599627370496.0;	// 2^52
		A = 2.0;
		B = 1023.0;
		C = 1.0;
		D1 = 2047;
		D2 = 1022.0;

		M1 = (double) L1 / e20 ;
		M2 = (double) L2 / e52 ;

		M = M1 + M2 ;
		
		if ( S == 0) F1 = 1.0;
		else F1 = -1.0;

		if ( 0 < E && E < D1 ) ret = F1 * ( C + M ) * pow ( A, E - B ) ;		
		else if ( E == 0 && M != 0 ) ret = F1 * M * pow ( A, D2 );
		else if ( E == 0 && M == 1 ) ret = F1 * 0;
		else if ( E == D1 && M == 0 ) return -1;
		else if ( E == D1 && M != 0 ) return -2; // Not a number	

		break;

	case IBM_DOUBLE_FLOAT:


		A = 16.0;
		B = 64.0;
		e24 = 16777216.0;			    // 2^24
		e56 = 72057594037927936.0;		// 2^56

		M1 = (double) L1 / e24 ;
		M2 = (double) L2 / e56 ;

		M = M1 + M2 ;
		
		if ( S == 0) F1 = 1.0;
		else F1 = -1.0;

		if ( S == 0 && E == 0 && M == 0 ) ret = 0;
		else ret = F1 * M * pow ( A, E - B ) ;	

		break;
}

*IeeeDoubleFloat = ret;

return 0;
}
