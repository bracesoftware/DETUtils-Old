/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - An extension to the DCC plugin.
 *
 *
 */

#if !defined DISCORD_COMMAND_PREFIX
    #error [DETUtils]: (error) - Discord Command prefix is not defined. Please do: `#define DISCORD_COMMAND_PREFIX '!'`
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

public DCC_OnMessageCreate(DCC_Message:message)
{
    new DCC_User:author, 
        DCC_Channel:channel, 
        DCC_Guild:guild, 
        content[1024];

    DCC_GetMessageAuthor(message, author);
    DCC_GetMessageChannel(message, channel);
    DCC_GetMessageContent(message, content);
    DCC_GetChannelGuild(channel, guild);

    if(content[0] == DISCORD_COMMAND_PREFIX)
    {
        new component[2][1024];
        sscanf do(content, component, 2); // using d_fmargs.inc

        strdel(component[0], 0, 1); //delete the prefix
        new cmdname[32];
        format(cmdname, sizeof cmdname, "dccmd_%s", component[0]);

        CallLocalFunction(cmdname, "iiiis", 
            _:guild, 
            _:channel, 
            _:message, 
            _:author, 
            component[1]);

        #if defined DETUTILS_DEBUG_MODE
        printf("[DETUtils]: (debug) - cmdinfo :: Command function: '%s' : command arguments: '%s'", cmdname, component[1]);
        #endif
    }
    return 1;
}