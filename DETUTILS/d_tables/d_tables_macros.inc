/*
 * 
 * SA:MP DEntisT's Utilities
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - An excel-like table management system.
 *
 *
 */

#define @DETUTILSTABLES_KWORD__@%0\32; @DETUTILSTABLES_KWORD__@
#define table @DETUTILSTABLES_KWORD__@
#define @DETUTILSTABLES_KWORD__1@%0\32; @DETUTILSTABLES_KWORD__1@
#define column @DETUTILSTABLES_KWORD__1@
#define @DETUTILSTABLES_KWORD__2@%0\32; @DETUTILSTABLES_KWORD__2@
#define row @DETUTILSTABLES_KWORD__2@
#define @DETUTILSTABLES_KWORD__3@%0\32; @DETUTILSTABLES_KWORD__3@
#define cell @DETUTILSTABLES_KWORD__3@
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

#define @DETUTILSTABLES_KWORD__@Create%0(%1) __CreateTable(%1)
#define @DETUTILSTABLES_KWORD__@Delete%0(%1) __DeleteTable(%1)

#define @DETUTILSTABLES_KWORD__1@Create%0(%1) __CreateColumn(%1)
#define @DETUTILSTABLES_KWORD__1@Delete%0(%1) __DeleteColumn(%1)

#define @DETUTILSTABLES_KWORD__2@Create%0(%1) __CreateRow(%1)
#define @DETUTILSTABLES_KWORD__2@Delete%0(%1) __DeleteRow(%1)

#define @DETUTILSTABLES_KWORD__@SetValue%0(%1) __SetCellValue(%1)
#define @DETUTILSTABLES_KWORD__@GetValue%0(%1) __GetCellValue(%1)

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
	#if defined detutils_debug
	SaveLogIntoFile("detutils_tables.log", "[samp-detutils]: (debug) - Loading...");
	SaveLogIntoFile("detutils_tables.log", "[samp-detutils]: (debug) - Loaded.");
	#endif
	LoadDETUtilsScript(DETUTILS_SCRIPT_TABLES);
	if(funcidx("d_tab_detutilsinit") != -1)
	{
		CallLocalFunction("d_tab_detutilsinit", "");
	}
	return 1;
}

#if defined _ALS_OnDETUtilsInit
	#undef OnDETUtilsInit
#else
	#define _ALS_OnDETUtilsInit
#endif

#define OnDETUtilsInit( d_tab_detutilsinit(

forward d_tab_detutilsinit();