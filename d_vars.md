# d_vars.inc
SA:MP Variables - A completely new type of a variable system.

[Go back to home page...](README.md)
## `d_vars.inc` variable scheme
- Each variable ID contains certain information about each variable, below that is schemed:
### Integers, booleans and floats
```md
Variable ID:
| - Valid
      | - true 
      | - false
| - Multi-dimensional variable (more returns)
      | - true
      | - false
| - Const (if it is not multi-dimensional)
      | - true
      | - false
| - Variable name
      | - string: 32 characters
| - Single return value (when it is not multidimensional variable)
      | - return value
| - 256 Dimensions (if it is multi-dimensional)
      | - Each dimension
            | - Single return value
```
### Strings
```md
Variable ID:
| - Valid
      | - true
      | - false
| - Const (if it is not multi-dimensional)
      | - true
      | - false
| - Variable name
      | - string: 32 characters
| - Single return value
      | - string: max 1024 characters
```
## How to start to use?
### Example 1
- People find this REALLY complicated, though - it's not. Start by making an variable handler:

```pawn
@variable( .datatype = INTEGER, .args = {"Variable", false, false, 0} ) HandlerName();
```
- Now, we declared a variable handler for a non-constant variable named `Variable`, with integer data type, single return value (without more than one dimension). Note that this is only a variable handler, until we call the handler - variable does not exist.

```pawn
public OnGameModeInit()
{
      CallVariableHandler("HandlerName");
      return 1;
}
```
### Example 2
- This is showing the declaration of all data types.

```pawn
@variable( .datatype = INTEGER, .args = {"Variable", false, false, 0} ) HandlerName();
@variable( .datatype = BOOLEAN, .args = {"Variable1", true, false, false} ) HandlerName1();
@variable( .datatype = FLOAT, .args = {"Variable2", false, false, 0.000} ) HandlerName2();
@variable( .datatype = STRING, .args = {"Variable3", true, "Cool string tho"} ) HandlerName3();

public OnGameModeInit()
{
      // Call the handlers in order to REALLY create the variables.
      // `@variable` decorator only handles the information,
      // then releases it after it gets called,
      // it can be called multiple times.
      CallVariableHandler("HandlerName");
      CallVariableHandler("HandlerName1");
      CallVariableHandler("HandlerName2");
      CallVariableHandler("HandlerName3");

      // EXAMPLE: set values.
      set Integer("Variable", 1243);
      set Boolean("Variable1", false, 3);
      set Float("Variable2", 213.21);

      // Example: get the values:
      printf("[samp-detutils]: (var info) - Testing variables: %i, %i, %f, %s",
            get Integer("Variable"),
            get Boolean("Variable1", 3),
            get Float("Variable2"),
            get String("Variable3"));

      // Delete the variables to free up space.
      delete Integer("Variable");
      delete Boolean("Variable1");
      delete Float("Variable2");
      delete String("Variable3");

      print("SA:MP | DETUtils - Testing mode script loaded.");
      return 1;
}
```
### Example 3
- Save the variable into `scriptfiles` folder instead of just deleting it.

```pawn
public Callback()
{
      save Integer("Variable");
      return 1;
}
```
**FUN FACT**: This can save up to ~531 bytes (or more if the variable is multi-dimensional) of data.
## API
- All of the functions can be seen below.
### Callbacks
------------------------------------
### `public` OnVariableCreate
- Called whenever a variable handler gets called.
```pawn
public OnVariableCreate(varname[], vartype)
{
    printf("Variable '%s' created - type : %i.", varname, vartype);
    return 1;
}
```
### `public` OnVariableUpdate
- Called whenever a variable value gets updated.
```pawn
public OnVariableUpdate(varname[], vartype, value, dimension)
{
    printf("Variable '%s' updated - type : %i, new value : %i, dimension : %i.", 
        varname, vartype, value, dimension);
    return 1;
}
```
### `public` OnVariableDelete
- Called when a certain variable gets deleted.
```pawn
public OnVariableDelete(varname[], vartype)
{
    printf("Variable '%s' deleted - type : %i.", varname, vartype);
    return 1;
}
```
### Keywords
------------------------------------

### Decorators
`@variable` decorator is actually a variable handler, which means, it only holds the information about the variable, and then that information is released after called (variable is declared and can be deleted, updated etc). This allows the faster server start.

**FUN FACT**: Variable handler contains around ~19 bytes of information.

#### Argument explanation
**Integers, booleans and floats**
```pawn
@variable( .datatype = (INTEGER, BOOLEAN, FLOAT), .args = {"NAME", (multi_dimensional ? true : false), (constant ? true : false), (constant_value)} ) HandlerName();
```
**Strings**
- Strings can't be multidimensional sadly (due to PAWN limits).
```pawn
@variable( .datatype = STRING, .args = {"NAME", (constant ? true : false), (constant_value)} ) HandlerName();
```

### Other
- `get` - used to get the value of the variable.
- `set` - used to set the value of the variable.
- `delete` - used to delete a variable.
- `save` - used to save the variable cache into `scriptfiles` (only if `d_filequeries.inc` is included) (save the variable as specially formatted persistent data and reuse it).
- `load` - used to load the variable previously saved using `save`

## Messages from creator
### Notes
### Warnings
