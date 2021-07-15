#include "a_commands"

command cmd(playerid,params[])
{
    return 1;
}

alias command test( playerid , params [ ] ) = cmd;
alias command test1( playerid ,params[] )= cmd;
alias command test2(playerid,     params  [   ]   ) =cmd;
alias command test3(playerid    ,params [ ] )=cmd;

/*

Compilation results:

Pawn compiler 3.10.10	 	 	Copyright (c) 1997-2006, ITB CompuPhase

Header size:            324 bytes
Code size:             1980 bytes
Data size:             1076 bytes
Stack/heap size:      16384 bytes; estimated max. usage=48 cells (192 bytes)
Total requirements:   19764 bytes
[Finished in 0.3s]

*/
