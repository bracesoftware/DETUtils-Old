# d_vars_circular.inc
Pawn Circular Variables - Reserves up space for new circular arrays - an array you can keep adding data to the end of, and once it reaches its capacity the earliest data added will be removed - which you can dynamically allocate during run-time.

[Go back to the home page...](d_vars.md)

## Circular arrays

A circular buffer is an array you can keep adding data to the end of, and once it reaches its capacity the earliest data added will be removed.

```pawn
@variable(.datatype = CIRCULAR_INTEGER, .args = {"CircularArray", 4}) CircArrayTest();

public OnGameModeInit()
{
    malloc("CircArrayTest");

    printf("[DETUtils]: (circarr) - Values: %i, %i, %i, %i", 
        get CircularInteger("CircularArray", 0),
        get CircularInteger("CircularArray", 1),
        get CircularInteger("CircularArray", 2),
        get CircularInteger("CircularArray", 3));

    add CircularInteger("CircularArray", 236);
    add CircularInteger("CircularArray", 72);

    printf("[DETUtils]: (circarr) - Values x2: %i, %i, %i, %i", 
        get CircularInteger("CircularArray", 0),
        get CircularInteger("CircularArray", 1),
        get CircularInteger("CircularArray", 2),
        get CircularInteger("CircularArray", 3));

    add CircularInteger("CircularArray", 34);
    add CircularInteger("CircularArray", 9);

    printf("[DETUtils]: (circarr) - Values x3: %i, %i, %i, %i", 
        get CircularInteger("CircularArray", 0),
        get CircularInteger("CircularArray", 1),
        get CircularInteger("CircularArray", 2),
        get CircularInteger("CircularArray", 3));

    add CircularInteger("CircularArray", 23);
    add CircularInteger("CircularArray", 6);

    printf("[DETUtils]: (circarr) - Values x3: %i, %i, %i, %i", 
        get CircularInteger("CircularArray", 0),
        get CircularInteger("CircularArray", 1),
        get CircularInteger("CircularArray", 2),
        get CircularInteger("CircularArray", 3));
    return 1;
}
```