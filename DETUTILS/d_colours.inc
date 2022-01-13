/*

                            =============================
                              SA:MP DEntisT's Utilities
                            =============================

Legal:
    Version: MPL 1.1
    
    The contents of this file are subject to the Mozilla Public License Version 
    1.1 the "License"; you may not use this file except in compliance with 
    the License. You may obtain a copy of the License at 
    http://www.mozilla.org/MPL/
    
    Software distributed under the License is distributed on an "AS IS" basis,
    WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
    for the specific language governing rights and limitations under the
    License.
    
    The Original Code is SA:MP | utils.
    
    The Initial Developer of the original code is DEntisT 'Unity' Brace.
    Portions created by the Initial Developer are Copyright C 2021
    the Initial Developer. All Rights Reserved.

Contributors:
    DEntisT

Thanks:
    open.mp team - ideas, support, help during development

Very special thanks to:
    Thiadmer - PAWN, whose limits continue to amaze me!
    Kye/Kalcor - SA:MP
    SA:MP Team past, present and future - SA:MP
    open.mp team present and future - SA:MP

Optional plugins:
    Incognito - streamer

*/

#tryinclude "d_extra\d_libtags.inc"

#if !defined d_extra_included
    #error [samp-detutils]: (error) - You are missing "d_extra\d_libtags.inc" in your "include\DETUTILS" folder.
#endif

#if defined d_colours_included

    #endinput

#endif

#define d_colours_included

/*

                                                                                      
88b           d88              88                         db         88888888ba   88  
888b         d888              ""                        d88b        88      "8b  88  
88`8b       d8'88                                       d8'`8b       88      ,8P  88  
88 `8b     d8' 88  ,adPPYYba,  88  8b,dPPYba,          d8'  `8b      88aaaaaa8P'  88  
88  `8b   d8'  88  ""     `Y8  88  88P'   `"8a        d8YaaaaY8b     88""""""'    88  
88   `8b d8'   88  ,adPPPPP88  88  88       88       d8""""""""8b    88           88  
88    `888'    88  88,    ,88  88  88       88      d8'        `8b   88           88  
88     `8'     88  `"8bbdP"Y8  88  88       88     d8'          `8b  88           88  
                                                                                      
                                                                                      

*/

// Colour definitions:

#define COLOUR_ COLOR_

#define COLOR_HEY_WHITE         0xFFFFFFFF
#define COLOR_HEX_GREY          0xAFAFAFAA
#define COLOR_HEX_GREEN         0x33AA33AA
#define COLOR_HEX_RED           0xAA3333AA
#define COLOR_HEX_YELLOW        0xFFFF00AA
#define COLOR_HEX_WHITE         0xFFFFFFAA
#define COLOR_HEX_BLUE          0x0000BBAA
#define COLOR_HEX_LIGHTBLUE     0x33CCFFAA
#define COLOR_HEX_ORANGE        0xFF9900AA
#define COLOR_HEX_RED           0xAA3333AA
#define COLOR_HEX_LIME          0x10F441AA
#define COLOR_HEX_MAGENTA       0xFF00FFFF
#define COLOR_HEX_NAVY          0x000080AA
#define COLOR_HEX_AQUA          0xF0F8FFAA
#define COLOR_HEX_CRIMSON       0xDC143CAA
#define COLOR_HEX_FLBLUE        0x6495EDAA
#define COLOR_HEX_BISQUE        0xFFE4C4AA
#define COLOR_HEX_BLACK         0x000000AA
#define COLOR_HEX_CHARTREUSE    0x7FFF00AA
#define COLOR_HEX_BROWN         0XA52A2AAA
#define COLOR_HEX_CORAL         0xFF7F50AA
#define COLOR_HEX_GOLD          0xB8860BAA
#define COLOR_HEX_GREENYELLOW   0xADFF2FAA
#define COLOR_HEX_INDIGO        0x4B00B0AA
#define COLOR_HEX_IVORY         0xFFFF82AA
#define COLOR_HEX_LAWNGREEN     0x7CFC00AA
#define COLOR_HEX_SEAGREEN      0x20B2AAAA
#define COLOR_HEX_LIMEGREEN     0x32CD32AA 
#define COLOR_HEX_MIDNIGHTBLUE  0X191970AA
#define COLOR_HEX_MAROON        0x800000AA
#define COLOR_HEX_OLIVE         0x808000AA
#define COLOR_HEX_ORANGERED     0xFF4500AA
#define COLOR_HEX_PINK          0xFFC0CBAA 
#define COLOR_HEX_SEAGREEN2     0x2E8B57AA
#define COLOR_HEX_SPRINGGREEN   0x00FF7FAA
#define COLOR_HEX_LIGHTRED      0xFF6347AA
#define COLOR_HEX_YELLOWGREEN   0x9ACD32AA 
#define COLOR_HEX_MEDIUMAQUA    0x83BFBFAA
#define COLOR_HEX_MEDIUMMAGENTA 0x8B008BAA 

// Limits:

#if !defined MAX_COLOUR_NAME_LENGTH && !defined MAX_COLOR_NAME_LENGTH

    #define MAX_COLOUR_NAME_LENGTH (32 - 7)
    
    #define MAX_COLOR_NAME_LENGTH MAX_COLOUR_NAME_LENGTH

#endif

static stock _DeclaredColours;

// Invalid colour ids:

#define INVALID_INTEGER_COLOUR_ID __
#define INVALID_STRING_COLOUR_ID "__"

// Integer value colour functions:

#define @newk_IntColour:%0=%1; \
    new intcol_%0 = %1; 

#if defined detutils_complete_error_boom

    _DeclaredColours++;

#endif

#define @newk_IntColor:%0=%1; \
    new intcol_%0 = %1;

#if defined detutils_complete_error_boom

    _DeclaredColours++;

#endif

#define ReturnIntColour(%0) intcol_%0

#define ReturnIntColor ReturnIntColour

#define ReturnIntegerColor ReturnIntColour

#define ReturnIntegerColour ReturnIntColour

// String value colour functions:

#define @newk_StrColour:%0[%1]=%2; \
    stock strcol_%0() { new colour[%1]; format(colour, %1, "%s", %2); return colour; }

#define @newk_StrColor:%0[%1]=%2; \
    stock strcol_%0() { new colour[%1]; format(colour, %1, "%s", %2); return colour; }

#define ReturnStrColour(%0) \
    strcol_%0()

#define ReturnStrColor ReturnStrColour

#define ReturnStringColor ReturnStrColour

#define ReturnStringColour ReturnStrColour

/*
                                                                      
88888888888                                                           
88                          ,d                                        
88                          88                                        
88aaaaa      8b,     ,d8  MM88MMM  8b,dPPYba,  ,adPPYYba,  ,adPPYba,  
88"""""       `Y8, ,8P'     88     88P'   "Y8  ""     `Y8  I8[    ""  
88              )888(       88     88          ,adPPPPP88   `"Y8ba,   
88            ,d8" "8b,     88,    88          88,    ,88  aa    ]8I  
88888888888  8P'     `Y8    "Y888  88          `"8bbdP"Y8  `"YbbdP"'  
                                                                      

*/

static AnnounceLibraryLoaded_colours()
{
    print("|======================================|");
    print("             d_colours.inc              ");
    print("          Successfully loaded!          ");
    print("                                        ");
    print("               By: DEntisT              ");
    print("|======================================|");
}

#if !defined FILTERSCRIPT

main()
{
    #if defined detutils_debug
    SaveLogIntoFile("detutils_colours.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_colours.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    AnnounceLibraryLoaded_colours();
    a_colours_main();
}

#if defined _ALS_main
    #undef main
#else
    #define _ALS_main
#endif

#define main a_colours_main

#else

#define detutils_colours_TRUE 1

public OnFilterScriptInit()
{
    AnnounceLibraryLoaded_colours();
    #if defined detutils_debug
    SaveLogIntoFile("detutils_colours.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_colours.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    if(funcidx("a_colours_OnfsInit") != -1)
    {
        CallLocalFunction("a_colours_OnfsInit", "i", playerid);
    }
    return detutils_colours_TRUE;
}

#if defined _ALS_OnFilterScriptInit
    #undef OnFilterScriptInit
#else
    #define _ALS_OnFilterScriptInit
#endif

#define OnFilterScriptInit a_colours_OnfsInit

forward a_colours_OnfsInit();

#endif