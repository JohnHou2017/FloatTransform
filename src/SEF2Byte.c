/***************************************************************************
                          SEF2Byte.c  -  description
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

int SingleSEF2Byte(int FloatType, unsigned char S, int E, unsigned long F, unsigned char bytes[4])
{

switch(FloatType)
{
	case IEEE_SINGLE_FLOAT:
		if( MemoryByteOrder() == BigEndian )
		{
			bytes[0] = (unsigned char) (S + ( ( E & 0xfe ) >> 1 ) );
			bytes[1] = (unsigned char) (( ( E & 0x01 ) << 7 ) + ( ( F & 0x007f0000 ) >> 16));
			bytes[2] = (unsigned char) (( F & 0x0000ff00 ) >> 8);
			bytes[3] = (unsigned char) (F & 0x000000ff);
		}
		else // LittleEndian
		{
			bytes[3] = (unsigned char) (S + ( ( E & 0xfe ) >> 1 ) );
			bytes[2] = (unsigned char) (( ( E & 0x01 ) << 7 ) + ( ( F & 0x007f0000 ) >> 16));
			bytes[1] = (unsigned char) (( F & 0x0000ff00 ) >> 8);
			bytes[0] = (unsigned char) (F & 0x000000ff);
		}	

		break;

	case IBM_SINGLE_FLOAT:
		if( MemoryByteOrder() == BigEndian )
		{
			bytes[0] = (unsigned char) ( S + E );
			bytes[1] = (unsigned char) ( ( F & 0x00ff0000 ) >> 16 );
			bytes[2] = (unsigned char) ( ( F & 0x0000ff00 ) >> 8);
			bytes[3] = (unsigned char) ( F & 0x000000ff );
		}
		else // LittleEndian
		{
			bytes[3] = (unsigned char) ( S + E );
			bytes[2] = (unsigned char) ( ( F & 0x00ff0000 ) >> 16 );
			bytes[1] = (unsigned char) ( ( F & 0x0000ff00 ) >> 8);
			bytes[0] = (unsigned char) ( F & 0x000000ff );
		}	

		break;
	case VAX_SINGLE_FLOAT:
		bytes[1] = (unsigned char) (S + ( ( E & 0xfe ) >> 1 ) );
		bytes[0] = (unsigned char) (( ( E & 0x01 ) << 7 ) + ( ( F & 0x007f0000 ) >> 16));
		bytes[3] = (unsigned char) (( F & 0x0000ff00 ) >> 8);
		bytes[2] = (unsigned char) (F & 0x000000ff);	

		break;
}

return 0;
}

int DoubleSEF2Byte(int FloatType, unsigned char S, int E, unsigned long L1, unsigned long L2, unsigned char bytes[8])
{

switch(FloatType)
{
	case IEEE_DOUBLE_FLOAT:
		if( MemoryByteOrder() == BigEndian )
		{
			bytes[0] = (unsigned char) ( S + ( ( E & 0x000007f0 ) >> 4 ) );	
			bytes[1] = (unsigned char) ( ( ( E & 0x0000000f ) << 4 ) + ( ( L1 & 0x000f0000 ) >> 16 ) );
			bytes[2] = (unsigned char) ( ( L1 & 0x0000ff00 ) >> 8 );
			bytes[3] = (unsigned char) ( L1 & 0x000000ff );
			bytes[4] = (unsigned char) ( ( L2 & 0xff000000 ) >> 24 );
			bytes[5] = (unsigned char) ( ( L2 & 0x00ff0000 ) >> 16 );
			bytes[6] = (unsigned char) ( ( L2 & 0x0000ff00 ) >> 8 );
			bytes[7] = (unsigned char) ( ( L2 & 0x000000ff ) );
		}
		else
		{
			bytes[7] = (unsigned char) ( S + ( ( E & 0x000007f0 ) >> 4 ) );	
			bytes[6] = (unsigned char) ( ( ( E & 0x0000000f ) << 4 ) + ( ( L1 & 0x000f0000 ) >> 16 ) );
			bytes[5] = (unsigned char) ( ( L1 & 0x0000ff00 ) >> 8 );
			bytes[4] = (unsigned char) ( L1 & 0x000000ff );
			bytes[3] = (unsigned char) ( ( L2 & 0xff000000 ) >> 24 );
			bytes[2] = (unsigned char) ( ( L2 & 0x00ff0000 ) >> 16 );
			bytes[1] = (unsigned char) ( ( L2 & 0x0000ff00 ) >> 8 );
			bytes[0] = (unsigned char) ( ( L2 & 0x000000ff ) );
		}

		break;
	case IBM_DOUBLE_FLOAT:
		if( MemoryByteOrder() == BigEndian )
		{
			bytes[0] = (unsigned char) ( S + E );
			bytes[1] = (unsigned char) ( ( L1 & 0x00ff0000 ) >> 16 );
			bytes[2] = (unsigned char) ( ( L1 & 0x0000ff00 ) >> 8 );
			bytes[3] = (unsigned char) ( L1 & 0x000000ff );
			bytes[4] = (unsigned char) ( ( L2 & 0xff000000 ) >> 24 );
			bytes[5] = (unsigned char) ( ( L2 & 0x00ff0000 ) >> 16 );
			bytes[6] = (unsigned char) ( ( L2 & 0x0000ff00 ) >> 8 );
			bytes[7] = (unsigned char) ( ( L2 & 0x000000ff ) );
		}
		else // LittleEndian
		{
			bytes[7] = (unsigned char) ( S + E );
			bytes[6] = (unsigned char) ( ( L1 & 0x00ff0000 ) >> 16 );
			bytes[5] = (unsigned char) ( ( L1 & 0x0000ff00 ) >> 8 );
			bytes[4] = (unsigned char) ( L1 & 0x000000ff );
			bytes[3] = (unsigned char) ( ( L2 & 0xff000000 ) >> 24 );
			bytes[2] = (unsigned char) ( ( L2 & 0x00ff0000 ) >> 16 );
			bytes[1] = (unsigned char) ( ( L2 & 0x0000ff00 ) >> 8 );
			bytes[0] = (unsigned char) ( ( L2 & 0x000000ff ) );
		}	

		break;
}

return 0;
}
