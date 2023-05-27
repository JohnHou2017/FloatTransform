/***************************************************************************
                          IeeeFloat.c  -  description
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

// all bytes array ( either input parameter or return parameter ) assume as local memory order

// transform ieee single float to bytes by LOG method
int IeeeSingleFloat2ByteL(float IeeeSingleFloat, unsigned char bytes[4])
{
// ===================================
// S EEEEEEEE FFFFFFF FFFFFFFF FFFFFFFF
// 0 1      8 9                       31
// byte0    byte1     byte2    byte3
// ===================================	

	unsigned char S;
	int E;
	unsigned long F;

	SingleFloat2SEF(BYLOG, IEEE_SINGLE_FLOAT, (double)IeeeSingleFloat, &S, &E, &F);

	SingleSEF2Byte(IEEE_SINGLE_FLOAT, S, E, F, bytes);

	return 0;
}

// transform ieee single float to bytes by MULTIPLE method
int IeeeSingleFloat2ByteM(float IeeeSingleFloat, unsigned char bytes[4])
{
// ===================================
// S EEEEEEEE FFFFFFF FFFFFFFF FFFFFFFF
// 0 1      8 9                       31
// byte0    byte1     byte2    byte3
// ===================================	

	unsigned char S;
	int E;
	unsigned long F;

	SingleFloat2SEF(BYMULTIPLE, IEEE_SINGLE_FLOAT, (double)IeeeSingleFloat, &S, &E, &F);

	SingleSEF2Byte(IEEE_SINGLE_FLOAT, S, E, F, bytes);

	return 0;

}

// transform byte to ieee single precision float
int Byte2IeeeSingleFloat(unsigned char bytes[4], float * IeeeSingleFloat)
{
// ===================================
// S EEEEEEEE FFFFFFF FFFFFFFF FFFFFFFF
// 0 1      8 9                       31
// byte0    byte1     byte2    byte3
// ===================================			
	
	unsigned char S;
	int E;
	unsigned long F;
	
	SingleByte2SEF(IEEE_SINGLE_FLOAT, bytes, &S, &E, &F);

	SingleSEF2Float(IEEE_SINGLE_FLOAT, S, E, F, IeeeSingleFloat);

	return 0;
}

// transform ieee double float to byte by LOG method
int IeeeDoubleFloat2ByteL(double IeeeDoubleFloat, unsigned char bytes[8])
{
// ===================================
// S EEEEEEE EEEE FFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF
// 0 1          1112                                                       63
// byte0     byte1     byte2    byte3    byte4    byte5    byte6    byte7
//                L1                     L2
// ===================================	

	unsigned char S;
	int E;
	unsigned long L1, L2;

	DoubleFloat2SEF(BYLOG, IEEE_DOUBLE_FLOAT, IeeeDoubleFloat, &S, &E, &L1, &L2);

	DoubleSEF2Byte(IEEE_DOUBLE_FLOAT, S, E, L1, L2, bytes);

	return 0;
}
  
// transform ieee double float to bytes by MUlTIPLE method
int IeeeDoubleFloat2ByteM(double IeeeDoubleFloat, unsigned char bytes[8])
{
// ===================================
// S EEEEEEE EEEE FFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF
// 0 1          1112                                                       63
// byte0     byte1     byte2    byte3    byte4    byte5    byte6    byte7
//                L1                     L2
// ===================================	

	unsigned char S;
	int E;
	unsigned long L1, L2;

	DoubleFloat2SEF(BYMULTIPLE, IEEE_DOUBLE_FLOAT, IeeeDoubleFloat, &S, &E, &L1, &L2);

	DoubleSEF2Byte(IEEE_DOUBLE_FLOAT, S, E, L1, L2, bytes);

	return 0;
}

// transform byte to ieee double precision float
int Byte2IeeeDoubleFloat(unsigned char bytes[8], double * IeeeDoubleFloat)
{
// ===================================
// S EEEEEEE EEEE FFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF
// 0 1          1112                                                       63
// byte0     byte1     byte2    byte3    byte4    byte5    byte6    byte7
//                L1                     L2
// ===================================			

	unsigned char S;
	int E;
	unsigned long L1, L2;
	
	DoubleByte2SEF(IEEE_DOUBLE_FLOAT, bytes, &S, &E, &L1, &L2);

	DoubleSEF2Float(IEEE_DOUBLE_FLOAT, S, E, L1, L2, IeeeDoubleFloat);

	return 0;
}

int IeeeSingleFloat2ByteUnion(float IeeeSingleFloat, unsigned char bytes[4])
{
	Ieee4Bytes u;
	u.f = IeeeSingleFloat;

	if( MemoryByteOrder() == LittleEndian )
	{
		bytes[0] = u.b[0];
		bytes[1] = u.b[1];
		bytes[2] = u.b[2];
		bytes[3] = u.b[3];
	}
	else // BigEndian
	{
		bytes[0] = u.b[3];
		bytes[1] = u.b[2];
		bytes[2] = u.b[1];
		bytes[3] = u.b[0];
	}	

}

int Byte2IeeeSingleFloatUnion(unsigned char bytes[4], float * IeeeSingleFloat)
{
	Ieee4Bytes u;

	if( MemoryByteOrder() == LittleEndian )
	{
		u.b[0] = bytes[0];
		u.b[1] = bytes[1];
		u.b[2] = bytes[2];
		u.b[3] = bytes[3];
	}
	else // BigEndian
	{
		u.b[0] = bytes[3];
		u.b[1] = bytes[2];
		u.b[2] = bytes[1];
		u.b[3] = bytes[0];
	}	

	*IeeeSingleFloat = u.f;
}

int IeeeDoubleFloat2ByteUnion(double IeeeDoubleFloat, unsigned char bytes[8])
{
	Ieee8Bytes u;
	u.f = IeeeDoubleFloat;

	if( MemoryByteOrder() == LittleEndian )
	{
		bytes[0] = u.b[0];
		bytes[1] = u.b[1];
		bytes[2] = u.b[2];
		bytes[3] = u.b[3];
		bytes[4] = u.b[4];
		bytes[5] = u.b[5];
		bytes[6] = u.b[6];
		bytes[7] = u.b[7];

	}
	else // BigEndian
	{
		bytes[0] = u.b[7];
		bytes[1] = u.b[6];
		bytes[2] = u.b[5];
		bytes[3] = u.b[4];
		bytes[4] = u.b[3];
		bytes[5] = u.b[2];
		bytes[6] = u.b[1];
		bytes[7] = u.b[0];
	}	
}

int Byte2IeeeDoubleFloatUnion(unsigned char bytes[8], double * IeeeDoubleFloat)
{
	Ieee8Bytes u;

	if( MemoryByteOrder() == LittleEndian )
	{
		u.b[0] = bytes[0];
		u.b[1] = bytes[1];
		u.b[2] = bytes[2];
		u.b[3] = bytes[3];
		u.b[4] = bytes[4];
		u.b[5] = bytes[5];
		u.b[6] = bytes[6];
		u.b[7] = bytes[7];
	}
	else // BigEndian
	{
		u.b[0] = bytes[7];
		u.b[1] = bytes[6];
		u.b[2] = bytes[5];
		u.b[3] = bytes[4];
		u.b[4] = bytes[3];
		u.b[5] = bytes[2];
		u.b[6] = bytes[1];
		u.b[7] = bytes[0];
	}	

	*IeeeDoubleFloat = u.f;

}
