# d_vars_stack.inc
Pawn Stack - Reserves up space for new stacks you can dynamically allocate during run-time, really similar to `malloc`.

[Go back to the home page...](d_vars.md)

## Stack
A stack is a conceptual structure consisting of a set of homogeneous elements and is based on the principle of last in first out (LIFO). It is a commonly used abstract data type with two major operations, namely push and pop. Push and pop are carried out on the topmost element, which is the item most recently added to the stack.

```pawn
@variable(.datatype = STACK_INTEGER, .args = {"Stack", 4}) StackTest();

public OnGameModeInit()
{
    malloc("StackTest");

    printf("[DETUtils]: (stack) - Values: %i, %i, %i, %i", 
        get StackInteger("Stack", 0),
        get StackInteger("Stack", 1),
        get StackInteger("Stack", 2),
        get StackInteger("Stack", 3));

    push StackInteger("Stack", 236);
    push StackInteger("Stack", 72);

    printf("[DETUtils]: (stack) - Values: %i, %i, %i, %i", 
        get StackInteger("Stack", 0),
        get StackInteger("Stack", 1),
        get StackInteger("Stack", 2),
        get StackInteger("Stack", 3));

    push StackInteger("Stack", 13);
    push StackInteger("Stack", 877);

    printf("[DETUtils]: (stack) - Values: %i, %i, %i, %i", 
        get StackInteger("Stack", 0),
        get StackInteger("Stack", 1),
        get StackInteger("Stack", 2),
        get StackInteger("Stack", 3));

    // There is no more stack space left.
    push StackInteger("Stack", 243);
    push StackInteger("Stack", 7212);

    printf("[DETUtils]: (stack) - Values: %i, %i, %i, %i", 
        get StackInteger("Stack", 0),
        get StackInteger("Stack", 1),
        get StackInteger("Stack", 2),
        get StackInteger("Stack", 3));

    // Pop the last two values:
    new var1, var2;

    pop StackInteger("Stack", var1);
    pop StackInteger("Stack", var2);

    printf("[DETUtils]: (stack) - Values: %i, %i, %i, %i", 
        get StackInteger("Stack", 0),
        get StackInteger("Stack", 1),
        get StackInteger("Stack", 2),
        get StackInteger("Stack", 3));

    push StackInteger("Stack", 787);

    printf("[DETUtils]: (stack) - Values: %i, %i, %i, %i", 
        get StackInteger("Stack", 0),
        get StackInteger("Stack", 1),
        get StackInteger("Stack", 2),
        get StackInteger("Stack", 3));

    return 1;
}