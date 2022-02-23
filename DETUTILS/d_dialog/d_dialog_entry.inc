/*
 * 
 * SA:MP DEntisT's Utilities
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which provides creating
 *   dialogs with many features.
 *
 *
 */

#tryinclude "d_extra\d_libtags.inc"

#if !defined d_extra_included
	#error [samp-detutils]: (error) - You are missing "d_extra\d_libtags.inc" in your "include\DETUTILS" folder.
#endif

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

enum
{
	DETUTILS_INTERNAL_DIALOG
}

// Macro setup:

#include "d_dialog_macros"

enum enum_PlayerDialogData
{
	Dialog[32]
}

new g_PlayerDialogCache[MAX_PLAYERS][enum_PlayerDialogData];

// Functions down there:

#if defined DETUTILS_OPENMP_COMPAT

	#define Dialog_ShowForPlayer ShowDialogForPlayer

#endif

forward OnPlayerDialogReceived(playerid, dialog[]);
forward OnPlayerDialogResponse(playerid, dialog[], response, listitem, inputtext[]);
forward OnPlayerDialogHide(playerid, dialog[]);

stock ShowDialogForPlayer(playerid, const name[])
{
	strmid(g_PlayerDialogCache[playerid][Dialog], name, 0, 32);
	new dialogfunc[32];
	format(dialogfunc, sizeof dialogfunc, "dlg_%s", name);
	if(funcidx(dialogfunc) != -1)
	{
		CallLocalFunction(dialogfunc, "i", playerid);
		CallLocalFunction("OnPlayerDialogReceived", "is", playerid, name);
	}
	else 
	{
		printf("[samp-detutils]: (dialog IID) - Invalid dialog : %s", name);
		return 0;
	}
	return 1;
}

stock GetDialogStyle(const name[])
{
	new dialogfunc[32];
	format(dialogfunc, sizeof dialogfunc, "dls_%s", name);
	if(funcidx(dialogfunc) != -1)
	{
		return CallLocalFunction(dialogfunc, "");
	}
	else 
	{
		printf("[samp-detutils]: (dialog IID) - Invalid dialog : %s", name);
		return -1;
	}
	return 1;
}

stock HideDialogForPlayer(playerid)
{
	if(!strcmp(g_PlayerDialogCache[playerid][Dialog], "NO_DIALOG"))
	{
		printf("[samp-detutils]: (dialog error) - Unable to hide a dialog 'NO_DIALOG'.");
		return 0;
	}
	CallLocalFunction("OnPlayerDialogHide", "is", playerid, g_PlayerDialogCache[playerid][Dialog]);
	strmid(g_PlayerDialogCache[playerid][Dialog], "NO_DIALOG", 0, 32);
	ShowPlayerDialog(playerid, -1, 1, @DETUTILSSTRING_NULL__4);
	return 1;
}

stock GetPlayerDialog(playerid)
{
	new dialog[32];

	strmid(dialog, g_PlayerDialogCache[playerid][Dialog], 0, 32);

	if(!strcmp(g_PlayerDialogCache[playerid][Dialog], "NO_DIALOG", false))
	{
		return 0;
	}

	return dialog;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case DETUTILS_INTERNAL_DIALOG:
		{
			#if defined detutils_debug
			printf("[samp-detutils]: (debug) - Processing the dialog...");
			#endif
			//new dialog[32];
			//format(dialog, sizeof dialog, "%s", g_PlayerDialogCache[playerid][Dialog]);
			#if defined detutils_debug
			printf("[samp-detutils]: (debug) - Dialog name : %s", 
				g_PlayerDialogCache[playerid][Dialog]);
			#endif
			/*if(inputtext[0] != EOS) 
			{
				CallLocalFunction("OnPlayerDialogResponse", "isiis", 
				playerid, g_PlayerDialogCache[playerid][Dialog],
				response, listitem, inputtext);
			}
			else
			{
				CallLocalFunction("OnPlayerDialogResponse", "isiis", 
				playerid, g_PlayerDialogCache[playerid][Dialog],
				response, listitem, "emptystring");
			}*/
			#if defined OnPlayerDialogResponse
				OnPlayerDialogResponse(playerid, g_PlayerDialogCache[playerid][Dialog],
				response, listitem, inputtext);
			#endif	
			#if defined detutils_debug
			printf("[samp-detutils]: (debug) - Called the dialog response function with args: \
				playerid : %i | dialog : %s | response : %i | listitem : %i | inputtext : %s",
				playerid, g_PlayerDialogCache[playerid][Dialog], response, listitem, inputtext);
			#endif
			//                                             012345678
			strmid(g_PlayerDialogCache[playerid][Dialog], "NO_DIALOG", 0, 8);
			#if defined detutils_debug
			printf("[samp-detutils]: (debug) - Processing the dialog finished; player's dialog set to '%s'",
				g_PlayerDialogCache[playerid][Dialog]);
			#endif
		}
	}
	if(funcidx("d_dlg_dresponse") != -1)
	{
		//CallLocalFunction("d_dlg_dresponse", "iiiis", playerid, dialogid, response, listitem, inputtext);
		#if defined detutils_debug
		printf("[samp-detutils]: (debug) - 'OnDialogResponse(..)' hooked.");
		#endif
		#if defined d_dlg_dresponse
		//#warning [samp-detutils]: (warning) - OnDialogResponse is deprecared.
		d_dlg_dresponse(playerid, dialogid, response, listitem, inputtext);
		#endif
	}
	return 1;
}

#if defined _ALS_OnDialogResponse
	#undef OnDialogResponse
#else
	#define _ALS_OnDialogResponse
#endif

#define OnDialogResponse d_dlg_dresponse

forward d_dlg_dresponse(playerid, dialogid, response, listitem, inputtext[]);

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
	for(new playerid; playerid < MAX_PLAYERS; playerid++)
	{
		strmid(g_PlayerDialogCache[playerid][Dialog], "NO_DIALOG", 0, 32);
	}

	#if defined detutils_debug
	SaveLogIntoFile("detutils_dialog.log", "[samp-detutils]: (debug) - Loading...");
	SaveLogIntoFile("detutils_dialog.log", "[samp-detutils]: (debug) - Loaded.");
	#endif
	LoadDETUtilsScript(DETUTILS_SCRIPT_DIALOG);
	if(funcidx("d_dlg_detutilsinit") != -1)
	{
		CallLocalFunction("d_dlg_detutilsinit", "");
	}
	return 1;
}

#if defined _ALS_OnDETUtilsInit
	#undef OnDETUtilsInit
#else
	#define _ALS_OnDETUtilsInit
#endif

#define OnDETUtilsInit( d_dlg_detutilsinit(

forward d_dlg_detutilsinit();