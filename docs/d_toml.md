# d_toml.inc
SA:MP TOML - Save, load and manage TOML files using the Pawn API.

[Go back to the home page...](../README.md)

## How to start to use?
NOTE: Function names start with lowercase letters.
### Management functions
- These functions are used to manage a TOML file.
### `tomlexist`
- Checks if the TOML file exists.

```pawn
tomlexist("file"); // checks for file: file.toml
```

### `tomlremove`
- Removes a TOML file.

```pawn
tomlremove("file"); // removes the file: file.toml
```

### `tomlcreate`
- This obviously creates a TOML file.

```pawn
tomlcreate("file"); // this creates the file: file.toml
```

- The content of `file.toml` should be:

```toml
[toml]

```
### "Get" functions
- Used to get key values.

### `tomlgetint`
- Get a integer key. Let's say this is your TOML file:

```toml
[toml]

adminlvl=0
```

```pawn
new admin = tomlgetint("file", "adminlvl");
```
- Variable `admin` will be `0`.

### `tomlgetbool`
- Get a boolean key. Let's say this is your TOML file:

```toml
[toml]

player=false
```

```pawn
new player = tomlgetbool("file", "player");
```
- Variable `player` will be `0`.

### `tomlgetfloat`
- Get a float key. Let's say this is your TOML file:

```toml
[toml]

coords=23.73
```

```pawn
new Float:coords = tomlgetfloat("file", "coords");
```
- Variable `Float:coords` will be `23.73`.

### `tomlgetstr`
- Get a string key. Let's say this is your TOML file:

```toml
[toml]

msg="string"
```

```pawn
SendClientMessage(playerid, -1, tomlgetstr("file", "msg"));
```
- Player will receive a message saying `"string"`.

### "Set" functions
- Used to get key values.

### `tomlsetint`
- Set a integer key.

```pawn
tomlsetint("file", "adminlvl", 1);
```

### `tomlsetbool`
- Set a boolean key.


```pawn
tomlsetbool("file", "player", true);
```

### `tomlsetfloat`
- Set a float key.

```pawn
tomlsetfloat("file", "coords", 24.36);
```


### `tomlsetstr`
- Set a string key.

```pawn
tomlsetstr("file", "msg", "Hello World.");
```

## Extras
- Extra functions.
### `tomlwritecomment`
- Write a TOML comment.

```pawn
tomlwritecomment("file", "This is a comment.");
```
- Your TOML should look like this:

```toml
[toml]
# This is a comment.
```

### `tomlwritetable`
- Write a TOML table.

```pawn
tomlwritetable("file", "test.table");
```

- Your TOML should look like this:

```toml
[toml]
[test.table]
```
