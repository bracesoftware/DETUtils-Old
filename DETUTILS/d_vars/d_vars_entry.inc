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

#include "d_vars_macros"

// Integers:

#define MAX_INTEGER_VARS 1000

enum enum_IntVarData
{
	Valid,
	Multi,
	Const,
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
	Const,
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
	Const,
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
	Const,
	FloatName[32],
	Float:ReturnVal,
	Float:Dimensions[MAX_VAR_DIMENSIONS]
}

new g_FloatCache[MAX_FLOAT_VARS][enum_FloatData];

stock CallVariableHandler(const name[])
{
	new funcname[32];
	format(funcname, sizeof funcname, "@DETVAR_%s", name);
	return CallLocalFunction(funcname, "");
}

varfunc DeclareInteger(const name[], multi, constant, constvalue = 0)
{
	for(new i; i < MAX_INTEGER_VARS; i++)
	{
		if(g_IntCache[i][Valid] == 0)
		{
			strmid(g_IntCache[i][IntName], name, 0, 32);
			g_IntCache[i][Multi] = multi;
			if(constant == 1 && multi == 1)
			{
				printf("[samp-detutils]: (var error) - You can't create constant variables with more dimensions.");
				return 0;
			}
			if(multi == 1)
			{
				for(new x; x < MAX_VAR_DIMENSIONS; x++)
				{
					g_IntCache[i][Dimensions][x] = 0;// Initialize the "dimension" sizes.
				}
			}
			else if(multi == 0)
			{
				g_IntCache[i][ReturnVal] = 0; // Initialize the single return size.
			}
			if(constant == 1)
			{
				g_IntCache[i][Const] = 1;
				g_IntCache[i][ReturnVal] = constvalue;
			}
			g_IntCache[i][Valid] = 1;
			return 1;
		}	
	}
	return 0;
}

varfunc DeclareBoolean(const name[], multi, constant, bool:constvalue = false)
{
	for(new i; i < MAX_BOOLEAN_VARS; i++)
	{
		if(g_BoolCache[i][Valid] == 0)
		{
			strmid(g_BoolCache[i][BoolName], name, 0, 32);
			g_BoolCache[i][Multi] = multi;
			if(constant == 1 && multi == 1)
			{
				printf("[samp-detutils]: (var error) - You can't create constant variables with more dimensions.");
				return 0;
			}
			if(multi == 1)
			{
				for(new x; x < MAX_VAR_DIMENSIONS; x++)
				{
					g_BoolCache[i][Dimensions][x] = 0;// Initialize the "dimension" sizes.
				}
			}
			else if(multi == 0)
			{
				g_BoolCache[i][ReturnVal] = false; // Initialize the single return size.
			}
			if(constant == 1)
			{
				if(constvalue != false && constvalue != true)
				{
					printf("[samp-detutils]: (var error) - Booleans can only have 0 and 1 as values.");
					return 0;
				}
				g_BoolCache[i][Const] = 1;
				g_BoolCache[i][ReturnVal] = constvalue;
			}
			g_BoolCache[i][Valid] = 1;
			return 1;
		}	
	}
	return 0;
}

varfunc DeclareFloat(const name[], multi, constant, Float:constvalue = 0.0000)
{
	for(new i; i < MAX_FLOAT_VARS; i++)
	{
		if(g_FloatCache[i][Valid] == 0)
		{
			strmid(g_FloatCache[i][FloatName], name, 0, 32);
			g_FloatCache[i][Multi] = multi;
			if(constant == 1 && multi == 1)
			{
				printf("[samp-detutils]: (var error) - You can't create constant variables with more dimensions.");
				return 0;
			}
			if(multi == 1)
			{
				for(new x; x < MAX_VAR_DIMENSIONS; x++)
				{
					g_FloatCache[i][Dimensions][x] = 0;// Initialize the "dimension" sizes.
				}
			}
			else if(multi == 0)
			{
				g_FloatCache[i][ReturnVal] = 0; // Initialize the single return size.
			}
			if(constant == 1)
			{
				g_FloatCache[i][Const] = 1;
				g_FloatCache[i][ReturnVal] = constvalue;
			}
			g_FloatCache[i][Valid] = 1;
			return 1;
		}	
	}
	return 0;
}

varfunc DeclareString(const name[], constant, const constvalue[])
{
	for(new i; i < MAX_STRINGS; i++)
	{
		if(g_StringCache[i][Valid] == 0)
		{
			new len = strlen(constvalue);
			strmid(g_StringCache[i][StringName], name, 0, 32);
			if(constant == 1)
			{
				strmid(g_StringCache[i][ReturnVal], constvalue, 0, len);
				g_StringCache[i][Const] = 1;
			}
			else if(constant == 0)
			{
				strmid(g_StringCache[i][ReturnVal], constvalue, 0, len);
			}
			g_StringCache[i][Valid] = 1;
			return 1;
		}	
	}
	return 0;
}

stock GetIntegerValue(const name[], dimension = -1)
{
	for(new i; i < MAX_INTEGER_VARS; i++)
	{
		if(!strcmp(g_IntCache[i][IntName], name, false))
		{
			if(g_IntCache[i][Multi] == 1)
			{
				if(dimension == -1)
				{
					printf("[samp-detutils]: (var error) - Invalid dimension.");
					return 0;
				}
				return g_IntCache[i][Dimensions][dimension];
			}
			else if(g_IntCache[i][Multi] == 0)
			{
				return g_IntCache[i][ReturnVal];
			}
		}
	}
	return 0;
}

stock GetBooleanValue(const name[], dimension = -1)
{
	for(new i; i < MAX_BOOLEAN_VARS; i++)
	{
		if(!strcmp(g_BoolCache[i][BoolName], name, false))
		{
			if(g_BoolCache[i][Multi] == 1)
			{
				if(dimension == -1)
				{
					printf("[samp-detutils]: (var error) - Invalid dimension.");
					return 0;
				}
				return g_BoolCache[i][Dimensions][dimension];
			}
			else if(g_BoolCache[i][Multi] == 0)
			{
				return g_BoolCache[i][ReturnVal];
			}
		}
	}
	return 0;
}

stock Float:GetFloatValue(const name[], dimension = -1)
{
	for(new i; i < MAX_BOOLEAN_VARS; i++)
	{
		if(!strcmp(g_FloatCache[i][FloatName], name, false))
		{
			if(g_FloatCache[i][Multi] == 1)
			{
				if(dimension == -1)
				{
					printf("[samp-detutils]: (var error) - Invalid dimension.");
					return Float:0;
				}
				return g_FloatCache[i][Dimensions][dimension];
			}
			else if(g_FloatCache[i][Multi] == 0)
			{
				return g_FloatCache[i][ReturnVal];
			}
		}
	}
	return Float:0;
}

stock GetStringValue(const name[])
{
	new ret[1024];
	format(ret, 4, "NULL");
			
	for(new i; i < MAX_BOOLEAN_VARS; i++)
	{
		if(!strcmp(g_StringCache[i][StringName], name, false))
		{
			format(ret, 1024, "%s", g_StringCache[i][ReturnVal]);
			return ret;
		}
	}
	return ret;
}

// SET THE VALUE.

stock SetIntegerValue(const name[], value, dimension = -1)
{
	for(new i; i < MAX_INTEGER_VARS; i++)
	{
		if(!strcmp(g_IntCache[i][IntName], name, false))
		{
			if(g_IntCache[i][Multi] == 1)
			{
				if(dimension == -1)
				{
					printf("[samp-detutils]: (var error) - Invalid dimension.");
					return 0;
				}
				g_IntCache[i][Dimensions][dimension] = value;
				return 1;
			}
			else if(g_IntCache[i][Multi] == 0)
			{
				g_IntCache[i][ReturnVal] = value;
				return 1;
			}
		}
	}
	return 0;
}

stock SetBooleanValue(const name[], bool:value, dimension = -1)
{
	for(new i; i < MAX_BOOLEAN_VARS; i++)
	{
		if(!strcmp(g_BoolCache[i][BoolName], name, false))
		{
			if(g_BoolCache[i][Multi] == 1)
			{
				if(dimension == -1)
				{
					printf("[samp-detutils]: (var error) - Invalid dimension.");
					return 0;
				}
				g_BoolCache[i][Dimensions][dimension] = value;
				return true;
			}
			else if(g_BoolCache[i][Multi] == 0)
			{
				g_BoolCache[i][ReturnVal] = value;
				return true;
			}
		}
	}
	return 0;
}

stock SetFloatValue(const name[], Float:value, dimension = -1)
{
	for(new i; i < MAX_BOOLEAN_VARS; i++)
	{
		if(!strcmp(g_FloatCache[i][FloatName], name, false))
		{
			if(g_FloatCache[i][Multi] == 1)
			{
				if(dimension == -1)
				{
					printf("[samp-detutils]: (var error) - Invalid dimension.");
					return 0;
				}
				g_FloatCache[i][Dimensions][dimension] = value;
				return 1;
			}
			else if(g_FloatCache[i][Multi] == 0)
			{
				g_FloatCache[i][ReturnVal] = value;
				return 1;
			}
		}
	}
	return 0;
}

stock SetStringValue(const name[], const value[])
{			
	for(new i; i < MAX_BOOLEAN_VARS; i++)
	{
		if(!strcmp(g_StringCache[i][StringName], name, false))
		{
			new len = strlen(value);
			strmid(g_StringCache[i][ReturnVal], value, 0, len);
			return 1;
		}
	}
	return 0;
}

#if defined detutils_complete_error_boom
stock CreateVariable( // this is deprecated function
	const name[], 
	type, 
	constant = 0, 
	{Float,_,bool}:constvalue = {Float,_,bool}:0, 
	const conststr[] = "_", 
	multi = 0
)
{
	switch(type)
	{
		case VARIABLE_TYPE_INTEGER:
		{
			// Integers.
			for(new i; i < MAX_INTEGER_VARS; i++)
			{
				if(g_IntCache[i][Valid] == 0)
				{
					strmid(g_IntCache[i][IntName], name, 0, 32);
					g_IntCache[i][Multi] = multi;
					if(constant == 1 && multi == 1)
					{
						printf("[samp-detutils]: (var error) - You can't create constant variables with more dimensions.");
						return 0;
					}
					if(multi == 1)
					{
						for(new x; x < MAX_VAR_DIMENSIONS; x++)
						{
							g_IntCache[i][Dimensions][x] = 0;// Initialize the "dimension" sizes.
						}
					}
					else if(multi == 0)
					{
						g_IntCache[i][ReturnVal] = 0; // Initialize the single return size.
					}
					if(constant == 1)
					{
						g_IntCache[i][Const] = 1;
						g_IntCache[i][ReturnVal] = constvalue;
					}
					g_IntCache[i][Valid] = 1;
					return 1;
				}	
			}
		}
		case VARIABLE_TYPE_BOOLEAN:
		{
			// Booleans.
			for(new i; i < MAX_BOOLEAN_VARS; i++)
			{
				if(g_BoolCache[i][Valid] == 0)
				{
					strmid(g_BoolCache[i][BoolName], name, 0, 32);
					g_BoolCache[i][Multi] = multi;
					if(constant == 1 && multi == 1)
					{
						printf("[samp-detutils]: (var error) - You can't create constant variables with more dimensions.");
						return 0;
					}
					if(multi == 1)
					{
						for(new x; x < MAX_VAR_DIMENSIONS; x++)
						{
							g_BoolCache[i][Dimensions][x] = 0;// Initialize the "dimension" sizes.
						}
					}
					else if(multi == 0)
					{
						g_BoolCache[i][ReturnVal] = 0; // Initialize the single return size.
					}
					if(constant == 1)
					{
						if(constvalue != 0 && constvalue != 1)
						{
							printf("[samp-detutils]: (var error) - Booleans can only have 0 and 1 as values.");
							return 0;
						}
						g_BoolCache[i][Const] = 1;
						g_BoolCache[i][ReturnVal] = constvalue;
					}
					g_BoolCache[i][Valid] = 1;
					return 1;
				}	
			}
		}
		case VARIABLE_TYPE_STRING:
		{
			// Strings.
			for(new i; i < MAX_STRINGS; i++)
			{
				if(g_StringCache[i][Valid] == 0)
				{
					strmid(g_IntCache[i][FloatName], name, 0, 32);
					g_StringCache[i][Multi] = multi;
					if(constant == 1 && multi == 1)
					{
						printf("[samp-detutils]: (var error) - You can't create constant variables with more dimensions.");
						return 0;
					}
					if(multi == 1)
					{
						// There can't be more than a 1 return size for strings :( Pawn limits
						printf("[samp-detutils]: (string error) - Strings cannot be multidimensional variables.");
						return 0;
					}
					else if(multi == 0)
					{
						g_StringCache[i][ReturnVal] = 0; // Initialize the single return size.
					}
					g_StringCache[i][Valid] = 1;
					return 1;
				}	
			}

		}
		case VARIABLE_TYPE_FLOAT:
		{
			// Floats / real numbers.
			for(new i; i < MAX_FLOAT_VARS; i++)
			{
				if(g_FloatCache[i][Valid] == 0)
				{
					strmid(g_FloatCache[i][FloatName], name, 0, 32);
					g_FloatCache[i][Multi] = multi;
					if(constant == 1 && multi == 1)
					{
						printf("[samp-detutils]: (var error) - You can't create constant variables with more dimensions.");
						return 0;
					}
					if(multi == 1)
					{
						for(new x; x < MAX_VAR_DIMENSIONS; x++)
						{
							g_FloatCache[i][Dimensions][x] = 0;// Initialize the "dimension" sizes.
						}
					}
					else if(multi == 0)
					{
						g_FloatCache[i][ReturnVal] = 0; // Initialize the single return size.
					}
					if(constant == 1)
					{
						g_FloatCache[i][Const] = 1;
						g_FloatCache[i][ReturnVal] = constvalue;
					}
					g_FloatCache[i][Valid] = 1;
					return 1;
				}	
			}
		}
	}
	return 0;
}

#endif

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