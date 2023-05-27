/***************************************************************************
                          Byte2SEF.c  -  description
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

int SingleByte2SEF(int FloatType, unsigned char bytes[4], unsigned char * S, int * E, unsigned long * F)
{
unsigned char b1,b2,b3,b4;	

switch(FloatType)
{
	case IEEE_SINGLE_FLOAT:
		if( MemoryByteOrder() == BigEndian )
		{
			b1=bytes[0];
			b2=bytes[1];
			b3=bytes[2];
			b4=bytes[3];
		}
		else
		{
			b1=bytes[3];
			b2=bytes[2];
			b3=bytes[1];
			b4=bytes[0];
		}

		*S = ( b1 & 0x80 ) >> 7;

		*E = ( ( b1 & 0x7f ) << 1 ) + ( ( b2 & 0x80 ) >> 7 );

		*F = ( ( b2 & 0x7f ) << 16 ) + ( b3 << 8 ) + b4;

		break;
	case IBM_SINGLE_FLOAT:
		if( MemoryByteOrder() == BigEndian )
		{
			b1=bytes[0];
			b2=bytes[1];
			b3=bytes[2];
			b4=bytes[3];
		}
		else
		{
			b1=bytes[3];
			b2=bytes[2];
			b3=bytes[1];
			b4=bytes[0];
		}

		*S = ( b1 & 0x80 ) >> 7;

		*E = ( b1 & 0x7f );

		*F = ( b2 << 16 ) + ( b3 << 8 ) + b4;

		break;
	case VAX_SINGLE_FLOAT:
		b1=bytes[1];
		b2=bytes[0];
		b3=bytes[3];
		b4=bytes[2];

		*S = ( b1 & 0x80 ) >> 7;

		*E = ( ( b1 & 0x7f ) << 1 ) + ( ( b2 & 0x80 ) >> 7 );

		*F = ( ( b2 & 0x7f ) << 16 ) + ( b3 << 8 ) + b4;

		break;
}

}

int DoubleByte2SEF(int FloatType, unsigned char bytes[8], unsigned char * S, int * E, unsigned long * L1, unsigned long * L2)
{
unsigned char b1,b2,b3,b4,b5,b6,b7,b8;	

switch(FloatType)
{
	case IEEE_DOUBLE_FLOAT:
		if( MemoryByteOrder() == BigEndian )
		{
			b1=bytes[0];
			b2=bytes[1];
			b3=bytes[2];
			b4=bytes[3];
			b5=bytes[4];
			b6=bytes[5];
			b7=bytes[6];
			b8=bytes[7];
		}
		else
		{
			b1=bytes[7];
			b2=bytes[6];
			b3=bytes[5];
			b4=bytes[4];
			b5=bytes[3];
			b6=bytes[2];
			b7=bytes[1];
			b8=bytes[0];
		}

		*S = ( b1 & 0x80 ) >> 7;

		*E = ( ( b1 & 0x7f ) << 4 ) + ( ( b2 & 0xf0 ) >> 4 );
		
		*L1 = ( ( b2 & 0x0f ) << 16 ) + ( b3 << 8 ) + b4;

		*L2 = ( b5 << 24 ) + ( b6 << 16 ) + ( b7 << 8 ) + b8;

		break;
	case IBM_DOUBLE_FLOAT:
		if( MemoryByteOrder() == BigEndian )
		{
			b1=bytes[0];
			b2=bytes[1];
			b3=bytes[2];
			b4=bytes[3];
			b5=bytes[4];
			b6=bytes[5];
			b7=bytes[6];
			b8=bytes[7];
		}
		else
		{
			b1=bytes[7];
			b2=bytes[6];
			b3=bytes[5];
			b4=bytes[4];
			b5=bytes[3];
			b6=bytes[2];
			b7=bytes[1];
			b8=bytes[0];
		}

		*S = ( b1 & 0x80 ) >> 7;

		*E = ( b1 & 0x7f );

		*L1 = ( b2 << 16 ) + ( b3 << 8 ) + b4;
		
		*L2 = ( b5 << 24 ) + ( b6 << 16 ) + ( b7 << 8 ) + b8;

		break;
}

}
