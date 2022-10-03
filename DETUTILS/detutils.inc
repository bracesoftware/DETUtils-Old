/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library entry file.
 *
 *
 */

// Include guard:
#if defined DETUTILS_INCLUDED

 	#endinput

#endif

#define DETUTILS_INCLUDED

// ENTRY POINT TO FIX main() NOT BEING CALLED IN FILTERSCRIPTS
#if defined FILTERSCRIPT

 	#define DETUTILS_FILTERSCRIPT_MODE

#endif

#tryinclude "d_core\d_core_mainfix"

// FIX "SYMBOL NEVER USED WARNINGS"
#pragma warning disable 203

// Dynamic:
#pragma dynamic 123456789

// Core libraries

#tryinclude "d_core\d_core_entry"

#if !defined d_core_included
	#error [DETUtils]: (error) - You are missing "d_core\d_core_entry.inc" in your "include\DETUTILS" folder.
#endif

/*

Includes

*/

#if !defined DETUTILS_NO_PERMISSIONS

 	//#warning [DETUtils]: (includes) - Library 'd_properties' is disabled.
	#include "d_permissions"

	// Vercheck

	#if !defined DETUTILS_LIBVER_PERMISSIONS
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_PERMISSIONS

		#if DETUTILS_LIBVER_PERMISSIONS != 1

			#error [DETUtils]: (version) - 'd_permissions.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_permissions' is disabled.

 	#endif

#endif
/* =============================================================== */
#if !defined DETUTILS_NO_PROPERTIES

 	//#warning [DETUtils]: (includes) - Library 'd_properties' is disabled.
	#include "d_properties"

	// Vercheck

	#if !defined DETUTILS_LIBVER_PROPERTIES
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_PROPERTIES

		#if DETUTILS_LIBVER_PROPERTIES != 1

			#error [DETUtils]: (version) - 'd_properties.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_properties' is disabled.

 	#endif

#endif
/* =============================================================== */
#if !defined DETUTILS_NO_COMMANDS
	
	//#warning [DETUtils]: (includes) - Library 'd_commands' is disabled.
	#include "d_commands"

	// Vercheck

	#if !defined DETUTILS_LIBVER_COMMANDS
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_COMMANDS

		#if DETUTILS_LIBVER_COMMANDS != 1

			#error [DETUtils]: (version) - 'd_commands.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_commands' is disabled.

 	#endif

#endif
/* =============================================================== */
#if !defined DETUTILS_NO_FMARGS

 	//#warning [DETUtils]: (includes) - Library 'd_fmargs' is disabled.
	#include "d_fmargs"

	// Vercheck

	#if !defined DETUTILS_LIBVER_FMARGS
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_FMARGS

		#if DETUTILS_LIBVER_FMARGS != 1

			#error [DETUtils]: (version) - 'd_fmargs.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_fmargs' is disabled.

 	#endif

#endif
/* =============================================================== */
#if !defined DETUTILS_NO_VISUAL

 	//#warning [DETUtils]: (includes) - Library 'd_visual' is disabled.
	#include "d_visual"

	// Vercheck

	#if !defined DETUTILS_LIBVER_VISUAL
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_VISUAL

		#if DETUTILS_LIBVER_VISUAL != 1

			#error [DETUtils]: (version) - 'd_visual.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_visual' is disabled.

 	#endif

#endif
/* =============================================================== */
#if !defined DETUTILS_NO_ANTICHEAT

 	//#warning [DETUtils]: (includes) - Library 'd_anticheat' is disabled.
	#include "d_anticheat"

	// Vercheck

	#if !defined DETUTILS_LIBVER_ANTICHEAT
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_ANTICHEAT

		#if DETUTILS_LIBVER_ANTICHEAT != 1

			#error [DETUtils]: (version) - 'd_anticheat.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_anticheat' is disabled.

 	#endif

#endif
/* =============================================================== */
#if !defined DETUTILS_NO_MAPEDITOR
	
	//#warning [DETUtils]: (includes) - Library 'd_mapeditor' is disabled.
	#include "d_mapeditor"

	// Vercheck

	#if !defined DETUTILS_LIBVER_MAPEDITOR
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_MAPEDITOR

		#if DETUTILS_LIBVER_MAPEDITOR != 1

			#error [DETUtils]: (version) - 'd_mapeditor.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_mapeditor' is disabled.

 	#endif

#endif
/* =============================================================== */
#if !defined DETUTILS_NO_FILEQUERIES
	
	//#warning [DETUtils]: (includes) - Library 'd_mapeditor' is disabled.
	#include "d_filequeries"

	// Vercheck

	#if !defined DETUTILS_LIBVER_FILEQUERIES
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_FILEQUERIES

		#if DETUTILS_LIBVER_FILEQUERIES != 1

			#error [DETUtils]: (version) - 'd_filequeries.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_filequeries' is disabled.

 	#endif

#endif
/* =============================================================== */
#if !defined DETUTILS_NO_FACTIONS
	
	//#warning [DETUtils]: (includes) - Library 'd_mapeditor' is disabled.
	#include "d_factions"

	// Vercheck

	#if !defined DETUTILS_LIBVER_FACTIONS
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_FACTIONS

		#if DETUTILS_LIBVER_FACTIONS != 1

			#error [DETUtils]: (version) - 'd_factions.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_factions' is disabled.

 	#endif

#endif
/* =============================================================== */
#if !defined DETUTILS_NO_DIALOG
	
	//#warning [DETUtils]: (includes) - Library 'd_mapeditor' is disabled.
	#include "d_dialog"

	// Vercheck

	#if !defined DETUTILS_LIBVER_DIALOG
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_DIALOG

		#if DETUTILS_LIBVER_DIALOG != 1

			#error [DETUtils]: (version) - 'd_dialog.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_dialog' is disabled.

 	#endif

#endif
/* =============================================================== */
#if !defined DETUTILS_NO_VARS
	
	//#warning [DETUtils]: (includes) - Library 'd_mapeditor' is disabled.
	#include "d_vars"

	// Vercheck

	#if !defined DETUTILS_LIBVER_VARS
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_VARS

		#if DETUTILS_LIBVER_VARS != 1

			#error [DETUtils]: (version) - 'd_vars.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_vars' is disabled.

 	#endif

#endif
/* =============================================================== */
#if !defined DETUTILS_NO_ALS

 	//#warning [DETUtils]: (includes) - Library 'd_properties' is disabled.
	#include "d_als"

	// Vercheck

	#if !defined DETUTILS_LIBVER_ALS
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_ALS

		#if DETUTILS_LIBVER_ALS != 1

			#error [DETUtils]: (version) - 'd_als.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_als' is disabled.

 	#endif

#endif
/* =============================================================== */
#if !defined DETUTILS_NO_FOREACH

 	//#warning [DETUtils]: (includes) - Library 'd_properties' is disabled.
	#include "d_foreach"

	// Vercheck

	#if !defined DETUTILS_LIBVER_ALS
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_ALS

		#if DETUTILS_LIBVER_ALS != 1

			#error [DETUtils]: (version) - 'd_foreach.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_foreach' is disabled.

 	#endif

#endif
/* =============================================================== */
#if !defined DETUTILS_NO_TABLES

 	//#warning [DETUtils]: (includes) - Library 'd_properties' is disabled.
	#include "d_tables"

	// Vercheck

	#if !defined DETUTILS_LIBVER_TABLES
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_TABLES

		#if DETUTILS_LIBVER_TABLES != 1

			#error [DETUtils]: (version) - 'd_tables.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_tables' is disabled.

 	#endif

#endif
/* =============================================================== */
#if !defined DETUTILS_NO_DISCORDAPI

 	//#warning [DETUtils]: (includes) - Library 'd_properties' is disabled.
	#include "d_discordapi"

	// Vercheck

	#if !defined DETUTILS_LIBVER_DISCORDAPI
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_DISCORDAPI

		#if DETUTILS_LIBVER_DISCORDAPI != 1

			#error [DETUtils]: (version) - 'd_discordapi.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_discordapi' is disabled.

 	#endif

#endif
/* =============================================================== */
#if !defined DETUTILS_NO_PROFILE

 	//#warning [DETUtils]: (includes) - Library 'd_properties' is disabled.
	#include "d_profile"

	// Vercheck

	#if !defined DETUTILS_LIBVER_PROFILE
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_PROFILE

		#if DETUTILS_LIBVER_PROFILE != 1

			#error [DETUtils]: (version) - 'd_profile.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_profile' is disabled.

 	#endif

#endif
/* =============================================================== */
#if !defined DETUTILS_NO_TIMERS

 	//#warning [DETUtils]: (includes) - Library 'd_properties' is disabled.
	#include "d_timers"

	// Vercheck

	#if !defined DETUTILS_LIBVER_TIMERS
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_TIMERS

		#if DETUTILS_LIBVER_TIMERS != 1

			#error [DETUtils]: (version) - 'd_timers.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_timers' is disabled.

 	#endif

#endif
/* =============================================================== */
#if !defined DETUTILS_NO_EVENTS

 	//#warning [DETUtils]: (includes) - Library 'd_properties' is disabled.
	#include "d_events"

	// Vercheck

	#if !defined DETUTILS_LIBVER_EVENTS
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_EVENTS

		#if DETUTILS_LIBVER_EVENTS != 1

			#error [DETUtils]: (version) - 'd_events.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_events' is disabled.

 	#endif

#endif
/* =============================================================== */
#if !defined DETUTILS_NO_SERVER

 	//#warning [DETUtils]: (includes) - Library 'd_properties' is disabled.
	#include "d_server"

	// Vercheck

	#if !defined DETUTILS_LIBVER_SERVER
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_SERVER

		#if DETUTILS_LIBVER_SERVER != 1

			#error [DETUtils]: (version) - 'd_server.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_server' is disabled.

 	#endif

#endif
/* =============================================================== */
#if !defined DETUTILS_NO_TOML

 	//#warning [DETUtils]: (includes) - Library 'd_properties' is disabled.
	#include "d_toml"

	// Vercheck

	#if !defined DETUTILS_LIBVER_TOML
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_TOML

		#if DETUTILS_LIBVER_TOML != 1

			#error [DETUtils]: (version) - 'd_toml.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_toml' is disabled.

 	#endif

#endif
/* =============================================================== */
#if !defined DETUTILS_NO_YAML

 	//#warning [DETUtils]: (includes) - Library 'd_properties' is disabled.
	#include "d_yaml"

	// Vercheck

	#if !defined DETUTILS_LIBVER_YAML
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_YAML

		#if DETUTILS_LIBVER_YAML != 1

			#error [DETUtils]: (version) - 'd_yaml.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_yaml' is disabled.

 	#endif

#endif
/* =============================================================== */
#if !defined DETUTILS_NO_TESTING

 	//#warning [DETUtils]: (includes) - Library 'd_properties' is disabled.
	#include "d_testing"

	// Vercheck

	#if !defined DETUTILS_LIBVER_TESTING
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_TESTING

		#if DETUTILS_LIBVER_TESTING != 1

			#error [DETUtils]: (version) - 'd_testing.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_testing' is disabled (not the DETUTILS_TESTING_MODE).

 	#endif

#endif
/* =============================================================== */
#if !defined DETUTILS_NO_RACES

 	//#warning [DETUtils]: (includes) - Library 'd_properties' is disabled.
	#include "d_races"

	// Vercheck

	#if !defined DETUTILS_LIBVER_RACES
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_RACES

		#if DETUTILS_LIBVER_RACES != 1

			#error [DETUtils]: (version) - 'd_races.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_races' is disabled.

 	#endif

#endif
/* =============================================================== */
#if !defined DETUTILS_NO_GLOBAL

 	//#warning [DETUtils]: (includes) - Library 'd_properties' is disabled.
	#include "d_global"

	// Vercheck

	#if !defined DETUTILS_LIBVER_GLOBAL
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_GLOBAL

		#if DETUTILS_LIBVER_GLOBAL != 1

			#error [DETUtils]: (version) - 'd_global.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_global' is disabled.

 	#endif

#endif
/* =============================================================== */
#if !defined DETUTILS_NO_ASCII

 	//#warning [DETUtils]: (includes) - Library 'd_properties' is disabled.
	#include "d_ascii"

	// Vercheck

	#if !defined DETUTILS_LIBVER_ASCII
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_ASCII

		#if DETUTILS_LIBVER_ASCII != 1

			#error [DETUtils]: (version) - 'd_ascii.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_ascii' is disabled.

 	#endif

#endif
/* =============================================================== */
#if !defined DETUTILS_NO_LAMBDA

 	//#warning [DETUtils]: (includes) - Library 'd_properties' is disabled.
	#include "d_lambda"

	// Vercheck

	#if !defined DETUTILS_LIBVER_LAMBDA
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_LAMBDA

		#if DETUTILS_LIBVER_LAMBDA != 1

			#error [DETUtils]: (version) - 'd_lambda.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_lambda' is disabled.

 	#endif

#endif
/* =============================================================== */

#if defined DETUTILS_NO_PROPERTIES && defined DETUTILS_NO_COMMANDS && defined DETUTILS_NO_FMARGS \
 && defined DETUTILS_NO_VISUAL && defined DETUTILS_NO_ANTICHEAT && defined DETUTILS_NO_FILEQUERIES \
 && defined DETUTILS_NO_MAPEDITOR && defined DETUTILS_NO_FACTIONS && defined DETUTILS_NO_SERVER \
 && defined DETUTILS_NO_DIALOG && defined DETUTILS_NO_VARS && defined DETUTILS_NO_ALS \
 && defined DETUTILS_NO_FOREACH && defined DETUTILS_NO_TABLES && defined DETUTILS_NO_TOML \
 && defined DETUTILS_NO_PROFILE && defined DETUTILS_NO_TIMERS && defined DETUTILS_NO_DISCORDAPI \
 && defined DETUTILS_NO_PERMISSIONS && defined DETUTILS_NO_EVENTS && defined DETUTILS_NO_YAML \
 && defined DETUTILS_NO_GLOBAL && defined DETUTILS_NO_ASCII && defined DETUTILS_NO_LAMBDA

	#warning [DETUtils]: (warning) - All library modules are disabled.

 	/*#tryinclude "d_extra\d_libtags.inc"

	#if !defined d_extra_included
	    #error [DETUtils]: (error) - You are missing "d_extra\d_libtags.inc" in your "include\DETUTILS" folder.
	#endif*/

#endif

#if defined DETUTILS_TESTING_MODE && defined DETUTILS_FILTERSCRIPT_MODE

 	#error [DETUtils]: (mode mismatch) - You can't use DETUTILS_TESTING_MODE and DETUTILS_FILTERSCRIPT_MODE at the same time.

#endif

#if defined DETUTILS_TESTING_MODE

 	#warning [DETUtils]: (warning) - testmode :: Testing mode is enabled. Remove `#define DETUTILS_TESTING_MODE` from your code to disable it.

 	#include "d_testing\d_testing_internal.inc"

#endif

#if defined DETUTILS_STATIC_MODE && !defined DETUTILS_NO_MODULE_WARNINGS

 	#warning [DETUtils]: (warning) - staticmode :: Static mode is enabled. Remove `#define DETUTILS_STATIC_MODE` from your code to disable it.

#endif

// Version check and release check

#if !defined __DETUtils

 	#error [DETUtils]: (version error) - Version not specified.

#endif

#if defined __DETUtils

 	#if __DETUtils != 0x207

 		#error [DETUtils]: (version mismatch) - Invalid version, 0x207 was expected.

 	#endif

#endif

#if !defined __DETUtilsRelease

 	#error [DETUtils]: (release error) - Version release not specified.

#endif

#if defined __DETUtilsRelease

 	#if __DETUtilsRelease != 0x2

 		#error [DETUtils]: (release mismatch) - Invalid version release, 0x2 was expected.

 	#endif

#endif

#if defined detutils_debug

 	#error [DETUtils]: (symbol deprecated) - Symbol 'detutils_debug' is deprecated and defining it does nothing.

#endif

// After all the checks passed

#if !defined DETUTILS_NO_MODULE_WARNINGS

 	#if __DETUtilsBeta == 1

 		#warning [DETUtils]: (beta) - Codebase is currently under the beta development. Please open an issue on github.com/samp-api/detutils in case of bugs.

 	#endif

#endif

#if !defined __SAMPStdLib

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (samp stdlib) - It is recommended to use the SA:MP standard library package modified by the SA:MP API team. You can get it at: github.com/samp-api/samp-stdlib

 	#endif

#endif

main()
{
	// Tell the script that initialization has been finished.
	@detmemory DET_o_SysInit, 0
	detutils_main();
}

#if defined _ALS_main

	#undef main

#elseif !defined _ALS_main

	#define _ALS_main

#endif

#define main( detutils_main(