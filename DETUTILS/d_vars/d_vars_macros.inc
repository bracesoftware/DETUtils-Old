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
#define @DETUTILSVARS_RENAME__@%0\32; @DETUTILSVARS_RENAME__@
#define rename @DETUTILSVARS_RENAME__@
#define @DETVAR_%0\32; @DETVAR_

#if !defined DETUTILS_NO_FILEQUERIES
#define @DETUTILSVARS_SAVE__@%0\32; @DETUTILSVARS_SAVE__@
#define save @DETUTILSVARS_SAVE__@
#define @DETUTILSVARS_LOAD__@%0\32; @DETUTILSVARS_LOAD__@
#define load @DETUTILSVARS_LOAD__@
#endif

// circular arrays:

#define @DETUTILSVARS_ADD__@%0\32; @DETUTILSVARS_ADD__@
#define add @DETUTILSVARS_ADD__@

// stack:

#define @DETUTILSVARS_PUSH__@%0\32; @DETUTILSVARS_PUSH__@
#define push @DETUTILSVARS_PUSH__@

#define @DETUTILSVARS_POP__@%0\32; @DETUTILSVARS_POP__@
#define pop @DETUTILSVARS_POP__@

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
#define @DETUTILSVARS_GET__@Integer __GetIntegerValue
// get Boolean("Variable");
#define @DETUTILSVARS_GET__@Boolean __GetBooleanValue
// get Float("Variable");
#define @DETUTILSVARS_GET__@Float __GetFloatValue
// get String("Variable");
#define @DETUTILSVARS_GET__@String __GetStringValue

// set Integer("Variable");
#define @DETUTILSVARS_SET__@Integer __SetIntegerValue
// set Boolean("Variable");
#define @DETUTILSVARS_SET__@Boolean __SetBooleanValue
// set Float("Variable");
#define @DETUTILSVARS_SET__@Float __SetFloatValue
// set String("Variable");
#define @DETUTILSVARS_SET__@String __SetStringValue

// delete Integer("Variable");
#define @DETUTILSVARS_DEL__@Integer __DeleteIntegerVariable
// delete Boolean("Variable");
#define @DETUTILSVARS_DEL__@Boolean __DeleteBooleanVariable
// delete Float("Variable");
#define @DETUTILSVARS_DEL__@Float __DeleteFloatVariable
// delete String("Variable");
#define @DETUTILSVARS_DEL__@String __DeleteStringVariable

// rename Integer("Variable", "Int");
#define @DETUTILSVARS_RENAME__@Integer __RenameIntegerVariable
// rename Boolean("Variable", "Bool");
#define @DETUTILSVARS_RENAME__@Boolean __RenameBooleanVariable
// rename Float("Variable", "Float");
#define @DETUTILSVARS_RENAME__@Float __RenameFloatVariable
// rename String("Variable", "String");
#define @DETUTILSVARS_RENAME__@String __RenameStringVariable

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
#define @DETUTILSVARS_GET__@CircularInteger __GetIntegerCircularArrayValue

// set CircularInteger("Variable");
#define @DETUTILSVARS_ADD__@CircularInteger __AddIntegerCircularArrayValue

// delete CircularInteger("Variable");
#define @DETUTILSVARS_DEL__@CircularInteger __DeleteIntegerCircularArray

// rename CircularInteger("Variable", "Int");
#define @DETUTILSVARS_RENAME__@CircularInteger __RenameIntegerCircularArray

// stack:

#define @DETUTILSVARS_DECORT__@STACK_INTEGER%1,%2.args%3=%4{%5}%6)%0(%7); \
    @DETVAR_%0();@DETVAR_%0() {return DET_gV_DeclareIntegerStack(%5);}

// get StackInteger("Variable");
#define @DETUTILSVARS_GET__@StackInteger __GetIntegerStackValue

// push StackInteger("Variable");
#define @DETUTILSVARS_PUSH__@StackInteger __PushIntegerStackValue

// pop StackInteger("Variable");
#define @DETUTILSVARS_POP__@StackInteger __PopIntegerStackValue

// delete StackInteger("Variable");
#define @DETUTILSVARS_DEL__@StackInteger __DeleteIntegerStack

// rename StackInteger("Variable", "Int");
#define @DETUTILSVARS_RENAME__@StackInteger __RenameIntegerStack