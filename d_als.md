# d_als.inc
SA:MP ALS Hooks - Provides `als` keyword used to create and interact with ALS hooked functons.

[Go back to home page...](README.md)

## How to start to use?
- After including `d_samp`, as other libraries, `d_als` will automatically get included. Though, in order to ALS-rehook the same callback, you'll need to reinclude `d_als` ONLY (same concept as `y_hooks` though, only "difference" is that this is not automatic!).

```pawn
#include "DETUTILS\d_samp"

public OnGameModeInit()
{
  als do("OnGameModeInit", "");
  return 1;
}

als function OnGameModeInit()
{
    printf("[samp-detutils]: (debug) - Test ALS hook called.");
    return als continue;
}

#include "DETUTILS\d_als"

als function OnGameModeInit()
{
    printf("This works! LOL");
    return als continue;
}
```
## API
- Nothing yet. Everything has been shown above.
## Messages from creator
### Notes
- No notes.
### Warnings
- No warnings!
