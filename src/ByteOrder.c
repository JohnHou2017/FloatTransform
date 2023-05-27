/***************************************************************************
                          ByteOrder.c  -  description
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

/*
The Basics

"Little Endian" means that the low-order byte of the number is stored in memory at the lowest address, and the high-order byte at the highest address. (The little end comes first.) For example, a 4 byte LongInt

    Byte3 Byte2 Byte1 Byte0

will be arranged in memory as follows:

    Base Address+0   Byte0
    Base Address+1   Byte1
    Base Address+2   Byte2
    Base Address+3   Byte3

Intel processors (those used in PC's) use "Little Endian" byte order.

"Big Endian" means that the high-order byte of the number is stored in memory at the lowest address, and the low-order byte at the highest address. (The big end comes first.) Our LongInt, would then be stored as:

    Base Address+0   Byte3
    Base Address+1   Byte2
    Base Address+2   Byte1
    Base Address+3   Byte0

Motorola processors (those used in Mac's) use "Big Endian" byte order.
 */

int MemoryByteOrder()
{

union {
	unsigned char cc[2];
	unsigned short int si;
}aa;

aa.si=258;

/* Intel: aa.cc[0]=2  // LittleEndian
   SPARC: aa.cc[0]=1  // BigEndian
*/

return aa.cc[0];
}
