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

#if defined @DETUTILSFUNCGEN
	
	#undef @DETUTILSFUNCGEN

#endif

#if defined DETUTILSFUNCGEN_INDEX__

 	#if DETUTILSFUNCGEN_INDEX__ == 0
		
		#undef DETUTILSFUNCGEN_INDEX__
		#define DETUTILSFUNCGEN_INDEX__ (1)
 		
 		#define @1@%0\32; @1@
		#define @DETUTILSFUNCGEN$%1..%2$ @1@%1(%2)

 		#if defined detutils_debug
	 	#warning [samp-detutils]: (debug) - DETUTILSFUNCGEN_INDEX__ is '1'.
	 	#endif
		
		#endinput

 	#elseif DETUTILSFUNCGEN_INDEX__ == 1
		
		#undef DETUTILSFUNCGEN_INDEX__
		#define DETUTILSFUNCGEN_INDEX__ (2)
 		
 		#define @2@%0\32; @2@
		#define @DETUTILSFUNCGEN$%1..%2$ @2@%1(%2)

 		#if defined detutils_debug
	 	#warning [samp-detutils]: (debug) - DETUTILSFUNCGEN_INDEX__ is '2'.
	 	#endif
		
		#endinput

	#elseif DETUTILSFUNCGEN_INDEX__ == 2
		
		#undef DETUTILSFUNCGEN_INDEX__
		#define DETUTILSFUNCGEN_INDEX__ (3)

		#define @3@%0\32; @3@
		#define @DETUTILSFUNCGEN$%1..%2$ @3@%1(%2)

 		#if defined detutils_debug
	 	#warning [samp-detutils]: (debug) - DETUTILSFUNCGEN_INDEX__ is '3'.
	 	#endif

		#endinput
	
	#endif
 	
#else

 	#define DETUTILSFUNCGEN_INDEX__ (0)
 	
 	#define @0@%0\32; @0@
	#define @DETUTILSFUNCGEN$%1..%2$ @0@%1(%2)

 	#if defined detutils_debug
 	#warning [samp-detutils]: (debug) - DETUTILSFUNCGEN_INDEX__ is '0'.
 	#endif
 	#endinput

#endif