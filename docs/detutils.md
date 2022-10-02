# detutils.inc

DETUtils Entry Point - The main file which is included in order to use the DETUtils libraries, because including them like they're standalones is not a good idea.

## How to start to use?

- Start to use the DETUtils by including `detutils.inc`:

```pawn
#include <DETUTILS\detutils>
```

- Before including the entry point, you can define some compile-time options in order to configure the DETUtils libraries the way you want to.

## Compile-time options
### `DETUTILS_DEV_MODE`
- This is a special build mode I use while developing the DETUtils code. It basically enables `DETUTILS_DEBUG_MODE`, `DETUTILS_TESTING_MODE` and disables `DETUTILS_NO_MODULE_WARNINGS` if it was enabled.

```pawn
#define DETUTILS_DEV_MODE
```

### `DETUTILS_DEBUG_MODE`

- By default, DETUtils includes rarely print any debug messages in the console. Enabling the `DETUTILS_DEBUG_MODE` flag will turn on the debug mode - this is really important and useful for beta feature testing!

```pawn
#define DETUTILS_DEBUG_MODE
```

### `DETUTILS_TESTING_MODE`

- If you want to test DETUtils but don't know where to start, simply enable the `DETUTILS_TESTING_MODE` flag and the `d_testing_internal.inc` will be included. In the basic terms, `d_testing_entry` is a just random gamemode written using the DETUtils includes.

```pawn
#define DETUTILS_TESTING_MODE
```

### `DETUTILS_NO_MODULE_WARNINGS`

- By default, DETUtils includes will show you a warning in case something has been disabled, changed or whatsoever. The example of those warnings is below.

```
../detutils/DETUTILS\d_core\d_funcgen.inc(9165) : warning 237: user warning: [DETUtils]: (debug) - DETUTILSFUNCGEN_INDEX__ is '0'.
../detutils/DETUTILS\d_core\d_funcgen.inc(34) : warning 237: user warning: [DETUtils]: (debug) - DETUTILSFUNCGEN_INDEX__ is '1'.
../detutils/DETUTILS\detutils.inc(653) : warning 237: user warning: [DETUtils]: (warning) - testmode :: Testing mode is enabled. Remove `#define DETUTILS_TESTING_MODE` from your code to disable it.
../detutils/DETUTILS\d_core\d_funcgen.inc(49) : warning 237: user warning: [DETUtils]: (debug) - DETUTILSFUNCGEN_INDEX__ is '2'.
```

- If you see these annoying, you can disable them by using:

```pawn
#define DETUTILS_NO_MODULE_WARNINGS
```

### `DETUTILS_COMPAT`

- This compile-time option enables the old keyword-based syntax since the DETUtils syntax is now mainly based on decorator macros.

```pawn
#define DETUTILS_COMPAT
```

### `DETUTILS_FILTERSCRIPT_MODE`

- If you're writing a filterscript, make sure that you enabled the `DETUTILS_FILTERSCRIPT_MODE` flag for fixes and optimization!

```pawn
#define DETUTILS_FILTERSCRIPT_MODE
```

### `DETUTILS_ALS_CALL_DEBUG`

- This is a flag which enables the debug mode for the `d_als` include. If this is not enabled, `d_als` won't spam your console with hooked function call messages. 

```pawn
#define DETUTILS_ALS_CALL_DEBUG
```

### `DETUTILS_NO_<UPPER-CASE LIBRARY NAME>`

- By default, DETUtils includes all the libraries at once. You can disable a certain library for any reason (i.e incompatibility issues, or other bugs that are yet unknown) by doing:

```pawn
#define DETUTILS_NO_<UPPER-CASE LIBRARY NAME>
```

- For examble:

```pawn
#define DETUTILS_NO_ALS
```

- This will uninclude `d_als.inc`.

### `DETUTILS_NO_<UPPER-CASE LIBRARY NAME>_<UPPER-CASE SUBLIBRARY NAME>`

- Almost every DETUtils library is divided into sublibraries or rather submodules. They're often optional and thus you can disable them for any reason by using:

```pawn
#define DETUTILS_NO_<UPPER-CASE LIBRARY NAME>_<UPPER-CASE SUBLIBRARY NAME>
```

- For examble:

```pawn
// Only disable d_vars_circular.inc submodule.
#define DETUTILS_NO_VARS_CIRCULAR
```

- This will uninclude `d_vars_circular.inc`. Please note that not all submodules are optional, so doing this:

```pawn
#define DETUTILS_NO_COMMANDS_SETUP
```
- Won't disable `d_commands_setup` because it's a required library. In this case, you can only do this:

```pawn
// Disable the whole d_commands.inc module.
#define DETUTILS_NO_COMMANDS
```

### `DETUTILS_NO_SSCANF`

- By default, DETUtils package entry includes its own `sscanf` implementation, you can disable it with:

```pawn
#define DETUTILS_NO_SSCANF
```

### `DETUTILS_FMARGS_FUNCREPLACE`
- Read more about this compile-time option [here](d_fmargs.md).

### `DETUTILS_NO_ANDROID_CHECK`
- Disables the `d_server` Android client check features.

### `DETUTILS_STATIC_MODE`
- Makes almost all of internal definitions inaccessible by other third-party includes.

```pawn
#define DETUTILS_STATIC_MODE
```

### `DETUTILS_DO_LST`
- Basically, does the same thing as:

```pawn
#pragma option -l
```

### `DETUTILS_NO_REM`

- Disables the internal `d_rem.inc` library.