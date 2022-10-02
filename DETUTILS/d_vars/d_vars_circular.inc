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

// CallLocalFunction("OnCircularArrayCreate", "si", name, CIRCULAR_ARRAY_TYPE_);
forward OnCircularArrayCreate(arrayname[], arraytype);
// CallLocalFunction("OnCircularArrayUpdate", "siii", name, CIRCULAR_ARRAY_TYPE_, value, dimension);
forward OnCircularArrayUpdate(arrayname[], arraytype, value, index);
// CallLocalFunction("OnCircularArrayDelete", "si", name, CIRCULAR_ARRAY_TYPE_);
forward OnCircularArrayDelete(arrayname[], arraytype);

// Integers:

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

stock _D_VARS_dica__(const name[])
{
    for(new i; i < MAX_INTEGER_CIRCULAR_ARRAYS; i++)
    {
        if(!strcmp(DET_g_ArrayIntegerCache[i][Name], name, false))
        {
            strmid(DET_g_ArrayIntegerCache[i][Name], " ", 0, 1);
            DET_g_ArrayIntegerCache[i][Valid] = 0;
            for(new x; x < MAX_CIRCULAR_ARRAY_SIZE; x++)
            {
                DET_g_ArrayIntegerCache[i][ReturnValues][x] = INVALID_CIRCULAR_VALUE;
            }
            CallLocalFunction("OnCircularArrayDelete", "si", name, CIRCULAR_ARRAY_TYPE_INTEGER);
            return 1;
        }
    }
    return 0;
}

// RENAME FUNCS:

stock _D_VARS_rica__(const oldname[], const newname[])
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
        if(size < 1)
        {
            __DETUtilsError(DETUTILS_ERROR_5,);
            return 0;
        }
        if(DET_g_ArrayIntegerCache[i][Valid] == 0)
        {
            strmid(DET_g_ArrayIntegerCache[i][Name], name, 0, 32);
            DET_g_ArrayIntegerCache[i][Size] = size;
            CallLocalFunction("OnCircularArrayCreate", "si", name, CIRCULAR_ARRAY_TYPE_INTEGER);
            DET_g_ArrayIntegerCache[i][Valid] = 1;
            for(new x; x < MAX_CIRCULAR_ARRAY_SIZE; x++)
            {
                DET_g_ArrayIntegerCache[i][ReturnValues][x] = INVALID_CIRCULAR_VALUE;
            }
            return 1;
        }   
    }
    return 0;
}

// GET... FUNCS

stock _D_VARS_gicav__(const name[], index)
{
    for(new i; i < MAX_INTEGER_CIRCULAR_ARRAYS; i++)
    {
        if(!strcmp(DET_g_ArrayIntegerCache[i][Name], name, false))
        {
            return DET_g_ArrayIntegerCache[i][ReturnValues][index];
        }
    }
    return INVALID_CIRCULAR_VALUE;
}

// SET THE VALUE.

stock _D_VARS_aicav__(const name[], value)
{
    for(new i; i < MAX_INTEGER_CIRCULAR_ARRAYS; i++)
    {
        if(!strcmp(DET_g_ArrayIntegerCache[i][Name], name, false))
        {
            if(DET_g_ArrayIntegerCache[i][ReturnValues][DET_g_ArrayIntegerCache[i][Size]] == INVALID_CIRCULAR_VALUE)
            {
                for(new x; x < DET_g_ArrayIntegerCache[i][Size] - 1; x++)
                {
                    if(DET_g_ArrayIntegerCache[i][ReturnValues][x] != INVALID_CIRCULAR_VALUE)
                    {
                        DET_g_ArrayIntegerCache[i][ReturnValues][x] = value;
                        return value;
                    } 
                }
            }
            else if(DET_g_ArrayIntegerCache[i][ReturnValues][DET_g_ArrayIntegerCache[i][Size]] != INVALID_CIRCULAR_VALUE)
            {
                new x;
                do
                {
                    DET_g_ArrayIntegerCache[i][ReturnValues][x] = DET_g_ArrayIntegerCache[i][ReturnValues][x+1];
                    x++;
                }
                while(x < DET_g_ArrayIntegerCache[i][Size] - 1);
                DET_g_ArrayIntegerCache[i][ReturnValues][DET_g_ArrayIntegerCache[i][Size]] = value;
                return value;
            }
        }
    }
    return INVALID_CIRCULAR_VALUE;
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