/*
 * 
 * SA:MP DEntisT's Utilities
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which provides generation
 *   of function names, REALLY 
 *   useful for anything such
 *   as function hooking...
 *
 *
 */

#if defined @DETUTILSFUNCGEN_INDEX__

	#if @DETUTILSFUNCGEN_INDEX__ < 0 || @DETUTILSFUNCGEN_INDEX__ >= 1000
		
		#error [samp-detutils]: (error) - 'd_funcgen.inc' index is out of default range.

	#elseif DETUTILSFUNCGEN_INDEX__ == 0
		
		#undef DETUTILSFUNCGEN_INDEX__
		#define DETUTILSFUNCGEN_INDEX__ 1
		#define @DETUTILSFUNCGEN_DECL__FUNC:%0$%1..%2$ %0@1@%1(%2);public %0@1@%1(%2)
		#endinput

	#elseif DETUTILSFUNCGEN_INDEX__ == 1
		
		#undef DETUTILSFUNCGEN_INDEX__
		#define DETUTILSFUNCGEN_INDEX__ 2
		#define @DETUTILSFUNCGEN_DECL__FUNC:%0$%1..%2$ %0@2@%1(%2);public %0@2@%1(%2)
		#endinput
	
	#endif

#else

	#define @DETUTILSFUNCGEN_INDEX__ 0
	#define @DETUTILSFUNCGEN_DECL__FUNC:%0$%1..%2$ %0@0@%1(%2);public %0@0@%1(%2)

#endif