#define DETUTILS_DEBUG_MODE
#define DETUTILS_TESTING_MODE
//#define DETUTILS_NO_MODULE_WARNINGS
#define DETUTILS_COMPAT
//#define DETUTILS_DO_LST
//#define DETUTILS_FILTERSCRIPT_MODE
//#define DETUTILS_NO_DISCORDAPI
#define DETUTILS_ALS_CALL_DEBUG
#define DISCORD_COMMAND_PREFIX '!'
#define DETUTILS_FMARGS_FUNCREPLACE

#include <a_samp>
// Because the standard "discord-connector.inc.in" cannot
// be included.
#include "dependencies\discord-connector.inc"

#include "DETUTILS\detutils"

main(){}

#if defined DETUTILS_ADVANCED_TESTS_LOL

#include "DETUTILS\d_als"

new timer;

@als() function OnGameModeInit(@rem(.level = BUG) : "lmao";)
{
    timer = DeferTask("ManualTimer", "");
    printf("This works! LOL");
    SetTimer("@stopManualTimer", 3000, false);
    return @als() break;
}

@stopManualTimer(); @stopManualTimer()
{
    return KillTimer(timer);
}

@task(.type = AUTOMATIC, .interval = 1000) AutomaticTimer()
{
    CallEvent("GlobalEvent" ,"");
    CallEvent("LocalEvent" , "");
    print("Automatic timer works.");
    return 1;
}

@task(.type = MANUAL, .interval = 1000, .repeating = true) ManualTimer()
{
    print("Manual timer works.");
    return 1;
}

@rem(.level = BUG) : "lmao";
@rem(.level = NOTE) : "lmao";
@rem(.level = HACK) : "lmao";
@rem(.level = IMPORTANT) : "lmao";

new static stock const a;

#endif
