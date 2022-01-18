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
1. System is more stable than before but it still has problems and bugs.
2. System sends fake cheating reports with cheat type **CHEAT_TYPE_HEALTH**.

### Visual game issues
1. ``FadePlayerScreen(...);`` is not working.
2. ``FadePlayerScreen(...);`` still calls ``OnPlayerScreenFade(...);`` callback, although that did not happen.

### Custom prefixed command processor issues
1. Custom prefixed commands aren't working as before for some reason. Any prefix provided will still call the command.
----------------------------------------
