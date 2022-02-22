/*
 * 
 * SA:MP DEntisT's Utilities
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Extra feature for d_vars.inc
 *
 *
 */

#endinput

// If you don't use YSI (I actually wrote these!):

#if defined DETUTILS_STRRET_COMPLICATED

#define YSI_STRRET_KEYWORD@%0\32; YSI_STRRET_KEYWORD@
#define __COMPILER_STRING YSI_STRRET_KEYWORD@
#define strret_%0\32; strret_
#define str_%0\32; str_
#define funcid_%0\32; funcid_

#if !defined strmid
    native strmid(dest[], const source[], start, end, maxlength=sizeof dest);
#endif

new YSI_g_StrretCache[YSI_MAX_STRING];

#define YSI_STRRET_KEYWORD@forward%0(%1) strret_%0(%1);str_%0(%1,YSI_g_StaticStrRet)
#define YSI_DO_FUNCID<%0..%1> {funcid_%0=funcidx(#strret_%0);return str_%0(%1,funcid_%0);}str_%0(%1,YSI_g_StaticStrRet)
#define YSI_STRRET_KEYWORD@public%0(%1) new funcid_%0;strret_%0(%1)YSI_DO_FUNCID<%0..%1>

#define YSI_STRRET_KEYWORD@return%0; return strmid(YSI_g_StrretCache,%0,0,YSI_MAX_STRING);
#define YSI_STRRET_KEYWORD@CallLocalFunction(%0,%1,%2)%3; CallLocalFunction(#strret_%0,%1,%2);

#else

// This is much easier to understand (but really bad):

#define YSI_STRRET_KEYWORD@%0\32; YSI_STRRET_KEYWORD@
#define __COMPILER_STRING YSI_STRRET_KEYWORD@

new YSI_g_StrretCache[YSI_MAX_STRING];

#define YSI_STRRET_KEYWORD@return%0; return strmid(YSI_g_StrretCache,%0,0,YSI_MAX_STRING);
#define YSI_STRRET_KEYWORD@get_last_return%0(%1) YSI_g_StrretCache

#endif