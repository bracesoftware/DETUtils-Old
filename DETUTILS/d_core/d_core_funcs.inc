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

#define @DETUTILSCORE_KWORD__@%0\32; @DETUTILSCORE_KWORD__@
#define det @DETUTILSCORE_KWORD__@

#if defined DETUTILS_COMPATIBILITY_MODE || defined detutils_complete_error_boom

    #error [DETUtils]: (fatal error) - crl :: Stop messing with the core libraries!

#endif

//Undefine this anyways:
#if defined DETUTILS_COMPATIBILITY_MODE
#undef DETUTILS_COMPATIBILITY_MODE
#endif

#if !defined __PawnBuild

    #error [DETUtils]: (fatal error) - DETUtils require community Pawn compiler. Get it from: github.com/pawn-lang/compiler

#endif

#if defined DETUTILS_DEBUG_MODE

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

#define D_COLOUR_GREY "{B9C9BF}"

stock d_SendWarningMessage(playerid, const string[])
{
    new message[300];
    format(message, 300, ""D_COLOUR_GREY"Warning: [DETUtils]: (debug) - %s", string);
    return SendClientMessage(playerid, -1, message);
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

#if defined DETUTILS_NO_DIALOG

stock HidePlayerDialog(playerid)
{
    ShowPlayerDialog(playerid, -1, 1, @DETUTILSSTRING_NULL__4);
    return 1;
}

#endif

stock _ReturnPlayerName(id) 
{
    new player_name[MAX_PLAYER_NAME];
    GetPlayerName(id, player_name, sizeof player_name);
    return player_name;
}

stock SaveLogIntoFile(const filename[], const message[]) 
{
    // For internal backwards compatibility I'm lazy to remove.
    return 1;
}

#if !defined __SAMPStdLib

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

#endif