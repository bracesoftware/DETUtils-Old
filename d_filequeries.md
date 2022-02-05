# d_filequeries.inc
SA:MP File Queries - save cache and load it during the run-time.

[Go back to home page...](README.md)

# How to start to use?
- Let's make an user system! I will show the procedure step by step. But before we continue, veoma important clarification - in this user system, password hashing was not implemented which is seriously NOT recommended. Always hash your passwords!

1. Declare an enumerator for player cache:
```pawn
enum PlayerData
{
    password[64],
    money,
    admin
}

new PlayerCache[MAX_PLAYERS][PlayerData];
```
2. Use ``OnPlayerConnect`` callback:
```pawn
public OnPlayerConnect(playerid)
{
    Query_Create("DEntisT_SAVE", QUERY_TYPE_SAVE, "Users", "DEntisT.ini"); // Create a query which will save cache
    Query_Create("DEntisT_LOAD", QUERY_TYPE_LOAD, "Users", "DEntisT.ini"); // Create a query which will load data
    
    if(Query_FileExist("DEntisT_SAVE")) // Check if the query file exists.... (Users/DEntisT.ini)
    {
        new content[1024]; // var in which the content will be stored
        Query_Format("DEntisT_LOAD", "LOAD *"); // format the file query
        Query_Send("DEntisT_LOAD"); // send it
        Query_GetLoadedContent("DEntisT_LOAD", content); // After the LOAD query was sent, we need to get the content of the data.
        SendClientMessage(playerid, -1, "Loaded query file content: %s", content); // For debugging purposes
        new array[3][64]; // declare this array for PARSING
        Query_ParseContent(content, array); // Parse the content
        strmid(PlayerCache[playerid][password], array[0]); // Get the password 
        PlayerCache[playerid][money] = strval(array[1]); // Get the money
        PlayerCache[playerid][admin] = strval(array[2]); // Get the admin boolean
        ShowPlayerDialog(playerid, 100, DIALOG_STYLE_INPUT, 
            "Login", "Please log in. Password:", "OK","Cancel"); // Show the login dialog
    }
    else // If the player is not registered.
    {
        ShowPlayerDialog(playerid, 101, DIALOG_STYLE_INPUT, 
            "Register", "Please register. Wanted password:", "OK","Cancel"); // show the register dialog
    }
    return 1;
}
```
3. Use ``OnDialogResponse`` callback now:
```pawn
public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
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
            Query_Format("DEntisT_SAVE", query); // Apply the format
            Query_Send("DEntisT_SAVE"); // Send the query we formatted
            SpawnPlayer(playerid); // Spawn the player
            SendClientMessage(playerid, -1, "You are successfully registered.");
        }
    }
    return 1;
}
```
# API
# Messages from creator
