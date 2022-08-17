/*
 * 
 * SA:MP DEntisT's Utilities
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - An extension to the DCC plugin.
 *
 *
 */

#if !defined dcconnector_included
 	#warning [samp-detutils]: (warning) - Discord Connector plugin is missing, the 'd_discordutils.inc' library was automatically disabled.
 	#endinput
#endif

#if !defined DISCORD_COMMAND_PREFIX
 	#error [samp-detutils]: (error) - Discord Command prefix is not defined. Please do: `#define DISCORD_COMMAND_PREFIX '!'`
#endif

#include "d_discordutils_macros"

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
		new i;
		new split[2][1024];
		for(i = 0; i < strlen(content); i++)
		{
			if(content[i] == ' ')
			{
				strmid(split[1], content, i, strlen(content));
				strmid(split[0], content, 0, i);
				break;
			}
		}

		strdel(split[0], 0, 1); //delete the prefix
		new cmdfunc[32];
		format(cmdfunc, sizeof cmdfunc, "dccmd_%s", split[0]);

		CallLocalFunction(cmdfunc, "iiiis", 
			_:guild, 
			_:channel, 
			_:message, 
			_:author, 
			split[1]);
		printf("cmd: %s, params: %s", split[0], split[1]);

	}
	return 1;
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

public OnDETUtilsInit()
{
	#if defined detutils_debug
	SaveLogIntoFile("detutils_discordutils.log", "[samp-detutils]: (debug) - Loading...");
	SaveLogIntoFile("detutils_discordutils.log", "[samp-detutils]: (debug) - Loaded.");
	#endif
	LoadDETUtilsScript(DETUTILS_SCRIPT_DISCORDUTILS);
	if(funcidx("d_dcutils_detutilsinit") != -1)
	{
		CallLocalFunction("d_dcutils_detutilsinit", "");
	}
	return 1;
}

#if defined _ALS_OnDETUtilsInit
	#undef OnDETUtilsInit
#else
	#define _ALS_OnDETUtilsInit
#endif

#define OnDETUtilsInit( d_dcutils_detutilsinit(

forward d_dcutils_detutilsinit();