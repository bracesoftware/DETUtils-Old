/*
 * 
 * SA:MP DEntisT's Utilities
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library core file.
 *
 *
 */

#pragma dynamic 215750000

 // Dummies:

als init OnGameModeInit;

keyword  public Func()
{
	return 1;
}

keyword   forward  Function(a, const b[], Float:c);


// Actual code:

@command(.type = SLASH_COMMAND) sscanftest(playerid, params[])
{
	new id, array[2][3];
	
	if(sscanf do(params, array, 2) == SSCANF_FAIL) // If sscanf fails (no spaces in a string)
	{
		return SendClientMessage(playerid, -1, "Sscanf failed.");
	}

	SendClientMessage(playerid, -1, "Sscanf succedeed.");

	return 1;
}

enum Enums
{
	Admin
}

als function OnGameModeInit()
{
    printf("[samp-detutils]: (debug) - Test ALS hook called.");
    return als continue;
}

@variable( .datatype = INTEGER, .args = {"Variable", false, false, 0} ) HandlerName();
@variable( .datatype = BOOLEAN, .args = {"Variable1", true, false, false} ) HandlerName1();
@variable( .datatype = FLOAT, .args = {"Variable2", false, false, 0.000} ) HandlerName2();
@variable( .datatype = STRING, .args = {"Variable3", true, "Cool string tho"} ) HandlerName3();

@variable( .datatype = INTEGER, .args = {"Variable4", false, false, 0} ) HandlerName4();

public OnDETUtilsInit() // This should be the last hook.
{
	CallVariableHandler("HandlerName");
	CallVariableHandler("HandlerName1");
	CallVariableHandler("HandlerName2");
	CallVariableHandler("HandlerName3");

	set Integer("Variable", 1243);
	set Boolean("Variable1", false, 3);
	set Float("Variable2", 213.21);

	printf("[samp-detutils]: (var info) - Testing variables: %i, %i, %f, %s",
		get Integer("Variable"),
		get Boolean("Variable1", 3),
		get Float("Variable2"),
		get String("Variable3"));

	CallVariableHandler("HandlerName4");
	set Integer("Variable4", 172364);
	save Integer("Variable4");
	load Integer("Variable4");

	delete Integer("Variable");
	delete Boolean("Variable1");
	delete Float("Variable2");
	delete String("Variable3");

	print("                                         ");
	print("                                         ");
	print("|=======================================|");
	print("                                         ");
	print("            SA:MP | DETUtils             ");
	print("     - Testing mode script loaded. -     ");
	print("                                         ");
	print("|=======================================|");
	print("                                         ");
	print("                                         ");
	return 1;
}

public OnVariableCreate(varname[], vartype)
{
	printf("Variable '%s' created - type : %i.", varname, vartype);
	return 1;
}

public OnVariableDelete(varname[], vartype)
{
	printf("Variable '%s' deleted - type : %i.", varname, vartype);
	return 1;
}

public OnVariableUpdate(varname[], vartype, value, dimension)
{
	printf("Variable '%s' updated - type : %i, new value : %i, dimension : %i.", 
		varname, vartype, value, dimension);
	return 1;
}

/* ONE

																					  
88b           d88              88                         db         88888888ba   88  
888b         d888              ""                        d88b        88      "8b  88  
88`8b       d8'88                                       d8'`8b       88      ,8P  88  
88 `8b     d8' 88  ,adPPYYba,  88  8b,dPPYba,          d8'  `8b      88aaaaaa8P'  88  
88  `8b   d8'  88  ""     `Y8  88  88P'   `"8a        d8YaaaaY8b     88""""""'    88  
88   `8b d8'   88  ,adPPPPP88  88  88       88       d8""""""""8b    88           88  
88    `888'    88  88,    ,88  88  88       88      d8'        `8b   88           88  
88     `8'     88  `"8bbdP"Y8  88  88       88     d8'          `8b  88           88  
																					  
																					  

*/

new Player[MAX_PLAYERS][Enums];

new Menu:teleportmenu;

enum PlayerData
{
	password[64],
	money,
	admin
}

new PlayerCache[MAX_PLAYERS][PlayerData];
/*
main()
{
	//printf("%d arrays in 'CallCommand'", DETUTILS_ARR_PARAMS_CallCommand);
	//printf("There are %d array parameters with size %d to \"my_test_function\"", countOf_my_test_function, sizeOf_my_test_function);
	print("SA:MP | DETUtils - Testing mode script loaded.");
}*/

public OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, Float:new_x, Float:new_y, Float:new_z, Float:vel_x, Float:vel_y, Float:vel_z) 
{
	if (GetVehicleDistanceFromPoint(vehicleid, new_x, new_y, new_z) > 3.0)
		SetVehicleToRespawn(vehicleid);
	return 0;
}

public OnPlayerWeaponChange(playerid, oldweapon, newweapon)
{
	new oldweap[32], newweap[32];
	GetWeaponName(oldweapon, oldweap, sizeof oldweap);
	GetWeaponName(newweapon, newweap, sizeof newweap);
	if(oldweapon == 0)
	{
		format(oldweap, sizeof oldweap, "none");
	}
	if(newweapon == 0)
	{
		format(newweap, sizeof newweap, "none");
	}
	SendClientMessage(playerid, -1, "You changed your weapon from %s to %s.", oldweap, newweap);
	return 1;
}
 
public OnPlayerSpawn(playerid)
{
	SetPlayerPos(playerid, 825.6589,-1614.8202,13.5469);
	SendClientMessage(playerid, -1, "Welcome %s, your id is %i", _ReturnPlayerName(playerid), playerid);
	SendClientMessageToAll(-1, "Player %s with id %i joined", ReturnPlayerName(playerid), playerid);
	GivePlayerMoney(playerid, 10364);
	SetPlayerSkin(playerid, 70);
	GivePlayerWeapon(playerid, 24, 999);
	GameTextForPlayer(playerid, "You spawned, %s!", 4000, 1, ReturnPlayerName(playerid));
	return 1;
}

@command(.type = SLASH_COMMAND) pickgun(playerid, params[]) 
{
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_PICKUP_WEAPON); // Pick up nearby dropped weapon.
	return 1;
}

@command(.type = SLASH_COMMAND) dropgun(playerid, params[]) 
{
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DROP_WEAPON); // Drop weapon which the player is holding.
	return 1;
}

@command(.type = SLASH_COMMAND) destroygun(playerid, params[]) 
{
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DESTROY_WEAPON); // Destroy nearby dropped weapon.
	return 1;
}

@command(.type = SLASH_COMMAND ) help (playerid, params[]) 
{
	SendClientMessage(playerid, -1, "New decorator thing works.");
	return 1;
}

@command(.type = SLASH_COMMAND) parsetest(playerid, params[], help) // Added `help` in order to test parsing.
{
	// There is no code since it won't get executed anyways,
	// since the parser function for the command will stop the processor
	// from processing the command, aka this code.
	
	return 1; // this code
}

@command ( .type = SLASH_COMMAND) cmdhelp ( playerid, params[], help) 
{
	SendClientMessage(playerid, -1, "New decorator thing works. #2");
	return 1;
}

@command(.type = DELAYED_COMMAND, .delay = 1000) delaytest(playerid, params[])
{
	SendClientMessage(playerid, -1, "One second passed.");
	return 1;
}

@command(.type = SLASH_COMMAND) typecheck(playerid, params[]) 
{
	new parameters[128], idx;

	new cmdname[32]; 

	parameters = strtok(params, idx);

	if(strlen(parameters) == 0) return SendClientMessage(playerid, 0xFFFFFFFF, "Usage: /typecheck <cmdname>");

	SendClientMessage(playerid, -1, "Command: %s | Slash command type: %i", cmdname, GetSlashCommandType(cmdname));
	return 1;
}

@dialog(.type = MESSAGE_BOX, .args = {"Hi", "Hello!", "OK", "NO"}) HiDialog(playerid);

@command(.type = SLASH_COMMAND) dialogtest(playerid, params[]) 
{
	ShowDialogForPlayer(playerid, "HiDialog");
	return 1;
}

public OnPlayerDialogReceived(playerid, dialog[])
{
	SendClientMessage(playerid, -1, "You received dialog '%s'", dialog);
	return 1;
}

public OnPlayerDialogHide(playerid, dialog[])
{
	SendClientMessage(playerid, -1, "'%s' hidden.", dialog);
	return 1;
}

public OnPlayerDialogResponse(playerid, dialog[], response, listitem, inputtext[])
{
	SendClientMessage(playerid, -1, 
		"You responded to dialog '%s', response: %i, listitem: %i, inputtext: %i", 
		dialog, response, listitem, inputtext);
	return 1;
}

@command ( .type = ADMIN_COMMAND ) amiadmin ( playerid, params[] ) 
{
	SendClientMessage(playerid, -1, "Yes you are.");
	return 1;
}

@command ( .type = PREFIXED_COMMAND, .prefix = "!" ) prefix( playerid, params[] ) 
{
	SendClientMessage(playerid, -1, "Cool prefix.");
	return 1;
}

@prefix(.value = "1") myprefix();

@command ( .type = PREFIXED_COMMAND, .prefix =myprefix ) prefixtest( playerid, params[] ) 
{
	SendClientMessage(playerid, -1, "Cool prefixtest.");
	return 1;
}

@flag(.dependencies=(Player[playerid][Admin] == 1)) admin(playerid);
@command(.type = FLAGGED_COMMAND , .flag = admin) amiadmin2( playerid,params[ ] ) 
{
	SendClientMessage(playerid, -1, "Yes you are.");
	return 1;
}

@command(.type = ALIAS_COMMAND) cmds( playerid, params[]) = help;

/* TWO

																					  
88b           d88              88                         db         88888888ba   88  
888b         d888              ""                        d88b        88      "8b  88  
88`8b       d8'88                                       d8'`8b       88      ,8P  88  
88 `8b     d8' 88  ,adPPYYba,  88  8b,dPPYba,          d8'  `8b      88aaaaaa8P'  88  
88  `8b   d8'  88  ""     `Y8  88  88P'   `"8a        d8YaaaaY8b     88""""""'    88  
88   `8b d8'   88  ,adPPPPP88  88  88       88       d8""""""""8b    88           88  
88    `888'    88  88,    ,88  88  88       88      d8'        `8b   88           88  
88     `8'     88  `"8bbdP"Y8  88  88       88     d8'          `8b  88           88  
																					  
																					  

*/

public OnPlayerScreenUpdate(playerid, updatetype)
{
	if(updatetype == SCREEN_UPDATE_PLAYER_TD_SHOW)
	{
		SendClientMessage(playerid, -1, "Player TD shown.");
	}
	if(updatetype == SCREEN_UPDATE_PLAYER_TD_HIDE)
	{
		SendClientMessage(playerid, -1, "Player TD hidden.");
	}
	if(updatetype == SCREEN_UPDATE_GLOBAL_TD_SHOW)
	{
		SendClientMessage(playerid, -1, "Global TD shown.");
	}
	if(updatetype == SCREEN_UPDATE_GLOBAL_TD_HIDE)
	{
		SendClientMessage(playerid, -1, "Global TD hidden.");
	}
	if(updatetype == SCREEN_UPDATE_GAMETEXT_SHOW)
	{
		SendClientMessage(playerid, -1, "GameText shown.");
	}
	if(updatetype == SCREEN_UPDATE_GAMETEXT_HIDE)
	{
		SendClientMessage(playerid, -1, "GameText hidden.");
	}
	if(updatetype == SCREEN_UPDATE_GTD_CHANGE_POS)
	{
		SendClientMessage(playerid, -1, "Global TD changed position.");
	}
	if(updatetype == SCREEN_UPDATE_PTD_CHANGE_POS)
	{
		SendClientMessage(playerid, -1, "Player TD changed position.");
	}
	return 1;
}

new Text:test;

DETUTILS Command:createtd(playerid, params[])
{
	test = TextDrawCreate(240.0,580.0, "~g~SA:MP DET-Utils");
	TextDrawShowForPlayer(playerid, test);
	return 1;
}

DETUTILS Command:movetd(playerid, params[])
{
	TextDrawHideForPlayer(playerid, test);
	TextDrawDestroy(test);
	test = TextDrawCreate(240.0,581.0, "~g~SA:MP DET-Utils");
	TextDrawShowForPlayer(playerid, test);
	return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	if(newstate == PLAYER_STATE_DRIVER)
	{
		SetPlayerVehiclePos(playerid, 825.6589,-1614.8202,13.5469);
	}
	return 1;
}

public OnPlayerUpdate(playerid)
{
	//SendClientMessage(playerid, -1, "Your speed is %i km/h.", d_ac_GetSpeed(playerid));
	return 1;
}
 
DETUTILS Command:acon(playerid,params[])
{
	ToggleAntiCheatSystem(true);
	return 1;
}

DETUTILS Command:acoff(playerid,params[])
{
	ToggleAntiCheatSystem(false);
	return 1;
}
 
DETUTILS Command: tagtest(playerid,params[])
{
	SendClientMessage(playerid, -1, "Tag command worked.");
	return 1;
}
 
DETUTILS CommandAlias:tagt(playerid,params[]) = tagtest;
 
CMD:cmd(playerid,params[])
{
	SendClientMessage(playerid, -1, "CMD: command worked.");
	SendClientMessage(playerid, -1,
	"{ffffff}This is white and {%06x}this is the %s's color!", 
	GetPlayerColor(playerid) >>> 8, ReturnPlayerName(playerid));
	return 1;
}

/* 3

																					  
88b           d88              88                         db         88888888ba   88  
888b         d888              ""                        d88b        88      "8b  88  
88`8b       d8'88                                       d8'`8b       88      ,8P  88  
88 `8b     d8' 88  ,adPPYYba,  88  8b,dPPYba,          d8'  `8b      88aaaaaa8P'  88  
88  `8b   d8'  88  ""     `Y8  88  88P'   `"8a        d8YaaaaY8b     88""""""'    88  
88   `8b d8'   88  ,adPPPPP88  88  88       88       d8""""""""8b    88           88  
88    `888'    88  88,    ,88  88  88       88      d8'        `8b   88           88  
88     `8'     88  `"8bbdP"Y8  88  88       88     d8'          `8b  88           88  
																					  
																					  

*/
 
YCMD:ycmd(playerid,params[])
{
	SendClientMessage(playerid, -1, "YCMD: command worked.");
	return 1;
}
 
COMMAND:command(playerid,params[])
{
	SendClientMessage(playerid, -1, "COMMAND: command worked.");
	return 1;
}

DETUTILS Command:mapeditor(playerid, params[])
{
	ShowMapEditorMenuToPlayer(playerid);
	return 1;
}

DETUTILS Command:labelon(playerid, params[])
{
	ShowObjectInfoLabels(GetPlayerVirtualWorld(playerid));
	return 1;
}

DETUTILS Command:labeloff(playerid, params[])
{
	HideObjectInfoLabels();
	return 1;
}
/*
#if !defined SSCANF_NO_K_SKIN
	SSCANF:skin(string[])
	{
		// This function is VERY basic, needs VASTLY improving to detect variations.
		if ('0' <= string[0] <= '9')
		{
			new
				ret = strval(string);
			if (0 <= ret <= 311)
			{
				return ret;
			}
		}
		else if (!strcmp(string, "cj", true)) return 0;
		else if (!strcmp(string, "truth", true)) return 1;
		else if (!strcmp(string, "maccer", true)) return 2;
		else if (!strcmp(string, "andre", true)) return 3;
		else if (!strcmp(string, "bbthin", true)) return 4;
		else if (!strcmp(string, "bb", true)) return 5;
		else if (!strcmp(string, "emmet", true)) return 6;
		else if (!strcmp(string, "male01", true)) return 7;
		else if (!strcmp(string, "janitor", true)) return 8;
		else if (!strcmp(string, "bfori", true)) return 9;
		else if (!strcmp(string, "bfost", true)) return 10;
		else if (!strcmp(string, "vbfycrp", true)) return 11;
		else if (!strcmp(string, "bfyri", true)) return 12;
		else if (!strcmp(string, "bfyst", true)) return 13;
		else if (!strcmp(string, "bmori", true)) return 14;
		else if (!strcmp(string, "bmost", true)) return 15;
		else if (!strcmp(string, "bmyap", true)) return 16;
		else if (!strcmp(string, "bmybu", true)) return 17;
		else if (!strcmp(string, "bmybe", true)) return 18;
		else if (!strcmp(string, "bmydj", true)) return 19;
		else if (!strcmp(string, "bmyri", true)) return 20;
		else if (!strcmp(string, "bmycr", true)) return 21;
		else if (!strcmp(string, "bmyst", true)) return 22;
		else if (!strcmp(string, "wmybmx", true)) return 23;
		else if (!strcmp(string, "wbdyg1", true)) return 24;
		else if (!strcmp(string, "wbdyg2", true)) return 25;
		else if (!strcmp(string, "wmybp", true)) return 26;
		else if (!strcmp(string, "wmycon", true)) return 27;
		else if (!strcmp(string, "bmydrug", true)) return 28;
		else if (!strcmp(string, "wmydrug", true)) return 29;
		else if (!strcmp(string, "hmydrug", true)) return 30;
		else if (!strcmp(string, "dwfolc", true)) return 31;
		else if (!strcmp(string, "dwmolc1", true)) return 32;
		else if (!strcmp(string, "dwmolc2", true)) return 33;
		else if (!strcmp(string, "dwmylc1", true)) return 34;
		else if (!strcmp(string, "hmogar", true)) return 35;
		else if (!strcmp(string, "wmygol1", true)) return 36;
		else if (!strcmp(string, "wmygol2", true)) return 37;
		else if (!strcmp(string, "hfori", true)) return 38;
		else if (!strcmp(string, "hfost", true)) return 39;
		else if (!strcmp(string, "hfyri", true)) return 40;
		else if (!strcmp(string, "hfyst", true)) return 41;
		else if (!strcmp(string, "jethro", true)) return 42;
		else if (!strcmp(string, "hmori", true)) return 43;
		else if (!strcmp(string, "hmost", true)) return 44;
		else if (!strcmp(string, "hmybe", true)) return 45;
		else if (!strcmp(string, "hmyri", true)) return 46;
		else if (!strcmp(string, "hmycr", true)) return 47;
		else if (!strcmp(string, "hmyst", true)) return 48;
		else if (!strcmp(string, "omokung", true)) return 49;
		else if (!strcmp(string, "wmymech", true)) return 50;
		else if (!strcmp(string, "bmymoun", true)) return 51;
		else if (!strcmp(string, "wmymoun", true)) return 52;
		else if (!strcmp(string, "ofori", true)) return 53;
		else if (!strcmp(string, "ofost", true)) return 54;
		else if (!strcmp(string, "ofyri", true)) return 55;
		else if (!strcmp(string, "ofyst", true)) return 56;
		else if (!strcmp(string, "omori", true)) return 57;
		else if (!strcmp(string, "omost", true)) return 58;
		else if (!strcmp(string, "omyri", true)) return 59;
		else if (!strcmp(string, "omyst", true)) return 60;
		else if (!strcmp(string, "wmyplt", true)) return 61;
		else if (!strcmp(string, "wmopj", true)) return 62;
		else if (!strcmp(string, "bfypro", true)) return 63;
		else if (!strcmp(string, "hfypro", true)) return 64;
		else if (!strcmp(string, "kendl", true)) return 65;
		else if (!strcmp(string, "bmypol1", true)) return 66;
		else if (!strcmp(string, "bmypol2", true)) return 67;
		else if (!strcmp(string, "wmoprea", true)) return 68;
		else if (!strcmp(string, "sbfyst", true)) return 69;
		else if (!strcmp(string, "wmosci", true)) return 70;
		else if (!strcmp(string, "wmysgrd", true)) return 71;
		else if (!strcmp(string, "swmyhp1", true)) return 72;
		else if (!strcmp(string, "swmihp2", true)) return 73;
		else if (!strcmp(string, "-", true)) return 74;
		else if (!strcmp(string, "swfopro", true)) return 75;
		else if (!strcmp(string, "wfystew", true)) return 76;
		else if (!strcmp(string, "swmotr1", true)) return 77;
		else if (!strcmp(string, "wmotr1", true)) return 78;
		else if (!strcmp(string, "bmotr1", true)) return 79;
		else if (!strcmp(string, "vbmybox", true)) return 80;
		else if (!strcmp(string, "vwmybox", true)) return 81;
		else if (!strcmp(string, "vhmyelv", true)) return 82;
		else if (!strcmp(string, "vbmyelv", true)) return 83;
		else if (!strcmp(string, "vimyelv", true)) return 84;
		else if (!strcmp(string, "vwfypro", true)) return 85;
		else if (!strcmp(string, "ryder3", true)) return 86;
		else if (!strcmp(string, "vwfyst1", true)) return 87;
		else if (!strcmp(string, "wfori", true)) return 88;
		else if (!strcmp(string, "wfost", true)) return 89;
		else if (!strcmp(string, "wfyjg", true)) return 90;
		else if (!strcmp(string, "wfyri", true)) return 91;
		else if (!strcmp(string, "wfyro", true)) return 92;
		else if (!strcmp(string, "wfyst", true)) return 93;
		else if (!strcmp(string, "wmori", true)) return 94;
		else if (!strcmp(string, "wmost", true)) return 95;
		else if (!strcmp(string, "wmyjg", true)) return 96;
		else if (!strcmp(string, "wmylg", true)) return 97;
		else if (!strcmp(string, "wmyri", true)) return 98;
		else if (!strcmp(string, "wmyro", true)) return 99;
		else if (!strcmp(string, "wmycr", true)) return 100;
		else if (!strcmp(string, "wmyst", true)) return 101;
		else if (!strcmp(string, "ballas1", true)) return 102;
		else if (!strcmp(string, "ballas2", true)) return 103;
		else if (!strcmp(string, "ballas3", true)) return 104;
		else if (!strcmp(string, "fam1", true)) return 105;
		else if (!strcmp(string, "fam2", true)) return 106;
		else if (!strcmp(string, "fam3", true)) return 107;
		else if (!strcmp(string, "lsv1", true)) return 108;
		else if (!strcmp(string, "lsv2", true)) return 109;
		else if (!strcmp(string, "lsv3", true)) return 110;
		else if (!strcmp(string, "maffa", true)) return 111;
		else if (!strcmp(string, "maffb", true)) return 112;
		else if (!strcmp(string, "mafboss", true)) return 113;
		else if (!strcmp(string, "vla1", true)) return 114;
		else if (!strcmp(string, "vla2", true)) return 115;
		else if (!strcmp(string, "vla3", true)) return 116;
		else if (!strcmp(string, "triada", true)) return 117;
		else if (!strcmp(string, "triadb", true)) return 118;
		else if (!strcmp(string, "sindaco", true)) return 119;
		else if (!strcmp(string, "triboss", true)) return 120;
		else if (!strcmp(string, "dnb1", true)) return 121;
		else if (!strcmp(string, "dnb2", true)) return 122;
		else if (!strcmp(string, "dnb3", true)) return 123;
		else if (!strcmp(string, "vmaff1", true)) return 124;
		else if (!strcmp(string, "vmaff2", true)) return 125;
		else if (!strcmp(string, "vmaff3", true)) return 126;
		else if (!strcmp(string, "vmaff4", true)) return 127;
		else if (!strcmp(string, "dnmylc", true)) return 128;
		else if (!strcmp(string, "dnfolc1", true)) return 129;
		else if (!strcmp(string, "dnfolc2", true)) return 130;
		else if (!strcmp(string, "dnfylc", true)) return 131;
		else if (!strcmp(string, "dnmolc1", true)) return 132;
		else if (!strcmp(string, "dnmolc2", true)) return 133;
		else if (!strcmp(string, "sbmotr2", true)) return 134;
		else if (!strcmp(string, "swmotr2", true)) return 135;
		else if (!strcmp(string, "sbmytr3", true)) return 136;
		else if (!strcmp(string, "swmotr3", true)) return 137;
		else if (!strcmp(string, "wfybe", true)) return 138;
		else if (!strcmp(string, "bfybe", true)) return 139;
		else if (!strcmp(string, "hfybe", true)) return 140;
		else if (!strcmp(string, "sofybu", true)) return 141;
		else if (!strcmp(string, "sbmyst", true)) return 142;
		else if (!strcmp(string, "sbmycr", true)) return 143;
		else if (!strcmp(string, "bmycg", true)) return 144;
		else if (!strcmp(string, "wfycrk", true)) return 145;
		else if (!strcmp(string, "hmycm", true)) return 146;
		else if (!strcmp(string, "wmybu", true)) return 147;
		else if (!strcmp(string, "bfybu", true)) return 148;
		else if (!strcmp(string, "smokev", true)) return 149;
		else if (!strcmp(string, "wfybu", true)) return 150;
		else if (!strcmp(string, "dwfylc1", true)) return 151;
		else if (!strcmp(string, "wfypro", true)) return 152;
		else if (!strcmp(string, "wmyconb", true)) return 153;
		else if (!strcmp(string, "wmybe", true)) return 154;
		else if (!strcmp(string, "wmypizz", true)) return 155;
		else if (!strcmp(string, "bmobar", true)) return 156;
		else if (!strcmp(string, "cwfyhb", true)) return 157;
		else if (!strcmp(string, "cwmofr", true)) return 158;
		else if (!strcmp(string, "cwmohb1", true)) return 159;
		else if (!strcmp(string, "cwmohb2", true)) return 160;
		else if (!strcmp(string, "cwmyhr", true)) return 161;
		else if (!strcmp(string, "cwmyhb1", true)) return 162;
		else if (!strcmp(string, "bmyboun", true)) return 163;
		else if (!strcmp(string, "wmyboun", true)) return 164;
		else if (!strcmp(string, "wmomib", true)) return 165;
		else if (!strcmp(string, "bmymib", true)) return 166;
		else if (!strcmp(string, "wmybell", true)) return 167;
		else if (!strcmp(string, "bmochil", true)) return 168;
		else if (!strcmp(string, "sofyri", true)) return 169;
		else if (!strcmp(string, "somyst", true)) return 170;
		else if (!strcmp(string, "vwmybjd", true)) return 171;
		else if (!strcmp(string, "vwfycrp", true)) return 172;
		else if (!strcmp(string, "sfr1", true)) return 173;
		else if (!strcmp(string, "sfr2", true)) return 174;
		else if (!strcmp(string, "sfr3", true)) return 175;
		else if (!strcmp(string, "bmybar", true)) return 176;
		else if (!strcmp(string, "wmybar", true)) return 177;
		else if (!strcmp(string, "wfysex", true)) return 178;
		else if (!strcmp(string, "wmyammo", true)) return 179;
		else if (!strcmp(string, "bmytatt", true)) return 180;
		else if (!strcmp(string, "vwmycr", true)) return 181;
		else if (!strcmp(string, "vbmocd", true)) return 182;
		else if (!strcmp(string, "vbmycr", true)) return 183;
		else if (!strcmp(string, "vhmycr", true)) return 184;
		else if (!strcmp(string, "sbmyri", true)) return 185;
		else if (!strcmp(string, "somyri", true)) return 186;
		else if (!strcmp(string, "somybu", true)) return 187;
		else if (!strcmp(string, "swmyst", true)) return 188;
		else if (!strcmp(string, "wmyva", true)) return 189;
		else if (!strcmp(string, "copgrl2", true)) return 190;
		else if (!strcmp(string, "gungrl3", true)) return 191;
		else if (!strcmp(string, "mecgrl3", true)) return 192;
		else if (!strcmp(string, "nurgrl3", true)) return 193;
		else if (!strcmp(string, "crogrl3", true)) return 194;
		else if (!strcmp(string, "gangrl3", true)) return 195;
		else if (!strcmp(string, "cwfofr", true)) return 196;
		else if (!strcmp(string, "cwfohb", true)) return 197;
		else if (!strcmp(string, "cwfyfr1", true)) return 198;
		else if (!strcmp(string, "cwfyfr2", true)) return 199;
		else if (!strcmp(string, "cwmyhb2", true)) return 200;
		else if (!strcmp(string, "dwfylc2", true)) return 201;
		else if (!strcmp(string, "dwmylc2", true)) return 202;
		else if (!strcmp(string, "omykara", true)) return 203;
		else if (!strcmp(string, "wmykara", true)) return 204;
		else if (!strcmp(string, "wfyburg", true)) return 205;
		else if (!strcmp(string, "vwmycd", true)) return 206;
		else if (!strcmp(string, "vhfypro", true)) return 207;
		else if (!strcmp(string, "suzie", true)) return 208;
		else if (!strcmp(string, "omonood", true)) return 209;
		else if (!strcmp(string, "omoboat", true)) return 210;
		else if (!strcmp(string, "wfyclot", true)) return 211;
		else if (!strcmp(string, "vwmotr1", true)) return 212;
		else if (!strcmp(string, "vwmotr2", true)) return 213;
		else if (!strcmp(string, "vwfywai", true)) return 214;
		else if (!strcmp(string, "sbfori", true)) return 215;
		else if (!strcmp(string, "swfyri", true)) return 216;
		else if (!strcmp(string, "wmyclot", true)) return 217;
		else if (!strcmp(string, "sbfost", true)) return 218;
		else if (!strcmp(string, "sbfyri", true)) return 219;
		else if (!strcmp(string, "sbmocd", true)) return 220;
		else if (!strcmp(string, "sbmori", true)) return 221;
		else if (!strcmp(string, "sbmost", true)) return 222;
		else if (!strcmp(string, "shmycr", true)) return 223;
		else if (!strcmp(string, "sofori", true)) return 224;
		else if (!strcmp(string, "sofost", true)) return 225;
		else if (!strcmp(string, "sofyst", true)) return 226;
		else if (!strcmp(string, "somobu", true)) return 227;
		else if (!strcmp(string, "somori", true)) return 228;
		else if (!strcmp(string, "somost", true)) return 229;
		else if (!strcmp(string, "swmotr5", true)) return 230;
		else if (!strcmp(string, "swfori", true)) return 231;
		else if (!strcmp(string, "swfost", true)) return 232;
		else if (!strcmp(string, "swfyst", true)) return 233;
		else if (!strcmp(string, "swmocd", true)) return 234;
		else if (!strcmp(string, "swmori", true)) return 235;
		else if (!strcmp(string, "swmost", true)) return 236;
		else if (!strcmp(string, "shfypro", true)) return 237;
		else if (!strcmp(string, "sbfypro", true)) return 238;
		else if (!strcmp(string, "swmotr4", true)) return 239;
		else if (!strcmp(string, "swmyri", true)) return 240;
		else if (!strcmp(string, "smyst", true)) return 241;
		else if (!strcmp(string, "smyst2", true)) return 242;
		else if (!strcmp(string, "sfypro", true)) return 243;
		else if (!strcmp(string, "vbfyst2", true)) return 244;
		else if (!strcmp(string, "vbfypro", true)) return 245;
		else if (!strcmp(string, "vhfyst3", true)) return 246;
		else if (!strcmp(string, "bikera", true)) return 247;
		else if (!strcmp(string, "bikerb", true)) return 248;
		else if (!strcmp(string, "bmypimp", true)) return 249;
		else if (!strcmp(string, "swmycr", true)) return 250;
		else if (!strcmp(string, "wfylg", true)) return 251;
		else if (!strcmp(string, "wmyva2", true)) return 252;
		else if (!strcmp(string, "bmosec", true)) return 253;
		else if (!strcmp(string, "bikdrug", true)) return 254;
		else if (!strcmp(string, "wmych", true)) return 255;
		else if (!strcmp(string, "sbfystr", true)) return 256;
		else if (!strcmp(string, "swfystr", true)) return 257;
		else if (!strcmp(string, "heck1", true)) return 258;
		else if (!strcmp(string, "heck2", true)) return 259;
		else if (!strcmp(string, "bmycon", true)) return 260;
		else if (!strcmp(string, "wmycd1", true)) return 261;
		else if (!strcmp(string, "bmocd", true)) return 262;
		else if (!strcmp(string, "vwfywa2", true)) return 263;
		else if (!strcmp(string, "wmoice", true)) return 264;
		else if (!strcmp(string, "tenpen", true)) return 265;
		else if (!strcmp(string, "pulaski", true)) return 266;
		else if (!strcmp(string, "hern", true)) return 267;
		else if (!strcmp(string, "dwayne", true)) return 268;
		else if (!strcmp(string, "smoke", true)) return 269;
		else if (!strcmp(string, "sweet", true)) return 270;
		else if (!strcmp(string, "ryder", true)) return 271;
		else if (!strcmp(string, "forelli", true)) return 272;
		else if (!strcmp(string, "tbone", true)) return 273;
		else if (!strcmp(string, "laemt1", true)) return 274;
		else if (!strcmp(string, "lvemt1", true)) return 275;
		else if (!strcmp(string, "sfemt1", true)) return 276;
		else if (!strcmp(string, "lafd1", true)) return 277;
		else if (!strcmp(string, "lvfd1", true)) return 278;
		else if (!strcmp(string, "sffd1", true)) return 279;
		else if (!strcmp(string, "lapd1", true)) return 280;
		else if (!strcmp(string, "sfpd1", true)) return 281;
		else if (!strcmp(string, "lvpd1", true)) return 282;
		else if (!strcmp(string, "csher", true)) return 283;
		else if (!strcmp(string, "lapdm1", true)) return 284;
		else if (!strcmp(string, "swat", true)) return 285;
		else if (!strcmp(string, "fbi", true)) return 286;
		else if (!strcmp(string, "army", true)) return 287;
		else if (!strcmp(string, "dsher", true)) return 288;
		else if (!strcmp(string, "zero", true)) return 289;
		else if (!strcmp(string, "rose", true)) return 290;
		else if (!strcmp(string, "paul", true)) return 291;
		else if (!strcmp(string, "cesar", true)) return 292;
		else if (!strcmp(string, "oglock", true)) return 293;
		else if (!strcmp(string, "wuzimu", true)) return 294;
		else if (!strcmp(string, "torino", true)) return 295;
		else if (!strcmp(string, "jizzy", true)) return 296;
		else if (!strcmp(string, "maddogg", true)) return 297;
		else if (!strcmp(string, "cat", true)) return 298;
		else if (!strcmp(string, "claude", true)) return 299;
		else if (!strcmp(string, "lapdna", true)) return 300;
		else if (!strcmp(string, "sfpdna", true)) return 301;
		else if (!strcmp(string, "lvpdna", true)) return 302;
		else if (!strcmp(string, "lapdpc", true)) return 303;
		else if (!strcmp(string, "lapdpd", true)) return 304;
		else if (!strcmp(string, "lvpdpc", true)) return 305;
		else if (!strcmp(string, "wfyclpd", true)) return 306;
		else if (!strcmp(string, "vbfycpd", true)) return 307;
		else if (!strcmp(string, "wfyclem", true)) return 308;
		else if (!strcmp(string, "wfycllv", true)) return 309;
		else if (!strcmp(string, "csherna", true)) return 310;
		else if (!strcmp(string, "dsherna", true)) return 311;
		return -1;
	}
#endif*/

alias command tag(playerid,params[]) =tagtest;
 
command sayhi (playerid,params[])
{
	new parameters[128], idx;

	new action; 

	parameters = strtok(params, idx);

	if(strlen(parameters) == 0) return SendClientMessage(playerid, 0xFFFFFFFF, "Usage: /sayhi <action>");

	action = strval(parameters);
	/*new action;
	if(sscanf(params, "i", action)) return SendClientMessage(playerid, 0xFFFFFFFF, "Usage: /sayhi <action>");*/

	if(action == 1)
	{
		SendClientMessage(playerid, -1, "Hi, %s.", _ReturnPlayerName(playerid));
	}
	else if(action != 1)
	{
		SendClientMessage(playerid, -1, "No HI for you!");
	}
	return 1;
}
 
alias command hi (playerid,params[]) = sayhi;
 
admin command ac (playerid,params[])
{
	SendClientMessage(playerid, -1, "You're admin.");
	return 1;
}
 
command untiltest(playerid, params[])
{
	new i;
	until(i = 50)
	{
		i++;
		printf("%i", i);
	}
	SendClientMessage(playerid, -1, "i is now 50.");
	return 1;
}
DETUTILS Command:lock(playerid, params[])
{
	new propertyid = GetNearPropertyEntrance(playerid);
	if(propertyid == 0) return SendClientMessage(playerid, -1, "You need to be near property entrance.");
	if(IsPropertyLocked(propertyid))
	{
		TogglePropertyLocked(propertyid, false);
		SendClientMessage(playerid, -1, "You Successfully Unlocked: %s", GetPropertyName(propertyid));
		return 1;
	}
	else if(!IsPropertyLocked(propertyid))
	{
		TogglePropertyLocked(propertyid, true);
		SendClientMessage(playerid, -1, "You Successfully Locked: %s", GetPropertyName(propertyid));
		return 1;
	}
	return 1;
}
 
public OnCommandStateChange(playerid, cmdtext[], stateid) // new and PROPER debugging
{
	if(stateid == COMMAND_DEBUG_STATE_RECEIVED)
	{
		printf("Command %s received.", cmdtext);
		return 1;
	}
	else if(stateid == COMMAND_DEBUG_STATE_READY)
	{
		printf("Command %s ready.", cmdtext);
		return 1;
	}
	else if(stateid == COMMAND_DEBUG_STATE_PERFORMED)
	{
		printf("Command %s performed.", cmdtext);
		return 1;
	}
	return 1;
}
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
public OnPrefixedCommandStateChange(playerid, cmdtext[], stateid) // you can also debug prefixed commands
{
	if(stateid == COMMAND_DEBUG_STATE_RECEIVED)
	{
		printf("Custom prefixed command %s received.", cmdtext);
		return 1;
	}
	else if(stateid == COMMAND_DEBUG_STATE_READY)
	{
		printf("Custom prefixed command %s ready.", cmdtext);
		return 1;
	}
	else if(stateid == COMMAND_DEBUG_STATE_PERFORMED)
	{
		printf("Custom prefixed command %s performed.", cmdtext);
		return 1;
	}
	else if(stateid == COMMAND_DEBUG_STATE_STOPPED)
	{
		printf("Command processing for command %s stopped.", cmdtext);
	}
	return 1;
}

public OnPlayerCheatDetected(playerid, cheattype)
{
	if(cheattype == CHEAT_TYPE_MONEY)
	{
		SendClientMessage(playerid, -1, "Stop using money hack, you could've just robbed a bank - but we got you!");
	}
	else if(cheattype == CHEAT_TYPE_SKINCHANGER)
	{
		SendClientMessage(playerid, -1, "Don't dare to change your skin this way ever again!");
	}
	else if(cheattype == CHEAT_TYPE_TELEPORT)
	{
		SendClientMessage(playerid, -1, "Stop teleporting!");
	}
	else if(cheattype == CHEAT_TYPE_HIGHPING)
	{
		SendClientMessage(playerid, -1, "Your ping is too high man! Try to reduce it a bit.");
	}
	else if(cheattype == CHEAT_TYPE_HEALTH)
	{
		SendClientMessage(playerid, -1, "Hey! Don't modify your health - you aren't immortal.");
	}
	else if(cheattype == CHEAT_TYPE_ARMOUR)
	{
		SendClientMessage(playerid, -1, "Stop changing your armour.");
	}
	else if(cheattype == CHEAT_TYPE_SPEEDHACK)
	{
		SendClientMessage(playerid, -1, "Aren't you too fast to be a human? Are you a... cheater?");
	}
	else if(cheattype == CHEAT_TYPE_DIALOG)
	{
		SendClientMessage(playerid, -1, "This is not the dialog you got shown!");
	}
	else if(cheattype == CHEAT_TYPE_MENU)
	{
		SendClientMessage(playerid, -1, "Switching menus? Why would you do that?");
	}
	return 1;
}

DETUTILS Prefix:shitprefix = "&";

public OnPlayerPassCommandPrefix(playerid, cmdtext[], passedprefix[], expectedprefix[])
{
	SendClientMessage(playerid, -1, "OnPlayerPassCommandPrefix is called.");
	SendClientMessage(playerid, -1, "CMD: %s | PASSED PREFIX: %s | EXPECTED PREFIX: %s", cmdtext, passedprefix, expectedprefix);

	if(passedprefix[0] == expectedprefix[0] && passedprefix[0] == shitprefix[0])
	{
		SendClientMessage(playerid, -1, "You aren't allowed to use commands with & prefix!");
		return 0;
	}
	return 1;
}
 
DETUTILS PrefixedCommand: test ( Prefix:"&",playerid, params[])
{
	SendClientMessage(playerid, -1, "Amazing %s, this custom-prefixed command worked.", _ReturnPlayerName(playerid));
	return 1;
}
 
DETUTILS PrefixedCommand:TEST(Prefix:"&",playerid, params[])
{
	SendClientMessage(playerid, -1, "WORKS!");
	return 1;
}
 
public OnPrefixedCommandReceived(playerid, cmdtext[])
{
	SendClientMessage(playerid, -1, "%s, your command was received. (%s)", _ReturnPlayerName(playerid), cmdtext);
	return 1;
}
 
public OnPrefixedCommandPerformed(playerid, cmdtext[], success)
{
	if(!success)
	{
		SendClientMessage(playerid, -1, "Command %s doesn't exist.", cmdtext);
	}
	return 1;
}
 
public OnPlayerCommandReceived(playerid, cmdtext[])
{
	SendClientMessage(playerid, -1, "%s, your command was received. (%s)", _ReturnPlayerName(playerid), cmdtext);
	return 1;
}
 
public OnPlayerCommandPerformed(playerid, cmdtext[], success)
{
	if(!success)
	{
		SendClientMessage(playerid, -1, "Command %s doesn't exist.", cmdtext);
	}
	return 1;
}
 
DETUTILS Prefix:aletter = "@";
DETUTILS Prefix: hashtag = "#" ;

DETUTILS Command:cson(playerid, params[])
{
	ToggleCommandCaseSensivity(true);
	SendClientMessage(playerid, -1, "%s turned command case-sensivity on.", ReturnPlayerName(playerid));
	return 1;
}

DETUTILS Command:csoff(playerid, params[])
{
	ToggleCommandCaseSensivity(false);
	SendClientMessage(playerid, -1, "%s turned command case-sensivity off.", ReturnPlayerName(playerid));
	return 1;
}
DETUTILS PrefixedCommand: dear ( Prefix: aletter, playerid, params[])
{
	SendClientMessage(playerid, -1, "%s said hi.", _ReturnPlayerName(playerid));
	return 1;
}/*

																					  
88b           d88              88                         db         88888888ba   88  
888b         d888              ""                        d88b        88      "8b  88  
88`8b       d8'88                                       d8'`8b       88      ,8P  88  
88 `8b     d8' 88  ,adPPYYba,  88  8b,dPPYba,          d8'  `8b      88aaaaaa8P'  88  
88  `8b   d8'  88  ""     `Y8  88  88P'   `"8a        d8YaaaaY8b     88""""""'    88  
88   `8b d8'   88  ,adPPPPP88  88  88       88       d8""""""""8b    88           88  
88    `888'    88  88,    ,88  88  88       88      d8'        `8b   88           88  
88     `8'     88  `"8bbdP"Y8  88  88       88     d8'          `8b  88           88  
																					  
																					  

*/
 
DETUTILS   PrefixedCommand: minecraft( Prefix: "#", playerid, params[])
{
	SendClientMessage(playerid, -1, "Hi man");
	return 1;
}
 
DETUTILS Prefix:dollar = "$"; 
DETUTILS PrefixedCommand: skal (  Prefix:dollar, playerid, params[])
{
	SendClientMessage(playerid, -1, "Cheers, %s!", ReturnPlayerName(playerid));
	return 1;
}
DETUTILS Prefix:plus = "+";
#if defined detutils_complete_error_boom
DETUTILS PrefixedCommand:sscanf(Prefix: "+",playerid, params[]) 
{
	new action;
	if(sscanf(params, "i", action)) return SendClientMessage(playerid, 0xFFFFFFFF, "Usage: +sscanf <action>");

	if(action == 1)
	{
		SendClientMessage(playerid, -1, "Hi, %s.", _ReturnPlayerName(playerid));
	}
	else if(action != 1)
	{
		SendClientMessage(playerid, -1, "No HI for you!");
	}
	return 1;
}
#endif
prefixed command lol(Prefix: "e", playerid, params[])
{
	SendClientMessageToAll(-1, "E");
	return 1;
}

create role AdminRole (playerid, Player[playerid][Admin] == 1);
 
DETUTILS Role:AdminRole2(playerid, Player[playerid][Admin] >= 1 );
 
command makeadmin (playerid, params[])
{
	SendClientMessage(playerid, -1, "You're now an administrator.");
	Player[playerid][Admin] = 1;
	return 1;
}
 
role command clearchat (Role:AdminRole,playerid, params[])
{
	for(new i; i < 20; i++)
		SendClientMessage(playerid, -1, "");

	SendClientMessage(playerid, -1, "You cleared the chat.");
	return 1;
}
 
DETUTILS RoleCommand:ao( Role:AdminRole2, playerid, params[])
{
	SendClientMessageToAll(-1, "Announcement!");
	return 1;
}

public OnDeathMatchZoneCreate(zoneid, zonename[])
{
	printf("DM Zone `%s`[%i] created!", zonename, zoneid);
	return 1;
}

public OnDeathMatchZoneDestroy(zoneid, zonename[])
{
	printf("DM Zone `%s`[%i] destroyed!", zonename, zoneid);
	return 1;
}

@command(.type = SLASH_COMMAND) dmjoin(playerid, params[])
{
	AddPlayerToDeathMatchZone(playerid, "Insane DeathMatch", 1, 10);
	return 1;
}

@command(.type = SLASH_COMMAND) dmleave(playerid, params[])
{
	RemovePlayerFromDeathMatchZone(playerid);
	return 1;
}

@command(.type = TEAM_COMMAND, .team = "Amazing people") amiamazing(playerid, params[])
{
	SendClientMessage(playerid, -1, "You are amazing!");
	return 1;
}

@command(.type = SLASH_COMMAND) joinamazing(playerid, params[])
{
	SendClientMessage(playerid, -1, "You're now amazing.");
	AddPlayerToTeam(playerid, "Amazing people");
	return 1;
}

@command(.type = SLASH_COMMAND) quitamazing(playerid, params[])
{
	SendClientMessage(playerid, -1, "You aren't amazing anymore.");
	AddPlayerToTeam(playerid, "NO_TEAM");
	return 1;
}

public OnGameModeInit()
{
	als do(OnGameModeInit, "");
	AddStaticVehicle(560, 844.7139,-1614.3539,13.5391,316.9723, 25, 23);
	CreateDeathMatchZone("Insane DeathMatch", 844.7139,-1614.3539,13.5391, 825.6589,-1614.8202,13.5469, 811.1299,-1616.0647,13.5469);
	CreateTeam("Amazing people");
	teleportmenu = CreateMenu("Teleportmenu", 2, 200.0, 100.0, 150.0, 150.0);
	AddMenuItem(teleportmenu, 0, "LS");
	AddMenuItem(teleportmenu, 0, "LS");
	AddMenuItem(teleportmenu, 0, "SF");
	AddMenuItem(teleportmenu, 0, "SF");
	AddMenuItem(teleportmenu, 0, "LV");
	AddMenuItem(teleportmenu, 0, "LV");
	 
	AddMenuItem(teleportmenu, 1, "Grove Street");
	AddMenuItem(teleportmenu, 1, "Starfish Tower");
	AddMenuItem(teleportmenu, 1, "Wheel Arch Angels");
	AddMenuItem(teleportmenu, 1, "Jizzys");
	AddMenuItem(teleportmenu, 1, "4 Dragons");
	AddMenuItem(teleportmenu, 1, "Come-a-Lot");
	UsePlayerPedAnims();
	DisableDefaultProperties();
	CreatePropertyEntrance("24/7 Market", 811.1299,-1616.0647,13.5469, 0, 0, true, INTERIOR_MARKET_247_1);
	CreatePropertyEntranceForTeam("Your Interior", "Amazing people", 825.6589,-1614.8202,13.5469, 0, 0, true, INTERIOR_CUSTOM, 0.0000, 0.0000, 4.0000, 1, 1);
	SetPropertyEntranceAngles(GetPropertyIDByName("Your Interior"), 1.0000, 2.0000);
	CreateDroppedWeapon(30,999,811.1299,-1616.0647,13.5469);
	return 1;
}

public OnTeamCreate(teamid, teamname[])
{
	printf("Team '%s'[%i] created.", teamname, teamid);
	return 1;
}

public OnTeamDelete(teamid, teamname[])
{
	printf("Team '%s'[%i] deleted.", teamname, teamid);
	return 1;
}

public OnPlayerSelectedMenuRow(playerid, row)
{
	new Menu:CurrentMenu = GetPlayerMenu(playerid);
	if(CurrentMenu == teleportmenu)
	{
		switch(row)
		{
			case 0: //Grove Street
			{
				SetPlayerPos(playerid, 2493.9133, -1682.3986, 13.3382);
				SetPlayerInterior(playerid, 0);
				SendClientMessage(playerid, 0xFFFFFFFF, "Welcome to Grove Street");
			}
			case 1: //Starfish Tower
			{
				SetPlayerPos(playerid, 1541.2833, -1362.4741, 329.6457);
				SetPlayerInterior(playerid, 0);
				SendClientMessage(playerid, 0xFFFFFFFF, "Welcome to the top of Starfish Tower");
			}
			case 2: //Wheel Arch Angels
			{
				SetPlayerPos(playerid, -2705.5503, 206.1621, 4.1797);
				SetPlayerInterior(playerid, 0);
				SendClientMessage(playerid, 0xFFFFFFFF, "Welcome to the Wheel Arch Angels tuning-shop");
			}
			case 3: //Jizzys
			{
				SetPlayerPos(playerid, -2617.5156, 1390.6353, 7.1105);
				SetPlayerInterior(playerid, 0);
				SendClientMessage(playerid, 0xFFFFFFFF, "Welcome to Jizzy's Nightclub!");
			}
			case 4: //4Dragons
			{
				SetPlayerPos(playerid, 2028.5538, 1008.3543, 10.8203);
				SetPlayerInterior(playerid, 0);
				SendClientMessage(playerid, 0xFFFFFFFF, "Welcome to the Four Dragons Casino");
			}
			case 5: //Come-a-Lot
			{
				SetPlayerPos(playerid, 2169.1838, 1122.5426, 12.6107);
				SetPlayerInterior(playerid, 0);
				SendClientMessage(playerid, 0xFFFFFFFF, "Welcome to the Come-a-Lot casino!");
			}
		}
	}
	return 1;
}

DETUTILS Command:tp(playerid, params[])
{
	ShowMenuForPlayer(teleportmenu,playerid);
	return 1;
}

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

public OnPlayerConnect(playerid)
{
	if(!IsPlayerUsingAndroidClient(playerid)) return SendClientMessage(playerid, -1, "You're using a computer to play SA:MP, great!");
	SetSpawnInfo(playerid, 0, 0, 811.1299,-1616.0647,13.5469, 0, 0,0,0,0,0,0);
	//SpawnPlayer(playerid);
	new LoadQuery[32], SaveQuery[32], file[32];
	format(LoadQuery, 32, "%s_LOAD", ReturnPlayerName(playerid));
	format(SaveQuery, 32, "%s_SAVE", ReturnPlayerName(playerid));
	format(file, 32, "%s.ini", ReturnPlayerName(playerid));
	CreateQuery(SaveQuery, QUERY_TYPE_SAVE, "Users", file); // Create a query which will save cache
	CreateQuery(LoadQuery, QUERY_TYPE_LOAD, "Users", file); // Create a query which will load data
	
	if(QueryFileExist(SaveQuery)) // Check if the query file exists.... (Users/DEntisT.ini)
	{
		new content[1024]; // var in which the content will be stored
		FormatQuery(LoadQuery, "LOAD *"); // format the file query
		SendQuery(LoadQuery); // send it
		GetLoadedQueryContent(LoadQuery, content); // After the LOAD query was sent, we need to get the content of the data.
		SendClientMessage(playerid, -1, "Loaded query file content: %s", content); // For debugging purposes
		new array[3][64]; // declare this array for PARSING
		ParseQueryContent(content, array); // Parse the content
		strmid(PlayerCache[playerid][password], array[0]); // Get the password 
		PlayerCache[playerid][money] = strval(array[1]); // Get the money
		PlayerCache[playerid][admin] = strval(array[2]); // Get the admin boolean
		ShowPlayerDialog(playerid, 100, DIALOG_STYLE_INPUT, 
			"Login", "Please log in. Password:", "OK","Cancel"); // Show the login dialog
	}
	else if(!QueryFileExist(SaveQuery)) // If the player is not registered.
	{
		ShowPlayerDialog(playerid, 101, DIALOG_STYLE_INPUT, 
			"Register", "Please register. Wanted password:", "OK","Cancel"); // show the register dialog
	}
	return 1;
}

public OnFileQuerySend(directory[], file[], query[], type) 
{
	printf("File query sent: %s, %s, %s, %i", directory, file, query, type);
	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	new SaveQuery[32];
	format(SaveQuery, 32, "%s_SAVE", ReturnPlayerName(playerid));
	if(dialogid == 100) // Check if it is login dialog
	{
		if(!response) return Kick(playerid); // If ESC pressed, kick
		if(response) // else
		{
			if(!strcmp(PlayerCache[playerid][password], inputtext)) // check if the player input the correct password
			{
				SpawnPlayer(playerid); // Spawn the player
			}
			else Kick(playerid); // if the password is wrong, kick
		}
	}
	if(dialogid == 101) // Check if it is register dialog
	{
		if(!response) return Kick(playerid); // If ESC pressed, kick
		if(response) // else
		{
			strmid(PlayerCache[playerid][password], inputtext, 0, 64); // Store the provided password
			new query[1024]; // Declare the string
			PlayerCache[playerid][money] = 1000; // Give starter money
			PlayerCache[playerid][admin] = 0; // Set admin value to 0
			format(query, 1024, "SAVE * %s,%i,%i", 
				PlayerCache[playerid][password],
				PlayerCache[playerid][money],
				PlayerCache[playerid][admin]); // Format the file query
			FormatQuery(SaveQuery, query); // Apply the format
			SendQuery(SaveQuery); // Send the query we formatted
			SpawnPlayer(playerid); // Spawn the player
			SendClientMessage(playerid, -1, "You are successfully registered.");
		}
	}
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	new SaveQuery[32];
	format(SaveQuery, 32, "%s_SAVE", ReturnPlayerName(playerid));
	new LoadQuery[32];
	format(SaveQuery, 32, "%s_LOAD", ReturnPlayerName(playerid));

	new query[1024];
	format(query, 1024, "SAVE * %s,%i,%i", 
		PlayerCache[playerid][password],
		PlayerCache[playerid][money],
		PlayerCache[playerid][admin]);
	FormatQuery(SaveQuery, query);
	SendQuery(SaveQuery);
	printf("DEBUG | PW : %s | M : %i | A : %i", PlayerCache[playerid][password],
		PlayerCache[playerid][money],
		PlayerCache[playerid][admin]);
	DestroyQuery(SaveQuery);
	DestroyQuery(LoadQuery);
	return 1;
}

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

public OnPlayerClientCheckReceived(playerid)
{
	printf("Successfully performed client check on player id %i.", playerid);
	return 1;
}
 
public OnPropertyActionPerformed(playerid, propertyid, actionid)
{
	new string[256];
	if(actionid == PROPERTY_ACTION_ENTER)
	{
		format(string, 256, "You entered %s, %s. Property id: %i [%i]", 
			GetPropertyName(propertyid),
			ReturnPlayerName(playerid), 
			GetPropertyIDByName(g_PropertyData[propertyid][p_PropertyName]), // to ensure this also works
			propertyid);
		SendClientMessage(playerid, -1, string);
		return 1;
	}
	else if(actionid == PROPERTY_ACTION_EXIT)
	{
		format(string, 256, "You exited %s, %s. Property id: %i [%i]", 
			GetPropertyName(propertyid),
			ReturnPlayerName(playerid), 
			GetPropertyIDByName(GetPropertyName(propertyid)),
			propertyid);
		SendClientMessage(playerid, -1, string);
		return 1;
	}
	else if(actionid == PROPERTY_ACTION_LOCK)
	{
		SendClientMessageToAll(-1, "Property %s [%i] is now locked!", 
			GetPropertyName(propertyid), GetPropertyIDByName(GetPropertyName(propertyid)));
	}
	else if(actionid == PROPERTY_ACTION_LOCK)
	{
		SendClientMessageToAll(-1, "Property %s [%i] is now unlocked!", 
			GetPropertyName(propertyid), GetPropertyIDByName(GetPropertyName(propertyid)));
	}
	return 0;
}

public OnPropertyCreate(propertyid)
{
	printf("Property created! ID: %i", propertyid);
	return 1;
}

public OnPropertyDestroy(propertyid)
{
	printf("Property deleted/removed! ID: %i", propertyid);
	return 1;
}

public OnPlayerEnterProperty(playerid)
{
  new message[256];
  format(message, 256, "%s opens the door and enters the object.", ReturnPlayerName(playerid));
  SendMessageInRange(3.0, playerid, message, -1);
  return 1;
}
 
public OnPlayerExitProperty(playerid)
{
  new message[256];
  format(message, 256, "%s opens the door and leaves the place.", ReturnPlayerName(playerid));
  SendMessageInRange(3.0, playerid, message, -1);
  return 1;
}
 
public OnPlayerScoreSniperHeadshot(playerid, killedid)
{
	new message[256];
	format(message, 256, "You killed %s by headshot.", ReturnPlayerName(killedid));
	SendClientMessage(playerid, -1, message);
	return 1;
}
 
public OnPlayerPickUpDroppedWeapon(playerid)
{
	SendClientMessage(playerid, -1, "You picked up a weapon.");
	return 1;
}
 
public OnPlayerDropWeapon(playerid)
{
	SendClientMessage(playerid, -1, "You dropped a weapon.");
	return 1;
}
 
public OnPlayerDestroyDroppedWeapon(playerid)
{
	SendClientMessage(playerid, -1, "You destroyed a weapon.");
	return 1;
}

// EOF