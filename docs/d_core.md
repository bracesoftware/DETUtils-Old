### Internal (`d_core`) libraries

- The folder containing all the libraries used by the DETUtils system itself.

[Go back to the home page...](../README.md)

| Library      | Description                                                                                |
| -------------------- | ------------------------------------------------------------------------------------------ |
| d_core_errors.inc | The internal library other DETUtils libraries use to log runtime errors that occured unexpectedly. |
| d_core_compilefix.inc | Using DETUtils sometimes requires extra compiler options, those are enabled in there. |
| d_core_funcgen.inc | Used to generate function names for `d_als`, `d_timers` and `d_testing`! |
| d_core_init.inc | Used for library initialisation. |
| d_core_funcs.inc | Contains functions used all throughout the DETUtils package and the core itself. |
| d_core_mainfix.inc | Provides a little fix where `main` function is not getting called in filterscripts! |
| d_core_text.inc | In this file, all of strings used in the libraries are defined. |
| d_core_thirdpartyinclude.inc | Using DETUtils requires some extra libraries, this include is here to manage that! |
| d_core_version.inc | Little include used to change library's version, including major release, minor release, patch and `R` marked release (re-release of the same version). There are also built-in constant values named `__DETUtils` which is a hex version number, and `__DETUtilsRelease` which is hex release number. |
| [d_core_rem.inc](d_rem.md) | Provides the `@rem` decorator and rem levels: `IMPORTANT`, `NOTE`, `HACK` and `BUG`. |
| [d_core_memory.inc](d_memory.md) | This is strictly an internal DETUtils library, which is used to modify the internal memory values to manipulate the includes. For example: `@detmemory UNUSED_RACE_INDEX 0` the last unused race index will be set to `0` which may cause lot of problems if you do it yourself. |
| d_core_entry.inc | The whole DETUtils entry point. Without it, the package wouldn't work as nothing would be included. |
| [d_core_debug.inc](d_debug.md) | Provides advanced debugging with precise information, error and warning location. |
