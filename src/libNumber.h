/***************************************************************************
                          libNumber.h  -  description
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

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "memory.h"

#define LittleEndian 2
#define BigEndian    1

union Ieee4Bytes {
	unsigned char b[4];
	unsigned long l;
	float f;
};

union Ieee8Bytes {
	unsigned char b[8];
	unsigned long long l;
	double f;
};

// Float type
enum { 
	IEEE_SINGLE_FLOAT,
	IEEE_DOUBLE_FLOAT,
	IBM_SINGLE_FLOAT,
	IBM_DOUBLE_FLOAT,
	VAX_SINGLE_FLOAT
};

// Method number
enum {
	BYMULTIPLE,
	BYLOG
};

int MemoryByteOrder();

// General method
int Float2S(double IeeeDoubleFloat, unsigned char * S);

int Float2EF1(int FloatType, double IeeeDoubleFloat, int * exponent, double * fraction);
int Float2EF2(int FloatType, double IeeeDoubleFloat, int * exponent, double * fraction);

int SingleFrac2Long(int FloatType, double fraction, unsigned long * F);
int DoubleFrac2Long(int FloatType, double fraction, unsigned long * L1, unsigned long * L2);

int SingleFloat2SEF(int MethodNo, int FloatType, double IeeeDoubleFloat, unsigned char * S, int * E, unsigned long * F);
int DoubleFloat2SEF(int MethodNo, int FloatType, double IeeeDoubleFloat, unsigned char * S, int * E, unsigned long * L1, unsigned long * L2);
int SingleSEF2Byte(int FloatType, unsigned char S, int E, unsigned long F, unsigned char bytes[4]);
int DoubleSEF2Byte(int FloatType, unsigned char S, int E, unsigned long L1, unsigned long L2, unsigned char bytes[8]);

int SingleSEF2Float(int FloatType, unsigned char S, int E, unsigned long F, float * IeeeSingleFloat);
int DoubleSEF2Float(int FloatType, unsigned char S, int E, unsigned long L1, unsigned long L2, double * IeeeDoubleFloat);
int SingleByte2SEF(int FloatType, unsigned char bytes[4], unsigned char * S, int * E, unsigned long * F);
int DoubleByte2SEF(int FloatType, unsigned char bytes[8], unsigned char * S, int * E, unsigned long * L1, unsigned long * L2);

// Ieee Float
int IeeeSingleFloat2ByteUnion(float IeeeSingleFloat, unsigned char bytes[4]);
int Byte2IeeeSingleFloatUnion(unsigned char bytes[4], float * IeeeSingleFloat);
int IeeeDoubleFloat2ByteUnion(double IeeeDoubleFloat, unsigned char bytes[8]);
int Byte2IeeeDoubleFloatUnion(unsigned char bytes[8], double * IeeeDoubleFloat);

int IeeeSingleFloat2ByteL(float IeeeSingleFloat, unsigned char bytes[4]);
int Byte2IeeeSingleFloat(unsigned char bytes[4], float * IeeeSingleFloat);
int IeeeDoubleFloat2ByteL(double IeeeDoubleFloat, unsigned char bytes[8]);
int Byte2IeeeDoubleFloat(unsigned char bytes[8], double * IeeeDoubleFloat);

int IeeeSingleFloat2ByteM(float IeeeSingleFloat, unsigned char bytes[4]);
int IeeeDoubleFloat2ByteM(double IeeeDoubleFloat, unsigned char bytes[8]);

// Ibm Float
int IbmSingleFloat2ByteL(float IbmSingleFloat, unsigned char bytes[4]);
int Byte2IbmSingleFloat(unsigned char bytes[4], float * IbmSingleFloat);
int IbmDoubleFloat2ByteL(double IbmDoubleFloat, unsigned char bytes[8]);
int Byte2IbmDoubleFloat(unsigned char bytes[8], double * IbmDoubleFloat);

int IbmSingleFloat2ByteM(float IbmSingleFloat, unsigned char bytes[4]);
int IbmDoubleFloat2ByteM(double IbmDoubleFloat, unsigned char bytes[8]);

// Vax Float
int VaxSingleFloat2ByteL(float VaxSingleFloat, unsigned char bytes[4]);
int Byte2VaxSingleFloat(unsigned char bytes[4], float * VaxSingleFloat);

int VaxSingleFloat2ByteM(float VaxSingleFloat, unsigned char bytes[4]);

// Test
void TestlibNumber(int FloatType, float f, double df);
void IeeeFloatTest(float f, double df);
void IbmFloatTest(float f, double df);
void VaxFloatTest(float f, double df);
