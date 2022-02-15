/*
 * 
 * SA:MP DEntisT's Utilities
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
#define @DETVAR_%0\32; @DETVAR_

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
