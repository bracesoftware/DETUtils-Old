/*
 * 
 * SA:MP DEntisT's Utilities
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which provides creating
 *   various types of variables
 *   or data.
 *
 *
 */

#tryinclude "d_extra\d_libtags.inc"

#if !defined d_extra_included
	#error [samp-detutils]: (error) - You are missing "d_extra\d_libtags.inc" in your "include\DETUTILS" folder.
#endif

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

// General definitions:

#define VARIABLE_TYPE_INTEGER 0
#define VARIABLE_TYPE_BOOLEAN 1
#define VARIABLE_TYPE_STRING 2
#define VARIABLE_TYPE_FLOAT 3
#define MAX_VAR_DIMENSIONS 256

// Data types:

// Integers:

#define MAX_INTEGER_VARS 1000

enum enum_IntVarData
{
	Valid,
	Multi,
	IntName[32],
	ReturnVal,
	Dimensions[MAX_VAR_DIMENSIONS]
}

new g_IntCache[MAX_INTEGER_VARS][enum_IntVarData];

// Booleans:

#define MAX_BOOLEAN_VARS 1000

enum enum_BoolVarData
{
	Valid,
	Multi,
	BoolName[32],
	bool:ReturnVal,
	Dimensions[MAX_VAR_DIMENSIONS]
}

new g_BoolCache[MAX_BOOLEAN_VARS][enum_BoolVarData];

// Strings:

#define MAX_STRINGS 1000
#define MAX_STRING_CELLS 1024

enum enum_StringData
{
	Valid,
	Multi,
	StringName[32],
	ReturnVal[MAX_STRING_CELLS]
}

new g_StringCache[MAX_STRINGS][enum_StringData];

// Floats:

#define MAX_FLOAT_VARS 1000

enum enum_FloatData
{
	Valid,
	Multi,
	FloatName[32],
	Float:ReturnVal,
	Float:Dimensions[MAX_VAR_DIMENSIONS]
}

new g_FloatCache[MAX_FLOAT_VARS][enum]

stock CreateVariable(const name[], type, multi)
{
	switch(type)
	{
		case VARIABLE_TYPE_INTEGER:
		{
			// Integers.
			for(new i; i < MAX_INTEGER_VARS; i++)
			{
				
			}
		}
		case VARIABLE_TYPE_BOOLEAN:
		{
			// Booleans.
		}
		case VARIABLE_TYPE_STRING:
		{
			// Strings.
		}
		case VARIABLE_TYPE_FLOAT:
		{
			// Floats / real numbers.
		}
	}
	return 0;
}

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

public OnDETUtilsInit()
{
	#if defined detutils_debug
	SaveLogIntoFile("detutils_vars.log", "[samp-detutils]: (debug) - Loading...");
	SaveLogIntoFile("detutils_vars.log", "[samp-detutils]: (debug) - Loaded.");
	#endif
	LoadDETUtilsScript(DETUTILS_SCRIPT_VARS);
	if(funcidx("d_vs_detutilsinit") != -1)
	{
		CallLocalFunction("d_vs_detutilsinit", "");
	}
	return 1;
}

#if defined _ALS_OnDETUtilsInit
	#undef OnDETUtilsInit
#else
	#define _ALS_OnDETUtilsInit
#endif

#define OnDETUtilsInit d_vs_detutilsinit

forward d_vs_detutilsinit();