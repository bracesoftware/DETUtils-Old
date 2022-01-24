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

#if defined d_samp_included

    #endinput
    #endscript

#endif

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

#define d_samp_included

#include "d_properties"
#include "d_commands"
#include "d_fmargs"
#include "d_visual"
#include "d_anticheat"
#include "d_colours"
#include "d_mapeditor"