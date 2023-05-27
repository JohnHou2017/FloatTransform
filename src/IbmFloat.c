/***************************************************************************
                          IbmFloat.c  -  description
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

// transform ibm single float to byte by LOG method
int IbmSingleFloat2ByteL(float IbmSingleFloat, unsigned char bytes[4])
{
// ===================================
// S EEEEEEE FFFFFFFF FFFFFFFF FFFFFFFF
// 0 1     7 9                        31
// byte0     byte1    byte2    byte3
// ===================================			

	unsigned char S;
	int E;
	unsigned long F;

	SingleFloat2SEF(BYLOG, IBM_SINGLE_FLOAT, (double)IbmSingleFloat, &S, &E, &F);

	SingleSEF2Byte(IBM_SINGLE_FLOAT, S, E, F, bytes);

	return 0;
}

// transform ibm single float to byte by MULTIPLE 
int IbmSingleFloat2ByteM(float IbmSingleFloat, unsigned char bytes[4])
{
// ===================================
// S EEEEEEE FFFFFFFF FFFFFFFF FFFFFFFF
// 0 1     7 9                        31
// byte0     byte1    byte2    byte3
// ===================================			

	unsigned char S;
	int E;
	unsigned long F;

	SingleFloat2SEF(BYMULTIPLE, IBM_SINGLE_FLOAT, (double)IbmSingleFloat, &S, &E, &F);

	SingleSEF2Byte(IBM_SINGLE_FLOAT, S, E, F, bytes);

	return 0;
}

// transform byte to ibm single precision float
int Byte2IbmSingleFloat(unsigned char bytes[4], float * IbmSingleFloat)
{
// ===================================
// S EEEEEEE FFFFFFFF FFFFFFFF FFFFFFFF
// 0 1     7 9                        31
// byte0     byte1    byte2    byte3
// ===================================			

	unsigned char S;
	int E;
	unsigned long F;
	
	SingleByte2SEF(IBM_SINGLE_FLOAT, bytes, &S, &E, &F);

	SingleSEF2Float(IBM_SINGLE_FLOAT, S, E, F, IbmSingleFloat);

	return 0;
}

// transform IBM double float to bytes by LOG method
int IbmDoubleFloat2ByteL(double IbmDoubleFloat, unsigned char bytes[8])
{
// ===================================
// S EEEEEEE FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF
// 0 1     7 9                                                            63
// byte0     byte1    byte2    byte3    byte4    byte5    byte6    byte7
// ===================================			

	unsigned char S;
	int E;
	unsigned long L1, L2;

	DoubleFloat2SEF(BYLOG, IBM_DOUBLE_FLOAT, IbmDoubleFloat, &S, &E, &L1, &L2);

	DoubleSEF2Byte(IBM_DOUBLE_FLOAT, S, E, L1, L2, bytes);

	return 0;
}

// transform IBM double float to bytes by MULTIPLE method
int IbmDoubleFloat2ByteM(double IbmDoubleFloat, unsigned char bytes[8])
{
// ===================================
// S EEEEEEE FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF
// 0 1     7 9                                                            63
// byte0     byte1    byte2    byte3    byte4    byte5    byte6    byte7
// ===================================			

	unsigned char S;
	int E;
	unsigned long L1, L2;

	DoubleFloat2SEF(BYMULTIPLE, IBM_DOUBLE_FLOAT, IbmDoubleFloat, &S, &E, &L1, &L2);

	DoubleSEF2Byte(IBM_DOUBLE_FLOAT, S, E, L1, L2, bytes);

	return 0;

}

int Byte2IbmDoubleFloat(unsigned char bytes[8], double * IbmDoubleFloat)
{
// ===================================
// S EEEEEEE FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF
// 0 1     7 9                                                            63
// byte0     byte1    byte2    byte3    byte4    byte5    byte6    byte7
// ===================================			
	
	unsigned char S;
	int E;
	unsigned long L1, L2;
	
	DoubleByte2SEF(IBM_DOUBLE_FLOAT, bytes, &S, &E, &L1, &L2);

	DoubleSEF2Float(IBM_DOUBLE_FLOAT, S, E, L1, L2, IbmDoubleFloat);

	return 0;

}
