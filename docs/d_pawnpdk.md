# d_pawnpdk.inc
Pawn Plugin Development Kit - This include contains a set of macros whose allow you to write SA:MP "plugins" in Pawn.

[Go back to the home page...](../README.md)

## How to start to use?
### Writing a plugin
- Let's make a plugin source code file named `hello.pwn` in the `plugins` folder. This is the code you should write:

```pawn
#include <a_samp>
#include "../detutils\DETUTILS\detutils"

```

- Let's add an initialization point.

```pawn
PAWN_PDK::plugincode.OnInit()
{
	print("Hello Plugin by DEntisT Loaded");
	return 1;
}
```
- The code above will print `Hello Plugin by DEntisT Loaded` when the plugin loads.
- Now let's make a native.

```pawn
PAWN_PDK::register.Native PrintHello(message[])
{
	PAWN_PDK::call.Callback("PluginCallback", "");
	print(message);
	return 1;
}
```
- This will register an useable native which will call a callback `PluginCallback` defined either in the gamemode or an include file you make using `d_pawnpdk`. 
- Alright, the `hello.pwn` file in the `plugins` folder should look like this:

```pawn
#include <a_samp>
#include "../detutils\DETUTILS\detutils"

PAWN_PDK::plugincode.OnInit()
{
	print("Hello Plugin by DEntisT Loaded");
	return 1;
}

PAWN_PDK::register.Native PrintHello(message[])
{
	PAWN_PDK::call.Callback("PluginCallback", "");
	print(message);
	return 1;
}
```

### Using the plugin functions in the script
- Now let's use this native and this function in our gamemode. Firstly, let's use the `OnPawnPDKInit` callback.

```pawn
public OnPawnPDKInit()
{
    return 1;
}
```
- Let's load our plugin.

```pawn
public OnPawnPDKInit()
{
    PAWN_PDK::plugin "hello";
    return 1;
}
```

- `PAWN_PDK::plugin <>` loads the plugin only by its name, note that you can load a plugin anywhere and at any time. Now let's use one of the plugin's functions.

```pawn
public OnPawnPDKInit()
{
    PAWN_PDK::plugin "hello";
    PAWN_PDK::using native PrintHello("s", "Plugin function works!");
    return 1;
}
```

- Now let's also use our callback. Firstly, we need to do a forward declaration of it.

```pawn
PAWN_PDK::forward PluginCallback();
```

- Now let's do anything we want within the callback.

```pawn
PAWN_PDK::public PluginCallback()
{
    print("PluginCallback called.");
    return 1;
}
```

- Alright, we finished, this is how your gamemode should look like:

```pawn
#include <a_samp>
#include "../detutils\DETUTILS\detutils"

public OnPawnPDKInit()
{
    PAWN_PDK::plugin "hello";
    PAWN_PDK::using native PrintHello("s", "Plugin function works!");
    return 1;
}

PAWN_PDK::forward PluginCallback();
PAWN_PDK::public PluginCallback()
{
    print("PluginCallback called.");
    return 1;
}
```

- Now let's run the plugin.

### Running the plugin
- Running the plugin is the easiest part. Just run the server and you should see the following in the console:

```
Hello Plugin by DEntisT Loaded
PluginCallback called.
Plugin function works!
```
