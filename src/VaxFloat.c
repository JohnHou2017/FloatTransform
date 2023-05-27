/***************************************************************************
                          VaxFloat.c  -  description
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

// transform vax single float to byte by LOG method
int VaxSingleFloat2ByteL(float VaxSingleFloat, unsigned char bytes[4])
{
// ===================================
// S EEEEEEEE FFFFFFF FFFFFFFF FFFFFFFF
// 0 1      8 9                       31
// byte1    byte0     byte3    byte2
// ===================================	

	unsigned char S;
	int E;
	unsigned long F;

	SingleFloat2SEF(BYLOG, VAX_SINGLE_FLOAT, (double)VaxSingleFloat, &S, &E, &F);

	SingleSEF2Byte(VAX_SINGLE_FLOAT, S, E, F, bytes);

	return 0;
}

// transform vax single float to byte by MULTIPLAE
int VaxSingleFloat2ByteM(float VaxSingleFloat, unsigned char bytes[4])
{
// ===================================
// S EEEEEEEE FFFFFFF FFFFFFFF FFFFFFFF
// 0 1      8 9                       31
// byte1    byte0     byte3    byte2
// ===================================	

	unsigned char S;
	int E;
	unsigned long F;

	SingleFloat2SEF(BYMULTIPLE, VAX_SINGLE_FLOAT, (double)VaxSingleFloat, &S, &E, &F);

	SingleSEF2Byte(VAX_SINGLE_FLOAT, S, E, F, bytes);

	return 0;
}

// transform byte to vax single precision float
int Byte2VaxSingleFloat(unsigned char bytes[4], float * VaxSingleFloat)
{
// ===================================
// S EEEEEEEE FFFFFFF FFFFFFFF FFFFFFFF
// 0 1      8 9                       31
// byte1    byte0     byte3    byte2
// ===================================			

	unsigned char S;
	int E;
	unsigned long F;
	
	SingleByte2SEF(VAX_SINGLE_FLOAT, bytes, &S, &E, &F);

	SingleSEF2Float(VAX_SINGLE_FLOAT, S, E, F, VaxSingleFloat);

	return 0;
}
