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

// CallLocalFunction("OnStackCreate", "si", name, STACK_TYPE_);
forward OnStackCreate(stackname[], stacktype);
// CallLocalFunction("OnStackUpdate", "siii", name, STACK_TYPE_, value, dimension);
forward OnStackUpdate(stackname[], stacktype, value, index);
// CallLocalFunction("OnStackDelete", "si", name, STACK_TYPE_);
forward OnStackDelete(stackname[], stacktype);

// Integers:

enum enum_IntStackData
{
    Valid,
    Name[32],
    Size,
    ReturnValues[MAX_STACK_SIZE]
}

new DET_g_StackCache[MAX_INTEGER_STACKS][enum_IntStackData];

// DELETE FUNCS

// Delete functions are REALLY important.
// Though, I HIGHLY recommend to delete every variable which is not needed because
// if you don't, you'll eventually run out of space required for variables to create 
// and create functions will fail.

stock _D_VARS_dis__(const name[])
{
    for(new i; i < MAX_INTEGER_STACKS; i++)
    {
        if(!strcmp(DET_g_StackCache[i][Name], name, false))
        {
            strmid(DET_g_StackCache[i][Name], " ", 0, 1);
            DET_g_StackCache[i][Valid] = 0;
            for(new x; x < MAX_STACK_SIZE; x++)
            {
                DET_g_StackCache[i][ReturnValues][x] = INVALID_STACK_VALUE;
            }
            CallLocalFunction("OnStackDelete", "si", name, STACK_TYPE_INTEGER);
            return 1;
        }
    }
    return 0;
}

// RENAME FUNCS:

stock _D_VARS_ris__(const oldname[], const newname[])
{
    for(new i; i < MAX_INTEGER_STACKS; i++)
    {
        if(!strcmp(DET_g_StackCache[i][Name], oldname, false))
        {
            strmid(DET_g_StackCache[i][Name], newname, 0, 32);
            return 1;
        }
    }
    return 0;
}

// DECLARATION FUNCS

varfunc DeclareIntegerStack(const name[], size)
{
    for(new i; i < MAX_INTEGER_STACKS; i++)
    {
        if(size < 1)
        {
            __DETUtilsError(DETUTILS_ERROR_5,);
            return 0;
        }
        if(DET_g_StackCache[i][Valid] == 0)
        {
            strmid(DET_g_StackCache[i][Name], name, 0, 32);
            DET_g_StackCache[i][Size] = size;
            CallLocalFunction("OnStackCreate", "si", name, STACK_TYPE_INTEGER);
            DET_g_StackCache[i][Valid] = 1;
            for(new x; x < MAX_STACK_SIZE; x++)
            {
                DET_g_StackCache[i][ReturnValues][x] = INVALID_STACK_VALUE;
            }
            return 1;
        }   
    }
    return 0;
}

// GET... FUNCS

stock _D_VARS_gisv__(const name[], index)
{
    for(new i; i < MAX_INTEGER_STACKS; i++)
    {
        if(!strcmp(DET_g_StackCache[i][Name], name, false))
        {
            return DET_g_StackCache[i][ReturnValues][index];
        }
    }
    return INVALID_STACK_VALUE;
}

// PUSH THE VALUE.

stock _D_VARS_pisv__(const name[], value)
{
    for(new i; i < MAX_INTEGER_STACKS; i++)
    {
        if(!strcmp(DET_g_StackCache[i][Name], name, false))
        {
            for(new x; x < DET_g_StackCache[i][Size]; x++)
            {
                __DETUtilsDebug("`__PopIntegerStackValue` called; x: %i", x);
                if(DET_g_StackCache[i][ReturnValues][x] != INVALID_STACK_VALUE)
                {
                    CallLocalFunction("OnStackUpdate", "siii", name, STACK_TYPE_INTEGER, value, x);
                    DET_g_StackCache[i][ReturnValues][x] = value;
                    return value;
                } 
            }
        }
    }
    return INVALID_STACK_VALUE;
}

// POP THE VALUE:

stock _D_VARS_pisv__2(const name[], dest)
{
    for(new i; i < MAX_INTEGER_STACKS; i++)
    {
        if(!strcmp(DET_g_StackCache[i][Name], name, false))
        {
            for(new x = DET_g_StackCache[i][Size] - 1; x > -1; x--)
            {
                __DETUtilsDebug("`__PopIntegerStackValue` called; x: %i", x);
                if(DET_g_StackCache[i][ReturnValues][x] != INVALID_STACK_VALUE)
                {
                    CallLocalFunction("OnStackUpdate", "siii", name, STACK_TYPE_INTEGER, INVALID_STACK_VALUE, x);
                    dest = DET_g_StackCache[i][ReturnValues][x];
                    DET_g_StackCache[i][ReturnValues][x] = INVALID_STACK_VALUE;
                    return dest;
                } 
            }
        }
    }
    return 0;
}

stock __GetIntegerStackId(const name[])
{
    for(new i = 1; 
        i < MAX_INTEGER_STACKS; 
        i++)
    {
        if(!strcmp(DET_g_StackCache[i][Name], name))
        {
            return i;
        }
    }
    return 0;
}