/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - New foreach loop.
 *
 *
 */

#include "d_foreach_macros"

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

#if defined __DETUTILS_DEFAULT_ITERATORS
#if !defined MAX_DIALOGS

	#define MAX_DIALOGS 37000

#endif

// SA:MP iteratorators.
iterator new Player<MAX_PLAYERS>;
iterator new NPC<MAX_PLAYERS>;

public OnPlayerConnect(playerid)
{
	iterator add(Player, playerid);
	if(IsPlayerNPC(playerid))
	{
		iterator remove(Player, playerid);
		iterator add(NPC, playerid);
	}
	if(funcidx("d_fr_playerconnect") != -1)
	{
		CallLocalFunction("d_fr_playerconnect", "i", playerid);
	}
	return 1;
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect( d_fr_playerconnect(

forward d_fr_playerconnect(playerid);

public OnPlayerDisconnect(playerid, reason)
{
	if(!IsPlayerNPC(playerid)) iterator remove(Player, playerid);
	if(IsPlayerNPC(playerid)) iterator remove(NPC, playerid);
	if(funcidx("d_fr_playerdisconnect") != -1)
	{
		CallLocalFunction("d_fr_playerdisconnect", "ii", playerid, reason);
	}
	return 1;
}

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect( d_fr_playerdisconnect(

forward d_fr_playerdisconnect(playerid, reason);

iterator new Vehicle<MAX_VEHICLES>;
iterator new PlayerTextDraw<_:MAX_PLAYER_TEXT_DRAWS>;
iterator new TextDraw<_:MAX_TEXT_DRAWS>;
iterator new Object<MAX_OBJECTS>;
iterator new Menu<_:MAX_MENUS>;
iterator new Pickup<MAX_PICKUPS>;
iterator new Dialog<MAX_DIALOGS>;
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

public OnDETUtilsInit()
{
	#if defined __DETUTILS_DEFAULT_ITERATORS
	// Iterator initialisation is IMPORTANT.
	iterator init(Player);
	iterator init(NPC);
	iterator init(Vehicle);
	iterator init(PlayerTextDraw);
	iterator init(TextDraw);
	iterator init(Object);
	iterator init(Menu);
	iterator init(Pickup);
	iterator init(Dialog);
	#endif

	#if defined DETUTILS_DEBUG_MODE
	SaveLogIntoFile("detutils_foreach.log", "[DETUtils]: (debug) - Loading...");
	SaveLogIntoFile("detutils_foreach.log", "[DETUtils]: (debug) - Loaded.");
	#endif
	LoadDETUtilsScript(DETUTILS_SCRIPT_FOREACH);
	if(funcidx("d_fr_detutilsinit") != -1)
	{
		CallLocalFunction("d_fr_detutilsinit", "");
	}
	return 1;
}

#if defined _ALS_OnDETUtilsInit
	#undef OnDETUtilsInit
#else
	#define _ALS_OnDETUtilsInit
#endif

#define OnDETUtilsInit( d_fr_detutilsinit(

forward d_fr_detutilsinit();