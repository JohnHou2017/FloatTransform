/***************************************************************************
                          test2.c  -  description
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

main()
{	
	float f;
	double df;

	printf("input a float:\n");
	scanf("%f",&f);
	df=(double)f;

	printf("\n****************** IEEE FLOAT TEST *********************\n");
	TestlibNumber(IEEE_SINGLE_FLOAT,f,df);

	printf("\n****************** IBM FLOAT TEST *********************\n");
	TestlibNumber(IBM_SINGLE_FLOAT,f,df);

	printf("\n****************** VAX FLOAT TEST *********************\n");
	TestlibNumber(VAX_SINGLE_FLOAT,f,df);


}
