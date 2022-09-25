/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Entry files.
 *
 *
 */


#include "d_core\d_core_entry"

// After funcgen (core entry) is included,
// we include the entry point.

#if defined __DETUTILS_INTERNAL_TIMERS_INC

    #endinput

#endif

#define __DETUTILS_INTERNAL_TIMERS_INC

#define DETUTILS_LIBVER_TIMERS 1

#include "d_timers\d_timers_entry"