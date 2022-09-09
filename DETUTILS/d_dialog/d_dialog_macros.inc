/*
 * 
 * DETUtils
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
// For types (styles):
#define dls_%0\32; dls_

#define @DETUTILSDIALOG_DEC__@%0\32; @DETUTILSDIALOG_DEC__@
#define @DETUTILSDIALOG_STYLE_SET__<%0:..%2> dls_%0();public dls_%0(){return %2;}
#define @DETUTILSDIALOG_DECL_FUNC__$%0..%1$ dlg_%0(%1);public dlg_%0(%1)
#define @DETUTILSDIALOG_RET_SHOWD__@(%1$%2..%3) {return ShowPlayerDialog(%1,DETUTILS_INTERNAL_DIALOG,%3,%2);}
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

#define @DETUTILSDIALOG_DEC__@MESSAGE_BOX%6,%5.args%3=%8{%2}%9)%0(%1); \
    @DETUTILSDIALOG_STYLE_SET__<%0:..DIALOG_STYLE_MSGBOX> @DETUTILSDIALOG_DECL_FUNC__$%0..%1$ \
    @DETUTILSDIALOG_RET_SHOWD__@(%1$%2..DIALOG_STYLE_MSGBOX)

#define @DETUTILSDIALOG_DEC__@INPUT_BOX%6,%5.args%3=%8{%2}%9)%0(%1); \
    @DETUTILSDIALOG_STYLE_SET__<%0:..DIALOG_STYLE_INPUT> @DETUTILSDIALOG_DECL_FUNC__$%0..%1$ \
    @DETUTILSDIALOG_RET_SHOWD__@(%1$%2..DIALOG_STYLE_INPUT)
    //dlg_%0(%1);public dlg_%0(%1){return ShowPlayerDialog(%1,DETUTILS_INTERNAL_DIALOG,DIALOG_STYLE_INPUT,%2);}

#define @DETUTILSDIALOG_DEC__@LIST%6,%5.args%3=%8{%2}%9)%0(%1); \
    @DETUTILSDIALOG_STYLE_SET__<%0:..DIALOG_STYLE_LIST> @DETUTILSDIALOG_DECL_FUNC__$%0..%1$ \
    @DETUTILSDIALOG_RET_SHOWD__@(%1$%2..DIALOG_STYLE_LIST)
    //dlg_%0(%1);public dlg_%0(%1){return ShowPlayerDialog(%1,DETUTILS_INTERNAL_DIALOG,DIALOG_STYLE_LIST,%2);}

#define @DETUTILSDIALOG_DEC__@PASSWORD_INPUT%6,%5.args%3=%8{%2}%9)%0(%1); \
    @DETUTILSDIALOG_STYLE_SET__<%0:..DIALOG_STYLE_PASSWORD> @DETUTILSDIALOG_DECL_FUNC__$%0..%1$ \
    @DETUTILSDIALOG_RET_SHOWD__@(%1$%2..DIALOG_STYLE_PASSWORD)
    //dlg_%0(%1);public dlg_%0(%1){return ShowPlayerDialog(%1,DETUTILS_INTERNAL_DIALOG,DIALOG_STYLE_PASSWORD,%2);}

#define @DETUTILSDIALOG_DEC__@TABLIST%6,%5.args%3=%8{%2}%9)%0(%1); \
    @DETUTILSDIALOG_STYLE_SET__<%0:..DIALOG_STYLE_TABLIST> @DETUTILSDIALOG_DECL_FUNC__$%0..%1$ \
    @DETUTILSDIALOG_RET_SHOWD__@(%1$%2..DIALOG_STYLE_TABLIST)
    //dlg_%0(%1);public dlg_%0(%1){return ShowPlayerDialog(%1,DETUTILS_INTERNAL_DIALOG,DIALOG_STYLE_TABLIST,%2);}

#define @DETUTILSDIALOG_DEC__@TABLIST_HEADERS%6,%5.args%3=%8{%2}%9)%0(%1); \
    @DETUTILSDIALOG_STYLE_SET__<%0:..DIALOG_STYLE_TABLIST_HEADERS> @DETUTILSDIALOG_DECL_FUNC__$%0..%1$ \
    @DETUTILSDIALOG_RET_SHOWD__@(%1$%2..DIALOG_STYLE_TABLIST_HEADERS)
    //dlg_%0(%1);public dlg_%0(%1){return ShowPlayerDialog(%1,DETUTILS_INTERNAL_DIALOG,DIALOG_STYLE_TABLIST_HEADERS,%2);}