#define DEV_MODE // Tells the library that we're testing it, so it includes a_samp.inc itself!

#include "a_interiors" // We include the library.

main()
{
  print("GameMode loaded."); // To prevent runtime error 4.
}

public OnGameModeInit()
{
  CreateCustomInterior("PoliceStation", 243.66, 345.21, 12.78, 9.0, 4564.8, 12.8, 1, 0, 1, 0); // Create interior named PoliceStation.

  SetInteriorEntranceCustomAngles(GetLastInterioridUsed(), 234.453, 0.23); // Set int enter and exit angles

  CreateCustomInterior("Bank", 243.66, 345.21, 12.78, 9.0, 4564.8, 12.8, 1, 0, 1, 0); // Create interior named Bank

    SetInteriorEntranceCustomAngles(GetLastInterioridUsed(), 234.453, 0.23); // Set interior entrance and exit angles. - (again)

    return 1;
}


interior PoliceStation(playerid) //we declare literal interior function
{
  if(IsInteriorActionPerformed(INTERIOR_ACTION_ENTER)) //when player enter the police station
  {
    SendClientMessage(playerid, -1, "You entered police station."); // it does this
  }
  else if(IsInteriorActionPerformed(INTERIOR_ACTION_ENTER)) // when exit
  {
    SendClientMessage(playerid, -1, "You exited police station."); // does this
  }
  return 1;
}

interior Bank(playerid) // we declare literal interior function
{
    if(IsInteriorActionPerformed( INTERIOR_ACTION_EXIT )) 
    return SendClientMessage(playerid, -1, "See you again!"); // when player exit bank it returns a message
    return 1;
}

/*

Compilation results:

Pawn compiler 3.10.4      Copyright (c) 1997-2006, ITB CompuPhase

Header size:            864 bytes
Code size:             7964 bytes
Data size:            65436 bytes
Stack/heap size:      16384 bytes; estimated max. usage=316 cells (1264 bytes)
Total requirements:   90648 bytes
[Finished in 0.4s]

Debug output:

[13:35:27] Interior 'PoliceStation' successfully created, entrance is set to: 243.660003, 345.209991, 12.779999.
[13:35:27] Interior 'PoliceStation' has an id 1.
[13:35:27] Interior 'Bank' successfully created, entrance is set to: 243.660003, 345.209991, 12.779999.
[13:35:27] Interior 'Bank' has an id 2.
[13:35:27] |======================================|
[13:35:27]             a_interiors.inc             
[13:35:27]           Successfully loaded!          
[13:35:27]                                         
[13:35:27]                By: DEntisT              
[13:35:27] |======================================|
[13:35:27] GameMode loaded.

*/