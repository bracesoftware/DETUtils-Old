#define DEV_MODE // Tells the library that we're testing it, so it includes a_samp.inc itself!

#include "a_commands" // We include a_commands.

main()
{
    print("GameMode loaded."); // This is just to avoid bad-entry-point runtime error.
}

command cmd(playerid,params[])
{
    return 1; // We made a command.
}

alias command test( playerid , params [ ] ) = cmd; // We make command alias. Don't mind that spacing in these alias commands 
                                                   // below, I was testing will messing with syntax give out 
                                                   // errors - since this is a macrofunction.

alias command test1( playerid ,params[] )= cmd;

alias command test2(playerid,     params  [   ]   ) =cmd;

alias command test3(playerid    ,params [ ] )=cmd;

debug command test()
{
    printf("Command %s successfully called.", GetDebuggedCommandName ( )); // We "attach" debug function to a command.
                                                                           // So all code between brackets will be executed 
                                                                           // after player submits to perform specific command.
    return 1;
}

debug command test1()
{
    printf("Command %s successfully called.", GetDebuggedCommandName( ));
    return 1;
}

debug command test2()
{
    printf("Command %s successfully called.", GetDebuggedCommandName());
    return 1;
}

debug command test3()
{
    printf("Command %s successfully called.", GetDebuggedCommandName ());
    return 1;
}

debug command cmd()
{
    printf("Command %s successfully called.", GetDebuggedCommandName ( ));
    return 1;
}