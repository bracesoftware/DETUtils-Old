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

#define DETUTILS_OLD_HOOK
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

	// Vercheck

	#if !defined DETUTILS_LIBVER_PROPERTIES
		
		#error [samp-detutils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_PROPERTIES

		#if DETUTILS_LIBVER_PROPERTIES != 1

			#error [samp-detutils]: (version) - 'd_properties.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [samp-detutils]: (includes) - Library 'd_properties' is disabled.

 	#endif

#endif
#if !defined DETUTILS_NO_COMMANDS
	
	//#warning [samp-detutils]: (includes) - Library 'd_commands' is disabled.
	#include "d_commands"

	// Vercheck

	#if !defined DETUTILS_LIBVER_COMMANDS
		
		#error [samp-detutils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_COMMANDS

		#if DETUTILS_LIBVER_COMMANDS != 1

			#error [samp-detutils]: (version) - 'd_commands.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [samp-detutils]: (includes) - Library 'd_commands' is disabled.

 	#endif

#endif
#if !defined DETUTILS_NO_FMARGS

 	//#warning [samp-detutils]: (includes) - Library 'd_fmargs' is disabled.
	#include "d_fmargs"

	// Vercheck

	#if !defined DETUTILS_LIBVER_FMARGS
		
		#error [samp-detutils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_FMARGS

		#if DETUTILS_LIBVER_FMARGS != 1

			#error [samp-detutils]: (version) - 'd_fmargs.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [samp-detutils]: (includes) - Library 'd_fmargs' is disabled.

 	#endif

#endif
#if !defined DETUTILS_NO_VISUAL

 	//#warning [samp-detutils]: (includes) - Library 'd_visual' is disabled.
	#include "d_visual"

	// Vercheck

	#if !defined DETUTILS_LIBVER_VISUAL
		
		#error [samp-detutils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_VISUAL

		#if DETUTILS_LIBVER_VISUAL != 1

			#error [samp-detutils]: (version) - 'd_visual.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [samp-detutils]: (includes) - Library 'd_visual' is disabled.

 	#endif

#endif
#if !defined DETUTILS_NO_ANTICHEAT

 	//#warning [samp-detutils]: (includes) - Library 'd_anticheat' is disabled.
	#include "d_anticheat"

	// Vercheck

	#if !defined DETUTILS_LIBVER_ANTICHEAT
		
		#error [samp-detutils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_ANTICHEAT

		#if DETUTILS_LIBVER_ANTICHEAT != 1

			#error [samp-detutils]: (version) - 'd_anticheat.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [samp-detutils]: (includes) - Library 'd_anticheat' is disabled.

 	#endif

#endif
#if !defined DETUTILS_NO_MAPEDITOR
	
	//#warning [samp-detutils]: (includes) - Library 'd_mapeditor' is disabled.
	#include "d_mapeditor"

	// Vercheck

	#if !defined DETUTILS_LIBVER_MAPEDITOR
		
		#error [samp-detutils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_MAPEDITOR

		#if DETUTILS_LIBVER_MAPEDITOR != 1

			#error [samp-detutils]: (version) - 'd_mapeditor.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [samp-detutils]: (includes) - Library 'd_mapeditor' is disabled.

 	#endif

#endif
#if !defined DETUTILS_NO_FILEQUERIES
	
	//#warning [samp-detutils]: (includes) - Library 'd_mapeditor' is disabled.
	#include "d_filequeries"

	// Vercheck

	#if !defined DETUTILS_LIBVER_FILEQUERIES
		
		#error [samp-detutils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_FILEQUERIES

		#if DETUTILS_LIBVER_FILEQUERIES != 1

			#error [samp-detutils]: (version) - 'd_filequeries.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [samp-detutils]: (includes) - Library 'd_filequeries' is disabled.

 	#endif

#endif
#if !defined DETUTILS_NO_DMZONE
	
	//#warning [samp-detutils]: (includes) - Library 'd_mapeditor' is disabled.
	#include "d_dmzone"

	// Vercheck

	#if !defined DETUTILS_LIBVER_DMZONE
		
		#error [samp-detutils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_DMZONE

		#if DETUTILS_LIBVER_DMZONE != 1

			#error [samp-detutils]: (version) - 'd_dmzone.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [samp-detutils]: (includes) - Library 'd_dmzone' is disabled.

 	#endif

#endif
#if !defined DETUTILS_NO_TEAMS
	
	//#warning [samp-detutils]: (includes) - Library 'd_mapeditor' is disabled.
	#include "d_teams"

	// Vercheck

	#if !defined DETUTILS_LIBVER_TEAMS
		
		#error [samp-detutils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_TEAMS

		#if DETUTILS_LIBVER_TEAMS != 1

			#error [samp-detutils]: (version) - 'd_teams.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [samp-detutils]: (includes) - Library 'd_teams' is disabled.

 	#endif

#endif
#if !defined DETUTILS_NO_DIALOG
	
	//#warning [samp-detutils]: (includes) - Library 'd_mapeditor' is disabled.
	#include "d_dialog"

	// Vercheck

	#if !defined DETUTILS_LIBVER_DIALOG
		
		#error [samp-detutils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_DIALOG

		#if DETUTILS_LIBVER_DIALOG != 1

			#error [samp-detutils]: (version) - 'd_dialog.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [samp-detutils]: (includes) - Library 'd_dialog' is disabled.

 	#endif

#endif
#if !defined DETUTILS_NO_VARS
	
	//#warning [samp-detutils]: (includes) - Library 'd_mapeditor' is disabled.
	#include "d_vars"

	// Vercheck

	#if !defined DETUTILS_LIBVER_VARS
		
		#error [samp-detutils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_VARS

		#if DETUTILS_LIBVER_VARS != 1

			#error [samp-detutils]: (version) - 'd_vars.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [samp-detutils]: (includes) - Library 'd_vars' is disabled.

 	#endif

#endif
#if !defined DETUTILS_NO_ALS

 	//#warning [samp-detutils]: (includes) - Library 'd_properties' is disabled.
	#include "d_als"

	// Vercheck

	#if !defined DETUTILS_LIBVER_ALS
		
		#error [samp-detutils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_ALS

		#if DETUTILS_LIBVER_ALS != 1

			#error [samp-detutils]: (version) - 'd_als.inc' is outdated.

		#endif

	#endif

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

// Version check and release check

#if !defined __DETUtils

 	#error [samp-detutils]: (version error) - Version not specified.

#endif

#if defined __DETUtils

 	#if __DETUtils != 0x203

 		#error [samp-detutils]: (version mismatch) - Invalid version, 0x203 was expected.

 	#endif

#endif

#if !defined __DETUtilsRelease

 	#error [samp-detutils]: (release error) - Version release not specified.

#endif

#if defined __DETUtilsRelease

 	#if __DETUtilsRelease != 0x7

 		#error [samp-detutils]: (release mismatch) - Invalid version, 0x7 was expected.

 	#endif

#endif