/*
 * 
 * SA:MP DEntisT's Utilities
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Macros for d_dialog.inc
 *
 *
 */

// Dialog function:
#define dlg_%0\32; dlg_

#define @DETUTILSDIALOG_DEC__@%0\32; @DETUTILSDIALOG_DEC__@

#define @dialog%0(%1.type%2= @DETUTILSDIALOG_DEC__@

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

// This is a replacement to
//ShowPlayerDialog(playerid, dialogid, style, caption[], info[], button1[], button2[])

/* Supporting these styles:

DIALOG_STYLE_MSGBOX
DIALOG_STYLE_INPUT
DIALOG_STYLE_LIST
DIALOG_STYLE_PASSWORD
DIALOG_STYLE_TABLIST
DIALOG_STYLE_TABLIST_HEADERS

*/

#define @DETUTILSDIALOG_DEC__@MESSAGE_BOX%6,%5.args%4=%3{%2})%0(%1); \
	dlg_%0(%1);public dlg_%0(%1){return ShowPlayerDialog(%1,DETUTILS_INTERNAL_DIALOG,DIALOG_STYLE_MSGBOX,%2);}

#define @DETUTILSDIALOG_DEC__@INPUT_BOX%6,%5.args%4=%3{%2})%0(%1); \
	dlg_%0(%1);public dlg_%0(%1){return ShowPlayerDialog(%1,DETUTILS_INTERNAL_DIALOG,DIALOG_STYLE_INPUT,%2);}

#define @DETUTILSDIALOG_DEC__@LIST%6,%5.args%4=%3{%2})%0(%1); \
	dlg_%0(%1);public dlg_%0(%1){return ShowPlayerDialog(%1,DETUTILS_INTERNAL_DIALOG,DIALOG_STYLE_LIST,%2);}

#define @DETUTILSDIALOG_DEC__@PASSWORD_INPUT%6,%5.args%4=%3{%2})%0(%1); \
	dlg_%0(%1);public dlg_%0(%1){return ShowPlayerDialog(%1,DETUTILS_INTERNAL_DIALOG,DIALOG_STYLE_PASSWORD,%2);}

#define @DETUTILSDIALOG_DEC__@TABLIST%6,%5.args%4=%3{%2})%0(%1); \
	dlg_%0(%1);public dlg_%0(%1){return ShowPlayerDialog(%1,DETUTILS_INTERNAL_DIALOG,DIALOG_STYLE_TABLIST,%2);}

#define @DETUTILSDIALOG_DEC__@TABLIST_HEADERS%6,%5.args%4=%3{%2})%0(%1); \
	dlg_%0(%1);public dlg_%0(%1){return ShowPlayerDialog(%1,DETUTILS_INTERNAL_DIALOG,DIALOG_STYLE_TABLIST_HEADERS,%2);}