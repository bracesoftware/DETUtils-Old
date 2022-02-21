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
	
	#elseif DETUTILSFUNCGEN_INDEX__ == 3
		
		#undef DETUTILSFUNCGEN_INDEX__
		#define DETUTILSFUNCGEN_INDEX__ (4)

		#define @4@%0\32; @4@
		#define @DETUTILSFUNCGEN$%1..%2$ @4@%1(%2)

 		#if defined detutils_debug
	 	#warning [samp-detutils]: (debug) - DETUTILSFUNCGEN_INDEX__ is '4'.
	 	#endif

		#endinput
	
	#elseif DETUTILSFUNCGEN_INDEX__ == 4
		
		#undef DETUTILSFUNCGEN_INDEX__
		#define DETUTILSFUNCGEN_INDEX__ (5)

		#define @5@%0\32; @5@
		#define @DETUTILSFUNCGEN$%1..%2$ @5@%1(%2)

 		#if defined detutils_debug
	 	#warning [samp-detutils]: (debug) - DETUTILSFUNCGEN_INDEX__ is '5'.
	 	#endif

		#endinput
	
	#elseif DETUTILSFUNCGEN_INDEX__ == 5
		
		#undef DETUTILSFUNCGEN_INDEX__
		#define DETUTILSFUNCGEN_INDEX__ (6)

		#define @6@%0\32; @6@
		#define @DETUTILSFUNCGEN$%1..%2$ @6@%1(%2)

 		#if defined detutils_debug
	 	#warning [samp-detutils]: (debug) - DETUTILSFUNCGEN_INDEX__ is '6'.
	 	#endif

		#endinput
	
	#elseif DETUTILSFUNCGEN_INDEX__ == 6
		
		#undef DETUTILSFUNCGEN_INDEX__
		#define DETUTILSFUNCGEN_INDEX__ (7)

		#define @7@%0\32; @7@
		#define @DETUTILSFUNCGEN$%1..%2$ @7@%1(%2)

 		#if defined detutils_debug
	 	#warning [samp-detutils]: (debug) - DETUTILSFUNCGEN_INDEX__ is '7'.
	 	#endif

		#endinput
	
	#endif
 	
#else

	//#define d_als_included
	#define DETUTILSFUNCGEN_INDEX__ (0)
 	
 	#define @0@%0\32; @0@
	#define @DETUTILSFUNCGEN$%1..%2$ @0@%1(%2)

 	#if defined detutils_debug
 	#warning [samp-detutils]: (debug) - DETUTILSFUNCGEN_INDEX__ is '0'.
 	#endif

#endif
