/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Macros for d_vars.inc
 *
 *
 */

#define @DETUTILSVARS_DECORT__@%0\32; @DETUTILSVARS_DECORT__@
#define @variable%0(%1.datatype%2= @DETUTILSVARS_DECORT__@
#define @DETUTILSVARS_DEL__@%0\32; @DETUTILSVARS_DEL__@
#define delete @DETUTILSVARS_DEL__@
#define @DETUTILSVARS_SET__@%0\32; @DETUTILSVARS_SET__@
#define set @DETUTILSVARS_SET__@
#define @DETUTILSVARS_GET__@%0\32; @DETUTILSVARS_GET__@
#define get @DETUTILSVARS_GET__@
#define @DETVAR_%0\32; @DETVAR_

#if !defined DETUTILS_NO_FILEQUERIES
#define @DETUTILSVARS_SAVE__@%0\32; @DETUTILSVARS_SAVE__@
#define save @DETUTILSVARS_SAVE__@
#define @DETUTILSVARS_LOAD__@%0\32; @DETUTILSVARS_LOAD__@
#define load @DETUTILSVARS_LOAD__@
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

//varfunc DeclareInteger(const name[], multi, constant, constvalue = 0)
//varfunc DeclareBoolean(const name[], multi, constant, constvalue = false)
//varfunc DeclareFloat(const name[], multi, constant, Float:constvalue = 0.0000)
//varfunc DeclareString(const name[], constant, const constvalue[])

#define @DETUTILSVARS_DECORT__@INTEGER%1,%2.args%3=%4{%5}%6)%0(%7); \
	@DETVAR_%0();@DETVAR_%0() {return DET_gV_DeclareInteger(%5);}

#define @DETUTILSVARS_DECORT__@BOOLEAN%1,%2.args%3=%4{%5}%6)%0(%7); \
	@DETVAR_%0();@DETVAR_%0() {return DET_gV_DeclareBoolean(%5);}

#define @DETUTILSVARS_DECORT__@FLOAT%1,%2.args%3=%4{%5}%6)%0(%7); \
	@DETVAR_%0();@DETVAR_%0() {return DET_gV_DeclareFloat(%5);}

#define @DETUTILSVARS_DECORT__@STRING%1,%2.args%3=%4{%5}%6)%0(%7); \
	@DETVAR_%0();@DETVAR_%0() {return DET_gV_DeclareString(%5);}

// get Integer("Variable");
#define @DETUTILSVARS_GET__@Integer%1(%0) __GetIntegerValue(%0)
// get Boolean("Variable");
#define @DETUTILSVARS_GET__@Boolean%1(%0) __GetBooleanValue(%0)
// get Float("Variable");
#define @DETUTILSVARS_GET__@Float%1(%0) __GetFloatValue(%0)
// get Integer("Variable");
#define @DETUTILSVARS_GET__@String%1(%0) __GetStringValue(%0)

// set Integer("Variable");
#define @DETUTILSVARS_SET__@Integer%1(%0) __SetIntegerValue(%0)
// set Boolean("Variable");
#define @DETUTILSVARS_SET__@Boolean%1(%0) __SetBooleanValue(%0)
// set Float("Variable");
#define @DETUTILSVARS_SET__@Float%1(%0) __SetFloatValue(%0)
// set Integer("Variable");
#define @DETUTILSVARS_SET__@String%1(%0) __SetStringValue(%0)

// delete Integer("Variable");
#define @DETUTILSVARS_DEL__@Integer%1(%0) __DeleteIntegerVariable(%0)
// delete Boolean("Variable");
#define @DETUTILSVARS_DEL__@Boolean%1(%0) __DeleteBooleanVariable(%0)
// delete Float("Variable");
#define @DETUTILSVARS_DEL__@Float%1(%0) __DeleteFloatVariable(%0)
// delete Integer("Variable");
#define @DETUTILSVARS_DEL__@String%1(%0) __DeleteStringVariable(%0)

#if !defined DETUTILS_NO_FILEQUERIES

// save Integer("Variable");
#define @DETUTILSVARS_SAVE__@Integer%1(%0) __SaveIntegerVariable(%0)
// save Boolean("Variable");
#define @DETUTILSVARS_SAVE__@Boolean%1(%0) __SaveBooleanVariable(%0)
// save Float("Variable");
#define @DETUTILSVARS_SAVE__@Float%1(%0) __SaveFloatVariable(%0)
// save Integer("Variable");
#define @DETUTILSVARS_SAVE__@String%1(%0) __SaveStringVariable(%0)

// load Integer("Variable");
#define @DETUTILSVARS_LOAD__@Integer%1(%0) __LoadIntegerVariable(%0)
// load Boolean("Variable");
#define @DETUTILSVARS_LOAD__@Boolean%1(%0) __LoadBooleanVariable(%0)
// load Float("Variable");
#define @DETUTILSVARS_LOAD__@Float%1(%0) __LoadFloatVariable(%0)
// load Integer("Variable");
#define @DETUTILSVARS_LOAD__@String%1(%0) __LoadStringVariable(%0)

#endif