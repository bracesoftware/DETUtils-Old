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

// Types:

#include "d_vars_macros"

#define VARIABLE_TYPE_INTEGER 0
#define VARIABLE_TYPE_BOOLEAN 1
#define VARIABLE_TYPE_STRING 2
#define VARIABLE_TYPE_FLOAT 3

#define CIRCULAR_ARRAY_TYPE_INTEGER 0
#define CIRCULAR_ARRAY_TYPE_BOOLEAN 1
#define CIRCULAR_ARRAY_TYPE_STRING 2
#define CIRCULAR_ARRAY_TYPE_FLOAT 3

#define STACK_TYPE_INTEGER 0
#define STACK_TYPE_BOOLEAN 1
#define STACK_TYPE_STRING 2
#define STACK_TYPE_FLOAT 3

// Sizes:

#define MAX_VAR_RETURN_SLOTS 256

#define MAX_CIRCULAR_ARRAY_SIZE 128

#define MAX_STACK_SIZE 128

// Limits:

#define MAX_INTEGER_VARS 256
#define MAX_BOOLEAN_VARS 256
#define MAX_FLOAT_VARS 256
#define MAX_STRING_VARS 128

#define MAX_INTEGER_CIRCULAR_ARRAYS 64
#define MAX_BOOLEAN_CIRCULAR_ARRAYS 64
#define MAX_FLOAT_CIRCULAR_ARRAYS 64
#define MAX_STRING_CIRCULAR_ARRAYS 32

#define MAX_INTEGER_STACKS 64
#define MAX_BOOLEAN_STACKS 64
#define MAX_FLOAT_STACKS 64
#define MAX_STRING_STACKS 32

// Variable limits:

#define MAX_STRING_CELLS 256

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

#include "d_vars_standard"
#include "d_vars_circular"
#include "d_vars_stack"

stock CallVariableHandler(const name[])
{
    new funcname[32];
    format(funcname, sizeof funcname, "@DETVAR_%s", name);
    return CallLocalFunction(funcname, "");
}

// malloc("HandlerName");
#if !defined malloc

    stock malloc(const handler[])
    {
        return CallVariableHandler(handler);
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

// cleanup

public OnDETUtilsExit()
{
    UnloadDETUtilsScript(DETUTILS_SCRIPT_VARS);
    if(funcidx("d_vars_detutilsexit") != -1)
    {
        CallLocalFunction("d_vars_detutilsexit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsExit
    #undef OnDETUtilsExit
#else
    #define _ALS_OnDETUtilsExit
#endif

#define OnDETUtilsExit( d_vars_detutilsexit(

forward d_vars_detutilsexit();