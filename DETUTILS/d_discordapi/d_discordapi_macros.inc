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

// commands


#if !defined DETUTILS_CMD_MACROS

#define @DETUTILS_CMD_DEC__@%0\32; @DETUTILS_CMD_DEC__@

#define @command%0(%1.type%2= @DETUTILS_CMD_DEC__@

#endif

#define dccmd_%0\32; dccmd_

#define @DETUTILS_CMD_DEC__@DISCORD_COMMAND%2)%0(%1) \
	dccmd_%0(%1);public dccmd_%0(%1)

// data

#if defined DETUTILS_BUGZ_LOL
#define @DETUTILSDCDATA_DEC__@%0\32; @DETUTILSDCDATA_DEC__@
#define @discord%0(%1.entity%2= @DETUTILSDCDATA_DEC__@
#endif

#define DCC_%0\32; DCC_
#define @discord%0(%1) DCC_

#if defined DETUTILS_BUGZ_LOL
#define @DETUTILSDCDATA_DEC__@GUILD%0)%1SetIntegerData(%2) \
DET_SetGuildData_Integer(%2)
#define @DETUTILSDCDATA_DEC__@GUILD%0)%1GetIntegerData(%2) \
DET_GetGuildData_Integer(%2)
#define @DETUTILSDCDATA_DEC__@GUILD%0)%1SetBooleanData(%2) \
DET_SetGuildData_Boolean(%2)
#define @DETUTILSDCDATA_DEC__@GUILD%0)%1GetBooleanData(%2) \
DET_GetGuildData_Boolean(%2)
#define @DETUTILSDCDATA_DEC__@GUILD%0)%1SetFloatData(%2) \
DET_SetGuildData_Float(%2)
#define @DETUTILSDCDATA_DEC__@GUILD%0)%1GetFloatData(%2) \
DET_GetGuildData_Float(%2)
#define @DETUTILSDCDATA_DEC__@GUILD%0)%1SetStringData(%2) \
DET_SetGuildData_String(%2)
#define @DETUTILSDCDATA_DEC__@GUILD%0)%1GetStringData(%2) \
DET_GetGuildData_String(%2)
#define @DETUTILSDCDATA_DEC__@CHANNEL%0)%1SetIntegerData(%2) \
DET_SetChannelData_Integer(%2)
#define @DETUTILSDCDATA_DEC__@CHANNEL%0)%1GetIntegerData(%2) \
DET_GetChannelData_Integer(%2)
#define @DETUTILSDCDATA_DEC__@CHANNEL%0)%1SetBooleanData(%2) \
DET_SetChannelData_Boolean(%2)
#define @DETUTILSDCDATA_DEC__@CHANNEL%0)%1GetBooleanData(%2) \
DET_GetChannelData_Boolean(%2)
#define @DETUTILSDCDATA_DEC__@CHANNEL%0)%1SetFloatData(%2) \
DET_SetChannelData_Float(%2)
#define @DETUTILSDCDATA_DEC__@CHANNEL%0)%1GetFloatData(%2) \
DET_GetChannelData_Float(%2)
#define @DETUTILSDCDATA_DEC__@CHANNEL%0)%1SetStringData(%2) \
DET_SetChannelData_String(%2)
#define @DETUTILSDCDATA_DEC__@CHANNEL%0)%1GetStringData(%2) \
DET_GetChannelData_String(%2)
#define @DETUTILSDCDATA_DEC__@USER%0)%1SetIntegerData(%2) \
DET_SetUserData_Integer(%2)
#define @DETUTILSDCDATA_DEC__@USER%0)%1GetIntegerData(%2) \
DET_GetUserData_Integer(%2)
#define @DETUTILSDCDATA_DEC__@USER%0)%1SetBooleanData(%2) \
DET_SetUserData_Boolean(%2)
#define @DETUTILSDCDATA_DEC__@USER%0)%1GetBooleanData(%2) \
DET_GetUserData_Boolean(%2)
#define @DETUTILSDCDATA_DEC__@USER%0)%1SetFloatData(%2) \
DET_SetUserData_Float(%2)
#define @DETUTILSDCDATA_DEC__@USER%0)%1GetFloatData(%2) \
DET_GetUserData_Float(%2)
#define @DETUTILSDCDATA_DEC__@USER%0)%1SetStringData(%2) \
DET_SetUserData_String(%2)
#define @DETUTILSDCDATA_DEC__@USER%0)%1GetStringData(%2) \
DET_GetUserData_String(%2)
#endif