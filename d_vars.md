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
      // This will create the variables:
      CallVariableHandler("HandlerName");
      CallVariableHandler("HandlerName1");
      CallVariableHandler("HandlerName2");
      CallVariableHandler("HandlerName3");

      // Set the values, or else all of them will be 0!
      SetIntegerValue("Variable", 1243);
      SetBooleanValue("Variable1", false, 3);
      SetFloatValue("Variable2", 213.21);
      // There is no `SetStringValue` because Variable3 is a constant value.
      //@variable( .datatype = STRING, .args = {"Variable3", true, "Cool string tho"} ) HandlerName3();
      //                                                    (this)
      // Though SetStringValue do exist.

      // Output will be 1243, 0, 213.21, Cool string tho
      printf("[samp-detutils]: (var info) - Testing variables: %i, %i, %f, %s",
        GetIntegerValue("Variable"),
        GetBooleanValue("Variable1", 3),
        GetFloatValue("Variable2"),
        GetStringValue("Variable3")
        )
      ;
      return 1;
}
```
## API
- All of the functions can be seen below.

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
## Messages from creator
### Notes
### Warnings
