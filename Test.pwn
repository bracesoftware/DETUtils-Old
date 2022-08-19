#define DETUTILS_DEBUG_MODE
#define DETUTILS_TESTING_MODE
#define DETUTILS_NO_MODULE_WARNINGS
//#define DETUTILS_DO_LST
//#define DETUTILS_FILTERSCRIPT_MODE
#define DETUTILS_ALS_CALL_DEBUG

#include <a_samp>

#include "../include/discord-connector"
#define DISCORD_COMMAND_PREFIX '!'
#include "../detutils/DETUTILS\d_samp"

main(){}

#include "../detutils/DETUTILS\d_als"

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