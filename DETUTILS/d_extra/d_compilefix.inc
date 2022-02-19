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

 	// THIS IS REALLY IMPORTANT!
 	// NOTE: This is a HACK, don't remove this:
	#pragma option -;+

#elseif defined DETUTILS_NO_COMPILE_FIX

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [samp-detutils]: (warning) - Internal library 'd_compilefix.inc' is disabled.

 	#endif

#endif