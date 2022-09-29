# d_vars.inc
Pawn Variables - A library which reserves up space for new variables you can dynamically allocate during run-time, which is really similar to `malloc` but can handle up to hundreds of variables, stacks and arrays of different types.

[Go back to the home page...](../README.md)

## How to start to use?
Read documentation for the each `d_vars` library.


| Library      | Description                                                                                |
| -------------------- | ------------------------------------------------------------------------------------------ |
| [d_vars_standard.inc](d_vars_standard.md) | Standard variables (integers, booleans, floats and strings) with up to 256 return values reserved. |
| [d_vars_circular.inc](d_vars_circular.md) | Reserves up space for new circular arrays - an array you can keep adding data to the end of, and once it reaches its capacity the earliest data added will be removed - which you can dynamically allocate during run-time. |
| [d_vars_stack.inc](d_vars_stack.md) | Reserves up space for new stacks - conceptual structure consisting of a set of homogeneous elements and is based on the principle of last in first out (LIFO) which is a commonly used abstract data type with two major operations, namely push and pop - which you can dynamically allocate during run-time. |
