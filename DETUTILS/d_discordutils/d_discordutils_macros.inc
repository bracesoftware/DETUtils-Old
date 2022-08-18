/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Macros for d_discordutils.inc
 *
 *
 */

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

#if !defined DETUTILS_CMD_MACROS

#define @DETUTILS_CMD_DEC__@%0\32; @DETUTILS_CMD_DEC__@

#define @command%0(%1.type%2= @DETUTILS_CMD_DEC__@

#endif

#define dccmd_%0\32; dccmd_

#define @DETUTILS_CMD_DEC__@DISCORD_COMMAND%2)%0(%1) \
	dccmd_%0(%1);public dccmd_%0(%1)
