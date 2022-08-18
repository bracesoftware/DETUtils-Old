/*
 * 
 * SA:MP DEntisT's Utilities
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Macros for d_profile.
 *
 *
 */

#define @DETUTILSPROFILE_KWORD__@%0\32; @DETUTILSPROFILE_KWORD__@
#define @profile%0(%1. @DETUTILSPROFILE_KWORD__@
#define __d_pfunc%0\32; __d_pfunc
 #define __d_pfunc2%0\32; __d_pfunc2

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

/*
@profile(.format = "ii", )
*/

#define CallProfiler%0(%1,%2) CallLocalFunction("__d_pfunc"%1,%2)

#define @DETUTILSPROFILE_KWORD__@format%2=%3{%4}%5)%0(%1) \
	__d_pfunc%0(%1);public __d_pfunc%0(%1){ \
		format(DET_g_ProfilerName,sizeof DET_g_ProfilerName,#%0); \
		DET_g_ProfilerCount = GetTickCount(); \
		return CallLocalFunction("__d_pfunc2"#%0, %4);} \
	__d_pfunc2%0(%1);public __d_pfunc2%0(%1)

#define @DETUTILSPROFILE_KWORD__@value%0=%1)%2return \
	printf("[samp-detutils]: (profiling) - Code '%s' took %i ticks to execute.",DET_g_ProfilerName,GetTickCount()-DET_g_ProfilerCount);return %1
