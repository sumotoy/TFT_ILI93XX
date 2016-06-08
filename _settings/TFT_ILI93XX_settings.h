#ifndef _TFT_ILI93XX_USETT_H_
#define _TFT_ILI93XX_USETT_H_
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
									USER SETTINGS
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*--------------------------------------------------------------------------------
Here you choose the display file for your display.
You must select just ONE and comment the others.
Default: #include "../_display/ILI9340_RED_PCB1.h"
(uncomment just one below...)
----------------------------------------------------------------------------------*/
	#include "../_display/ILI9340_RED_PCB1.h"
/*--------------------------------------------------------------------------------
- Size Reducing (decrease slight performances) -
Ignored for Teensy 3.x, DUE
Small CPU like UNO have very small resources and code optimizations uses lot of.
Uncomment _ILI93XX_SIZEOPTIMIZER will decrease space needed by code but some performance
will suffer a bit, however it can be usefult in many cases!
Default:uncommented (automatically enabled for some CPU)
----------------------------------------------------------------------------------*/
#if !defined(__MK20DX128__) && !defined(__MK20DX256__) && !defined(__SAM3X8E__)// && !defined(ESP8266)
	#define _ILI93XX_SIZEOPTIMIZER
#endif
/*--------------------------------------------------------------------------------
- Default Font -
To change default font, you must:
	_ILI93XX_DEF_FONT_PATH "the complete path of the font" (default:"_fonts/defaultFont.c")
	_ILI93XX_DEF_FONT_NAME	the_unique_name_of_the_font (default:defaultFont)
To avoid any font, just uncomment the 2 defines and a blank font will be loaded (almost 0 resources)
Default: (defaultFont = arial_2x)
#define _ILI93XX_DEF_FONT_PATH			"_fonts/defaultFont.c"
#define _ILI93XX_DEF_FONT_NAME			defaultFont
----------------------------------------------------------------------------------*/
	#define _ILI93XX_DEF_FONT_PATH			"_fonts/defaultFont.c"
	#define _ILI93XX_DEF_FONT_NAME			defaultFont
/*--------------------------------------------------------------------------------
- Default Display Rotation -
This parameter can be changed in your code but here you can force orientation
Default:0
----------------------------------------------------------------------------------*/
#define _ILI93XX_ROTATION			0
/*--------------------------------------------------------------------------------
- Default Background Color & Default Foreground Color -
When display turns on, it will set the defaul background and foreground.
the default background and foreground affects several other function
when you forget to assign color, for example clearScreen() will clear screen to black
Assigning setBackground(0xF800), red, will result in a red screen when cleared.
Default:BLACK & WHITE
----------------------------------------------------------------------------------*/
#define _ILI93XX_BACKGROUND		BLACK
#define _ILI93XX_FOREGROUND		WHITE
/*--------------------------------------------------------------------------------
- Teensy LC Fast CS Port option -
Teensy LC optional Direct Port vs digitalWriteFast methods
If you have any issues ONLY with Teensy LC and other SPI devices that share
the same SPI lines try to comment the line nelow...
The library default uses Direct Port Manipulation (that it's slight faster)
Default:uncommented
----------------------------------------------------------------------------------*/
#if defined(__MKL26Z64__)
	#define _TEENSYLC_FASTPORT
#endif
/*--------------------------------------------------------------------------------
- ESP8266 Faster SPI -
This force library to use the SPI.write method instead the legacy SPI.transfer.
As result is much faster. (Thanks Reaper7)
Default:uncommented
----------------------------------------------------------------------------------*/
#if defined(ESP8266)
	#define _ESP8266_SPIFAST
#endif
/*--------------------------------------------------------------------------------
- ESP8266 Compatibility mode -
This force library to use an alternative way to trigger ESP8266 GPIO, if you uncomment
the line it will use the standard digitaWrite wich is slow, this help debugging.
NOTE: uncomment this, code is MUCH slower!
Default:commented
----------------------------------------------------------------------------------*/
#if defined(ESP8266)
	//#define _ESP8266_STANDARDMODE
#endif
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*---------------------------------------------------------------------------------
 							 END OF USER SETTINGS
----------------------------------------------------------------------------------*/
#endif
