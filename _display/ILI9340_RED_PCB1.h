#ifndef _TFT_ILI9340_REDPCB1_H
#define _TFT_ILI9340_REDPCB1_H
#include <stdio.h>
#include "../_includes/ILI9341_registers.h"

/*=========================================================================================
	Part of TFT_ILI93XX library
    Copyright (c) 2014/2015/2016, .S.U.M.O.T.O.Y., coded by Max MC Costa.

    TFT_ILI93XX Library is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    TFT_ILI93XX Library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
	---------------------------------------------------------------------------------------
	Single Display Parameters
	---------------------------------------------------------------------------------------
	Display Type: RED PCB_1
===========================================================================================*/
	/* Physical display size
	*/
	static const int16_t	TFT_ILI93XX_TFTWIDTH	=	240;
	static const int16_t	TFT_ILI93XX_TFTHEIGHT 	=	320;
	static const uint32_t	TFT_ILI93XX_CGRAM = uint32_t(TFT_ILI93XX_TFTWIDTH) * uint32_t(TFT_ILI93XX_TFTHEIGHT); //type corrected
	/* Gamma Set*/
	#define TFT_ILI93XX_GAMMASET
	/* Colorspace
	Some display can use GBR colorspace or RGB (1:GBR - 0:RGB) */
	static const uint8_t	TFT_ILI93XX_CSPACE 		= 	MADCTL_BGR;
	/* Offset
	Vendors like to set his display as they like, result in offset that is different between models
	Here's a offset map for any rotatio of the display, helping code to deal with this.
	First index is rotation, second 2 parameters are offset in x and y axis. [rotation][x,y] */
	//#define TFT_ILI93XX_OFSTNEED
	
	#if defined(TFT_ILI93XX_OFSTNEED)
	static const uint8_t 	TFT_ILI93XX_OFST[4][2] = {
		{0,0},//rot 0 - x,y
		{0,0},//rot 1 - x,y
		{0,0},//rot 2 - x,y
		{0,0} //rot 3 - x,y
	};
	#endif

	
	static const uint8_t	TFT_ILI93XX_EXTREG_1[4]	=	{3,0x03,0x80,0x02};
	static const uint8_t	TFT_ILI93XX_EXTREG_2[4]	=	{3,0x00,0xC1,0x30};
	static const uint8_t	TFT_ILI93XX_EXTREG_3[4]	=	{3,0x64,0x03,0x12};
	static const uint8_t	TFT_ILI93XX_EXTREG_4[4]	=	{3,0x85,0x00,0x78};
	static const uint8_t	TFT_ILI93XX_EXTREG_5[4]	=	{3,0x39,0x2C,0x00};
	static const uint8_t	TFT_ILI93XX_EXTREG_6[2]	=	{1,0x20};
	static const uint8_t	TFT_ILI93XX_EXTREG_7[3]	=	{2,0x00,0x00};
	/*Defines how many bits per pixel are used in the interface*/
	static const uint8_t 	TFT_ILI93XX_PIXFMT[2]	=	{1,0x55};
	/*Selects the gamma curve used by the display device (0x01[1],0x02[2],0x04[3],0x08[4])*/
	static const uint8_t 	TFT_ILI93XX_GAMMACURV 	=	0x01;//[alt 0x04] default gamma curve
	//Frame Rate Control_1 (In normal mode/Full colors)
	static const uint8_t 	TFT_ILI93XX_FRMCTR1[3]	=	{2,0x00,0x18};
	//Frame Rate Control_2 (Idle mode/8 Bits)
	//static const uint8_t 	TFT_ILI93XX_FRMCTR2[3]	=	{0x01,0x2C,0x2D};
	//Frame Rate Control_3 ()
	//static const uint8_t 	TFT_ILI93XX_FRMCTR3[3]	=	{0x01,0x2C,0x2D};
	//
	static const uint8_t	TFT_ILI93XX_DFUNCTR[4]	=	{3,0x08,0x82,0x27};
	//
	static const uint8_t	TFT_ILI93XX_DINVCTR		=	0x00;//(0x00 or 0x07)
	//Power settings
	/* Set the GVDD and voltage*/
	static const uint8_t 	TFT_ILI93XX_PWCTR1[2]	= 	{1,0x23};
	static const uint8_t 	TFT_ILI93XX_PWCTR2[2]	= 	{1,0x10};
	/*Set the amount of current in Operation amplifier in normal mode/full colors.*/
	//static const uint8_t 	TFT_ILI93XX_PWCTR3[2]	= {0x0A,0x00};
	/*Set the amount of current in Operational amplifier in Idle mode/8-colors*/
	//static const uint8_t 	TFT_ILI93XX_PWCTR4[2]	= {0x8A,0x2A};
	/*Set the amount of current in Operational amplifier in Partial mode/full-colors*/
	//static const uint8_t 	TFT_ILI93XX_PWCTR5[3]	= {2,0x8A,0x2A};
	/**/
	static const uint8_t 	TFT_ILI93XX_VCOMCTR1[3] = 	{2,0x3E,0x28};
	/**/
	static const uint8_t 	TFT_ILI93XX_VCOMCTR2[2] = 	{1,0x86};
	
	static const uint8_t 	TFT_ILI93XX_GAMMASPOS[15]= 	{0x0F,0x31,0x2B,0x0C,0x0E,0x08,0x4E,0xF1,0x37,0x07,0x10,0x03,0x0E,0x09,0x00};
	static const uint8_t 	TFT_ILI93XX_GAMMASNEG[15]= 	{0x00,0x0E,0x14,0x07,0x11,0x07,0x31,0xC1,0x48,0x08,0x0F,0x0C,0x31,0x36,0x0F};
#endif
