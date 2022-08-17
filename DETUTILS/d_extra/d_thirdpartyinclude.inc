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

#if !defined _INC_code_parse_inc

    #warning [samp-detutils]: (warning) - Missing code parser for Pawn function analysing.

#elseif defined _INC_code_parse_inc

    #include "d_codeparse"

#endif

#endif