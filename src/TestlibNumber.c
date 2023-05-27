/***************************************************************************
                          TestlibNumber.c  -  description
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

void TestlibNumber(int FloatType, float f, double df)
{

switch(FloatType)
{
	case IEEE_SINGLE_FLOAT:
	case IEEE_DOUBLE_FLOAT:
		IeeeFloatTest(f, df);
		break;
	case IBM_SINGLE_FLOAT:
	case IBM_DOUBLE_FLOAT:
		IbmFloatTest(f, df);
		break;
	case VAX_SINGLE_FLOAT:
		VaxFloatTest(f, df);
		break;
}

}

void IeeeFloatTest(float f, double df)
{
	unsigned char bb[8];
	float f1=f;
	double df1=df;

	// ieee float test

	printf("--------------------------------------------\n");

	memset(bb,'\0',sizeof(bb));

	IeeeSingleFloat2ByteUnion(f1,bb);

	printf("\nIeeeSingleFloat2ByteUnion:\n%f ==> %.2X %.2X %.2X %.2X\n", f1,
		bb[0],bb[1],bb[2],bb[3]);

	f1=0;

	Byte2IeeeSingleFloatUnion(bb,&f1);

	printf("\nByte2IeeeSingleFloatUnion:\n%.2X %.2X %.2X %.2X ==> %f\n",
		bb[0],bb[1],bb[2],bb[3],f1);

	printf("--------------------------------------------\n");

	
	memset(bb,'\0',sizeof(bb));

	IeeeDoubleFloat2ByteUnion(f1,bb);

	printf("\nIeeeDoubleFloat2ByteUnion:\n%f ==> %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X\n", df1,
		bb[0],bb[1],bb[2],bb[3],bb[4],bb[5],bb[6],bb[7]);

	df1=0;

	Byte2IeeeDoubleFloatUnion(bb,&df1);

	printf("\nByte2IeeeDoubleFloatUnion:\n%.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X ==> %f\n",
		bb[0],bb[1],bb[2],bb[3],bb[4],bb[5],bb[6],bb[7],df1);

	printf("--------------------------------------------\n");
		
	f1=f;
	memset(bb,'\0',sizeof(bb));

	IeeeSingleFloat2ByteL(f1,bb);

	printf("\nIeeeSingleFloat2ByteL:\n%f ==> %.2X %.2X %.2X %.2X\n",
		f1,bb[0],bb[1],bb[2],bb[3]);

	f1=f;
	memset(bb,'\0',sizeof(bb));

	IeeeSingleFloat2ByteM(f1,bb);

	printf("\nIeeeSingleFloat2ByteM:\n%f ==> %.2X %.2X %.2X %.2X\n",
		f1,bb[0],bb[1],bb[2],bb[3]);

	f1=0;

	Byte2IeeeSingleFloat(bb,&f1);

	printf("\nByte2IeeeSingleFloat:\n%.2X %.2X %.2X %.2X ==> %f\n",
		bb[0],bb[1],bb[2],bb[3],f1);
	
	printf("--------------------------------------------\n");

	// ieee double byte test

	df1=df;
	memset(bb,'\0',sizeof(bb));

	IeeeDoubleFloat2ByteL(df1,bb);

	printf("\nIeeeDoubleFloat2ByteL:\n%f ==> %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X\n", df1,
		bb[0],bb[1],bb[2],bb[3],bb[4],bb[5],bb[6],bb[7]);

	df1=df;
	memset(bb,'\0',sizeof(bb));

	IeeeDoubleFloat2ByteM(df1,bb);

	printf("\nIeeeDoubleFloat2ByteM:\n%f ==> %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X\n", df1,
		bb[0],bb[1],bb[2],bb[3],bb[4],bb[5],bb[6],bb[7]);

	df1=0;

	Byte2IeeeDoubleFloat(bb,&df1);

	printf("\nByte2IeeeDoubleFloat:\n%.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X ==> %f\n", 
		bb[0],bb[1],bb[2],bb[3],bb[4],bb[5],bb[6],bb[7],df1);

	printf("--------------------------------------------\n");
}

void IbmFloatTest(float f, double df)
{
	unsigned char bb[8];
	float f1=f;
	double df1=df;

	// ibm float to byte

	f1=f;
	memset(bb,'\0',sizeof(bb));

	IbmSingleFloat2ByteL(f1,bb);

	printf("\nIbmSingleFloat2ByteL:\n%f ==> %.2X %.2X %.2X %.2X\n",
		f1,bb[0],bb[1],bb[2],bb[3]);	

	f1=f;
	memset(bb,'\0',sizeof(bb));

	IbmSingleFloat2ByteM(f1,bb);

	printf("\nIbmSingleFloat2ByteM:\n%f ==> %.2X %.2X %.2X %.2X\n",
		f1,bb[0],bb[1],bb[2],bb[3]);	

	f1=0;

	Byte2IbmSingleFloat(bb,&f1);

	printf("\nByte2IbmSingleFloat:\n%.2X %.2X %.2X %.2X ==> %f\n",
		bb[0],bb[1],bb[2],bb[3],f1);	

	printf("--------------------------------------------\n");

	df1=df;
	memset(bb,'\0',sizeof(bb));

	IbmDoubleFloat2ByteL(df1,bb);

	printf("\nIbmDoubleFloat2ByteL:\n%f ==> %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X\n", df1,
		bb[0],bb[1],bb[2],bb[3],bb[4],bb[5],bb[6],bb[7]);

	df1=df;
	memset(bb,'\0',sizeof(bb));

	IbmDoubleFloat2ByteM(df1,bb);

	printf("\nIbmDoubleFloat2ByteM:\n%f ==> %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X\n", df1,
		bb[0],bb[1],bb[2],bb[3],bb[4],bb[5],bb[6],bb[7]);

	df1=0;

	Byte2IbmDoubleFloat(bb,&df1);

	printf("\nByte2IbmDoubleFloat:\n%.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X ==> %f\n", 
		bb[0],bb[1],bb[2],bb[3],bb[4],bb[5],bb[6],bb[7],df1);

	printf("--------------------------------------------\n");

}

void VaxFloatTest(float f, double df)
{
	unsigned char bb[8];
	float f1=f;
	double df1=df;

	// vax float test

	f1=f;
	memset(bb,'\0',sizeof(bb));

	VaxSingleFloat2ByteL(f1,bb);

	printf("\nVaxSingleFloat2ByteL:\n%f ==> %.2X %.2X %.2X %.2X\n",
		f1,bb[0],bb[1],bb[2],bb[3]);	

	f1=f;
	memset(bb,'\0',sizeof(bb));

	VaxSingleFloat2ByteM(f1,bb);

	printf("\nVaxSingleFloat2ByteM:\n%f ==> %.2X %.2X %.2X %.2X\n",
		f1,bb[0],bb[1],bb[2],bb[3]);	

	f1=0;

	Byte2VaxSingleFloat(bb,&f1);

	printf("\nByte2VaxSingleFloat:\n%.2X %.2X %.2X %.2X ==> %f\n",
		bb[0],bb[1],bb[2],bb[3],f1);	

	printf("--------------------------------------------\n");
}	
