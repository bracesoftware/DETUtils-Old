#include "a_commands"

command cmd(playerid,params[])
{
    return 1;
}

alias command test( playerid , params [ ] ) = cmd;
alias command test1( playerid ,params[] )= cmd;
alias command test2(playerid,     params  [   ]   ) =cmd;
alias command test3(playerid    ,params [ ] )=cmd;