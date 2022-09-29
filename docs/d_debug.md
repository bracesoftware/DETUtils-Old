# d_core_debug.inc
DETUtils Debug - Provides advanced debugging with precise information, error and warning location.

[Go back to the home page...](d_core.md)

```pawn
__DETUtilsDebug("Debug.",); // Works only with DETUTILS_DEBUG_MODE enabled.

// `,);` is required for formatting, and `__file` and `__line`.

__DETUtilsWarning("Warning.",);
__DETUtilsError("Error.",);
__DETUtilsInfo("Info.",);
```

- You can format your message.

```pawn
__DETUtilsDebug("Debug: %i.",var);
__DETUtilsWarning("Warning %i.",var);
__DETUtilsError("Error %i.",var);
__DETUtilsInfo("Info %i.",var);
```