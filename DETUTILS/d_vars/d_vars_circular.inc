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

// CallLocalFunction("OnCircularArrayCreate", "si", name, CIRCULAR_ARRAY_TYPE_);
forward OnCircularArrayCreate(varname[], vartype);
// CallLocalFunction("OnCircularArrayUpdate", "siii", name, CIRCULAR_ARRAY_TYPE_, value, dimension);
forward OnCircularArrayUpdate(varname[], vartype, value, dimension);
// CallLocalFunction("OnCircularArrayDelete", "si", name, CIRCULAR_ARRAY_TYPE_);
forward OnCircularArrayDelete(varname[], vartype);

#define CIRCULAR_ARRAY_TYPE_INTEGER 0
#define CIRCULAR_ARRAY_TYPE_BOOLEAN 1
#define CIRCULAR_ARRAY_TYPE_STRING 2
#define CIRCULAR_ARRAY_TYPE_FLOAT 3
#define MAX_CIRCULAR_ARRAY_SIZE 1000

// Integers:

#define MAX_INTEGER_CIRCULAR_ARRAYS 1000

enum enum_IntCircArrayData
{
    Valid,
    Name[32],
    Size,
    ReturnValues[MAX_CIRCULAR_ARRAY_SIZE]
}

new DET_g_ArrayIntegerCache[MAX_INTEGER_CIRCULAR_ARRAYS][enum_IntCircArrayData];

// DELETE FUNCS

// Delete functions are REALLY important.
// Though, I HIGHLY recommend to delete every variable which is not needed because
// if you don't, you'll eventually run out of space required for variables to create 
// and create functions will fail.

stock __DeleteIntegerCircularArray(const name[])
{
    for(new i; i < MAX_INTEGER_CIRCULAR_ARRAYS; i++)
    {
        if(!strcmp(DET_g_ArrayIntegerCache[i][Name], name, false))
        {
            strmid(DET_g_ArrayIntegerCache[i][Name], " ", 0, 1);
            DET_g_ArrayIntegerCache[i][Valid] = 0;
            for(new x; x < MAX_CIRCULAR_ARRAY_SIZE; x++)
            {
                DET_g_ArrayIntegerCache[i][ReturnValues][x] = -1;
            }
            CallLocalFunction("OnCircularArrayDelete", "si", name, CIRCULAR_ARRAY_TYPE_INTEGER);
            return 1;
        }
    }
    return 0;
}

// RENAME FUNCS:

stock __RenameIntegerCircularArray(const oldname[], const newname[])
{
    for(new i; i < MAX_INTEGER_CIRCULAR_ARRAYS; i++)
    {
        if(!strcmp(DET_g_ArrayIntegerCache[i][Name], oldname, false))
        {
            strmid(DET_g_ArrayIntegerCache[i][Name], newname, 0, 32);
            return 1;
        }
    }
    return 0;
}

// DECLARATION FUNCS

varfunc DeclareIntegerCircArray(const name[], size)
{
    for(new i; i < MAX_INTEGER_CIRCULAR_ARRAYS; i++)
    {
        if(DET_g_ArrayIntegerCache[i][Valid] == 0)
        {
            strmid(DET_g_ArrayIntegerCache[i][Name], name, 0, 32);
            DET_g_ArrayIntegerCache[i][Size] = size;
            CallLocalFunction("OnCircularArrayCreate", "si", name, CIRCULAR_ARRAY_TYPE_INTEGER);
            DET_g_ArrayIntegerCache[i][Valid] = 1;
            for(new x; x < MAX_CIRCULAR_ARRAY_SIZE; x++)
            {
                DET_g_ArrayIntegerCache[i][ReturnValues][x] = -1;
            }
            return 1;
        }   
    }
    return 0;
}

// GET... FUNCS

stock __GetIntegerCircularArrayValue(const name[], index)
{
    for(new i; i < MAX_INTEGER_CIRCULAR_ARRAYS; i++)
    {
        if(!strcmp(DET_g_ArrayIntegerCache[i][Name], name, false))
        {
            return DET_g_ArrayIntegerCache[i][ReturnValues][index];
        }
    }
    return -1;
}

// SET THE VALUE.

stock __AddIntegerCircularArrayValue(const name[], value)
{
    for(new i; i < MAX_INTEGER_CIRCULAR_ARRAYS; i++)
    {
        if(!strcmp(DET_g_ArrayIntegerCache[i][Name], name, false))
        {
            if(DET_g_ArrayIntegerCache[i][ReturnValues][DET_g_ArrayIntegerCache[i][Size]] == -1)
            {
                for(new x; x < DET_g_ArrayIntegerCache[i][Size]; x++)
                {
                    if(DET_g_ArrayIntegerCache[i][ReturnValues][x] != -1)
                    {
                        DET_g_ArrayIntegerCache[i][ReturnValues][x] = value;
                        return value;
                    } 
                }
            }
            else if(DET_g_ArrayIntegerCache[i][ReturnValues][DET_g_ArrayIntegerCache[i][Size]] != -1)
            {
                new x;
                do
                {
                    DET_g_ArrayIntegerCache[i][ReturnValues][x] = DET_g_ArrayIntegerCache[i][ReturnValues][x+1];
                    x++;
                }
                while(x < DET_g_ArrayIntegerCache[i][Size]);
                DET_g_ArrayIntegerCache[i][ReturnValues][DET_g_ArrayIntegerCache[i][Size]] = value;
                return value;
            }
        }
    }
    return -1;
}

stock __GetIntegerCircularArrayId(const name[])
{
    for(new i = 1; 
        i < MAX_INTEGER_CIRCULAR_ARRAYS; 
        i++)
    {
        if(!strcmp(DET_g_ArrayIntegerCache[i][Name], name))
        {
            return i;
        }
    }
    return 0;
}