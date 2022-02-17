# d_filequeries.inc
SA:MP File Queries - save cache and load it during the run-time.

[Go back to home page...](README.md)

# How to start to use?
- Let's make an user system! I will show the procedure step by step. But before we continue, seriously important clarification - in this user system, password hashing was not implemented which is seriously NOT recommended. Always hash your passwords!

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
```
3. Use ``OnDialogResponse`` callback now:
```pawn
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
```
4. Now we need to destroy the queries we created on `OnPlayerDisconnect` - see:
```pawn
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
```
# API
- Below, you can take look at all of the functions provided by the include.

## ``ParseQueryContent``
- Used to parse the string containing the file data previously saved by the SAVE query. Example is shown above.
## Callback - ``OnFileQuerySend``
- Mainly used for debugging purposes.
```pawn
public OnFileQuerySend(directory[], file[], query[], type) 
{
    // Code.
    return 1;
}
```
Usage:
```pawn
public OnFileQuerySend(directory[], file[], query[], type) 
{
    printf("File query sent: %s, %s, %s, %i", directory, file, query, type);
    return 1;
}
```

## ``CreateQuery``
- Used to create the query, example is shown above.

## ``FormatQuery``
- Used to format the query, example is also shown above.

## ``QueryFileExist``
- Used to check if the query file (file which contains the data) exists - example is shown above.

## ``SendQuery``
- Used to send a specific query.

## ``GetLoadedQueryContent``
- Used to get the loaded content from a file after the LOAD query was sent, the content is not returned directly but stored in the another variable.

## ``GetLastQueryType``
- Get the type of a last query sent.

```pawn
static type = GetLastQueryType();
```
## ``SetQueryDelimiter``
- Used to set the query string delimiter, used by the parser function. By default, delimiter is `,`.
```pawn
format(query, 1024, "SAVE * %s,%i,%i", 
                PlayerCache[playerid][password],
                PlayerCache[playerid][money],
                PlayerCache[playerid][admin]); // Format the file query
```
- As you can see in the code above, I've put comma symbol everywhere between value specifiers, ``ParseQueryContent`` uses `,` to detect values.
To change the delimiter, simply use ``SetQueryDelimiter`` to update it - recommended to use on ``OnGameModeInit`` callback. Note that the delimiter can only be a SINGLE character.
```pawn
public OnGameModeInit()
{
    SetQueryDelimiter('.'); // Set a fullstop as a delimiter
    return 1;
}
```
## `DestroyQuery`
- Used to destroy the query and free up space in the slot for another query. Example is shown on ``OnPlayerDisconnect``.
# Messages from creator
- None currently.
