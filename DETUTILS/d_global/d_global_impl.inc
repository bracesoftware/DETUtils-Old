/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - A library providing an execution
 *   of code outside functions.
 *
 *
 */

#if defined detutils_complete_error_boom

    #define @DETUTILSGLOBAL_KWORD__@%0\32; @DETUTILSGLOBAL_KWORD__@
    #define global @DETUTILSGLOBAL_KWORD__@

#endif

#define @glb%0\32; @glb
#define @glbc_%0\32; @glbc_

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

stock LoadDETUtilsGlobalCode()
{
    new amx_assembly = 0;
    #if defined AMX_HEADER_INC

        //#emit JUMP amx_assembly
        amx_assembly = 1;

    #endif
    new globalfunc[32];
    if(amx_assembly == 0) 
    {
        for(new i; i < 1000; i++)
        {
            format(globalfunc, sizeof globalfunc, "@%i@glb", i);
            if(funcidx(globalfunc) != -1)
            {
                CallLocalFunction(globalfunc, "");
            }
        }
    }
    if(amx_assembly == 1)
    {
        for(new i; i < 10000; i++)
        {
            // Get public name from the code header.
            GetPublicNameFromIndex(i, globalfunc);
            if(globalfunc[0] == '@' &&
                globalfunc[1] == 'g' &&
                globalfunc[2] == 'l' &&
                globalfunc[3] == 'b' &&
                globalfunc[4] == 'c' &&
                globalfunc[5] == '_') // Check if the function is global code.
            {
                // Call the code.
                CallLocalFunction(globalfunc, "");
            }
        }
    }
    return 1;
}

#if !defined AMX_HEADER_INC

#define global%0; \
    @DETUTILSGLOBAL_FUNC__$glb..$; @DETUTILSGLOBAL_FUNC__$glb..$ @DETUTILSGLOBAL_RET__FUNC:%0;

#elseif defined AMX_HEADER_INC

#define global%0()%1; \
    @DETUTILSGLOBAL_AMXFUNC__:%0; @DETUTILSGLOBAL_RET__FUNC:%1;

stock CallGlobalProcedure(const procedure[])
{
    new globalfunc[32];
    format(globalfunc, sizeof globalfunc, "@glbc_%s", procedure);

    if(funcidx(globalfunc) != -1)
    {
        CallLocalFunction(globalfunc, "");
        return 1;
    }
    return 0;
}

#endif 