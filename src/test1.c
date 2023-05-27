/***************************************************************************
                          test1.c  -  description
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

// small number and zero test
main()
{	
/**********************************************
 IeeeFloat: 1.0 <= 1+M <= 2.0
	test data at least include: 0.9, 1.0, 1.1, 2.0, 2.1
 IbmFloat: 0 <= M <= 1.0
	test data at least include: 0.1, 1.0, 1.1
 VaxFloat: 0.5 <= 0.5+M <= 1.5
	test data at lease include: 0.1, 0.5, 0.6, 1.5, 1.6
 **********************************************/

	float f;
	double df;

	printf("\n****************** IEEE FLOAT TEST *********************\n");
	for(df=-10.0;df<=10.0;df+=0.1)
	{
		TestlibNumber(IEEE_SINGLE_FLOAT,(float)df,df);
	}

	printf("\n****************** IBM FLOAT TEST *********************\n");
	for(df=-10.0;df<=10.0;df+=0.1)
	{
		TestlibNumber(IBM_SINGLE_FLOAT,(float)df,df);
	}

	printf("\n****************** VAX FLOAT TEST *********************\n");
	for(df=-10.0;df<=10.0;df+=0.1)
	{
		TestlibNumber(VAX_SINGLE_FLOAT,(float)df,df);
	}

}
