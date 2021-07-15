#include "a_commands"

main()
{
    print("GameMode loaded.");
}

command cmd(playerid,params[])
{
    return 1;
}

alias command test( playerid , params [ ] ) = cmd;
alias command test1( playerid ,params[] )= cmd;
alias command test2(playerid,     params  [   ]   ) =cmd;
alias command test3(playerid    ,params [ ] )=cmd;

debug command test()
{
    printf("Command %s successfully called.", GetDebuggedCommandName ( ));
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

/*

Compilation results:

Pawn compiler 3.10.10	 	 	Copyright (c) 1997-2006, ITB CompuPhase

Header size:            324 bytes
Code size:             1980 bytes
Data size:             1076 bytes
Stack/heap size:      16384 bytes; estimated max. usage=48 cells (192 bytes)
Total requirements:   19764 bytes
[Finished in 0.3s]

Debug output:


[16:25:11] Command /cmd successfully called.
[16:25:15] Command /test successfully called.
[16:25:17] Command /test1 successfully called.
[16:25:19] Command /test3 successfully called.
[16:25:22] Command /test2 successfully called.

*/
