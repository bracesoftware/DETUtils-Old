# d_testing.inc
Pawn Testing - Provides a fast and an easy way of code testing.

[Go back to the home page...](../README.md)

## How to start to use?
```pawn
@testing(.subject = SCRIPT_TESTING) d_testing_test()
{
    DETUtilsAssert(1 == 1, "1 is 1", "1 is not 1");
    return 1;
}
```
- `d_testing` is mostly used in DETUtils itself, but you can still use it by changing the subject to `CUSTOM`:

```pawn
@testing(.subject = CUSTOM) CustomTest()
{
    DETUtilsAssert(1 == 1, "1 is 1", "1 is not 1");
    return 1;
}
```
