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

#if !defined dcconnector_included
 	#warning [DETUtils]: (warning) - Discord Connector plugin is missing, the 'd_discorddata.inc' library was automatically disabled.
 	#endinput
#endif

#include "d_discorddata_macros"

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

//guilds
stock void:DET_GetGuildData_Integer(DCC_Guild:guild, const data_address[], dest)
{
	new id[DCC_ID_SIZE], returned_data[10], file_name[150];
	DCC_GetGuildId(guild, id);
	format(file_name, sizeof file_name, "gi_%s_%s.discord_data", 
		id, data_address);
	if(!fexist(file_name)) return 0;
	new File:file = fopen(file_name, io_read);
	if(file)
	{
		fread(file, returned_data);
		dest = strval(returned_data);
		fclose(file);
	}
}

stock DET_SetGuildData_Integer(DCC_Guild:guild, const data_address[], value)
{
	new id[DCC_ID_SIZE], saved_data[10], file_name[150];
	DCC_GetGuildId(guild, id);
	format(file_name, sizeof file_name, "gi_%s_%s.discord_data", 
		id, data_address);
	format(saved_data, sizeof(saved_data), "%i", value);
	new File: file2 = fopen(file_name, io_write);
	fwrite(file2, saved_data);
	fclose(file2);
	return 1;
}

stock void:DET_GetGuildData_Boolean(DCC_Guild:guild, const data_address[], bool:dest)
{
	new id[DCC_ID_SIZE], returned_data[10], file_name[150];
	DCC_GetGuildId(guild, id);
	format(file_name, sizeof file_name, "gb_%s_%s.discord_data", 
		id, data_address);
	if(!fexist(file_name)) return 0;
	new File:file = fopen(file_name, io_read);
	if(file)
	{
		fread(file, returned_data);
		dest = strval(returned_data) ? true : false;
		fclose(file);
	}
}

stock DET_SetGuildData_Boolean(DCC_Guild:guild, const data_address[], bool:value)
{
	new id[DCC_ID_SIZE], saved_data[10], file_name[150];
	DCC_GetGuildId(guild, id);
	format(file_name, sizeof file_name, "gb_%s_%s.discord_data", 
		id, data_address);
	if(value != true && value != false)
	{
		value = false;
	}
	format(saved_data, sizeof(saved_data), "%i", value);
	new File: file2 = fopen(file_name, io_write);
	fwrite(file2, saved_data);
	fclose(file2);
	return 1;
}

stock void:DET_GetGuildData_Float(DCC_Guild:guild, const data_address[], Float:dest)
{
	new id[DCC_ID_SIZE], returned_data[10], file_name[150];
	DCC_GetGuildId(guild, id);
	format(file_name, sizeof file_name, "gf_%s_%s.discord_data", 
		id, data_address);
	if(!fexist(file_name)) return 0;
	new File:file = fopen(file_name, io_read);
	if(file)
	{
		fread(file, returned_data);
		dest = floatstr(returned_data);
		fclose(file);
	}
}

stock DET_SetGuildData_Float(DCC_Guild:guild, const data_address[], Float:value)
{
	new id[DCC_ID_SIZE], saved_data[10], file_name[150];
	DCC_GetGuildId(guild, id);
	format(file_name, sizeof file_name, "gf_%s_%s.discord_data", 
		id, data_address);
	format(saved_data, sizeof(saved_data), "%f", value);
	new File: file2 = fopen(file_name, io_write);
	fwrite(file2, saved_data);
	fclose(file2);
	return 1;
}

stock void:DET_GetGuildData_String(DCC_Guild:guild, const data_address[], dest[], size = sizeof dest)
{
	new id[DCC_ID_SIZE], returned_data[512], file_name[150];
	DCC_GetGuildId(guild, id);
	format(file_name, sizeof file_name, "gs_%s_%s.discord_data", 
		id, data_address);
	if(!fexist(file_name)) return 0;
	new File:file = fopen(file_name, io_read);
	if(file)
	{
		fread(file, returned_data);
		format(dest, size, returned_data);
		fclose(file);
	}
}

stock DET_SetGuildData_String(DCC_Guild:guild, const data_address[], const value[])
{
	new id[DCC_ID_SIZE], saved_data[512], file_name[150];
	DCC_GetGuildId(guild, id);
	format(file_name, sizeof file_name, "gs_%s_%s.discord_data", 
		id, data_address);
	format(saved_data, sizeof(saved_data), "%s", value);
	new File: file2 = fopen(file_name, io_write);
	fwrite(file2, saved_data);
	fclose(file2);
	return 1;
}

//Channels

stock void:DET_GetChannelData_Integer(DCC_Channel:channel, const data_address[], dest)
{
	new id[DCC_ID_SIZE], returned_data[10], file_name[150];
	DCC_GetChannelId(channel, id);
	format(file_name, sizeof file_name, "ci_%s_%s.discord_data", 
		id, data_address);
	if(!fexist(file_name)) return 0;
	new File:file = fopen(file_name, io_read);
	if(file)
	{
		fread(file, returned_data);
		dest = strval(returned_data);
		fclose(file);
	}
}

stock DET_SetChannelData_Integer(DCC_Channel:channel, const data_address[], value)
{
	new id[DCC_ID_SIZE], saved_data[10], file_name[150];
	DCC_GetChannelId(channel, id);
	format(file_name, sizeof file_name, "ci_%s_%s.discord_data", 
		id, data_address);
	format(saved_data, sizeof(saved_data), "%i", value);
	new File: file2 = fopen(file_name, io_write);
	fwrite(file2, saved_data);
	fclose(file2);
	return 1;
}

stock void:DET_GetChannelData_Boolean(DCC_Channel:channel, const data_address[], bool:dest)
{
	new id[DCC_ID_SIZE], returned_data[10], file_name[150];
	DCC_GetChannelId(channel, id);
	format(file_name, sizeof file_name, "cb_%s_%s.discord_data", 
		id, data_address);
	if(!fexist(file_name)) return 0;
	new File:file = fopen(file_name, io_read);
	if(file)
	{
		fread(file, returned_data);
		dest = strval(returned_data) ? true : false;
		fclose(file);
	}
}

stock DET_SetChannelData_Boolean(DCC_Channel:channel, const data_address[], bool:value)
{
	new id[DCC_ID_SIZE], saved_data[10], file_name[150];
	DCC_GetChannelId(channel, id);
	format(file_name, sizeof file_name, "cb_%s_%s.discord_data", 
		id, data_address);
	if(value != true && value != false)
	{
		value = false;
	}
	format(saved_data, sizeof(saved_data), "%i", value);
	new File: file2 = fopen(file_name, io_write);
	fwrite(file2, saved_data);
	fclose(file2);
	return 1;
}

stock void:DET_GetChannelData_Float(DCC_Channel:channel, const data_address[], Float:dest)
{
	new id[DCC_ID_SIZE], returned_data[10], file_name[150];
	DCC_GetChannelId(channel, id);
	format(file_name, sizeof file_name, "cf_%s_%s.discord_data", 
		id, data_address);
	if(!fexist(file_name)) return 0;
	new File:file = fopen(file_name, io_read);
	if(file)
	{
		fread(file, returned_data);
		dest = floatstr(returned_data);
		fclose(file);
	}
}

stock DET_SetChannelData_Float(DCC_Channel:channel, const data_address[], Float:value)
{
	new id[DCC_ID_SIZE], saved_data[10], file_name[150];
	DCC_GetChannelId(channel, id);
	format(file_name, sizeof file_name, "cf_%s_%s.discord_data", 
		id, data_address);
	format(saved_data, sizeof(saved_data), "%f", value);
	new File: file2 = fopen(file_name, io_write);
	fwrite(file2, saved_data);
	fclose(file2);
	return 1;
}

stock void:DET_GetChannelData_String(DCC_Channel:channel, const data_address[], dest[], size = sizeof dest)
{
	new id[DCC_ID_SIZE], returned_data[512], file_name[150];
	DCC_GetChannelId(channel, id);
	format(file_name, sizeof file_name, "cs_%s_%s.discord_data", 
		id, data_address);
	if(!fexist(file_name)) return 0;
	new File:file = fopen(file_name, io_read);
	if(file)
	{
		fread(file, returned_data);
		format(dest, size, returned_data);
		fclose(file);
	}
}

stock DET_SetChannelData_String(DCC_Channel:channel, const data_address[], const value[])
{
	new id[DCC_ID_SIZE], saved_data[512], file_name[150];
	DCC_GetChannelId(channel, id);
	format(file_name, sizeof file_name, "cs_%s_%s.discord_data", 
		id, data_address);
	format(saved_data, sizeof(saved_data), "%s", value);
	new File: file2 = fopen(file_name, io_write);
	fwrite(file2, saved_data);
	fclose(file2);
	return 1;
}

// users

stock void:DET_GetUserData_Integer(DCC_User:user, const data_address[], dest)
{
	new id[DCC_ID_SIZE], returned_data[10], file_name[150];
	DCC_GetUserId(user, id);
	format(file_name, sizeof file_name, "ui_%s_%s.discord_data", 
		id, data_address);
	if(!fexist(file_name)) return 0;
	new File:file = fopen(file_name, io_read);
	if(file)
	{
		fread(file, returned_data);
		dest = strval(returned_data);
		fclose(file);
	}
}

stock DET_SetUserData_Integer(DCC_User:user, const data_address[], value)
{
	new id[DCC_ID_SIZE], saved_data[10], file_name[150];
	DCC_GetUserId(user, id);
	format(file_name, sizeof file_name, "ui_%s_%s.discord_data", 
		id, data_address);
	format(saved_data, sizeof(saved_data), "%i", value);
	new File: file2 = fopen(file_name, io_write);
	fwrite(file2, saved_data);
	fclose(file2);
	return 1;
}

stock void:DET_GetUserData_Boolean(DCC_User:user, const data_address[], bool:dest)
{
	new id[DCC_ID_SIZE], returned_data[10], file_name[150];
	DCC_GetUserId(user, id);
	format(file_name, sizeof file_name, "ub_%s_%s.discord_data", 
		id, data_address);
	if(!fexist(file_name)) return 0;
	new File:file = fopen(file_name, io_read);
	if(file)
	{
		fread(file, returned_data);
		dest = strval(returned_data) ? true : false;
		fclose(file);
	}
}

stock DET_SetUserData_Boolean(DCC_User:user, const data_address[], bool:value)
{
	new id[DCC_ID_SIZE], saved_data[10], file_name[150];
	DCC_GetUserId(user, id);
	format(file_name, sizeof file_name, "ub_%s_%s.discord_data", 
		id, data_address);
	if(value != true && value != false)
	{
		value = false;
	}
	format(saved_data, sizeof(saved_data), "%i", value);
	new File: file2 = fopen(file_name, io_write);
	fwrite(file2, saved_data);
	fclose(file2);
	return 1;
}

stock void:DET_GetUserData_Float(DCC_User:user, const data_address[], Float:dest)
{
	new id[DCC_ID_SIZE], returned_data[10], file_name[150];
	DCC_GetUserId(user, id);
	format(file_name, sizeof file_name, "uf_%s_%s.discord_data", 
		id, data_address);
	if(!fexist(file_name)) return 0;
	new File:file = fopen(file_name, io_read);
	if(file)
	{
		fread(file, returned_data);
		dest = floatstr(returned_data);
		fclose(file);
	}
}

stock DET_SetUserData_Float(DCC_User:user, const data_address[], Float:value)
{
	new id[DCC_ID_SIZE], saved_data[10], file_name[150];
	DCC_GetUserId(user, id);
	format(file_name, sizeof file_name, "uf_%s_%s.discord_data", 
		id, data_address);
	format(saved_data, sizeof(saved_data), "%f", value);
	new File: file2 = fopen(file_name, io_write);
	fwrite(file2, saved_data);
	fclose(file2);
	return 1;
}

stock void:DET_GetUserData_String(DCC_User:user, const data_address[], dest[], size = sizeof dest)
{
	new id[DCC_ID_SIZE], returned_data[512], file_name[150];
	DCC_GetUserId(user, id);
	format(file_name, sizeof file_name, "us_%s_%s.discord_data", 
		id, data_address);
	if(!fexist(file_name)) return 0;
	new File:file = fopen(file_name, io_read);
	if(file)
	{
		fread(file, returned_data);
		format(dest, size, returned_data);
		fclose(file);
	}
}

stock DET_SetUserData_String(DCC_User:user, const data_address[], const value[])
{
	new id[DCC_ID_SIZE], saved_data[512], file_name[150];
	DCC_GetUserId(user, id);
	format(file_name, sizeof file_name, "us_%s_%s.discord_data", 
		id, data_address);
	format(saved_data, sizeof(saved_data), "%s", value);
	new File: file2 = fopen(file_name, io_write);
	fwrite(file2, saved_data);
	fclose(file2);
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
	SaveLogIntoFile("detutils_discorddata.log", "[DETUtils]: (debug) - Loading...");
	SaveLogIntoFile("detutils_discorddata.log", "[DETUtils]: (debug) - Loaded.");
	#endif
	LoadDETUtilsScript(DETUTILS_SCRIPT_DISCORDDATA);
	if(funcidx("d_dcutils2_detutilsinit") != -1)
	{
		CallLocalFunction("d_dcutils2_detutilsinit", "");
	}
	return 1;
}

#if defined _ALS_OnDETUtilsInit
	#undef OnDETUtilsInit
#else
	#define _ALS_OnDETUtilsInit
#endif

#define OnDETUtilsInit( d_dcutils2_detutilsinit(

forward d_dcutils2_detutilsinit();