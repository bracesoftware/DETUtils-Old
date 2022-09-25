/*
 *
 * THIRD PARTY INCLUDES
 *
 *
 *
 * DETUtils core
 *
 *
 */

#if !defined @DETUTILSCMD_NO_PARSER__

    #tryinclude <code-parse>
    #tryinclude "code-parse"

    #if !defined _INC_code_parse_inc

        #warning [DETUtils]: (warning) - Missing code parser for Pawn function analysing.
     
    #endif

#endif

#tryinclude <amx_header>
#tryinclude "amx_header"

#if !defined AMX_HEADER_INC

    #warning [DETUtils]: (warning) - Missing AMX assembly libraries for Pawn AMX header reading.
 
#endif

#if !defined DETUTILS_NO_DISCORDAPI

    #tryinclude <discord-connector>
    #tryinclude "discord-connector"

    #if !defined dcconnector_included

        #warning [DETUtils]: (warning) - Missing the Discord Connector plugin natives.
     
    #endif

#endif