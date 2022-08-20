/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which provides creating
 *   of property entrances and exits,
 *   and interiors.
 *
 *
 */

#define DisableDefaultProperties DisableInteriorEnterExits

#if !defined MAX_PROPERTIES

#define MAX_PROPERTIES 300

#endif

enum enum_PropertyData
{
	ValidProp,
	p_PropertyName[32],

	Float:p_PropertyEntrance_X,
	Float:p_PropertyEntrance_Y,
	Float:p_PropertyEntrance_Z,
	Float:p_PropertyEntrance_A,

	Float:p_PropertyExit_X,
	Float:p_PropertyExit_Y,
	Float:p_PropertyExit_Z,
	Float:p_PropertyExit_A,

	p_PropertyIntid,
	p_PropertyIntid_OUT,
	p_PropertyVwid,
	p_PropertyVwid_OUT,

	p_PropertyPickup,
	p_PropertyPickupID,
	Text3D:p_PropertyLabel,
	Text3D:p_PropertyLabelID,

	p_PropertyLocked
	#if !defined DETUTILS_NO_TEAMS
	,p_PropertyTeam,
	p_PropTeam[32]
	#endif
};

forward OnPropertyCreate(propertyid);
forward OnPropertyDestroy(propertyid);
forward OnPlayerEnterProperty(playerid);
forward OnPlayerExitProperty(playerid);

new g_PlayerProperty[MAX_PLAYERS];

new g_PropertyData[MAX_PROPERTIES][enum_PropertyData];

new DET_g_CreatedProperties;

new _EntranceTitleShown[MAX_PLAYERS];

// Interior IDs:

#define DETUTILS_PROP_PARAMS__(%0,%1,%2,%3); \
	g_PropertyData[g_PropertyID][p_PropertyIntid] = %3;g_PropertyData[g_PropertyID][p_PropertyVwid] = %3;_eInteriorid = %3; _eVirtualWorldid = %3;g_PropertyData[g_PropertyID][p_PropertyExit_X] = %0;g_PropertyData[g_PropertyID][p_PropertyExit_Y] = %1;g_PropertyData[g_PropertyID][p_PropertyExit_Z] = %3;

#define INTERIOR_CUSTOM         -1
#define INTERIOR_MARKET_247_1    0
#define INTERIOR_MARKET_247_2    1
#define INTERIOR_MARKET_247_3    2
#define INTERIOR_MARKET_247_4    3
#define INTERIOR_MARKET_247_5    4
#define INTERIOR_MARKET_247_6    5

/*

															  
88        88                            88                    
88        88                            88                    
88        88                            88                    
88aaaaaaaa88   ,adPPYba,    ,adPPYba,   88   ,d8   ,adPPYba,  
88""""""""88  a8"     "8a  a8"     "8a  88 ,a8"    I8[    ""  
88        88  8b       d8  8b       d8  8888[       `"Y8ba,   
88        88  "8a,   ,a8"  "8a,   ,a8"  88`"Yba,   aa    ]8I  
88        88   `"YbbdP"'    `"YbbdP"'   88   `Y8a  `"YbbdP"'  
															  
															  

*/

#define int_%0\32; int_

#define PROPERTY_ACTION_ENTER 0
#define PROPERTY_ACTION_EXIT 1
#define PROPERTY_ACTION_LOCK 2
#define PROPERTY_ACTION_UNLOCK 3

static void:_PropertyLoadingTime(const playerid)
{
	#if defined DETUTILS_DEBUG_MODE
	printf("[DETUtils]: (debug) - tpcll :: Player ( id : %i ) is now controlable.", playerid);
	#endif
	SetTimerEx("_ToggleControllable", 1000, false, "i", playerid);
}

static g_HideAnnouncement[MAX_PLAYERS];

static _Announcement(playerid, const _Message[])
{
	new c_Message[300];

	KillTimer(g_HideAnnouncement[playerid]);

	format(c_Message,300,"%s",_Message);

	TextDrawShowForPlayer(playerid, g_AnnouncementUsebox);

	PlayerTextDrawSetString( playerid, g_AnnouncementString[ playerid ], c_Message );

	PlayerTextDrawShow(playerid,g_AnnouncementString[ playerid ]);

	g_HideAnnouncement[playerid] = _SetTimer("hideannc", 4000, false, "i", playerid);
	return 1;
}

DETUTILS_DECL__ func:hideannc(playerid)
{
	TextDrawHideForPlayer(playerid, g_AnnouncementUsebox);
	PlayerTextDrawHide(playerid, g_AnnouncementString[playerid]);
	KillTimer(g_HideAnnouncement[playerid]);
	return 1;
}

static _CreateAnncTextDraws()
{
	g_AnnouncementUsebox = TextDrawCreate(366.444427, 363.882232, "usebox");
	TextDrawLetterSize(g_AnnouncementUsebox, 0.000000, 1.840366);
	TextDrawTextSize(g_AnnouncementUsebox, 267.333312, 0.000000);
	TextDrawAlignment(g_AnnouncementUsebox, 1);
	TextDrawColor(g_AnnouncementUsebox, 0);
	TextDrawUseBox(g_AnnouncementUsebox, true);

	TextDrawBoxColor(g_AnnouncementUsebox, 102);
	TextDrawSetShadow(g_AnnouncementUsebox, 0);
	TextDrawSetOutline(g_AnnouncementUsebox, 0);
	TextDrawFont(g_AnnouncementUsebox, 0);
	return 1;
}

//#define STRING "string" // for some reasons this exists

static _CreatePlayerTextDraws(playerid)
{
	g_AnnouncementString[playerid] = CreatePlayerTextDraw(playerid, 315.111145, 364.373321, "string");
	PlayerTextDrawLetterSize(playerid, g_AnnouncementString[playerid], 0.201111, 1.346133);

	PlayerTextDrawAlignment(playerid, g_AnnouncementString[playerid], 2);
	PlayerTextDrawColor(playerid, g_AnnouncementString[playerid], -1);
	PlayerTextDrawSetShadow(playerid, g_AnnouncementString[playerid], 0);

	PlayerTextDrawSetOutline(playerid, g_AnnouncementString[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, g_AnnouncementString[playerid], 51);
	PlayerTextDrawFont(playerid, g_AnnouncementString[playerid], 2);
	PlayerTextDrawSetProportional(playerid, g_AnnouncementString[playerid], 1);
	return 1;
}

forward _ToggleControllable(i);

public _ToggleControllable(i)
{
	//for(new i; i < MAX_PLAYERS; i++)
	//{
		TogglePlayerControllable(i, true);
	//}
	//rem:<This is used to prevent player being frozen for several minutes>;
	return 1;
}

#if !defined FILTERSCRIPT
/*
public OnGameModeInit()
{
	_CreateAnncTextDraws();
	
	if(funcidx("a_props_OnGameModeInit") != -1)
	{
		CallLocalFunction("a_props_OnGameModeInit", "");
	}
	return 1;
}

#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif

#define OnGameModeInit a_props_OnGameModeInit

forward a_props_OnGameModeInit();
*/
#endif

public OnPlayerConnect(playerid)
{
	_CreatePlayerTextDraws(playerid);
	if(funcidx("a_props_OnPlayerConnect") != -1)
	{
		CallLocalFunction("a_props_OnPlayerConnect", "i", playerid);
	}
	return 1;
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect a_props_OnPlayerConnect

forward a_props_OnPlayerConnect(playerid);

public OnPlayerSpawn(playerid)
{
	TextDrawHideForPlayer(playerid, g_AnnouncementUsebox);
	PlayerTextDrawHide(playerid, g_AnnouncementString[playerid]);
	if(funcidx("a_props_OnplayerSpawn") != -1)
	{
		CallLocalFunction("a_props_OnplayerSpawn", "i", playerid);
	}
	return 1;
}

#if defined _ALS_OnPlayerSpawn
	#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif

#define OnPlayerSpawn a_props_OnplayerSpawn

forward a_props_OnplayerSpawn(playerid);

_OnPlayerNearEntrance(playerid);

#if !defined DETUTILS_NO_TEAMS

#define MAX_TEAMS 256

enum enum_TeamData
{
	ValidTeam,
	TeamName[32],
	TeamMembers
}

new g_TeamCache[MAX_TEAMS][enum_TeamData];

enum enum_PlayerTeamData
{
	Team[32]
}

new g_PlayerTeamCache[MAX_PLAYERS][enum_PlayerTeamData];

#endif

public _OnPlayerNearEntrance(playerid)
{
	//new PropertyFuncName[100];
	new PropertyActionID;
	
	for(new i; i < MAX_PROPERTIES; i++)
	{
		if( IsPlayerInRangeOfPoint( playerid, 1.5, g_PropertyData[ i ][p_PropertyEntrance_X], \
		g_PropertyData[ i ][p_PropertyEntrance_Y], g_PropertyData[ i ][p_PropertyEntrance_Z]) \
		&& GetPlayerVirtualWorld( playerid ) == g_PropertyData[ i ][p_PropertyVwid_OUT] \
		&& !IsPlayerInAnyVehicle( playerid ))
		{
			#if !defined DETUTILS_NO_TEAMS
				
				if(g_PropertyData[i][p_PropertyTeam] == 1)
				{
					if(strcmp(g_PlayerTeamCache[playerid][Team], g_PropertyData[i][p_PropTeam]))
					{
						return SendClientMessage(playerid, -1, DETUTILS_TEXT_TEAMPROP_LOCK);
					}
				}
			
			#endif
			if(g_PropertyData[i][p_PropertyLocked] == 1)
			{
				return SendClientMessage(playerid, -1, DETUTILS_TEXT_PROP_LOCK);
			}

			PropertyActionID = 0;
			/*format(PropertyFuncName,sizeof(PropertyFuncName),
				"OnPropertyActionPerformed",g_PropertyData[ i ][p_PropertyName]);*/

			if(funcidx("OnPropertyActionPerformed") != -1) CallLocalFunction("OnPropertyActionPerformed",
																"iii",playerid,i,PropertyActionID);

			SetPlayerInterior( playerid, g_PropertyData[ i ][p_PropertyIntid] );
			SetPlayerVirtualWorld( playerid, g_PropertyData[ i ][p_PropertyVwid] );
			
			#if defined DETUTILS_NO_ANTICHEAT
			SetPlayerPos
			#else
			d_ac_SetPlayerPos
			#endif
			( playerid, g_PropertyData[ i ][p_PropertyExit_X], g_PropertyData[ i ][p_PropertyExit_Y], \
			g_PropertyData[ i ][p_PropertyExit_Z] );
			
			SetPlayerFacingAngle( playerid, g_PropertyData[ i ][p_PropertyExit_A] );
			SetCameraBehindPlayer( playerid );
			
			#if defined DETUTILS_DEBUG_MODE
			printf("[DETUtils]: (debug) - nearintcallback :: Player entered the interior with id : %i.", i);
			#endif

			TogglePlayerControllable(playerid,false);

			SetPlayerTime( playerid, 12, 0 );
			_PropertyLoadingTime(playerid);
			
			g_PlayerProperty[ playerid ] = i;
			
			if(funcidx("OnPlayerEnterProperty") != -1)
				CallLocalFunction("OnPlayerEnterProperty", "i", playerid);
			
		}
		else if( IsPlayerInRangeOfPoint( playerid, 1.5, g_PropertyData[ i ][p_PropertyExit_X], \
		g_PropertyData[ i ][p_PropertyExit_Y], g_PropertyData[ i ][p_PropertyExit_Z]) && \
		GetPlayerVirtualWorld( playerid ) == g_PropertyData[ i ][p_PropertyVwid])
		{
			#if !defined DETUTILS_NO_TEAMS
				
				if(g_PropertyData[i][p_PropertyTeam] == 1)
				{
					if(strcmp(g_PlayerTeamCache[playerid][Team], g_PropertyData[i][p_PropTeam]))
					{
						return SendClientMessage(playerid, -1, DETUTILS_TEXT_TEAMPROP_LOCK);
					}
				}
			
			#endif
			if(g_PropertyData[i][p_PropertyLocked] == 1)
			{
				return SendClientMessage(playerid, -1, DETUTILS_TEXT_PROP_LOCK);
			}

			SetPlayerVirtualWorld( playerid, g_PropertyData[ i ][p_PropertyVwid_OUT] );
			SetPlayerInterior( playerid, g_PropertyData[ i ][p_PropertyIntid_OUT] );
			
			#if defined DETUTILS_NO_ANTICHEAT
			SetPlayerPos
			#else
			d_ac_SetPlayerPos
			#endif
			( playerid, g_PropertyData[ i ][p_PropertyEntrance_X], g_PropertyData[ i ][p_PropertyEntrance_Y], \
			g_PropertyData[ i ][p_PropertyEntrance_Z] );
			
			SetPlayerFacingAngle( playerid, g_PropertyData[ i ][p_PropertyEntrance_A] );
			SetCameraBehindPlayer( playerid );

			TogglePlayerControllable(playerid,false);

			_PropertyLoadingTime(playerid);

			#if defined DETUTILS_DEBUG_MODE
			printf("[DETUtils]: (debug) - nearintcallback :: Player exited the interior with id : %i.", i);
			#endif

			PropertyActionID = 1;
			/*format(PropertyFuncName,sizeof(PropertyFuncName),
				"OnPropertyActionPerformed",g_PropertyData[ i ][p_PropertyName]);*/

			if(funcidx("OnPropertyActionPerformed") != -1) CallLocalFunction("OnPropertyActionPerformed","iii",playerid,i,PropertyActionID);

			g_PlayerProperty[ playerid ] = -1;
			
			if(funcidx("OnPlayerExitProperty") != -1)
				CallLocalFunction("OnPlayerExitProperty", "i", playerid);
		}
	}
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	ClearPlayerPropertyData(playerid);
	if(funcidx("aint_ALS_OnPlayerDisconnect") != -1)
	{
		CallLocalFunction("aint_ALS_OnPlayerDisconnect", "ii", playerid, reason);
	}
	#if defined DETUTILS_DEBUG_MODE
	printf("[DETUtils]: (debug) - playerdiscc :: Player interior data cleared.");
	#endif
	return 1;
}

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect aint_ALS_OnPlayerDisconnect

forward aint_ALS_OnPlayerDisconnect(playerid, reason);

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if( newkeys == KEY_SECONDARY_ATTACK)
	{
		if(GetPlayerState(playerid) == 1)
		{
			_OnPlayerNearEntrance(playerid);
			#if defined DETUTILS_DEBUG_MODE
			printf("[DETUtils]: (debug) - keystate :: OnPlayerNearEntrance called successfully.");
			#endif
		}

		if( GetPlayerSpecialAction(playerid ) != SPECIAL_ACTION_NONE && \
		GetPlayerSpecialAction(playerid ) != SPECIAL_ACTION_CUFFED)
		{
			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		}
	}
	if(funcidx("aint_ALS_OnPlayerKeyStateChange") != -1)
	{
		CallLocalFunction("aint_ALS_OnPlayerKeyStateChange", "iii", playerid, newkeys, oldkeys);
	}
	return 1;
}

#if defined _ALS_OnPlayerKeyStateChange
	#undef OnPlayerKeyStateChange
#else
	#define _ALS_OnPlayerKeyStateChange
#endif

#define OnPlayerKeyStateChange aint_ALS_OnPlayerKeyStateChange

forward aint_ALS_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);

DETUTILS_DECL__ func:ResetUpdateBool(playerid)
{
	#if defined DETUTILS_DEBUG_MODE
	printf("[DETUtils]: (debug) - keystate :: util function 'ResetUpdateBool' called successfully.");
	#endif

	_EntranceTitleShown[playerid] = 0;
	return 1;
}

public OnPlayerUpdate(playerid)
{
	for(new i; i < MAX_PROPERTIES; i++)
	{
		if( IsPlayerInRangeOfPoint( playerid, 1.5, g_PropertyData[ i ][p_PropertyEntrance_X], \
		g_PropertyData[ i ][p_PropertyEntrance_Y], g_PropertyData[ i ][p_PropertyEntrance_Z]) \
		&& GetPlayerVirtualWorld( playerid ) == g_PropertyData[ i ][p_PropertyVwid_OUT] \
		&& !IsPlayerInAnyVehicle( playerid ) && _EntranceTitleShown[playerid] != 1)
		{
			new PropertyName[100];
			format(PropertyName,sizeof(PropertyName),DETUTILS_TEXT_PROPERTY_NAME,g_PropertyData[ i ][ p_PropertyName ]);
			
			_Announcement(playerid, PropertyName);
			#if defined DETUTILS_DEBUG_MODE
			printf("[DETUtils]: (debug) - playerupdate :: Gametext shown.");
			#endif
			_EntranceTitleShown[playerid] = 1;
			_SetTimer("ResetUpdateBool", 10000, false, "i", playerid);
		}
	}
	if(funcidx("a_props_playerupdate") != -1)
	{
		CallLocalFunction("a_props_playerupdate", "i", playerid);
	}
	return 1;
}

#if defined _ALS_OnPlayerUpdate
	#undef OnPlayerUpdate
#else
	#define _ALS_OnPlayerUpdate
#endif

#define OnPlayerUpdate a_props_playerupdate

forward a_props_playerupdate(playerid);

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

stock __Create3DLabelAndPickup( // Internal function.
		const _LabelString[], 
		Float:_xPosition, 
		Float:_yPosition, 
		Float:_zPosition,  
		_VirtualWorld, 
		_Pickupid, 
		Float:_LabelRadius, 
		Text3D:label,
		pickup ) 
{
	#pragma unused label
	#pragma unused pickup
	#if defined DETUTILS_DEBUG_MODE
	printf("[DETUtils]: (debug) - c3dladp :: String checking finished.");
	#endif

	if(_VirtualWorld < 0)
		return 0;

	#if defined DETUTILS_DEBUG_MODE
	printf("[DETUtils]: (debug) - c3dladp :: Virtual world validity checked.");
	#endif

	if(_LabelRadius <= 0)
		return 0;

	#if defined DETUTILS_DEBUG_MODE
	printf("[DETUtils]: (debug) - c3dladp :: Label visibility radius check finished.");
	#endif

	if(_Pickupid < 0)
		return 0;

	#if defined DETUTILS_DEBUG_MODE
	printf("[DETUtils]: (debug) - c3dladp :: Pickup id validity checked.");
	#endif
	#if !defined _DETUTILS_NO_COMMUNITY_COMPILER
	label = Create3DTextLabel(
							_LabelString, 
							0xffffffff, 
							_xPosition, 
							_yPosition, 
							_zPosition, 
							_LabelRadius, 
							_VirtualWorld);

	#if defined DETUTILS_DEBUG_MODE
	printf("[DETUtils]: (debug) - c3dladp :: Created 3d label successfully.");
	#endif

	pickup = CreatePickup(
					_Pickupid, 
					1, 
					_xPosition, 
					_yPosition, 
					_zPosition, 
					_VirtualWorld);

	#if defined DETUTILS_DEBUG_MODE
	printf("[DETUtils]: (debug) - c3dladp :: Created dynamic pickup successfully.");
	#endif
	#endif
	#if !defined _DETUTILS_NO_COMMUNITY_COMPILER
	#if defined DETUTILS_DEBUG_MODE
	printf("[DETUtils]: (debug) - Operation completed successfully. Error code: ERRNULL");
	#endif
	#else
	#if defined DETUTILS_DEBUG_MODE
	printf("[DETUtils]: (debug) - Operation completed. Error code: COMPILER_INVALID");
	#endif
	#endif
	return 1;
}

stock CreatePropertyEntrance(
		const PropertyName[], 
		Float:_xEntrance, 
		Float:_yEntrance, 
		Float:_zEntrance,  
		_xInteriorid,  
		_xVirtualWorldid,
		bool:Labels = false,
		Interior = INTERIOR_CUSTOM,
		Float:_xExit = 0.000, 
		Float:_yExit = 0.000, 
		Float:_zExit = 0.000, 
		_eInteriorid = 0,
		_eVirtualWorldid = 0)
{
	for(new g_PropertyID = 1; 
		g_PropertyID < MAX_PROPERTIES; 
		g_PropertyID++)
		{
			if(g_PropertyData[g_PropertyID][ValidProp] == 0)
			{
				printf("[DETUtils]: (debug) - Property '%s' successfully created, entrance is set to: %f, %f, %f.",
						PropertyName,
						Float:_xEntrance, 
						Float:_yEntrance, 
						Float:_zEntrance);
				#if defined DETUTILS_DEBUG_MODE
				printf("[DETUtils]: (debug) - Property created.");
				#endif

				//g_PropertyID++;

				#if defined DETUTILS_DEBUG_MODE
				printf("[DETUtils]: (debug) - Property id assigned.");
				#endif

				strmid(g_PropertyData[g_PropertyID][p_PropertyName], 
						PropertyName, 
						0, 
						strlen(PropertyName), 
						255);

				#if defined DETUTILS_DEBUG_MODE
				printf("[DETUtils]: (debug) - Saved property name.");
				#endif

				printf("[DETUtils]: (debug) - Property '%s' has an id %d.",PropertyName,g_PropertyID);

				g_PropertyData[g_PropertyID][p_PropertyEntrance_X] = _xEntrance;
				g_PropertyData[g_PropertyID][p_PropertyEntrance_Y] = _yEntrance;
				g_PropertyData[g_PropertyID][p_PropertyEntrance_Z] = _zEntrance;

				#if defined DETUTILS_DEBUG_MODE
				printf("[DETUtils]: (debug) - Entrance coordinates assigned to property data.");
				#endif

				g_PropertyData[g_PropertyID][p_PropertyExit_X] = _xExit;
				g_PropertyData[g_PropertyID][p_PropertyExit_Y] = _yExit;
				g_PropertyData[g_PropertyID][p_PropertyExit_Z] = _zExit;

				#if defined DETUTILS_DEBUG_MODE
				printf("[DETUtils]: (debug) - Exit coordinates assigned to property data.");
				#endif

				g_PropertyData[g_PropertyID][p_PropertyIntid] = _eInteriorid;
				g_PropertyData[g_PropertyID][p_PropertyIntid_OUT] = _xInteriorid;
				g_PropertyData[g_PropertyID][p_PropertyVwid] = _eVirtualWorldid;
				g_PropertyData[g_PropertyID][p_PropertyVwid_OUT] = _xVirtualWorldid;

				#if defined DETUTILS_DEBUG_MODE
				printf("[DETUtils]: (debug) - Virtual world IDs and interior IDs assigned to property data.");
				#endif

				if(Interior != INTERIOR_CUSTOM)
				{
					#if defined DETUTILS_DEBUG_MODE
					printf("[DETUtils]: (debug) - Assigned interior map id to property id : %i", Interior);
					#endif

					if(Interior == INTERIOR_MARKET_247_1)
					{
						g_PropertyData[g_PropertyID][p_PropertyIntid] = 17;
						g_PropertyData[g_PropertyID][p_PropertyVwid] = 17;
						_eInteriorid = 17;
						_eVirtualWorldid = 17;

						g_PropertyData[g_PropertyID][p_PropertyExit_X] = -25.884498;
						g_PropertyData[g_PropertyID][p_PropertyExit_Y] = -185.868988;
						g_PropertyData[g_PropertyID][p_PropertyExit_Z] = 1003.546875;
					}
					if(Interior == INTERIOR_MARKET_247_2)
					{
						DETUTILS_PROP_PARAMS__(6.091179,-29.271898,1003.549438,10);
					}
					if(Interior == INTERIOR_MARKET_247_3)
					{
						DETUTILS_PROP_PARAMS__(-30.946699,-89.609596,1003.546875,18);
					}
					if(Interior == INTERIOR_MARKET_247_4)
					{
						DETUTILS_PROP_PARAMS__(-25.132598,-139.066986,1003.546875,16);
					}
					if(Interior == INTERIOR_MARKET_247_5)
					{
						DETUTILS_PROP_PARAMS__(-27.312299,-29.277599,1003.557250,4);
					}
					if(Interior == INTERIOR_MARKET_247_6)
					{
						DETUTILS_PROP_PARAMS__(-26.691598,-55.714897,1003.546875,6);
					}
				}

				if(Labels == true)
				{
					new _EntranceLabelString[300];
					#if defined DETUTILS_DEBUG_MODE
					printf("[DETUtils]: (debug) - Empty string declared.");
					#endif
					format(_EntranceLabelString,sizeof(_EntranceLabelString),"{ffffff}[ %s ]\n{ffffff}Enter here!",PropertyName);
					#if defined DETUTILS_DEBUG_MODE
					printf("[DETUtils]: (debug) - Formatted the 3D label string successfully.");
					#endif
					__Create3DLabelAndPickup(_EntranceLabelString, _xEntrance,_yEntrance,_zEntrance, 
						_xVirtualWorldid, 19133, 3.0, 
						g_PropertyData[g_PropertyID][p_PropertyLabelID], 
						g_PropertyData[g_PropertyID][p_PropertyPickupID]);
					#if defined DETUTILS_DEBUG_MODE
					printf("[DETUtils]: (debug) - lab :: Created 3D label and pickup on entrance.");
					#endif
					__Create3DLabelAndPickup("Exit here!", g_PropertyData[g_PropertyID][p_PropertyExit_X],
						g_PropertyData[g_PropertyID][p_PropertyExit_Y], 
						g_PropertyData[g_PropertyID][p_PropertyExit_Z], 
						_eVirtualWorldid, 19133, 3.0,
						g_PropertyData[g_PropertyID][p_PropertyLabel], 
						g_PropertyData[g_PropertyID][p_PropertyPickup]);
					#if defined DETUTILS_DEBUG_MODE
					printf("[DETUtils]: (debug) - pick :: Created 3D label and pickup on exit.");
					#endif
				}

				#if defined DETUTILS_DEBUG_MODE
				printf("[DETUtils]: (debug) - Internal property data assigned.");
				#endif

				if(funcidx("OnPropertyCreate") != -1)
				{
					CallLocalFunction("OnPropertyCreate", "i", g_PropertyID);
				}

				#if defined DETUTILS_DEBUG_MODE
				printf("[DETUtils]: (debug) - OnPropertyCreate(propertyid) called.");
				#endif

				g_PropertyData[g_PropertyID][ValidProp] = 1;
				DET_g_CreatedProperties ++;
				break;
			}
			else
			{
				if(DET_g_CreatedProperties == MAX_PROPERTIES)
				{
					#if defined DETUTILS_DEBUG_MODE
					for(new i = 0; i < MAX_PLAYERS; i++)
					{
						if(i != INVALID_PLAYER_ID)
						{
							d_SendWarningMessage(i, DETUTILS_TEXT_MAX_PROPS_REACH);
						}
					}
					#endif
					return 0;
				}
			}
		}
	return 1;
}

stock DestroyPropertyEntrance(const name[])
{
	for(new i = 1; i < MAX_PROPERTIES; i++)
	{
		if(!strcmp(g_PropertyData[i][p_PropertyName], name, false))
		{
			CallLocalFunction("OnPropertyDestroy", "i", i);
			g_PropertyData[i][ValidProp] = 0;
			DET_g_CreatedProperties --;
			Delete3DTextLabel(g_PropertyData[i][p_PropertyLabelID]);
			Delete3DTextLabel(g_PropertyData[i][p_PropertyLabel]);
			DestroyPickup(g_PropertyData[i][p_PropertyPickupID]);
			DestroyPickup(g_PropertyData[i][p_PropertyPickup]);
			g_PropertyData[i][p_PropertyExit_X] = 0;
			g_PropertyData[i][p_PropertyExit_Y] = 0;
			g_PropertyData[i][p_PropertyExit_Z] = 0;
			g_PropertyData[i][p_PropertyEntrance_X] = 0;
			g_PropertyData[i][p_PropertyEntrance_Y] = 0;
			g_PropertyData[i][p_PropertyEntrance_Z] = 0;
			#if defined DETUTILS_DEBUG_MODE
			printf("[DETUtils]: (debug) - dpe :: Destroyed a property entrance ID : %i", i);
			#endif
			return 1;
		}
	}
	return 0;
}

// DELETED FUNCTION, MAKES NO SENSE.

#if defined detutils_complete_error_boom

stock CreateCustomInterior(
		const PropertyName[], 
		Float:_xEntrance, 
		Float:_yEntrance, 
		Float:_zEntrance, 
		Float:_xExit, 
		Float:_yExit, 
		Float:_zExit, 
		_eInteriorid, 
		_xInteriorid, 
		_eVirtualWorldid, 
		_xVirtualWorldid)
{
	if(g_PropertyID == MAX_PROPERTIES)
	{
		#if defined DETUTILS_DEBUG_MODE
		for(new i = 0; i < MAX_PLAYERS; i++)
		{
			if(i != INVALID_PLAYER_ID)
			{
				d_SendWarningMessage(i, "Maximum number of created interiors reached.");
			}
		}
		#endif
		return 0;
	}
	printf("[DETUtils]: (debug) - Interior '%s' successfully created, entrance is set to: %f, %f, %f.",
			PropertyName,
			Float:_xEntrance, 
			Float:_yEntrance, 
			Float:_zEntrance);

	#if defined DETUTILS_DEBUG_MODE
	printf("[DETUtils]: (debug) - Interior created.");
	#endif

	g_PropertyID++;

	strmid(g_PropertyData[g_PropertyID][p_PropertyName], 
			PropertyName, 
			0, 
			strlen(PropertyName), 
			255);

	#if defined DETUTILS_DEBUG_MODE
	printf("[DETUtils]: (debug) - Saved interior name.");
	#endif

	printf("[DETUtils]: (debug) - Interior '%s' has an id %d.",PropertyName,g_PropertyID);
	#if defined DETUTILS_DEBUG_MODE
	printf("[DETUtils]: (debug) - Interior id assigned.");
	#endif
	g_PropertyData[g_PropertyID][p_PropertyEntrance_X] = _xEntrance;
	g_PropertyData[g_PropertyID][p_PropertyEntrance_Y] = _yEntrance;
	g_PropertyData[g_PropertyID][p_PropertyEntrance_Z] = _zEntrance;

	#if defined DETUTILS_DEBUG_MODE
	printf("[DETUtils]: (debug) - Entrance coordinates assigned to interior data.");
	#endif

	g_PropertyData[g_PropertyID][p_PropertyExit_X] = _xExit;
	g_PropertyData[g_PropertyID][p_PropertyExit_Y] = _yExit;
	g_PropertyData[g_PropertyID][p_PropertyExit_Z] = _zExit;

	#if defined DETUTILS_DEBUG_MODE
	printf("[DETUtils]: (debug) - Exit coordinates assigned to interior data.");
	#endif

	g_PropertyData[g_PropertyID][p_PropertyIntid] = _eInteriorid;
	g_PropertyData[g_PropertyID][p_PropertyIntid_OUT] = _xInteriorid;
	g_PropertyData[g_PropertyID][p_PropertyVwid] = _eVirtualWorldid;
	g_PropertyData[g_PropertyID][p_PropertyVwid_OUT] = _xVirtualWorldid;

	#if defined DETUTILS_DEBUG_MODE
	printf("[DETUtils]: (debug) - Virtual world and interiorids assigned to custom interior.");
	#endif

	#if defined DETUTILS_DEBUG_MODE
	printf("[DETUtils]: (debug) - Internal interior data assigned.");
	#endif

	if(funcidx("OnPropertyCreate") != -1)
	{
		CallLocalFunction("OnPropertyCreate", "i", g_PropertyID);
	}

	#if defined DETUTILS_DEBUG_MODE
	printf("[DETUtils]: (debug) - OnPropertyCreate(customintid) called.");
	#endif

	return 1;
}

#endif

// NORMAL CODE, MAKES SENSE:

stock IsPropertyLocked(propertyid)
{
	if(g_PropertyData[propertyid][p_PropertyLocked] == 1)
	{
		return 1;
	}
	else if(g_PropertyData[propertyid][p_PropertyLocked] == 0)
	{
		return 0;
	}
	return -1;
}

stock void:TogglePropertyLocked(propertyid, bool:lock)
{
	if(lock == true)
	{
		if(funcidx("OnPropertyActionPerformed") != -1) 
			CallLocalFunction("OnPropertyActionPerformed",
			"iii",INVALID_PLAYER_ID,propertyid,PROPERTY_ACTION_LOCK);
		g_PropertyData[propertyid][p_PropertyLocked] = 1;
	}
	else if(lock == false)
	{
		if(funcidx("OnPropertyActionPerformed") != -1) 
			CallLocalFunction("OnPropertyActionPerformed",
			"iii",INVALID_PLAYER_ID,propertyid,PROPERTY_ACTION_UNLOCK);
		g_PropertyData[propertyid][p_PropertyLocked] = 0;
	}
}

stock GetNearPropertyEntrance(playerid)
{
	for(new i; i < MAX_PROPERTIES; i++)
	{
		if( IsPlayerInRangeOfPoint( playerid, 3.0, g_PropertyData[ i ][p_PropertyEntrance_X], \
		g_PropertyData[ i ][p_PropertyEntrance_Y], g_PropertyData[ i ][p_PropertyEntrance_Z]) \
		&& GetPlayerVirtualWorld( playerid ) == g_PropertyData[ i ][p_PropertyVwid_OUT] \
		&& !IsPlayerInAnyVehicle( playerid ))
		{
			return i;
		}
	}
	return 0;
}

stock bool:IsPlayerInProperty(playerid)
{
	if(g_PlayerProperty[playerid] == -1) return false;
	else return true;
}

stock ClearPlayerPropertyData(playerid)
{
	#if defined DETUTILS_DEBUG_MODE
	printf("[DETUtils]: (debug) - ClearPlayerPropertyData called successfully.");
	#endif
	g_PlayerProperty[playerid] = -1;
	#if defined DETUTILS_DEBUG_MODE
	printf("[DETUtils]: (debug) - ClearPlayerPropertyData action successfully performed.");
	#endif
	return 1;
}

stock GetPropertyCount()
{
	#if defined DETUTILS_DEBUG_MODE
	printf("[DETUtils]: (debug) - GetPropertyCount successfully called.");
	#endif
	return DET_g_CreatedProperties;
}

stock SetPropertyEntranceAngles(
		const _PropertyID,
		Float:_aAngle,
		Float:_bAngle)
{
	#if defined DETUTILS_DEBUG_MODE
	printf("[DETUtils]: (debug) - Successfully set interior (intid : %i) angles to %f-%f.", 
		_PropertyID, _aAngle, _bAngle);
	#endif
	g_PropertyData[_PropertyID][p_PropertyEntrance_A] = _aAngle;
	g_PropertyData[_PropertyID][p_PropertyExit_A] = _bAngle;
	return 1;
}

/*

																								 
88888888888                                                          db         88888888ba   88  
88                          ,d                                      d88b        88      "8b  88  
88                          88                                     d8'`8b       88      ,8P  88  
88aaaaa      8b,     ,d8  MM88MMM  8b,dPPYba,  ,adPPYYba,         d8'  `8b      88aaaaaa8P'  88  
88"""""       `Y8, ,8P'     88     88P'   "Y8  ""     `Y8        d8YaaaaY8b     88""""""'    88  
88              )888(       88     88          ,adPPPPP88       d8""""""""8b    88           88  
88            ,d8" "8b,     88,    88          88,    ,88      d8'        `8b   88           88  
88888888888  8P'     `Y8    "Y888  88          `"8bbdP"Y8     d8'          `8b  88           88  
																								 
																								 
*/

// Bug fix:

public OnPlayerSpawn(playerid)
{
	TogglePlayerControllable(playerid, 1);
	if(funcidx("a_props_playerspawn") != -1)
	{
		CallLocalFunction("a_props_playerspawn", "i", playerid);
	}
	return 1;
}

#if defined _ALS_OnPlayerSpawn
	#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif

#define OnPlayerSpawn a_props_playerspawn

forward a_props_playerspawn(playerid);

//////////////////////////////////////////////////

//#if !defined DETUTILS_COMPATIBILITY_MODE

forward OnPropertyActionPerformed(playerid, propertyid, actionid);

stock GetPropertyName(PropertyID)
{
	//#if defined detutils_complete_error_boom
	new f_PropertyName[256];

	strcat(f_PropertyName, g_PropertyData[PropertyID][p_PropertyName]);

	return f_PropertyName;
	//#endif
	//return g_PropertyData[PropertyID][p_PropertyName];
}

stock GetPropertyIDByName(const PropertyName[])
{
	for(new PropertyCount = 1; 
		PropertyCount < MAX_PROPERTIES; 
		PropertyCount++)
	{
		if(!strcmp(g_PropertyData[PropertyCount][p_PropertyName], PropertyName))
		{
			return PropertyCount;
		}
	}
	return 0;
}

stock SetPlayerProperty(_p_Playerid, pg_PropertyID)
{
	if(pg_PropertyID < -1)
		return 0;

	#if defined DETUTILS_DEBUG_MODE
	printf("[DETUtils]: (debug) - Successfully set player's (id : %i) property id to %i.", _p_Playerid, pg_PropertyID);
	#endif

	g_PlayerProperty[_p_Playerid] = pg_PropertyID;
	return 1;
}

// Actually extra.

public OnDETUtilsInit()
{
	_CreateAnncTextDraws();
	#if defined DETUTILS_DEBUG_MODE
	SaveLogIntoFile("detutils_properties.log", "[DETUtils]: (debug) - Loading...");
	SaveLogIntoFile("detutils_properties.log", "[DETUtils]: (debug) - Loaded.");
	#endif
	LoadDETUtilsScript(DETUTILS_SCRIPT_PROPERTIES);
	if(funcidx("d_props_detutilsinit") != -1)
	{
		CallLocalFunction("d_props_detutilsinit", "");
	}
	return 1;
}

#if defined _ALS_OnDETUtilsInit
	#undef OnDETUtilsInit
#else
	#define _ALS_OnDETUtilsInit
#endif

#define OnDETUtilsInit( d_props_detutilsinit(

forward d_props_detutilsinit();