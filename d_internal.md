# Internal libraries
- Bunch of libraries in `d_extra` whose provide various stuff and are included everywhere.

## Include documentation
Below, you have a list of all internal files.

### d_codeparse.inc
- Useless file.

### d_compilefix.inc
- Using DETUtils sometimes requires extra compiler options, these are enabled in there.

### d_funcgen.inc
- Used to generate function names for `d_als.inc`!

### d_init.inc
- Used for generally library initialisation.

### d_libtags.inc
- Entry point for all of these.

### d_mainfix.inc
- Provides a little fix where `main` function is not getting called in filterscripts!

### d_text.inc
- In this file, all of strings used in the libraries are defined.

### d_thirdpartyinclude.inc
- Using DETUtils requires some extra libraries, this include is here to manage that!

### d_version.inc
- Little include used to change library's version, including major release, minor release, patch and `R` marked release (re-release of the same version).

### d_rem.inc
- Provides the `@rem` decorator and rem levels: `IMPORTANT`, `NOTE`, `HACK` and `BUG`. View the examples below:

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

# Facts

## Versions

- There are built-in constant values named `__DETUtils` which is a hex version number, and `__DETUtilsRelease` which is hex release number.

## Not interested?
[Go back to home page...](README.md)
