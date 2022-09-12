# d_rem.inc
Pawn REM - Comments.

## How to use?
```pawn
stock Func(args, ...)
{
  return ...;
}
@rem(.level = BUG) : "This code above may cause bugs!";

#define DISABLE_OPTION 3

@rem(.level = NOTE) : "This code will only work if it is placed before the include import.";

forward public Func(...) return 1;

@rem(.level = HACK) : "This is incredibly nice thing!";

$some_macro<>=#DATA;

@rem(.level = IMPORTANT) : "This is some retarded macro! Don't reuse it!";
```
- You can use it like this:

```pawn
als function OnGameModeInit(@rem(.level = BUG) : "cool";)
{
    printf("This works! LOL");
    return als break;
}
```
- Or even as a return or inside a function:

```pawn
stock cool()
{
  	@rem(.level = NOTE) : "note";
    code;
    return @rem(.level = IMPORTANT) : "really cool";;
}
```
- Anywhere!

```pawn
#define SUPER_COOL_DEFINE @rem(.level = BUG) : "cool";
```
