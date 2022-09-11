# d_yaml.inc
SA:MP YAML - Save, load and manage YAML files using the Pawn API.

[Go back to the home page...](../README.md)

## Example
- For the impatient:

**`script.pwn`**
```pawn
yamlremove("test");
printf("YAML test.yaml exists : %i", yamlexist("test"));
yamlcreate("test");
yamlwritecomment("test", "This is a comment.");
yamlsetint("test", "int", 1);
yamlsetbool("test", "bool", false);
yamlsetfloat("test", "float", 0.1);
yamlsetstr("test", "string", "Hello World.");
yamlwritetable("test", "test.table");
printf("YAML test.yaml exists : %i", yamlexist("test"));
printf("YAML val 'int' is : '%i'", yamlgetint("test", "int"));
printf("YAML val 'bool' is : '%i'", yamlgetbool("test", "bool"));
printf("YAML val 'float' is : '%f'", yamlgetfloat("test", "float"));
printf("YAML val 'string' is : '%s'", yamlgetstr("test", "string"));
```
**`test.yaml`**
```yaml

# This is a comment.
int: 1
bool: false
float: 0.100000
string: Hello World.
[test.table]
```
**Console output:**
```
YAML test.yaml exists : 0
YAML test.yaml exists : 1
YAML val 'int' is : '1'
YAML val 'bool' is : '0'
YAML val 'float' is : '0.100000'
YAML val 'string' is : 'Hello World.'
```

## How to start to use?
NOTE: Function names start with lowercase letters.
### Management functions
- These functions are used to manage a YAML file.
### `yamlexist`
- Checks if the YAML file exists.

```pawn
yamlexist("file"); // checks for file: file.yaml
```

### `yamlremove`
- Removes a YAML file.

```pawn
yamlremove("file"); // removes the file: file.yaml
```

### `yamlcreate`
- This obviously creates a YAML file.

```pawn
yamlcreate("file"); // this creates the file: file.yaml
```

- The content of `file.yaml` should be:

```yaml


```
### "Get" functions
- Used to get key values.

### `yamlgetint`
- Get a integer key. Let's say this is your YAML file:

```yaml


adminlvl: 0
```

```pawn
new admin = yamlgetint("file", "adminlvl");
```
- Variable `admin` will be `0`.

### `yamlgetbool`
- Get a boolean key. Let's say this is your YAML file:

```yaml


player: false
```

```pawn
new player = yamlgetbool("file", "player");
```
- Variable `player` will be `0`.

### `yamlgetfloat`
- Get a float key. Let's say this is your YAML file:

```yaml


coords: 23.73
```

```pawn
new Float:coords = yamlgetfloat("file", "coords");
```
- Variable `Float:coords` will be `23.73`.

### `yamlgetstr`
- Get a string key. Let's say this is your YAML file:

```yaml


msg: string
```

```pawn
SendClientMessage(playerid, -1, yamlgetstr("file", "msg"));
```
- Player will receive a message saying `"string"`.

### "Set" functions
- Used to get key values.

### `yamlsetint`
- Set a integer key.

```pawn
yamlsetint("file", "adminlvl", 1);
```

### `yamlsetbool`
- Set a boolean key.


```pawn
yamlsetbool("file", "player", true);
```

### `yamlsetfloat`
- Set a float key.

```pawn
yamlsetfloat("file", "coords", 24.36);
```


### `yamlsetstr`
- Set a string key.

```pawn
yamlsetstr("file", "msg", "Hello World.");
```

## Extras
- Extra functions.
### `yamlwritecomment`
- Write a YAML comment.

```pawn
yamlwritecomment("file", "This is a comment.");
```
- Your YAML should look like this:

```yaml
# This is a comment.
```
