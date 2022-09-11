# d_toml.inc
SA:MP TOML - Save, load and manage TOML files using the Pawn API.

## How to start to use?
NOTE: Function names start with lowercase letters.
### `tomlexist`
- Checks if the TOML file exist.

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

```
[toml]

```
