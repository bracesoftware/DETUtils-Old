/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library core file.
 *   
 *
 *
 */

#define __line,) __line)

#if defined DETUTILS_DEBUG_MODE

    #if defined __DETUtilsDebug
        #undef __DETUtilsDebug
    #endif
    #define __DETUtilsDebug(%1,%2) printf("[DETUtils]: (debug @ %s:%i) - "%1,__file,__line,%2)

#elseif !defined DETUTILS_DEBUG_MODE

    #define __DETUtilsDebug(%1)%2;

#endif

#if defined __DETUtilsWarning
    #undef __DETUtilsWarning
#endif
#define __DETUtilsWarning(%1,%2) printf("*** [DETUtils]: (warning @ %s:%i) - "%1,__file,__line,%2)

#if defined __DETUtilsError
    #undef __DETUtilsError
#endif
#define __DETUtilsError(%1,%2) printf("*!* [DETUtils]: (error @ %s:%i) - "%1,__file,__line,%2)

#if defined __DETUtilsInfo
    #undef __DETUtilsInfo
#endif
#define __DETUtilsInfo(%1,%2) printf("* [DETUtils]: (info @ %s:%i) - "%1,__file,__line,%2)