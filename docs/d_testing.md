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
Output:
```
[19:51:49] [Info] |======================================|
[19:51:49] [Info]                                         
[19:51:49] [Info]                 DETUtils                
[19:51:49] [Info]            Tests are staring...         
[19:51:49] [Info]                                         
[19:51:49] [Info] |======================================|
[19:51:49] [Info]                                         
[19:51:49] [Info]                                         
[19:51:49] [Info]                                         
[19:51:49] [Info]                                         
[19:51:49] [Info] *** [DETUtils]: (testing) - init :: Testing a module: d_testing.inc [3]
[19:51:49] [Info]                                         
[19:51:49] [Info] *** [DETUtils]: (testing) - assert :: Assertion successful : 1 is 1
[19:51:49] [Info]                                         
[19:51:49] [Info]                                                                         
[19:51:49] [Info]                                         
[19:51:49] [Info] |======================================|
[19:51:49] [Info]                                         
[19:51:49] [Info]                 DETUtils                
[19:51:49] [Info]    All tests performed successfully!    
[19:51:49] [Info]                                         
[19:51:49] [Info] |======================================|
```
- `d_testing` is mostly used in DETUtils itself, but you can still use it by changing the subject to `CUSTOM`:

```pawn
@testing(.subject = CUSTOM) CustomTest()
{
    DETUtilsAssert(1 == 1, "1 is 1", "1 is not 1");
    return 1;
}
```
Output:
```
[19:51:49] [Info] |======================================|
[19:51:49] [Info]                                         
[19:51:49] [Info]                 DETUtils                
[19:51:49] [Info]            Tests are staring...         
[19:51:49] [Info]                                         
[19:51:49] [Info] |======================================|
[19:51:49] [Info]                                         
[19:51:49] [Info]                                                                            
[19:51:49] [Info]                                         
[19:51:49] [Info] *** [DETUtils]: (testing) - init :: Performing an user test... [3]
[19:51:49] [Info]                                         
[19:51:49] [Info] *** [DETUtils]: (testing) - assert :: Assertion successful : 1 is 1
[19:51:49] [Info]                                         
[19:51:49] [Info]                                         
[19:51:49] [Info]                                         
[19:51:49] [Info] |======================================|
[19:51:49] [Info]                                         
[19:51:49] [Info]                 DETUtils                
[19:51:49] [Info]    All tests performed successfully!    
[19:51:49] [Info]                                         
[19:51:49] [Info] |======================================|
```
