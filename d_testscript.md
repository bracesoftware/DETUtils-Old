# Code
```pawn
#define DETUTILS_DEBUG_MODE
#define DETUTILS_COMPAT

#include <a_samp>
#include <sscanf2>
#include "DETUTILS\d_samp"

// Dummies:

keyword  public Func()
{
    return 1;
}

keyword   forward  Function(a, const b[], Float:c);

// Actual code:

enum Enums
{
    Admin
}

new Player[MAX_PLAYERS][Enums];

new Menu:teleportmenu;

main()
{
    printf("%d arrays in 'CallCommand'", DETUTILS_ARR_PARAMS_CallCommand);
    print("Gamemode loaded.");
}

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

@command ( .type = SLASH_COMMAND) cmdhelp ( playerid, params[] ) 
{
    SendClientMessage(playerid, -1, "New decorator thing works. #2");
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
    SendClientMessage(playerid, COLOR_WHITE,
    "{ffffff}This is white and {%06x}this is the %s's color!", 
    GetPlayerColor(playerid) >>> 8, ReturnPlayerName(playerid));
    return 1;
}
 
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
}
 
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
 
public OnGameModeInit()
{
    AddStaticVehicle(560, 844.7139,-1614.3539,13.5391,316.9723, 25, 23);
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
    CreatePropertyEntrance("Your Interior", 825.6589,-1614.8202,13.5469, 0, 0, true, INTERIOR_CUSTOM, 0.0000, 0.0000, 4.0000, 1, 1);
    CreateDroppedWeapon(30,999,811.1299,-1616.0647,13.5469);
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
 
public OnPlayerConnect(playerid)
{
    if(!IsPlayerUsingAndroidClient(playerid)) return SendClientMessage(playerid, -1, "You're using a computer to play SA:MP, great!");
    SetSpawnInfo(playerid, 0, 0, 811.1299,-1616.0647,13.5469, 0, 0,0,0,0,0,0);
    SpawnPlayer(playerid);
    return 1;
}
 
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
            GetPropertyIDByName(g_PropertyData[propertyid][p_PropertyName]), //GetPropertyIDByName(GetPropertyName(propertyid)), // to ensure this also works
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
 
public OnPropertyCreated(propertyid)
{
    printf("Property created! ID: %i", propertyid);
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
 ```
