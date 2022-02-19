/*
 * 
 * SA:MP DEntisT's Utilities
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library entry file.
 *
 *
 */

#define DETUTILS_COMPAT

// ENTRY POINT TO FIX main() NOT BEING CALLED IN FILTERSCRIPTS
#if defined FILTERSCRIPT

 	#define DETUTILS_FILTERSCRIPT_MODE

#endif

#tryinclude "d_extra\d_mainfix"

#if defined d_samp_included

    #endinput
    #endscript

#endif

#define DETUTILS_OPENMP_COMPAT

#if defined DETUTILS_DEBUG_MODE

 	#define detutils_debug

#endif

#if defined DETUTILS_COMPATIBILITY_MODE

 	#undef DETUTILS_COMPATIBILITY_MODE

#endif

#if defined detutils_complete_error_boom

 	#undef detutils_complete_error_boom

#endif

#pragma warning disable 203

#if defined FILTERSCRIPT

 	#undef FILTERSCRIPT

#endif

#define d_samp_included

#tryinclude "d_extra\d_libtags"

/*

Includes

*/

#if !defined DETUTILS_NO_PROPERTIES

 	//#warning [samp-detutils]: (includes) - Library 'd_properties' is disabled.
	#include "d_properties"

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [samp-detutils]: (includes) - Library 'd_properties' is disabled.

 	#endif

#endif
#if !defined DETUTILS_NO_COMMANDS
	
	//#warning [samp-detutils]: (includes) - Library 'd_commands' is disabled.
	#include "d_commands"

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [samp-detutils]: (includes) - Library 'd_commands' is disabled.

 	#endif

#endif
#if !defined DETUTILS_NO_FMARGS

 	//#warning [samp-detutils]: (includes) - Library 'd_fmargs' is disabled.
	#include "d_fmargs"

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [samp-detutils]: (includes) - Library 'd_fmargs' is disabled.

 	#endif

#endif
#if !defined DETUTILS_NO_VISUAL

 	//#warning [samp-detutils]: (includes) - Library 'd_visual' is disabled.
	#include "d_visual"

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [samp-detutils]: (includes) - Library 'd_visual' is disabled.

 	#endif

#endif
#if !defined DETUTILS_NO_ANTICHEAT

 	//#warning [samp-detutils]: (includes) - Library 'd_anticheat' is disabled.
	#include "d_anticheat"

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [samp-detutils]: (includes) - Library 'd_anticheat' is disabled.

 	#endif

#endif
#if !defined DETUTILS_NO_MAPEDITOR
	
	//#warning [samp-detutils]: (includes) - Library 'd_mapeditor' is disabled.
	#include "d_mapeditor"

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [samp-detutils]: (includes) - Library 'd_mapeditor' is disabled.

 	#endif

#endif
#if !defined DETUTILS_NO_FILEQUERIES
	
	//#warning [samp-detutils]: (includes) - Library 'd_mapeditor' is disabled.
	#include "d_filequeries"

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [samp-detutils]: (includes) - Library 'd_filequeries' is disabled.

 	#endif

#endif
#if !defined DETUTILS_NO_DMZONE
	
	//#warning [samp-detutils]: (includes) - Library 'd_mapeditor' is disabled.
	#include "d_dmzone"

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [samp-detutils]: (includes) - Library 'd_dmzone' is disabled.

 	#endif

#endif
#if !defined DETUTILS_NO_TEAMS
	
	//#warning [samp-detutils]: (includes) - Library 'd_mapeditor' is disabled.
	#include "d_teams"

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [samp-detutils]: (includes) - Library 'd_teams' is disabled.

 	#endif

#endif
#if !defined DETUTILS_NO_DIALOG
	
	//#warning [samp-detutils]: (includes) - Library 'd_mapeditor' is disabled.
	#include "d_dialog"

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [samp-detutils]: (includes) - Library 'd_dialog' is disabled.

 	#endif

#endif
#if !defined DETUTILS_NO_VARS
	
	//#warning [samp-detutils]: (includes) - Library 'd_mapeditor' is disabled.
	#include "d_vars"

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [samp-detutils]: (includes) - Library 'd_vars' is disabled.

 	#endif

#endif
#if !defined DETUTILS_NO_ALS

 	//#warning [samp-detutils]: (includes) - Library 'd_properties' is disabled.
	#include "d_als"

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [samp-detutils]: (includes) - Library 'd_als' is disabled.

 	#endif

#endif

#if defined DETUTILS_NO_PROPERTIES && defined DETUTILS_NO_COMMANDS && defined DETUTILS_NO_FMARGS \
 && defined DETUTILS_NO_VISUAL && defined DETUTILS_NO_ANTICHEAT && defined DETUTILS_NO_FILEQUERIES \
 && defined DETUTILS_NO_MAPEDITOR && defined DETUTILS_NO_DMZONE && defined DETUTILS_NO_TEAMS \
 && defined DETUTILS_NO_DIALOG && defined DETUTILS_NO_VARS && defined DETUTILS_NO_ALS

	#warning [samp-detutils]: (warning) - All library modules are disabled.

 	#tryinclude "d_extra\d_libtags.inc"

	#if !defined d_extra_included
	    #error [samp-detutils]: (error) - You are missing "d_extra\d_libtags.inc" in your "include\DETUTILS" folder.
	#endif

#endif

#if defined DETUTILS_TESTING_MODE && defined DETUTILS_FILTERSCRIPT_MODE

 	#error [samp-detutils]: (mode mismatch) - You can't use DETUTILS_TESTING_MODE and DETUTILS_FILTERSCRIPT_MODE at the same time.

#endif

#if defined DETUTILS_TESTING_MODE

 	#warning [samp-detutils]: (warning) - testmode :: Testing mode is enabled. Remove `#define DETUTILS_TESTING_MODE` from your code to disable it.

 	#include "d_testing\d_testing_entry.inc"

#endif