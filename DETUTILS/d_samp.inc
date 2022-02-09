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


// ENTRY POINT TO FIX main() NOT BEING CALLED IN FILTERSCRIPTS
#if defined FILTERSCRIPT

 	#define DETUTILS_FILTERSCRIPT_MODE

#endif

#tryinclude "d_extra\d_mainfix"

#tryinclude "d_extra\d_libtags"

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

#if !defined DETUTILS_NO_PROPERTIES

 	//#warning [samp-detutils]: (includes) - Library 'd_properties' is disabled.
	#include "d_properties"

#else

 	#warning [samp-detutils]: (includes) - Library 'd_properties' is disabled.

#endif
#if !defined DETUTILS_NO_COMMANDS
	
	//#warning [samp-detutils]: (includes) - Library 'd_commands' is disabled.
	#include "d_commands"

#else

 	#warning [samp-detutils]: (includes) - Library 'd_commands' is disabled.

#endif
#if !defined DETUTILS_NO_FMARGS

 	//#warning [samp-detutils]: (includes) - Library 'd_fmargs' is disabled.
	#include "d_fmargs"

#else

 	#warning [samp-detutils]: (includes) - Library 'd_fmargs' is disabled.

#endif
#if !defined DETUTILS_NO_VISUAL

 	//#warning [samp-detutils]: (includes) - Library 'd_visual' is disabled.
	#include "d_visual"

#else

 	#warning [samp-detutils]: (includes) - Library 'd_visual' is disabled.

#endif
#if !defined DETUTILS_NO_ANTICHEAT

 	//#warning [samp-detutils]: (includes) - Library 'd_anticheat' is disabled.
	#include "d_anticheat"

#else

 	#warning [samp-detutils]: (includes) - Library 'd_anticheat' is disabled.

#endif
#if !defined DETUTILS_NO_MAPEDITOR
	
	//#warning [samp-detutils]: (includes) - Library 'd_mapeditor' is disabled.
	#include "d_mapeditor"

#else

 	#warning [samp-detutils]: (includes) - Library 'd_mapeditor' is disabled.

#endif
#if !defined DETUTILS_NO_FILEQUERIES
	
	//#warning [samp-detutils]: (includes) - Library 'd_mapeditor' is disabled.
	#include "d_filequeries"

#else

 	#warning [samp-detutils]: (includes) - Library 'd_userdata' is disabled.

#endif

#if defined DETUTILS_NO_PROPERTIES && defined DETUTILS_NO_COMMANDS && defined DETUTILS_NO_FMARGS \
 && defined DETUTILS_NO_VISUAL && defined DETUTILS_NO_ANTICHEAT && defined DETUTILS_NO_FILEQUERIES \
 && defined DETUTILS_NO_MAPEDITOR

	#warning [samp-detutils]: (error) - All library modules are disabled.

 	#tryinclude "d_extra\d_libtags.inc"

	#if !defined d_extra_included
	    #error [samp-detutils]: (error) - You are missing "d_extra\d_libtags.inc" in your "include\DETUTILS" folder.
	#endif

#endif 