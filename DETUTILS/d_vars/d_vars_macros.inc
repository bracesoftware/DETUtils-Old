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
#define DETUTILS_delete @DETUTILSVARS_DEL__@
#define @DETUTILSVARS_SET__@%0\32; @DETUTILSVARS_SET__@
#define DETUTILS_set @DETUTILSVARS_SET__@
#define @DETUTILSVARS_GET__@%0\32; @DETUTILSVARS_GET__@
#define DETUTILS_get @DETUTILSVARS_GET__@
#define @DETUTILSVARS_RENAME__@%0\32; @DETUTILSVARS_RENAME__@
#define DETUTILS_rename @DETUTILSVARS_RENAME__@
#define @DETVAR_%0\32; @DETVAR_

#if !defined DETUTILS_NO_FILEQUERIES
#define @DETUTILSVARS_SAVE__@%0\32; @DETUTILSVARS_SAVE__@
#define DETUTILS_save @DETUTILSVARS_SAVE__@
#define @DETUTILSVARS_LOAD__@%0\32; @DETUTILSVARS_LOAD__@
#define DETUTILS_load @DETUTILSVARS_LOAD__@
#endif

// circular arrays:

#define @DETUTILSVARS_ADD__@%0\32; @DETUTILSVARS_ADD__@
#define DETUTILS_add @DETUTILSVARS_ADD__@

// stack:

#define @DETUTILSVARS_PUSH__@%0\32; @DETUTILSVARS_PUSH__@
#define DETUTILS_push @DETUTILSVARS_PUSH__@

#define @DETUTILSVARS_POP__@%0\32; @DETUTILSVARS_POP__@
#define DETUTILS_pop @DETUTILSVARS_POP__@

// compatibility mode:

#if DETUTILS_KEYWORD__(delete)
    #define delete DETUTILS_delete
#endif
#if DETUTILS_KEYWORD__(set)
    #define set DETUTILS_set
#endif
#if DETUTILS_KEYWORD__(get)
    #define get DETUTILS_get
#endif
#if DETUTILS_KEYWORD__(rename)
    #define rename DETUTILS_rename
#endif
#if DETUTILS_KEYWORD__(save)
    #define save DETUTILS_save
#endif
#if DETUTILS_KEYWORD__(load)
    #define load DETUTILS_load
#endif
#if DETUTILS_KEYWORD__(add)
    #define add DETUTILS_add
#endif
#if DETUTILS_KEYWORD__(push)
    #define push DETUTILS_push
#endif
#if DETUTILS_KEYWORD__(pop)
    #define pop DETUTILS_pop
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
#define @DETUTILSVARS_GET__@Integer _D_VARS_giv__
// get Boolean("Variable");
#define @DETUTILSVARS_GET__@Boolean _D_VARS_gbv__
// get Float("Variable");
#define @DETUTILSVARS_GET__@Float _D_VARS_gfv__
// get String("Variable");
#define @DETUTILSVARS_GET__@String _D_VARS_gsv__

// set Integer("Variable");
#define @DETUTILSVARS_SET__@Integer _D_VARS_siv__
// set Boolean("Variable");
#define @DETUTILSVARS_SET__@Boolean _D_VARS_sbv__
// set Float("Variable");
#define @DETUTILSVARS_SET__@Float _D_VARS_sfv__
// set String("Variable");
#define @DETUTILSVARS_SET__@String _D_VARS_ssv__

// delete Integer("Variable");
#define @DETUTILSVARS_DEL__@Integer _D_VARS_div__
// delete Boolean("Variable");
#define @DETUTILSVARS_DEL__@Boolean _D_VARS_dbv__
// delete Float("Variable");
#define @DETUTILSVARS_DEL__@Float _D_VARS_dfv__
// delete String("Variable");
#define @DETUTILSVARS_DEL__@String _D_VARS_dsv__

// rename Integer("Variable", "Int");
#define @DETUTILSVARS_RENAME__@Integer _D_VARS_riv__
// rename Boolean("Variable", "Bool");
#define @DETUTILSVARS_RENAME__@Boolean _D_VARS_rbv__
// rename Float("Variable", "Float");
#define @DETUTILSVARS_RENAME__@Float _D_VARS_rfv__
// rename String("Variable", "String");
#define @DETUTILSVARS_RENAME__@String _D_VARS_rsv__

#if !defined DETUTILS_NO_FILEQUERIES

// save Integer("Variable");
#define @DETUTILSVARS_SAVE__@Integer __SaveIntegerVariable
// save Boolean("Variable");
#define @DETUTILSVARS_SAVE__@Boolean __SaveBooleanVariable
// save Float("Variable");
#define @DETUTILSVARS_SAVE__@Float __SaveFloatVariable
// save String("Variable");
#define @DETUTILSVARS_SAVE__@String __SaveStringVariable

// load Integer("Variable");
#define @DETUTILSVARS_LOAD__@Integer __LoadIntegerVariable
// load Boolean("Variable");
#define @DETUTILSVARS_LOAD__@Boolean __LoadBooleanVariable
// load Float("Variable");
#define @DETUTILSVARS_LOAD__@Float __LoadFloatVariable
// load String("Variable");
#define @DETUTILSVARS_LOAD__@String __LoadStringVariable

#endif

// circular arrays:

#define @DETUTILSVARS_DECORT__@CIRCULAR_INTEGER%1,%2.args%3=%4{%5}%6)%0(%7); \
    @DETVAR_%0();@DETVAR_%0() {return DET_gV_DeclareIntegerCircArray(%5);}

// get CircularInteger("Variable");
#define @DETUTILSVARS_GET__@CircularInteger _D_VARS_gicav__

// set CircularInteger("Variable");
#define @DETUTILSVARS_ADD__@CircularInteger _D_VARS_aicav__

// delete CircularInteger("Variable");
#define @DETUTILSVARS_DEL__@CircularInteger _D_VARS_dica__

// rename CircularInteger("Variable", "Int");
#define @DETUTILSVARS_RENAME__@CircularInteger _D_VARS_rica__

// stack:

#define @DETUTILSVARS_DECORT__@STACK_INTEGER%1,%2.args%3=%4{%5}%6)%0(%7); \
    @DETVAR_%0();@DETVAR_%0() {return DET_gV_DeclareIntegerStack(%5);}

// get StackInteger("Variable");
#define @DETUTILSVARS_GET__@StackInteger _D_VARS_gisv__

// push StackInteger("Variable");
#define @DETUTILSVARS_PUSH__@StackInteger _D_VARS_pisv__

// pop StackInteger("Variable");
#define @DETUTILSVARS_POP__@StackInteger _D_VARS_pisv__2

// delete StackInteger("Variable");
#define @DETUTILSVARS_DEL__@StackInteger _D_VARS_dis__

// rename StackInteger("Variable", "Int");
#define @DETUTILSVARS_RENAME__@StackInteger _D_VARS_ris__