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

#define __DETUTILS_DEBUG_STRSIZE 1024

new
    __DETUtilsDebug_[__DETUTILS_DEBUG_STRSIZE],
    __DETUtilsError_[__DETUTILS_DEBUG_STRSIZE],
    __DETUtilsWarning_[__DETUTILS_DEBUG_STRSIZE],
    __DETUtilsInfo_[__DETUTILS_DEBUG_STRSIZE];

#if defined DETUTILS_DEBUG_MODE

    #if defined __DETUtilsDebug
        #undef __DETUtilsDebug
    #endif

    #define __DETUtilsDebug%0(%1,%2) \
    format(__DETUtilsDebug_,__DETUTILS_DEBUG_STRSIZE,"[DETUtils]: (debug @ %s:%i) - "%1,__file,__line,%2)&& \
    print(__DETUtilsDebug_)&&SaveDETUtilsLog(__DETUtilsDebug_)

#elseif !defined DETUTILS_DEBUG_MODE

    #define __DETUtilsDebug%0(%1)%2;

#endif

#if defined __DETUtilsWarning
    #undef __DETUtilsWarning
#endif

#define __DETUtilsWarning%0(%1,%2) \
    format(__DETUtilsWarning_,__DETUTILS_DEBUG_STRSIZE,"*** [DETUtils]: (warning @ %s:%i) - "%1,__file,__line,%2)&& \
    print(__DETUtilsWarning_)&&SaveDETUtilsLog(__DETUtilsWarning_)


#if defined __DETUtilsError
    #undef __DETUtilsError
#endif

#define __DETUtilsError%0(%1,%2) \
    format(__DETUtilsError_,__DETUTILS_DEBUG_STRSIZE,"*!* [DETUtils]: (error @ %s:%i) - "%1,__file,__line,%2)&& \
    print(__DETUtilsError_)&&SaveDETUtilsLog(__DETUtilsError_)

#if defined __DETUtilsInfo
    #undef __DETUtilsInfo
#endif

#define __DETUtilsInfo%0(%1,%2) \
    format(__DETUtilsInfo_,__DETUTILS_DEBUG_STRSIZE,"* [DETUtils]: (info @ %s:%i) - "%1,__file,__line,%2)&& \
    print(__DETUtilsInfo_)&&SaveDETUtilsLog(__DETUtilsInfo_)