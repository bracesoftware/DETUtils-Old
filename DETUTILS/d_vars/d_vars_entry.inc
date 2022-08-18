/*
 * 
 * DETUtils
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
	#error [DETUtils]: (error) - You are missing "d_extra\d_libtags.inc" in your "include\DETUTILS" folder.
#endif

// Defining up there for 'strret' thing.
#define MAX_STRING_CELLS 1024

#if !defined DETUTILS_NO_STRVARRET

 	#include "d_vars_strret"

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

// CallLocalFunction("OnVariableCreate", "si", name, VARIABLE_TYPE_);
forward OnVariableCreate(varname[], vartype);
// CallLocalFunction("OnVariableUpdate", "siii", name, VARIABLE_TYPE_, value, dimension);
forward OnVariableUpdate(varname[], vartype, value, dimension);
// CallLocalFunction("OnVariableDelete", "si", name, VARIABLE_TYPE_);
forward OnVariableDelete(varname[], vartype);

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
#define MAX_STRING_VARS MAX_STRINGS

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

// DELETE FUNCS

// Delete functions are REALLY important.
// Though, I HIGHLY recommend to delete every variable which is not needed because
// if you don't, you'll eventually run out of space required for variables to create 
// and create functions will fail.

stock __DeleteIntegerVariable(const name[])
{
	for(new i; i < MAX_INTEGER_VARS; i++)
	{
		if(!strcmp(g_IntCache[i][IntName], name, false))
		{
			strmid(g_IntCache[i][IntName], " ", 0, 1);
			g_IntCache[i][Valid] = 0;
			for(new x; x < MAX_VAR_DIMENSIONS; x++)
			{
				g_IntCache[i][Dimensions][x] = 0;
			}
			g_IntCache[i][ReturnVal] = 0;
			CallLocalFunction("OnVariableDelete", "si", name, VARIABLE_TYPE_INTEGER);
			return 1;
		}
	}
	return 0;
}

stock __DeleteBooleanVariable(const name[])
{
	for(new i; i < MAX_BOOLEAN_VARS; i++)
	{
		if(!strcmp(g_BoolCache[i][BoolName], name, false))
		{
			strmid(g_BoolCache[i][BoolName], " ", 0, 1);
			g_BoolCache[i][Valid] = 0;
			for(new x; x < MAX_VAR_DIMENSIONS; x++)
			{
				g_BoolCache[i][Dimensions][x] = false;
			}
			g_BoolCache[i][ReturnVal] = false;
			CallLocalFunction("OnVariableDelete", "si", name, VARIABLE_TYPE_BOOLEAN);
			return 1;
		}
	}
	return 0;
}

stock __DeleteFloatVariable(const name[])
{
	for(new i; i < MAX_FLOAT_VARS; i++)
	{
		if(!strcmp(g_FloatCache[i][FloatName], name, false))
		{
			strmid(g_FloatCache[i][FloatName], " ", 0, 1);
			g_FloatCache[i][Valid] = 0;
			for(new x; x < MAX_VAR_DIMENSIONS; x++)
			{
				g_FloatCache[i][Dimensions][x] = Float:0;
			}
			g_FloatCache[i][ReturnVal] = Float:0;
			CallLocalFunction("OnVariableDelete", "si", name, VARIABLE_TYPE_FLOAT);
			return 1;
		}
	}
	return 0;
}

stock __DeleteStringVariable(const name[])
{
	for(new i; i < MAX_STRING_VARS; i++)
	{
		if(!strcmp(g_StringCache[i][StringName], name, false))
		{
			strmid(g_StringCache[i][ReturnVal], " ", 0, 1);
			strmid(g_StringCache[i][StringName], " ", 0, 1);
			g_StringCache[i][Valid] = 0;
			CallLocalFunction("OnVariableDelete", "si", name, VARIABLE_TYPE_STRING);
			return 1;
		}
	}
	return 0;
}

// DECLARATION FUNCS

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
				printf("[DETUtils]: (var error) - You can't create constant variables with more dimensions.");
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
			CallLocalFunction("OnVariableCreate", "si", name, VARIABLE_TYPE_INTEGER);
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
				printf("[DETUtils]: (var error) - You can't create constant variables with more dimensions.");
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
					printf("[DETUtils]: (var error) - Booleans can only have 0 and 1 as values.");
					return 0;
				}
				g_BoolCache[i][Const] = 1;
				g_BoolCache[i][ReturnVal] = constvalue;
			}
			CallLocalFunction("OnVariableCreate", "si", name, VARIABLE_TYPE_BOOLEAN);
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
				printf("[DETUtils]: (var error) - You can't create constant variables with more dimensions.");
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
			CallLocalFunction("OnVariableCreate", "si", name, VARIABLE_TYPE_FLOAT);
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
			CallLocalFunction("OnVariableCreate", "si", name, VARIABLE_TYPE_STRING);
			g_StringCache[i][Valid] = 1;
			return 1;
		}	
	}
	return 0;
}

// GET... FUNCS

stock __GetIntegerValue(const name[], dimension = -1)
{
	for(new i; i < MAX_INTEGER_VARS; i++)
	{
		if(!strcmp(g_IntCache[i][IntName], name, false))
		{
			if(g_IntCache[i][Multi] == 1)
			{
				if(dimension == -1)
				{
					printf("[DETUtils]: (var error) - Invalid dimension.");
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

stock __GetBooleanValue(const name[], dimension = -1)
{
	for(new i; i < MAX_BOOLEAN_VARS; i++)
	{
		if(!strcmp(g_BoolCache[i][BoolName], name, false))
		{
			if(g_BoolCache[i][Multi] == 1)
			{
				if(dimension == -1)
				{
					printf("[DETUtils]: (var error) - Invalid dimension.");
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

stock Float:__GetFloatValue(const name[], dimension = -1)
{
	for(new i; i < MAX_FLOAT_VARS; i++)
	{
		if(!strcmp(g_FloatCache[i][FloatName], name, false))
		{
			if(g_FloatCache[i][Multi] == 1)
			{
				if(dimension == -1)
				{
					printf("[DETUtils]: (var error) - Invalid dimension.");
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

stock __GetStringValue(const name[])
{
	new ret[1024];
	format(ret, 4, "NULL");
			
	for(new i; i < MAX_STRING_VARS; i++)
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

stock __SetIntegerValue(const name[], value, dimension = -1)
{
	for(new i; i < MAX_INTEGER_VARS; i++)
	{
		if(!strcmp(g_IntCache[i][IntName], name, false))
		{
			if(g_IntCache[i][Const] == 1)
			{
				printf("[DETUtils]: (var error) - Cannot update the constant value of : %s", name);
				return 0;
			}
			if(g_IntCache[i][Multi] == 1)
			{
				if(dimension == -1)
				{
					printf("[DETUtils]: (var error) - Invalid dimension.");
					return 0;
				}
				CallLocalFunction("OnVariableUpdate", "siii", name, VARIABLE_TYPE_INTEGER, value, dimension);
				g_IntCache[i][Dimensions][dimension] = value;
				return 1;
			}
			else if(g_IntCache[i][Multi] == 0)
			{
				CallLocalFunction("OnVariableUpdate", "siii", name, VARIABLE_TYPE_INTEGER, value, dimension);
				g_IntCache[i][ReturnVal] = value;
				return 1;
			}
		}
	}
	return 0;
}

stock __SetBooleanValue(const name[], bool:value, dimension = -1)
{
	for(new i; i < MAX_BOOLEAN_VARS; i++)
	{
		if(!strcmp(g_BoolCache[i][BoolName], name, false))
		{
			if(g_BoolCache[i][Const] == 1)
			{
				printf("[DETUtils]: (var error) - Cannot update the constant value of : %s", name);
				return 0;
			}
			if(value != false && value != true)
			{
				printf("[DETUtils]: (var error) - Boolean variables can only hold the values of 0 and 1.");
				return 0;
			}
			if(g_BoolCache[i][Multi] == 1)
			{
				if(dimension == -1)
				{
					printf("[DETUtils]: (var error) - Invalid dimension.");
					return 0;
				}
				CallLocalFunction("OnVariableUpdate", "siii", name, VARIABLE_TYPE_BOOLEAN, value, dimension);
				g_BoolCache[i][Dimensions][dimension] = value;
				return true;
			}
			else if(g_BoolCache[i][Multi] == 0)
			{
				CallLocalFunction("OnVariableUpdate", "siii", name, VARIABLE_TYPE_BOOLEAN, value, dimension);
				g_BoolCache[i][ReturnVal] = value;
				return true;
			}
		}
	}
	return 0;
}

stock __SetFloatValue(const name[], Float:value, dimension = -1)
{
	for(new i; i < MAX_FLOAT_VARS; i++)
	{
		if(!strcmp(g_FloatCache[i][FloatName], name, false))
		{
			if(g_FloatCache[i][Const] == 1)
			{
				printf("[DETUtils]: (var error) - Cannot update the constant value of : %s", name);
				return 0;
			}
			if(g_FloatCache[i][Multi] == 1)
			{
				if(dimension == -1)
				{
					printf("[DETUtils]: (var error) - Invalid dimension.");
					return 0;
				}
				CallLocalFunction("OnVariableUpdate", "siii", name, VARIABLE_TYPE_FLOAT, value, dimension);
				g_FloatCache[i][Dimensions][dimension] = value;
				return 1;
			}
			else if(g_FloatCache[i][Multi] == 0)
			{
				CallLocalFunction("OnVariableUpdate", "siii", name, VARIABLE_TYPE_FLOAT, value, dimension);
				g_FloatCache[i][ReturnVal] = value;
				return 1;
			}
		}
	}
	return 0;
}

stock __SetStringValue(const name[], const value[])
{			
	for(new i; i < MAX_STRING_VARS; i++)
	{
		if(!strcmp(g_StringCache[i][StringName], name, false))
		{
			if(g_StringCache[i][Const] == 1)
			{
				printf("[DETUtils]: (var error) - Cannot update the constant value of : %s", name);
				return 0;
			}
			new len = strlen(value);
			strmid(g_StringCache[i][ReturnVal], value, 0, len);
			CallLocalFunction("OnVariableUpdate", "siii", name, VARIABLE_TYPE_STRING, 0, -1);
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
						printf("[DETUtils]: (var error) - You can't create constant variables with more dimensions.");
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
						printf("[DETUtils]: (var error) - You can't create constant variables with more dimensions.");
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
							printf("[DETUtils]: (var error) - Booleans can only have 0 and 1 as values.");
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
						printf("[DETUtils]: (var error) - You can't create constant variables with more dimensions.");
						return 0;
					}
					if(multi == 1)
					{
						// There can't be more than a 1 return size for strings :( Pawn limits
						printf("[DETUtils]: (string error) - Strings cannot be multidimensional variables.");
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
						printf("[DETUtils]: (var error) - You can't create constant variables with more dimensions.");
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

stock __GetIntegerVarId(const name[])
{
	for(new i = 1; 
        i < MAX_INTEGER_VARS; 
        i++)
    {
        if(!strcmp(g_IntCache[i][IntName], name))
        {
            return i;
        }
    }
    return 0;
}

stock __GetBoolVarId(const name[])
{
	for(new i = 1; 
        i < MAX_BOOLEAN_VARS; 
        i++)
    {
        if(!strcmp(g_BoolCache[i][BoolName], name))
        {
            return i;
        }
    }
    return 0;
}

stock __GetFloatVarId(const name[])
{
	for(new i = 1; 
        i < MAX_FLOAT_VARS; 
        i++)
    {
        if(!strcmp(g_FloatCache[i][FloatName], name))
        {
            return i;
        }
    }
    return 0;
}

stock __GetStringVarId(const name[])
{
	for(new i = 1; 
        i < MAX_STRING_VARS; 
        i++)
    {
        if(!strcmp(g_StringCache[i][StringName], name))
        {
            return i;
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

#if defined DETUTILS_OLD_HOOK
public OnDETUtilsInit()
{
	#if defined detutils_debug
	SaveLogIntoFile("detutils_vars.log", "[DETUtils]: (debug) - Loading...");
	SaveLogIntoFile("detutils_vars.log", "[DETUtils]: (debug) - Loaded.");
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

#define OnDETUtilsInit( d_vs_detutilsinit(

forward d_vs_detutilsinit();
#endif
/*
public OnDETUtilsInit()
{
    // Set the default return value.
    #emit ZERO.pri
    #if defined d_vs_detutilsinit
        d_vs_detutilsinit();
    #endif
    #if defined detutils_debug
	SaveLogIntoFile("detutils_vars.log", "[DETUtils]: (debug) - Loading...");
	SaveLogIntoFile("detutils_vars.log", "[DETUtils]: (debug) - Loaded.");
	#endif
	LoadDETUtilsScript(DETUTILS_SCRIPT_VARS);
    // Implicitly return the value of the previous call.  This means we can
    // call `main` and return it's return value, without requiring it to
    // have a `return` statement.  It might, but the most common uses don't.
    #emit RETN
    // Return 0, just in case.
    return 0;
}

#if defined _ALS_OnDETUtilsInit
    #undef OnDETUtilsInit
#else
    #define _ALS_OnDETUtilsInit
#endif
forward d_vs_detutilsinit();

#define OnDETUtilsInit( d_vs_detutilsinit(
*/
// d_filequeries.inc
#if !defined DETUTILS_NO_FILEQUERIES

// INTEGERS

/*
enum enum_IntVarData
{
	Valid,
	Multi,
	Const,
	IntName[32],
	ReturnVal,
	Dimensions[MAX_VAR_DIMENSIONS]
}
*/

stock __SaveIntegerVariable(const name[])
{
	for(new i; i < MAX_INTEGER_VARS; i++)
	{
		if(!strcmp(g_IntCache[i][IntName], name, false))
		{
			new 
				savequeryfile[32], 
				savequery[64], 
				query[1024],
				dquery[64];

			format(savequeryfile, sizeof savequeryfile, "d_int_%s.ini", name);
			format(savequery, sizeof savequery, "d_int_%s", name);

			CreateQuery(savequery, QUERY_TYPE_SAVE, "d_vars_cache", savequeryfile);
			format(query, sizeof query, "SAVE * %i,%i,%i,%s,%i", 
				g_IntCache[i][Valid],
				g_IntCache[i][Multi],
				g_IntCache[i][Const],
				g_IntCache[i][IntName],
				g_IntCache[i][ReturnVal]);

			for(new x; x < MAX_VAR_DIMENSIONS; x++)
			{
				format(dquery, sizeof dquery, ",%i", g_IntCache[i][Dimensions][x]);
				strcat(query, dquery);
			}

			FormatQuery(savequery, query);
			SendQuery(savequery);
			DestroyQuery(savequery);
			
			delete Integer(name);

			return 1;
		}
	}
	return 0;
}

/*
new content[1024]; // var in which the content will be stored
FormatQuery(LoadQuery, "LOAD *"); // format the file query
SendQuery(LoadQuery); // send it
GetLoadedQueryContent(LoadQuery, content); // After the LOAD query was sent, we need to get the content of the data.
SendClientMessage(playerid, -1, "Loaded query file content: %s", content); // For debugging purposes
new array[3][64]; // declare this array for PARSING
ParseQueryContent(content, array); // Parse the content
strmid(PlayerCache[playerid][password], array[0]); // Get the password 
PlayerCache[playerid][money] = strval(array[1]); // Get the money
PlayerCache[playerid][admin] = strval(array[2]); // Get the admin boolean

enum enum_IntVarData
{
	Valid,
	Multi,
	Const,
	IntName[32],
	ReturnVal,
	Dimensions[MAX_VAR_DIMENSIONS]
}
*/

stock __LoadIntegerVariable(const name[])
{
	new 
		loadqueryfile[32], 
		loadquery[64], 
		content[1024],
		address[263][64];

	format(loadqueryfile, sizeof loadqueryfile, "d_int_%s.ini", name);
	format(loadquery, sizeof loadquery, "d_int_%s", name);

	CreateQuery(loadquery, QUERY_TYPE_SAVE, "d_vars_cache", loadqueryfile);

	if(!QueryFileExist(loadquery))
	{
		printf("[DETUtils]: (var error) - Unable to load variable : '%s'; persistent data does not exist.", name);
		DestroyQuery(loadquery);
		return 0;
	}

	FormatQuery(loadquery, "LOAD *");
	SendQuery(loadquery);

	GetLoadedQueryContent(loadquery, content);
	ParseQueryContent(content, address);

	DET_gV_DeclareInteger(name, false, false, 0);
	new id = __GetIntegerVarId(name);

	g_IntCache[id][Valid] = strval(address[0]);
	g_IntCache[id][Multi] = strval(address[1]);
	g_IntCache[id][Const] = strval(address[2]);
	// We skip 3 since it is name.
	g_IntCache[id][ReturnVal] = strval(address[4]);
	for(new i; i < MAX_VAR_DIMENSIONS; i++)
	{
		g_IntCache[id][Dimensions][i] = strval(address[i+5]);
	}

	DestroyQuery(loadquery);

	return 1;
}

// BOOLEANS

/*
enum enum_IntVarData
{
	Valid,
	Multi,
	Const,
	IntName[32],
	ReturnVal,
	Dimensions[MAX_VAR_DIMENSIONS]
}
*/

stock __SaveBooleanVariable(const name[])
{
	for(new i; i < MAX_BOOLEAN_VARS; i++)
	{
		if(!strcmp(g_BoolCache[i][BoolName], name, false))
		{
			new 
				savequeryfile[32], 
				savequery[64], 
				query[1024],
				dquery[64];

			format(savequeryfile, sizeof savequeryfile, "d_bol_%s.ini", name);
			format(savequery, sizeof savequery, "d_bol_%s", name);

			CreateQuery(savequery, QUERY_TYPE_SAVE, "d_vars_cache", savequeryfile);
			format(query, sizeof query, "SAVE * %i,%i,%i,%s,%i", 
				g_BoolCache[i][Valid],
				g_BoolCache[i][Multi],
				g_BoolCache[i][Const],
				g_BoolCache[i][BoolName],
				g_BoolCache[i][ReturnVal]);

			for(new x; x < MAX_VAR_DIMENSIONS; x++)
			{
				format(dquery, sizeof dquery, ",%i", g_BoolCache[i][Dimensions][x]);
				strcat(query, dquery);
			}

			FormatQuery(savequery, query);
			SendQuery(savequery);
			DestroyQuery(savequery);
			
			delete Boolean(name);

			return 1;
		}
	}
	return 0;
}

/*
new content[1024]; // var in which the content will be stored
FormatQuery(LoadQuery, "LOAD *"); // format the file query
SendQuery(LoadQuery); // send it
GetLoadedQueryContent(LoadQuery, content); // After the LOAD query was sent, we need to get the content of the data.
SendClientMessage(playerid, -1, "Loaded query file content: %s", content); // For debugging purposes
new array[3][64]; // declare this array for PARSING
ParseQueryContent(content, array); // Parse the content
strmid(PlayerCache[playerid][password], array[0]); // Get the password 
PlayerCache[playerid][money] = strval(array[1]); // Get the money
PlayerCache[playerid][admin] = strval(array[2]); // Get the admin boolean

enum enum_IntVarData
{
	Valid,
	Multi,
	Const,
	IntName[32],
	ReturnVal,
	Dimensions[MAX_VAR_DIMENSIONS]
}
*/

stock __LoadBooleanVariable(const name[])
{
	new 
		loadqueryfile[32], 
		loadquery[64], 
		content[1024],
		address[263][64];

	format(loadqueryfile, sizeof loadqueryfile, "d_bol_%s.ini", name);
	format(loadquery, sizeof loadquery, "d_bol_%s", name);

	CreateQuery(loadquery, QUERY_TYPE_SAVE, "d_vars_cache", loadqueryfile);

	if(!QueryFileExist(loadquery))
	{
		printf("[DETUtils]: (var error) - Unable to load variable : '%s'; persistent data does not exist.", name);
		DestroyQuery(loadquery);
		return 0;
	}

	FormatQuery(loadquery, "LOAD *");
	SendQuery(loadquery);

	GetLoadedQueryContent(loadquery, content);
	ParseQueryContent(content, address);

	DET_gV_DeclareBoolean(name, false, false, 0);
	new id = __GetBooleanVarId(name);

	g_BoolCache[id][Valid] = strval(address[0]);
	g_BoolCache[id][Multi] = strval(address[1]);
	g_BoolCache[id][Const] = strval(address[2]);
	// We skip 3 since it is name.
	g_BoolCache[id][ReturnVal] = strval(address[4]);
	for(new i; i < MAX_VAR_DIMENSIONS; i++)
	{
		g_BoolCache[id][Dimensions][i] = strval(address[i+5]);
	}

	DestroyQuery(loadquery);

	return 1;
}

// FLOATS

/*
enum enum_IntVarData
{
	Valid,
	Multi,
	Const,
	IntName[32],
	ReturnVal,
	Dimensions[MAX_VAR_DIMENSIONS]
}
*/

stock __SaveFloatVariable(const name[])
{
	for(new i; i < MAX_FLOAT_VARS; i++)
	{
		if(!strcmp(g_FloatCache[i][FloatName], name, false))
		{
			new 
				savequeryfile[32], 
				savequery[64], 
				query[1024],
				dquery[64];

			format(savequeryfile, sizeof savequeryfile, "d_flo_%s.ini", name);
			format(savequery, sizeof savequery, "d_flo_%s", name);

			CreateQuery(savequery, QUERY_TYPE_SAVE, "d_vars_cache", savequeryfile);
			format(query, sizeof query, "SAVE * %i,%i,%i,%s,%f", 
				g_FloatCache[i][Valid],
				g_FloatCache[i][Multi],
				g_FloatCache[i][Const],
				g_FloatCache[i][FloatName],
				g_FloatCache[i][ReturnVal]);

			for(new x; x < MAX_VAR_DIMENSIONS; x++)
			{
				format(dquery, sizeof dquery, ",%f", g_FloatCache[i][Dimensions][x]);
				strcat(query, dquery);
			}

			FormatQuery(savequery, query);
			SendQuery(savequery);
			DestroyQuery(savequery);
			
			delete Float(name);

			return 1;
		}
	}
	return 0;
}

/*
new content[1024]; // var in which the content will be stored
FormatQuery(LoadQuery, "LOAD *"); // format the file query
SendQuery(LoadQuery); // send it
GetLoadedQueryContent(LoadQuery, content); // After the LOAD query was sent, we need to get the content of the data.
SendClientMessage(playerid, -1, "Loaded query file content: %s", content); // For debugging purposes
new array[3][64]; // declare this array for PARSING
ParseQueryContent(content, array); // Parse the content
strmid(PlayerCache[playerid][password], array[0]); // Get the password 
PlayerCache[playerid][money] = strval(array[1]); // Get the money
PlayerCache[playerid][admin] = strval(array[2]); // Get the admin boolean

enum enum_IntVarData
{
	Valid,
	Multi,
	Const,
	IntName[32],
	ReturnVal,
	Dimensions[MAX_VAR_DIMENSIONS]
}
*/

stock __LoadFloatVariable(const name[])
{
	new 
		loadqueryfile[32], 
		loadquery[64], 
		content[1024],
		address[263][64];

	format(loadqueryfile, sizeof loadqueryfile, "d_flo_%s.ini", name);
	format(loadquery, sizeof loadquery, "d_flo_%s", name);

	CreateQuery(loadquery, QUERY_TYPE_SAVE, "d_vars_cache", loadqueryfile);

	if(!QueryFileExist(loadquery))
	{
		printf("[DETUtils]: (var error) - Unable to load variable : '%s'; persistent data does not exist.", name);
		DestroyQuery(loadquery);
		return 0;
	}

	FormatQuery(loadquery, "LOAD *");
	SendQuery(loadquery);

	GetLoadedQueryContent(loadquery, content);
	ParseQueryContent(content, address);

	DET_gV_DeclareFloat(name, false, false, 0);
	new id = __GetFloatVarId(name);

	g_BoolCache[id][Valid] = strval(address[0]);
	g_BoolCache[id][Multi] = strval(address[1]);
	g_BoolCache[id][Const] = strval(address[2]);
	// We skip 3 since it is name.
	g_BoolCache[id][ReturnVal] = floatstr(address[4]);
	for(new i; i < MAX_VAR_DIMENSIONS; i++)
	{
		g_BoolCache[id][Dimensions][i] = floatstr(address[i+5]);
	}

	DestroyQuery(loadquery);

	return 1;
}

// STRINGS

/*
enum enum_IntVarData
{
	Valid,
	Multi,
	Const,
	IntName[32],
	ReturnVal,
	Dimensions[MAX_VAR_DIMENSIONS]
}
*/

stock __SaveStringVariable(const name[])
{
	for(new i; i < MAX_STRING_VARS; i++)
	{
		if(!strcmp(g_StringCache[i][StringName], name, false))
		{
			new 
				savequeryfile[32], 
				savequery[64], 
				query[1024],
				dquery[64];

			format(savequeryfile, sizeof savequeryfile, "d_str_%s.ini", name);
			format(savequery, sizeof savequery, "d_str_%s", name);

			CreateQuery(savequery, QUERY_TYPE_SAVE, "d_vars_cache", savequeryfile);
			format(query, sizeof query, "SAVE * %i,%i,%s,%s", 
				g_StringCache[i][Valid],
				g_StringCache[i][Const],
				g_StringCache[i][StringName],
				g_StringCache[i][ReturnVal]);

			FormatQuery(savequery, query);
			SendQuery(savequery);
			DestroyQuery(savequery);
			
			delete String(name);

			return 1;
		}
	}
	return 0;
}

/*
new content[1024]; // var in which the content will be stored
FormatQuery(LoadQuery, "LOAD *"); // format the file query
SendQuery(LoadQuery); // send it
GetLoadedQueryContent(LoadQuery, content); // After the LOAD query was sent, we need to get the content of the data.
SendClientMessage(playerid, -1, "Loaded query file content: %s", content); // For debugging purposes
new array[3][64]; // declare this array for PARSING
ParseQueryContent(content, array); // Parse the content
strmid(PlayerCache[playerid][password], array[0]); // Get the password 
PlayerCache[playerid][money] = strval(array[1]); // Get the money
PlayerCache[playerid][admin] = strval(array[2]); // Get the admin boolean

enum enum_IntVarData
{
	Valid,
	Multi,
	Const,
	IntName[32],
	ReturnVal,
	Dimensions[MAX_VAR_DIMENSIONS]
}
*/

stock __LoadStringVariable(const name[])
{
	new 
		loadqueryfile[32], 
		loadquery[64], 
		content[1024],
		address[263][64];

	format(loadqueryfile, sizeof loadqueryfile, "d_str_%s.ini", name);
	format(loadquery, sizeof loadquery, "d_str_%s", name);

	CreateQuery(loadquery, QUERY_TYPE_SAVE, "d_vars_cache", loadqueryfile);

	if(!QueryFileExist(loadquery))
	{
		printf("[DETUtils]: (var error) - Unable to load variable : '%s'; persistent data does not exist.", name);
		DestroyQuery(loadquery);
		return 0;
	}

	FormatQuery(loadquery, "LOAD *");
	SendQuery(loadquery);

	GetLoadedQueryContent(loadquery, content);
	ParseQueryContent(content, address);

	DET_gV_DeclareString(name, false, "_");
	new id = __GetStringVarId(name);

	g_StringCache[id][Valid] = strval(address[0]);
	g_StringCache[id][Const] = strval(address[1]);
	// We skip 2 since it is name.
	strmid(g_StringCache[id][ReturnVal], address[3], 0, strlen(address[3]));

	DestroyQuery(loadquery);

	return 1;
}

#endif