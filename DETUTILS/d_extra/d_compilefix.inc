/*
 * 
 * SA:MP DEntisT's Utilities
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which provides slight
 *   "compile fix".
 *
 *
 */

#if !defined DETUTILS_NO_COMPILE_FIX

	#pragma option -i<include>

	#pragma option $file
 
	#pragma option -d3
	#pragma option -Z+
	#pragma option -;+

#elseif defined DETUTILS_NO_COMPILE_FIX

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [samp-detutils]: (warning) - Internal library 'd_compilefix.inc' is disabled.

 	#endif

#endif