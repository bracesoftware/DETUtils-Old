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

// Integers:

enum enum_IntVarData
{
    Valid,
    Multi,
    Const,
    IntName[32],
    ReturnVal,
    Dimensions[MAX_VAR_RETURN_SLOTS]
}

new DET_g_IntegerCache[MAX_INTEGER_VARS][enum_IntVarData];

// Booleans:

enum enum_BoolVarData
{
    Valid,
    Multi,
    Const,
    BoolName[32],
    bool:ReturnVal,
    Dimensions[MAX_VAR_RETURN_SLOTS]
}

new DET_g_BoolCache[MAX_BOOLEAN_VARS][enum_BoolVarData];

// Strings:

enum enum_StringData
{
    Valid,
    Const,
    StringName[32],
    ReturnVal[MAX_STRING_CELLS]
}

new DET_g_StringCache[MAX_STRING_VARS][enum_StringData];

// Floats:

enum enum_FloatData
{
    Valid,
    Multi,
    Const,
    FloatName[32],
    Float:ReturnVal,
    Float:Dimensions[MAX_VAR_RETURN_SLOTS]
}

new DET_g_FloatCache[MAX_FLOAT_VARS][enum_FloatData];

// DELETE FUNCS

// Delete functions are REALLY important.
// Though, I HIGHLY recommend to DETUTILS_delete  every variable which is not needed because
// if you don't, you'll eventually run out of space required for variables to create 
// and create functions will fail.

stock _D_VARS_div__(const name[])
{
    for(new i; i < MAX_INTEGER_VARS; i++)
    {
        if(!strcmp(DET_g_IntegerCache[i][IntName], name, false))
        {
            strmid(DET_g_IntegerCache[i][IntName], " ", 0, 1);
            DET_g_IntegerCache[i][Valid] = 0;
            for(new x; x < MAX_VAR_RETURN_SLOTS; x++)
            {
                DET_g_IntegerCache[i][Dimensions][x] = 0;
            }
            DET_g_IntegerCache[i][ReturnVal] = 0;
            CallLocalFunction("OnVariableDelete", "si", name, VARIABLE_TYPE_INTEGER);
            return 1;
        }
    }
    return 0;
}

stock _D_VARS_dbv__(const name[])
{
    for(new i; i < MAX_BOOLEAN_VARS; i++)
    {
        if(!strcmp(DET_g_BoolCache[i][BoolName], name, false))
        {
            strmid(DET_g_BoolCache[i][BoolName], " ", 0, 1);
            DET_g_BoolCache[i][Valid] = 0;
            for(new x; x < MAX_VAR_RETURN_SLOTS; x++)
            {
                DET_g_BoolCache[i][Dimensions][x] = false;
            }
            DET_g_BoolCache[i][ReturnVal] = false;
            CallLocalFunction("OnVariableDelete", "si", name, VARIABLE_TYPE_BOOLEAN);
            return 1;
        }
    }
    return 0;
}

stock _D_VARS_dfv__(const name[])
{
    for(new i; i < MAX_FLOAT_VARS; i++)
    {
        if(!strcmp(DET_g_FloatCache[i][FloatName], name, false))
        {
            strmid(DET_g_FloatCache[i][FloatName], " ", 0, 1);
            DET_g_FloatCache[i][Valid] = 0;
            for(new x; x < MAX_VAR_RETURN_SLOTS; x++)
            {
                DET_g_FloatCache[i][Dimensions][x] = Float:0;
            }
            DET_g_FloatCache[i][ReturnVal] = Float:0;
            CallLocalFunction("OnVariableDelete", "si", name, VARIABLE_TYPE_FLOAT);
            return 1;
        }
    }
    return 0;
}

stock _D_VARS_dsv__(const name[])
{
    for(new i; i < MAX_STRING_VARS; i++)
    {
        if(!strcmp(DET_g_StringCache[i][StringName], name, false))
        {
            strmid(DET_g_StringCache[i][ReturnVal], " ", 0, 1);
            strmid(DET_g_StringCache[i][StringName], " ", 0, 1);
            DET_g_StringCache[i][Valid] = 0;
            CallLocalFunction("OnVariableDelete", "si", name, VARIABLE_TYPE_STRING);
            return 1;
        }
    }
    return 0;
}

// RENAME FUNCS:

stock _D_VARS_riv__(const oldname[], const newname[])
{
    for(new i; i < MAX_INTEGER_VARS; i++)
    {
        if(!strcmp(DET_g_IntegerCache[i][IntName], oldname, false))
        {
            strmid(DET_g_IntegerCache[i][IntName], newname, 0, 32);
            return 1;
        }
    }
    return 0;
}

stock _D_VARS_rbv__(const oldname[], const newname[])
{
    for(new i; i < MAX_BOOLEAN_VARS; i++)
    {
        if(!strcmp(DET_g_BoolCache[i][BoolName], oldname, false))
        {
            strmid(DET_g_BoolCache[i][BoolName], newname, 0, 32);
            return 1;
        }
    }
    return 0;
}

stock _D_VARS_rfv__(const oldname[], const newname[])
{
    for(new i; i < MAX_FLOAT_VARS; i++)
    {
        if(!strcmp(DET_g_FloatCache[i][FloatName], oldname, false))
        {
            strmid(DET_g_FloatCache[i][FloatName], newname, 0, 32);
            return 1;
        }
    }
    return 0;
}

stock _D_VARS_rsv__(const oldname[], const newname[])
{
    for(new i; i < MAX_STRING_VARS; i++)
    {
        if(!strcmp(DET_g_StringCache[i][StringName], oldname, false))
        {
            strmid(DET_g_StringCache[i][StringName], newname, 0, 32);
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
        if(DET_g_IntegerCache[i][Valid] == 0)
        {
            strmid(DET_g_IntegerCache[i][IntName], name, 0, 32);
            DET_g_IntegerCache[i][Multi] = multi;
            if(constant == 1 && multi == 1)
            {
                printf("[DETUtils]: (var error) - You can't create constant variables with more dimensions.");
                return 0;
            }
            if(multi == 1)
            {
                for(new x; x < MAX_VAR_RETURN_SLOTS; x++)
                {
                    DET_g_IntegerCache[i][Dimensions][x] = 0; // Initialize the "dimension" sizes.
                }
            }
            else if(multi == 0)
            {
                DET_g_IntegerCache[i][ReturnVal] = 0; // Initialize the single return size.
            }
            if(constant == 1)
            {
                DET_g_IntegerCache[i][Const] = 1;
                DET_g_IntegerCache[i][ReturnVal] = constvalue;
            }
            CallLocalFunction("OnVariableCreate", "si", name, VARIABLE_TYPE_INTEGER);
            DET_g_IntegerCache[i][Valid] = 1;
            return 1;
        }   
    }
    return 0;
}

varfunc DeclareBoolean(const name[], multi, constant, bool:constvalue = false)
{
    for(new i; i < MAX_BOOLEAN_VARS; i++)
    {
        if(DET_g_BoolCache[i][Valid] == 0)
        {
            strmid(DET_g_BoolCache[i][BoolName], name, 0, 32);
            DET_g_BoolCache[i][Multi] = multi;
            if(constant == 1 && multi == 1)
            {
                printf("[DETUtils]: (var error) - You can't create constant variables with more dimensions.");
                return 0;
            }
            if(multi == 1)
            {
                for(new x; x < MAX_VAR_RETURN_SLOTS; x++)
                {
                    DET_g_BoolCache[i][Dimensions][x] = 0; // Initialize the "dimension" sizes.
                }
            }
            else if(multi == 0)
            {
                DET_g_BoolCache[i][ReturnVal] = false; // Initialize the single return size.
            }
            if(constant == 1)
            {
                if(constvalue != false && constvalue != true)
                {
                    printf("[DETUtils]: (var error) - Booleans can only have 0 and 1 as values.");
                    return 0;
                }
                DET_g_BoolCache[i][Const] = 1;
                DET_g_BoolCache[i][ReturnVal] = constvalue;
            }
            CallLocalFunction("OnVariableCreate", "si", name, VARIABLE_TYPE_BOOLEAN);
            DET_g_BoolCache[i][Valid] = 1;
            return 1;
        }   
    }
    return 0;
}

varfunc DeclareFloat(const name[], multi, constant, Float:constvalue = 0.0000)
{
    for(new i; i < MAX_FLOAT_VARS; i++)
    {
        if(DET_g_FloatCache[i][Valid] == 0)
        {
            strmid(DET_g_FloatCache[i][FloatName], name, 0, 32);
            DET_g_FloatCache[i][Multi] = multi;
            if(constant == 1 && multi == 1)
            {
                printf("[DETUtils]: (var error) - You can't create constant variables with more dimensions.");
                return 0;
            }
            if(multi == 1)
            {
                for(new x; x < MAX_VAR_RETURN_SLOTS; x++)
                {
                    DET_g_FloatCache[i][Dimensions][x] = 0; // Initialize the "dimension" sizes.
                }
            }
            else if(multi == 0)
            {
                DET_g_FloatCache[i][ReturnVal] = 0; // Initialize the single return size.
            }
            if(constant == 1)
            {
                DET_g_FloatCache[i][Const] = 1;
                DET_g_FloatCache[i][ReturnVal] = constvalue;
            }
            CallLocalFunction("OnVariableCreate", "si", name, VARIABLE_TYPE_FLOAT);
            DET_g_FloatCache[i][Valid] = 1;
            return 1;
        }   
    }
    return 0;
}

varfunc DeclareString(const name[], constant, const constvalue[])
{
    for(new i; i < MAX_STRING_VARS; i++)
    {
        if(DET_g_StringCache[i][Valid] == 0)
        {
            new len = strlen(constvalue);
            strmid(DET_g_StringCache[i][StringName], name, 0, 32);
            if(constant == 1)
            {
                strmid(DET_g_StringCache[i][ReturnVal], constvalue, 0, len);
                DET_g_StringCache[i][Const] = 1;
            }
            else if(constant == 0)
            {
                strmid(DET_g_StringCache[i][ReturnVal], constvalue, 0, len);
            }
            CallLocalFunction("OnVariableCreate", "si", name, VARIABLE_TYPE_STRING);
            DET_g_StringCache[i][Valid] = 1;
            return 1;
        }   
    }
    return 0;
}

// GET... FUNCS

stock _D_VARS_giv__(const name[], dimension = 0)
{
    for(new i; i < MAX_INTEGER_VARS; i++)
    {
        if(!strcmp(DET_g_IntegerCache[i][IntName], name, false))
        {
            if(DET_g_IntegerCache[i][Multi] == 1)
            {
                if(dimension == -1)
                {
                    __DETUtilsError(DETUTILS_ERROR_4,);
                    return 0;
                }
                return DET_g_IntegerCache[i][Dimensions][dimension];
            }
            else if(DET_g_IntegerCache[i][Multi] == 0)
            {
                return DET_g_IntegerCache[i][ReturnVal];
            }
        }
    }
    return 0;
}

stock _D_VARS_gbv__(const name[], dimension = 0)
{
    for(new i; i < MAX_BOOLEAN_VARS; i++)
    {
        if(!strcmp(DET_g_BoolCache[i][BoolName], name, false))
        {
            if(DET_g_BoolCache[i][Multi] == 1)
            {
                if(dimension == -1)
                {
                    __DETUtilsError(DETUTILS_ERROR_4,);
                    return 0;
                }
                return DET_g_BoolCache[i][Dimensions][dimension];
            }
            else if(DET_g_BoolCache[i][Multi] == 0)
            {
                return DET_g_BoolCache[i][ReturnVal];
            }
        }
    }
    return 0;
}

stock Float:_D_VARS_gfv__(const name[], dimension = 0)
{
    for(new i; i < MAX_FLOAT_VARS; i++)
    {
        if(!strcmp(DET_g_FloatCache[i][FloatName], name, false))
        {
            if(DET_g_FloatCache[i][Multi] == 1)
            {
                if(dimension == -1)
                {
                    __DETUtilsError(DETUTILS_ERROR_4,);
                    return Float:0;
                }
                return DET_g_FloatCache[i][Dimensions][dimension];
            }
            else if(DET_g_FloatCache[i][Multi] == 0)
            {
                return DET_g_FloatCache[i][ReturnVal];
            }
        }
    }
    return Float:0;
}

stock _D_VARS_gsv__(const name[])
{
    new ret[1024];
    format(ret, 4, "NULL");
            
    for(new i; i < MAX_STRING_VARS; i++)
    {
        if(!strcmp(DET_g_StringCache[i][StringName], name, false))
        {
            format(ret, 1024, "%s", DET_g_StringCache[i][ReturnVal]);
            return ret;
        }
    }
    return ret;
}

// SET THE VALUE.

stock _D_VARS_siv__(const name[], value, dimension = 0)
{
    for(new i; i < MAX_INTEGER_VARS; i++)
    {
        if(!strcmp(DET_g_IntegerCache[i][IntName], name, false))
        {
            if(DET_g_IntegerCache[i][Const] == 1)
            {
                printf("[DETUtils]: (var error) - Cannot update the constant value of : %s", name);
                return 0;
            }
            if(DET_g_IntegerCache[i][Multi] == 1)
            {
                if(dimension == -1)
                {
                    __DETUtilsError(DETUTILS_ERROR_4,);
                    return 0;
                }
                CallLocalFunction("OnVariableUpdate", "siii", name, VARIABLE_TYPE_INTEGER, value, dimension);
                DET_g_IntegerCache[i][Dimensions][dimension] = value;
                return 1;
            }
            else if(DET_g_IntegerCache[i][Multi] == 0)
            {
                CallLocalFunction("OnVariableUpdate", "siii", name, VARIABLE_TYPE_INTEGER, value, dimension);
                DET_g_IntegerCache[i][ReturnVal] = value;
                return 1;
            }
        }
    }
    return 0;
}

stock _D_VARS_sbv__(const name[], bool:value, dimension = 0)
{
    for(new i; i < MAX_BOOLEAN_VARS; i++)
    {
        if(!strcmp(DET_g_BoolCache[i][BoolName], name, false))
        {
            if(DET_g_BoolCache[i][Const] == 1)
            {
                printf("[DETUtils]: (var error) - Cannot update the constant value of : %s", name);
                return 0;
            }
            if(value != false && value != true)
            {
                printf("[DETUtils]: (var error) - Boolean variables can only hold the values of 0 and 1.");
                return 0;
            }
            if(DET_g_BoolCache[i][Multi] == 1)
            {
                if(dimension == -1)
                {
                    __DETUtilsError(DETUTILS_ERROR_4,);
                    return 0;
                }
                CallLocalFunction("OnVariableUpdate", "siii", name, VARIABLE_TYPE_BOOLEAN, value, dimension);
                DET_g_BoolCache[i][Dimensions][dimension] = value;
                return true;
            }
            else if(DET_g_BoolCache[i][Multi] == 0)
            {
                CallLocalFunction("OnVariableUpdate", "siii", name, VARIABLE_TYPE_BOOLEAN, value, dimension);
                DET_g_BoolCache[i][ReturnVal] = value;
                return true;
            }
        }
    }
    return 0;
}

stock _D_VARS_sfv__(const name[], Float:value, dimension = 0)
{
    for(new i; i < MAX_FLOAT_VARS; i++)
    {
        if(!strcmp(DET_g_FloatCache[i][FloatName], name, false))
        {
            if(DET_g_FloatCache[i][Const] == 1)
            {
                printf("[DETUtils]: (var error) - Cannot update the constant value of : %s", name);
                return 0;
            }
            if(DET_g_FloatCache[i][Multi] == 1)
            {
                if(dimension == -1)
                {
                    __DETUtilsError(DETUTILS_ERROR_4,);
                    return 0;
                }
                CallLocalFunction("OnVariableUpdate", "siii", name, VARIABLE_TYPE_FLOAT, value, dimension);
                DET_g_FloatCache[i][Dimensions][dimension] = value;
                return 1;
            }
            else if(DET_g_FloatCache[i][Multi] == 0)
            {
                CallLocalFunction("OnVariableUpdate", "siii", name, VARIABLE_TYPE_FLOAT, value, dimension);
                DET_g_FloatCache[i][ReturnVal] = value;
                return 1;
            }
        }
    }
    return 0;
}

stock _D_VARS_ssv__(const name[], const value[])
{           
    for(new i; i < MAX_STRING_VARS; i++)
    {
        if(!strcmp(DET_g_StringCache[i][StringName], name, false))
        {
            if(DET_g_StringCache[i][Const] == 1)
            {
                printf("[DETUtils]: (var error) - Cannot update the constant value of : %s", name);
                return 0;
            }
            new len = strlen(value);
            strmid(DET_g_StringCache[i][ReturnVal], value, 0, len);
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
                if(DET_g_IntegerCache[i][Valid] == 0)
                {
                    strmid(DET_g_IntegerCache[i][IntName], name, 0, 32);
                    DET_g_IntegerCache[i][Multi] = multi;
                    if(constant == 1 && multi == 1)
                    {
                        printf("[DETUtils]: (var error) - You can't create constant variables with more dimensions.");
                        return 0;
                    }
                    if(multi == 1)
                    {
                        for(new x; x < MAX_VAR_RETURN_SLOTS; x++)
                        {
                            DET_g_IntegerCache[i][Dimensions][x] = 0;// Initialize the "dimension" sizes.
                        }
                    }
                    else if(multi == 0)
                    {
                        DET_g_IntegerCache[i][ReturnVal] = 0; // Initialize the single return size.
                    }
                    if(constant == 1)
                    {
                        DET_g_IntegerCache[i][Const] = 1;
                        DET_g_IntegerCache[i][ReturnVal] = constvalue;
                    }
                    DET_g_IntegerCache[i][Valid] = 1;
                    return 1;
                }   
            }
        }
        case VARIABLE_TYPE_BOOLEAN:
        {
            // Booleans.
            for(new i; i < MAX_BOOLEAN_VARS; i++)
            {
                if(DET_g_BoolCache[i][Valid] == 0)
                {
                    strmid(DET_g_BoolCache[i][BoolName], name, 0, 32);
                    DET_g_BoolCache[i][Multi] = multi;
                    if(constant == 1 && multi == 1)
                    {
                        printf("[DETUtils]: (var error) - You can't create constant variables with more dimensions.");
                        return 0;
                    }
                    if(multi == 1)
                    {
                        for(new x; x < MAX_VAR_RETURN_SLOTS; x++)
                        {
                            DET_g_BoolCache[i][Dimensions][x] = 0;// Initialize the "dimension" sizes.
                        }
                    }
                    else if(multi == 0)
                    {
                        DET_g_BoolCache[i][ReturnVal] = 0; // Initialize the single return size.
                    }
                    if(constant == 1)
                    {
                        if(constvalue != 0 && constvalue != 1)
                        {
                            printf("[DETUtils]: (var error) - Booleans can only have 0 and 1 as values.");
                            return 0;
                        }
                        DET_g_BoolCache[i][Const] = 1;
                        DET_g_BoolCache[i][ReturnVal] = constvalue;
                    }
                    DET_g_BoolCache[i][Valid] = 1;
                    return 1;
                }   
            }
        }
        case VARIABLE_TYPE_STRING:
        {
            // Strings.
            for(new i; i < MAX_STRING_VARS; i++)
            {
                if(DET_g_StringCache[i][Valid] == 0)
                {
                    strmid(DET_g_IntegerCache[i][FloatName], name, 0, 32);
                    DET_g_StringCache[i][Multi] = multi;
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
                        DET_g_StringCache[i][ReturnVal] = 0; // Initialize the single return size.
                    }
                    DET_g_StringCache[i][Valid] = 1;
                    return 1;
                }   
            }

        }
        case VARIABLE_TYPE_FLOAT:
        {
            // Floats / real numbers.
            for(new i; i < MAX_FLOAT_VARS; i++)
            {
                if(DET_g_FloatCache[i][Valid] == 0)
                {
                    strmid(DET_g_FloatCache[i][FloatName], name, 0, 32);
                    DET_g_FloatCache[i][Multi] = multi;
                    if(constant == 1 && multi == 1)
                    {
                        printf("[DETUtils]: (var error) - You can't create constant variables with more dimensions.");
                        return 0;
                    }
                    if(multi == 1)
                    {
                        for(new x; x < MAX_VAR_RETURN_SLOTS; x++)
                        {
                            DET_g_FloatCache[i][Dimensions][x] = 0;// Initialize the "dimension" sizes.
                        }
                    }
                    else if(multi == 0)
                    {
                        DET_g_FloatCache[i][ReturnVal] = 0; // Initialize the single return size.
                    }
                    if(constant == 1)
                    {
                        DET_g_FloatCache[i][Const] = 1;
                        DET_g_FloatCache[i][ReturnVal] = constvalue;
                    }
                    DET_g_FloatCache[i][Valid] = 1;
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
        if(!strcmp(DET_g_IntegerCache[i][IntName], name))
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
        if(!strcmp(DET_g_BoolCache[i][BoolName], name))
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
        if(!strcmp(DET_g_FloatCache[i][FloatName], name))
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
        if(!strcmp(DET_g_StringCache[i][StringName], name))
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

/*
public OnDETUtilsInit()
{
    // Set the default return value.
    #emit ZERO.pri
    #if defined d_vs_detutilsinit
        d_vs_detutilsinit();
    #endif
    #if defined DETUTILS_DEBUG_MODE
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
    Dimensions[MAX_VAR_RETURN_SLOTS]
}
*/

stock __SaveIntegerVariable(const name[])
{
    for(new i; i < MAX_INTEGER_VARS; i++)
    {
        if(!strcmp(DET_g_IntegerCache[i][IntName], name, false))
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
                DET_g_IntegerCache[i][Valid],
                DET_g_IntegerCache[i][Multi],
                DET_g_IntegerCache[i][Const],
                DET_g_IntegerCache[i][IntName],
                DET_g_IntegerCache[i][ReturnVal]);

            for(new x; x < MAX_VAR_RETURN_SLOTS; x++)
            {
                format(dquery, sizeof dquery, ",%i", DET_g_IntegerCache[i][Dimensions][x]);
                strcat(query, dquery);
            }

            FormatQuery(savequery, query);
            SendQuery(savequery);
            DestroyQuery(savequery);
            
            DETUTILS_delete  Integer(name);

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
    Dimensions[MAX_VAR_RETURN_SLOTS]
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

    DET_g_IntegerCache[id][Valid] = strval(address[0]);
    DET_g_IntegerCache[id][Multi] = strval(address[1]);
    DET_g_IntegerCache[id][Const] = strval(address[2]);
    // We skip 3 since it is name.
    DET_g_IntegerCache[id][ReturnVal] = strval(address[4]);
    for(new i; i < MAX_VAR_RETURN_SLOTS; i++)
    {
        DET_g_IntegerCache[id][Dimensions][i] = strval(address[i+5]);
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
    Dimensions[MAX_VAR_RETURN_SLOTS]
}
*/

stock __SaveBooleanVariable(const name[])
{
    for(new i; i < MAX_BOOLEAN_VARS; i++)
    {
        if(!strcmp(DET_g_BoolCache[i][BoolName], name, false))
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
                DET_g_BoolCache[i][Valid],
                DET_g_BoolCache[i][Multi],
                DET_g_BoolCache[i][Const],
                DET_g_BoolCache[i][BoolName],
                DET_g_BoolCache[i][ReturnVal]);

            for(new x; x < MAX_VAR_RETURN_SLOTS; x++)
            {
                format(dquery, sizeof dquery, ",%i", DET_g_BoolCache[i][Dimensions][x]);
                strcat(query, dquery);
            }

            FormatQuery(savequery, query);
            SendQuery(savequery);
            DestroyQuery(savequery);
            
            DETUTILS_delete  Boolean(name);

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
    Dimensions[MAX_VAR_RETURN_SLOTS]
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

    DET_g_BoolCache[id][Valid] = strval(address[0]);
    DET_g_BoolCache[id][Multi] = strval(address[1]);
    DET_g_BoolCache[id][Const] = strval(address[2]);
    // We skip 3 since it is name.
    DET_g_BoolCache[id][ReturnVal] = strval(address[4]);
    for(new i; i < MAX_VAR_RETURN_SLOTS; i++)
    {
        DET_g_BoolCache[id][Dimensions][i] = strval(address[i+5]);
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
    Dimensions[MAX_VAR_RETURN_SLOTS]
}
*/

stock __SaveFloatVariable(const name[])
{
    for(new i; i < MAX_FLOAT_VARS; i++)
    {
        if(!strcmp(DET_g_FloatCache[i][FloatName], name, false))
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
                DET_g_FloatCache[i][Valid],
                DET_g_FloatCache[i][Multi],
                DET_g_FloatCache[i][Const],
                DET_g_FloatCache[i][FloatName],
                DET_g_FloatCache[i][ReturnVal]);

            for(new x; x < MAX_VAR_RETURN_SLOTS; x++)
            {
                format(dquery, sizeof dquery, ",%f", DET_g_FloatCache[i][Dimensions][x]);
                strcat(query, dquery);
            }

            FormatQuery(savequery, query);
            SendQuery(savequery);
            DestroyQuery(savequery);
            
            DETUTILS_delete  Float(name);

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
    Dimensions[MAX_VAR_RETURN_SLOTS]
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

    DET_g_BoolCache[id][Valid] = strval(address[0]);
    DET_g_BoolCache[id][Multi] = strval(address[1]);
    DET_g_BoolCache[id][Const] = strval(address[2]);
    // We skip 3 since it is name.
    DET_g_BoolCache[id][ReturnVal] = floatstr(address[4]);
    for(new i; i < MAX_VAR_RETURN_SLOTS; i++)
    {
        DET_g_BoolCache[id][Dimensions][i] = floatstr(address[i+5]);
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
    Dimensions[MAX_VAR_RETURN_SLOTS]
}
*/

stock __SaveStringVariable(const name[])
{
    for(new i; i < MAX_STRING_VARS; i++)
    {
        if(!strcmp(DET_g_StringCache[i][StringName], name, false))
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
                DET_g_StringCache[i][Valid],
                DET_g_StringCache[i][Const],
                DET_g_StringCache[i][StringName],
                DET_g_StringCache[i][ReturnVal]);

            FormatQuery(savequery, query);
            SendQuery(savequery);
            DestroyQuery(savequery);
            
            DETUTILS_delete  String(name);

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
    Dimensions[MAX_VAR_RETURN_SLOTS]
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

    DET_g_StringCache[id][Valid] = strval(address[0]);
    DET_g_StringCache[id][Const] = strval(address[1]);
    // We skip 2 since it is name.
    strmid(DET_g_StringCache[id][ReturnVal], address[3], 0, strlen(address[3]));

    DestroyQuery(loadquery);

    return 1;
}

#endif