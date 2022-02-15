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
- People find this REALLY complicated, though - it's not. Start by making an variable handler:

```pawn
@variable(.datatype = INTEGER, .args = "Variable", false, false, 0) HandlerName();
```
- Now, we declared a variable handler for a non-constant variable named `Variable`, with integer data type, single return value (without more than one dimension). Note that this is only a variable handler, until we call the handler - variable does not exist.

```pawn
public OnGameModeInit()
{
      CallVariableHandler("HandlerName");
      return 1;
}
```
## API
## Messages from creator
### Notes
### Warnings
