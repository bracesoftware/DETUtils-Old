# d_global.inc
Pawn Global - A library providing an execution of independent code - or in better words, code outside the functions.

[Go back to the home page...](../README.md)

## How to start to use?

```pawn
new str[32];
global format(str, sizeof str, "str formatted.");
```

- You can literally put any function or expression next to `global` and it'll get called before `main()`.

```pawn
global SendClientMessageToAll(-1, "Hi"); // pointless, but it'll work.
```

## Notes
- Please note that you need to reinclude `d_global.inc` before using `global` again.

```pawn
new str[32], str2[32];
global format(str, sizeof str, "str formatted.");

#include <DETUTILS\d_global> // Include again.
global format(str2, sizeof str2, "str2 formatted.");
```

- If you don't want to, don't worry. You can simply download `amx_assembly` includes and put them into your includes folder, and you'll now be able to do:

```pawn
new test_str[32];
global test1() format(test_str, sizeof test_str, "Hmm nice test");
new test_str2[32];
global test2() format(test_str2, sizeof test_str2, "Hmm nice test2");
```

- In `global NAME__() do;`, `NAME__` can be anything you want it to be. This is also valid:

```pawn
new test_str[32];
global omg() format(test_str, sizeof test_str, "Hmm nice test");
new test_str2[32];
global lol() format(test_str2, sizeof test_str2, "Hmm nice test2");
```

## API

### `CallGlobalProcedure` *

- This function can be used only if you've installed AMX assembly into your includes folder. Basically, you just use it to recall the global procedure you've made before.

```pawn
new test_str[32];
global Test() format(test_str, sizeof test_str, "Hmm nice test");

public OnGameModeInit()
{
	// Modify test_str.
	format(test_str, sizeof test_str, "OnGameModeInit called!");
	print(test_str);

	// Reset test_str back to default.
	CallGlobalProcedure("Test");
	return 1;
}
```