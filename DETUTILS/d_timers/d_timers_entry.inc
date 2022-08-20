/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - A library which is providing the
 *	 automatic and manual timers.
 *
 *
 */

#include "d_timers_macros"

/*
                                                                                      
88b           d88              88                         db         88888888ba   88  
888b         d888              ""                        d88b        88      "8b  88  
88`8b       d8'88                                       d8'`8b       88      ,8P  88  
88 `8b     d8' 88  ,adPPYYba,  88  8b,dPPYba,          d8'  `8b      88aaaaaa8P'  88  
88  `8b   d8'  88  ""     `Y8  88  88P'   `"8a        d8YaaaaY8b     88""""""'    88  
88   `8b d8'   88  ,adPPPPP88  88  88       88       d8""""""""8b    88           88  
88    `888'    88  88,    ,88  88  88       88      d8'        `8b   88           88  
88     `8'     88  `"8bbdP"Y8  88  88       88     d8'          `8b  88           88  
                                                                                      
                                                                                      
*/

stock void:LoadDETUtilsAutomaticTimers()
{
	new intervalfunc[32];
	new taskfunc[32];
	for(new i; i < 1000; i++)
	{
		format(taskfunc, sizeof taskfunc, "@%i@d_timerid", i);
		format(intervalfunc, sizeof intervalfunc, "@%i@d_t_int", i);
		SetTimer(taskfunc, CallLocalFunction(intervalfunc, ""), true);
	}
}

/*
                                                                      
88888888888                                                           
88                          ,d                                        
88                          88                                        
88aaaaa      8b,     ,d8  MM88MMM  8b,dPPYba,  ,adPPYYba,  ,adPPYba,  
88"""""       `Y8, ,8P'     88     88P'   "Y8  ""     `Y8  I8[    ""  
88              )888(       88     88          ,adPPPPP88   `"Y8ba,   
88            ,d8" "8b,     88,    88          88,    ,88  aa    ]8I  
88888888888  8P'     `Y8    "Y888  88          `"8bbdP"Y8  `"YbbdP"'  
                                                                      

*/

public OnDETUtilsInit()
{
	LoadDETUtilsAutomaticTimers();
	#if defined DETUTILS_DEBUG_MODE
	SaveLogIntoFile("detutils_timers.log", "[DETUtils]: (debug) - Loading...");
	SaveLogIntoFile("detutils_timers.log", "[DETUtils]: (debug) - Loaded.");
	#endif
	LoadDETUtilsScript(DETUTILS_SCRIPT_TIMERS);
	if(funcidx("d_timers_detutilsinit") != -1)
	{
		CallLocalFunction("d_timers_detutilsinit", "");
	}
	return 1;
}

#if defined _ALS_OnDETUtilsInit
	#undef OnDETUtilsInit
#else
	#define _ALS_OnDETUtilsInit
#endif

#define OnDETUtilsInit( d_timers_detutilsinit(

forward d_timers_detutilsinit();