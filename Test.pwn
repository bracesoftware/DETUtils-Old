#define DETUTILS_DEBUG_MODE
#define DETUTILS_TESTING_MODE
#define DETUTILS_NO_MODULE_WARNINGS
//#define DETUTILS_DO_LST
//#define DETUTILS_FILTERSCRIPT_MODE
#define DETUTILS_ALS_CALL_DEBUG

#define YSI_MAX_STRING 256

#include <a_samp>
#include "DETUTILS\d_samp"

main(){}
/*
#include "DETUTILS\d_als"

#define FILE__ "d_funcgen.inc"

als function OnGameModeInit()
{
    new output[256];
    for(new i = 1; i < 1000; i++)
    {
        PWN_WRITE(FILE__,"\r\n");
        format(output,256,"#elseif DETUTILSFUNCGEN_INDEX__ == %i\r\n", i);
        PWN_WRITE(FILE__,output);
        PWN_WRITE(FILE__,"\r\n");
        PWN_WRITE(FILE__,"#undef DETUTILSFUNCGEN_INDEX__\r\n");
        format(output,256,"#define DETUTILSFUNCGEN_INDEX__ (%i)\r\n",i+1);
        PWN_WRITE(FILE__,output);
        PWN_WRITE(FILE__,"\r\n");
        format(output,256,"#define @%i@ PERCENT 0 SLASH 32; @%i@\r\n",i+1,i+1);
        PWN_WRITE(FILE__,output);
        format(output,256,"#define @DETUTILSFUNCGEN$ PERCENT 1.. PERCENT 2$ @%i@ PERCENT 1( PERCENT 2)\r\n",i+1);
        PWN_WRITE(FILE__,output);
        PWN_WRITE(FILE__,"\r\n");
        PWN_WRITE(FILE__,"#if defined detutils_debug\r\n");
        format(output,256,"#warning [samp-detutils]: (debug) - DETUTILSFUNCGEN_INDEX__ is '%i'.\r\n",i+1);
        PWN_WRITE(FILE__,output);
        PWN_WRITE(FILE__,"#endif\r\n");
        PWN_WRITE(FILE__,"\r\n");
        PWN_WRITE(FILE__,"#endinput\r\n");
    }
    return als continue;
}

//PWN_WRITE()

stock void:PWN_WRITE(const file[], const _Log[]) 
{
    new _Entry[ 128 ];
    
    format( _Entry, sizeof( _Entry ), 
        "%s", _Log );

    new File:_File;
    _File = fopen( file, io_append );

    fwrite( _File, _Entry );

    fclose( _File );
}*/

#include "DETUTILS\d_als"

als function OnGameModeInit()
{
    CallLocalFunction("LOL", "i", 1);
    printf("Returned value: `%s`", __COMPILER_STRING get_last_return());
    printf("This works! LOL");
    return als break;
}

forward LOL(ah);
public LOL(ah)
{
    __COMPILER_STRING return "ass";
}
