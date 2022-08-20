/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library core file.
 *   
 *
 *
 */

#include "d_rem"

// The rest of shit

#define @DETUTILSCORE_KWORD__@%0\32; @DETUTILSCORE_KWORD__@
#define det @DETUTILSCORE_KWORD__@

#define DET_g_%0\32; DET_g_
#define __DETUTILS_ARRAY..%0,%1,%2; new DET_g_%0[%1][%2];

//#define @DETUTILSCORE_KWORD__@global%0; DET_g_%0;

#if defined A_INTS_COMPATIBILITY_MODE || defined A_CMDS_COMPATIBILITY_MODE

	#define DETUTILS_COMPATIBILITY_MODE

#endif

#if defined DETUTILS_COMPATIBILITY_MODE || defined detutils_complete_error_boom

	#error [DETUtils]: (fatal error) - crl :: Stop messing with the core libraries!

#endif

//Undefine this anyways:
#if defined DETUTILS_COMPATIBILITY_MODE
#undef DETUTILS_COMPATIBILITY_MODE
#endif

#if !defined DETUTILS_NO_COMPILEFIX

	#include "d_compilefix" // Add compile options

#endif//#include "d_funcgen"
#include "d_thirdpartyinclude" //_INC_code_parse_inc

#if !defined __PawnBuild

	#error [DETUtils]: (fatal error) - DETUtils require community Pawn compiler. Get it from: github.com/pawn-lang/compiler

#endif

#if defined d_extra_included
	#endinput
#endif

#define d_extra_included

#include "d_init.inc"

#if defined detutils_debug

	#pragma warning disable 231

#endif

/*
												
88888888ba,                                     
88      `"8b                 ,d                 
88        `8b                88                 
88         88  ,adPPYYba,  MM88MMM  ,adPPYYba,  
88         88  ""     `Y8    88     ""     `Y8  
88         8P  ,adPPPPP88    88     ,adPPPPP88  
88      .a8P   88,    ,88    88,    88,    ,88  
88888888Y"'    `"8bbdP"Y8    "Y888  `"8bbdP"Y8  
												
*/

#define COLOUR_GREY "{B9C9BF}"

stock d_SendWarningMessage(playerid, const string[])
{
	new message[300];
	format(message, 300, ""COLOUR_GREY"Warning: [DETUtils]: (debug) - %s", string);
	return SendClientMessage(playerid, -1, message);
}

#define detutils_visual_TRUE

#define until(%0)%8\10;%9 while( !( %0 ))%8

stock _RemID;

#define rem:<%0>; _RemID++; printf("[DETUtils]: (rem) - Rem called. ID: %i", _RemID);

#define MAX_INTERIORS 300

#define MAX_FUNC_NAME (32)

////////////////////////////////////////////////////////////////////

#define @new_%0\32; @new_

#define DETUTILS_DECL__ @new_

#define @new_func:%0(%1) DETUTILS@%0(%1); public DETUTILS@%0(%1)
#define @new_var:%0<%1> stock %1DETUTILS@%0

#if defined DETUTILS_COMPAT

#define @newk_%0\32; @newk_

#define DETUTILS @newk_

#endif
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

new PlayerText:g_AnnouncementString[MAX_PLAYERS];
new Text:g_AnnouncementUsebox;

stock _CallFunction(const func[], const spec[], id)
{
	new funcname[100];
	format(funcname, 100, "DETUTILS@%s", func);
	return CallLocalFunction(funcname, spec, id);
}

stock _SetTimer(const func[], delay, bool:a, const spec[], id)
{
	new funcname[100];
	format(funcname, 100, "DETUTILS@%s", func);
	return SetTimerEx(funcname, delay, a, spec, id);
}

#if !defined OnPlayerCommandReceived

	forward OnPlayerCommandReceived(playerid, cmdtext[]);

#endif

#if !defined OnPlayerCommandPerformed

	forward OnPlayerCommandPerformed(playerid, cmdtext[], success);

#endif

stock _Functionid;

stock _GlobalFileName[MAX_PLAYERS][MAX_PLAYER_NAME];

#define _FormatPlayerDatabaseFileName(%0) \
	format(_GlobalFileName[%0],MAX_PLAYER_NAME,"%s.ini",ReturnPlayerName(%0))

new const _g_Script = 0;

static _g_Client[MAX_PLAYERS];

#if !defined DETUTILS_NO_ANDROID_CHECK

#if !defined SendClientCheck

	native SendClientCheck(playerid, type, memAddr, memOffset, byteCount);

#endif


#if defined OnPlayerClientCheckReceived

	forward OnPlayerClientCheckReceived(playerid);

#endif

public OnPlayerConnect(playerid)
{
	_g_Client[playerid] = 0;
	SendClientCheck(playerid, 0x48, 0, 0, 2);
	if(funcidx("OnPlayerClientCheckReceived") != -1)
	{
		CallLocalFunction("OnPlayerClientCheckReceived", "i", playerid);
	}
	if(funcidx("a_lib_OnPlayerConnect") != -1)
	{
		#if defined a_lib_OnPlayerConnect
		a_lib_OnPlayerConnect(playerid);
		#endif
	}
	return 1;
}

forward OnClientCheckResponse(playerid, actionid, memaddr, retndata);

public OnClientCheckResponse(playerid, actionid, memaddr, retndata)
{
	if(actionid == 0x48)
	{
		_g_Client[playerid] = 1;
	}
	if(funcidx("a_lib_OnClientCheckResponse") != -1)
	{
		CallLocalFunction("a_lib_OnClientCheckResponse", "iiii", playerid, actionid, memaddr, retndata);
	}
	return 1;
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect a_lib_OnPlayerConnect

forward a_lib_OnPlayerConnect(playerid);

#if defined _ALS_OnClientCheckResponse
	#undef OnClientCheckResponse
#else
	#define _ALS_OnClientCheckResponse
#endif

#define OnClientCheckResponse a_lib_OnClientCheckResponse

forward a_lib_OnClientCheckResponse(playerid, actionid, memaddr, retndata);

stock bool:IsPlayerUsingPCClient(playerid)
{
	if(_g_Client[playerid] == 1) return true;
	return false;
}

stock bool:IsPlayerUsingAndroidClient(playerid)
{
	if(_g_Client[playerid] == 0) return true;
	return false;
}

#endif

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

#if defined DETUTILS_NO_DIALOG

stock HidePlayerDialog(playerid)
{
	ShowPlayerDialog(playerid, -1, 1, @DETUTILSSTRING_NULL__4);
	return 1;
}

#endif

new bool:g_PlayerPedAnims = false;

stock d_lib_UsePlayerPedAnims()
{
	g_PlayerPedAnims = true;
	return UsePlayerPedAnims();
}

stock bool:ArePlayerPedAnimsUsed()
{
	return g_PlayerPedAnims;
}

#if defined _ALS_UsePlayerPedAnims
	#undef UsePlayerPedAnims
#else
	#define _ALS_UsePlayerPedAnims
#endif

#define UsePlayerPedAnims d_lib_UsePlayerPedAnims

stock _ReturnPlayerName(id) 
{
	new _PlayerName[ MAX_PLAYER_NAME ];
	
	GetPlayerName( id, _PlayerName, sizeof _PlayerName);
	return _PlayerName;
}

new _g_Shifthour, _g_Timeshift = 0;

static stock _FixHourData(_f_Hour)
{
	_f_Hour = _g_Timeshift+_f_Hour;

	if(_f_Hour < 0)
	{
		_f_Hour = _f_Hour+24;
	}
	else if(_f_Hour > 23)
	{
		_f_Hour = _f_Hour-24;
	}
	_g_Shifthour = _f_Hour;
	return 1;
}

stock void:SaveLogIntoFile( const _FileName[], const _Log[]) 
{
	new _Entry[ 128 ], 
		_sec, 
		_minutes, 
		_data, 
		_day, 
		_year, 
		_month;

	getdate( _year, _month, _day );

	gettime( _sec, _minutes, _data );

	_FixHourData( _sec );

	_sec = _g_Shifthour;
	
	format( _Entry, sizeof( _Entry ), 
		"%d/%d/%d | %d/%d/%d | %s\r\n", 
		_day, _month, _year, 
		_sec, _minutes, _data, _Log );

	new File:_File;
	_File = fopen( _FileName, io_append );

	fwrite( _File, _Entry );

	fclose( _File );
}

stock void:_SetTag( const _FileName[], const _TagName[] )
{
	SaveLogIntoFile(_FileName,_TagName);
}

stock strtok(const string[], &index, delimiter = ' ') {
	new length = strlen(string);
	while ((index < length) && (string[index] <= delimiter)) {
		index++;
	}
	new offset = index;
	new result[128];
	while ((index < length) && (string[index] > delimiter) && ((index - offset) < (sizeof(result) - 1))) {
		result[index - offset] = string[index];
		index++;
	}
	result[index - offset] = EOS;
	return result;
}

stock strrest(const string[], &index)
{
	new length = strlen(string);
	while ((index < length) && (string[index] <= ' '))
	{
		index++;
	}
	new offset = index;
	new result[128];
	while ((index < length) && ((index - offset) < (sizeof(result) - 1)))
	{
		result[index - offset] = string[index];
		index++;
	}
	result[index - offset] = EOS;
	return result;
}