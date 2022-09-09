# Information about the program

- Below you can see a library test log. Since this is an open-sourced library, I've decided to make this test log thing so I can log my progress and that progress is now available to everyone.

**NOTE:** This version of the library is a BETA version and is really unstable.

**WARNING:** I started test logging program on **13 Jan 2022**.

# Library test log
----------------------------------------
## Test no. 1 - 13 Jan 2022

- Tested by: DEntisT-ofc
- Version: 1.5.2

### Anti-cheat issues
1. System is really unstable. 
2. System sends fake cheating reports with cheat types: **CHEAT_TYPE_HEALTH**, **CHEAT_TYPE_ARMOUR** and **CHEAT_TYPE_SKINCHANGER**.

### Visual game issues
1. ``FadePlayerScreen(...);`` is not working.
2. ``FadePlayerScreen(...);`` still calls ``OnPlayerScreenFade(...);`` callback, although that did not happen.
----------------------------------------

## Test no. 1 - 18 Jan 2022

- Tested by: DEntisT-ofc
- Version: 1.5.5

### Anti-cheat issues
1. System still sends fake cheating reports with cheat type **CHEAT_TYPE_HEALTH**.

### Visual game issues
1. ``FadePlayerScreen(...);`` is not working.
2. ``FadePlayerScreen(...);`` still calls ``OnPlayerScreenFade(...);`` callback, although that did not happen.

### Custom prefixed command processor issues
1. Custom prefixed commands aren't working as before for some reason. Any prefix provided will still call the command.
----------------------------------------
## Test no. 1 - 20 Jan 2022

- Tested by: DEntisT-ofc
- Version: 1.5.6

### Anti-cheat issues
1. System is more stable than before but it still has problems and bugs.
2. System sends fake cheating reports with cheat type **CHEAT_TYPE_HEALTH**.

### Visual game issues
1. ``FadePlayerScreen(...);`` is not working.
2. ``FadePlayerScreen(...);`` still calls ``OnPlayerScreenFade(...);`` callback, although that did not happen.

### Fixes
- Fixed the issue with custom prefixed commands processor.
----------------------------------------
## Test no. 1 - 24 Jan 2022

- Tested by: DEntisT-ofc
- Version: 1.5.8

### Fixes

- Everything at a glance! Besides the ``FadePlayerScreen(...)`` TextDraw is not showing, fixing it soon.

----------------------------------------
## Test no. 1 - 22 Feb 2022

- Tested by: DEntisT-ofc
- Version: 2.0.2-R5

## Anti-cheat issues

- Health and armour anti-cheat is not working correctly.

### Fixes

- Everything at a glance!

----------------------------------------
## Test no. 1 - 9 Sep 2022

- Tested by: DEntisT
- Version: 2.0.7-R1

## Anti-cheat issues

- Health and armour anti-cheat is not working correctly.

## Server crashes

- Unexpected and unknown crashes are occuring. They weren't a thing a week ago.

### Fixes

- Everything at a glance!

----------------------------------------
