# d_als.inc
Pawn ALS Hooks - Provides `@als()` decorator used to create and interact with ALS hooked functons.

[Go back to home page...](README.md)

## How to start to use?
- After including `detutils.inc`, as other libraries, `d_als` will automatically get included. Though, in order to ALS-rehook the same callback, you'll need to reinclude `d_als` ONLY (same concept as `y_hooks` though, only "difference" is that this is not automatic!).

```pawn
#include "DETUTILS\d_samp"

public OnGameModeInit()
{
  @als() do("OnGameModeInit", "");
  return 1;
}

@als() function OnGameModeInit()
{
    printf("1st hook called.");
    return @als() continue;
}

#include "DETUTILS\d_als"

@als() function OnGameModeInit()
{
    printf("Hook 2 called!");
    return @als() break;
}
```
## Facts and tips
### Looping
- Since this is an actually hook loop, there are `@als() continue` (or just `1`) and `@als() break` (or just `0`) return values. If you return `@als() continue`, the loop through ALS functions will continue, but if you return `@als() break` the looping through ALS functions will stop.

```pawn
@als() function OnGameModeInit()
{
    printf("This will break the loop!");
    return @als() break;
}
```
### Hooking fact
- You can literally hook anything you want! As you can see, all you need to do such are `als do` and `als function`.
- Hooking **y_timers** timers:

```pawn
task SuperCoolTask[1000]()
{
  @als() do("MyTaskName", "");
  return 1;
}

@als() function MyTaskName()
{
  print("MyTaskName called!");
  return @als() continue;
}
```
### `hook` keyword
- Instead of using `@als() function`, you can simply use `hook`. Which means this will work too:

```pawn
task SuperCoolTask[1000]()
{
  @als() do("MyTaskName", "");
  return 1;
}

hook MyTaskName()
{
  print("MyTaskName called!");
  return @als() continue;
}
```
- If you wish to, for any reason, you can disable this keyword simply by using:

```pawn
#define DETUTILS_NO_HOOK_KEYWORD
```
## Messages from creator
### Notes
- No notes.
### Warnings
- No warnings!
