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


static lol;

// ENTRY POINT TO FIX main() NOT BEING CALLED IN FILTERSCRIPTS
#if defined FILTERSCRIPT

 	#define DETUTILS_FILTERSCRIPT_MODE

#endif

#tryinclude "d_core\d_mainfix"

#pragma warning disable 203

// Core libraries

#tryinclude "d_core\d_libtags"

#if !defined d_extra_included
	#error [DETUtils]: (error) - You are missing "d_core\d_libtags.inc" in your "include\DETUTILS" folder.
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
#if !defined DETUTILS_NO_DMZONE
	
	//#warning [DETUtils]: (includes) - Library 'd_mapeditor' is disabled.
	#include "d_dmzone"

	// Vercheck

	#if !defined DETUTILS_LIBVER_DMZONE
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_DMZONE

		#if DETUTILS_LIBVER_DMZONE != 1

			#error [DETUtils]: (version) - 'd_dmzone.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_dmzone' is disabled.

 	#endif

#endif
#if !defined DETUTILS_NO_TEAMS
	
	//#warning [DETUtils]: (includes) - Library 'd_mapeditor' is disabled.
	#include "d_teams"

	// Vercheck

	#if !defined DETUTILS_LIBVER_TEAMS
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_TEAMS

		#if DETUTILS_LIBVER_TEAMS != 1

			#error [DETUtils]: (version) - 'd_teams.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_teams' is disabled.

 	#endif

#endif
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

#if !defined DETUTILS_NO_DISCORDCMD

 	//#warning [DETUtils]: (includes) - Library 'd_properties' is disabled.
	#include "d_discordcmd"

	// Vercheck

	#if !defined DETUTILS_LIBVER_DISCORDCMD
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_DISCORDCMD

		#if DETUTILS_LIBVER_DISCORDCMD != 1

			#error [DETUtils]: (version) - 'd_discordcmd.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_discordcmd' is disabled.

 	#endif

#endif

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

#if !defined DETUTILS_NO_DISCORDDATA

 	//#warning [DETUtils]: (includes) - Library 'd_properties' is disabled.
	#include "d_discorddata"

	// Vercheck

	#if !defined DETUTILS_LIBVER_DISCORDDATA
		
		#error [DETUtils]: (version) - Version not specified.
	
	#elseif defined DETUTILS_LIBVER_DISCORDDATA

		#if DETUTILS_LIBVER_DISCORDDATA != 1

			#error [DETUtils]: (version) - 'd_discorddata.inc' is outdated.

		#endif

	#endif

#else

 	#if !defined DETUTILS_NO_MODULE_WARNINGS

 		#warning [DETUtils]: (includes) - Library 'd_discorddata' is disabled.

 	#endif

#endif

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

#if defined DETUTILS_NO_PROPERTIES && defined DETUTILS_NO_COMMANDS && defined DETUTILS_NO_FMARGS \
 && defined DETUTILS_NO_VISUAL && defined DETUTILS_NO_ANTICHEAT && defined DETUTILS_NO_FILEQUERIES \
 && defined DETUTILS_NO_MAPEDITOR && defined DETUTILS_NO_DMZONE && defined DETUTILS_NO_TEAMS \
 && defined DETUTILS_NO_DIALOG && defined DETUTILS_NO_VARS && defined DETUTILS_NO_ALS \
 && defined DETUTILS_NO_FOREACH && defined DETUTILS_NO_TABLES && defined DETUTILS_NO_DISCORDCMD \
 && defined DETUTILS_NO_PROFILE && defined DETUTILS_NO_TIMERS && defined DETUTILS_NO_DISCORDDATA \
 && defined DETUTILS_NO_PERMISSIONS && defined DETUTILS_NO_EVENTS

	#warning [DETUtils]: (warning) - All library modules are disabled.

 	#tryinclude "d_extra\d_libtags.inc"

	#if !defined d_extra_included
	    #error [DETUtils]: (error) - You are missing "d_extra\d_libtags.inc" in your "include\DETUTILS" folder.
	#endif

#endif

#if defined DETUTILS_TESTING_MODE && defined DETUTILS_FILTERSCRIPT_MODE

 	#error [DETUtils]: (mode mismatch) - You can't use DETUTILS_TESTING_MODE and DETUTILS_FILTERSCRIPT_MODE at the same time.

#endif

#if defined DETUTILS_TESTING_MODE

 	#warning [DETUtils]: (warning) - testmode :: Testing mode is enabled. Remove `#define DETUTILS_TESTING_MODE` from your code to disable it.

 	#include "d_testing\d_testing_entry.inc"

#endif

// Version check and release check

#if !defined __DETUtils

 	#error [DETUtils]: (version error) - Version not specified.

#endif

#if defined __DETUtils

 	#if __DETUtils != 0x205

 		#error [DETUtils]: (version mismatch) - Invalid version, 0x205 was expected.

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