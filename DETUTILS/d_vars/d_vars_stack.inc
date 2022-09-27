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

// CallLocalFunction("OnStackCreate", "si", name, STACK_TYPE_);
forward OnStackCreate(stackname[], stacktype);
// CallLocalFunction("OnStackUpdate", "siii", name, STACK_TYPE_, value, dimension);
forward OnStackUpdate(stackname[], stacktype, value, index);
// CallLocalFunction("OnStackDelete", "si", name, STACK_TYPE_);
forward OnStackDelete(stackname[], stacktype);

#define STACK_TYPE_INTEGER 0
#define STACK_TYPE_BOOLEAN 1
#define STACK_TYPE_STRING 2
#define STACK_TYPE_FLOAT 3
#define MAX_STACK_SIZE 1000

// Integers:

#define MAX_INTEGER_STACKS 1000

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

stock __DeleteIntegerStack(const name[])
{
    for(new i; i < MAX_INTEGER_STACKS; i++)
    {
        if(!strcmp(DET_g_StackCache[i][Name], name, false))
        {
            strmid(DET_g_StackCache[i][Name], " ", 0, 1);
            DET_g_StackCache[i][Valid] = 0;
            for(new x; x < MAX_STACK_SIZE; x++)
            {
                DET_g_StackCache[i][ReturnValues][x] = -1;
            }
            CallLocalFunction("OnStackDelete", "si", name, STACK_TYPE_INTEGER);
            return 1;
        }
    }
    return 0;
}

// RENAME FUNCS:

stock __RenameIntegerStack(const oldname[], const newname[])
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
        if(DET_g_StackCache[i][Valid] == 0)
        {
            strmid(DET_g_StackCache[i][Name], name, 0, 32);
            DET_g_StackCache[i][Size] = size;
            CallLocalFunction("OnStackCreate", "si", name, STACK_TYPE_INTEGER);
            DET_g_StackCache[i][Valid] = 1;
            for(new x; x < MAX_STACK_SIZE; x++)
            {
                DET_g_StackCache[i][ReturnValues][x] = -1;
            }
            return 1;
        }   
    }
    return 0;
}

// GET... FUNCS

stock __GetIntegerStackValue(const name[], index)
{
    for(new i; i < MAX_INTEGER_STACKS; i++)
    {
        if(!strcmp(DET_g_StackCache[i][Name], name, false))
        {
            return DET_g_StackCache[i][ReturnValues][index];
        }
    }
    return -1;
}

// PUSH THE VALUE.

stock __PushIntegerStackValue(const name[], value)
{
    for(new i; i < MAX_INTEGER_STACKS; i++)
    {
        if(!strcmp(DET_g_StackCache[i][Name], name, false))
        {
            for(new x; x < DET_g_StackCache[i][Size]; x++)
            {
                if(DET_g_StackCache[i][ReturnValues][x] != -1)
                {
                    CallLocalFunction("OnStackUpdate", "siii", name, STACK_TYPE_INTEGER, value, x);
                    DET_g_StackCache[i][ReturnValues][x] = value;
                    return value;
                } 
            }
        }
    }
    return -1;
}

// POP THE VALUE:

stock __PopIntegerStackValue(const name[], dest)
{
    for(new i; i < MAX_INTEGER_STACKS; i++)
    {
        if(!strcmp(DET_g_StackCache[i][Name], name, false))
        {
            for(new x = DET_g_StackCache[i][Size]; x > -1; x--)
            {
                if(DET_g_StackCache[i][ReturnValues][x] != -1)
                {
                    CallLocalFunction("OnStackUpdate", "siii", name, STACK_TYPE_INTEGER, -1, x);
                    dest = DET_g_StackCache[i][ReturnValues][x];
                    DET_g_StackCache[i][ReturnValues][x] = -1;
                    return 1;
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