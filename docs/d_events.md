# d_events.inc
Pawn Events - Provides the new `@event` callback which is now a replacement for `forward` and `public`.

[Go back to the home page](../README.md)

## How to start to use?

- Now using `@event` you can create local and global events on a file level. The difference between local and global events is similar to static and global variables and functions! Local event usage is limited to only **one** file. You declare it like this:

### Local Events

```pawn
// file1.pwn
@event(.type = LOCAL) LocalEvent()
{
    print("Debug");
    return 1;
}
```

- This event can now be used only in `file1.pwn`. You can use it by calling it using `CallEvent`.

```pawn
// file1.pwn
CallEvent("LocalEvent" , "");
```

- After you start the compiled script, you should see this in the console:

```
Debug
```

- But if you try to do this:

```pawn
// It was previously used only in file1.pwn
// file2.pwn
CallEvent("LocalEvent" , "");
```

- Your code will get compiled, but you won't see any messages in the console which is not the case with global events.

### Global Events

```pawn
// file1.pwn
@event(.type = GLOBAL) GlobalEvent()
{
    print("Debug2");
    return 1;
}
```

- This is a global event, and its usage isn't limited to a single file.

```pawn
CallEvent("GlobalEvent", "");
```
- Using this in any file will work and will print the `Debug2` messages in the console.

## API

### `CallEvent`

- This is a macrofunction which, obviously, calls an event. Note that this is a MACRO, and thus the first argument is NOT a string but just a part of macro definition. Which means that this will not work:

```pawn
new funcname[32];
format(funcname, sizeof funcname, "somename");
CallEvent(funcname, "", ...);
```

## Extended API
- `d_events` extends the functionality of `d_dialog`, `d_properties` and `d_commands.`

### Dialog events

```pawn
@dialog(.type = MESSAGE_BOX, .args = {"HiEvent", "Hi", "Hello!", "OK", "NO"}) HiDialog(playerid);

@event(.type = DIALOG_EVENT) HiEvent(playerid, response, listitem, inputtext[])
{
	SendClientMessage(playerid, -1, "Hi again from HiEvent!");
    return 1;
}
```

- Whenever the player responds to a `d_dialog` dialog, he will receive a message saying `Hi again from HiEvent!`.

### Property events

```pawn
public Func()
{
	CreatePropertyEntrance("24/7 Market", 811.1299,-1616.0647,13.5469, 0, 0, true, INTERIOR_MARKET_247_1, .event = "PropertyEvent");
	return 1;
}

@event(.type = PROPERTY_EVENT) PropertyEvent(playerid, propertyid, actionid)
{
    SendClientMessage(playerid, -1, "PropertyEvent works!");
    return 1;
}
```

- Whenever the player leaves or enters a property, he will receive a message saying `PropertyEvent works!`.

### Command events
