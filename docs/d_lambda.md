# d_lambda.inc
Pawn Lambda - Provides short functions whose can be used in expressions. Or in other words lambda functions.

## How to start to use?

- The most common example is using the for loop as a function argument:

```pawn
new Lambda:TestLambda = {
    print("Lambda test passed!");
    return 1;
}

main()
{
    print("sussylambda : %i", lambda for = {"TestLambda", 10});
}
```

This way you'll use `print("Lambda test passed!")` ten times as a function argument. So the code above is equivalent to the code below:

```pawn
TestLambda()
{
	for(new i; i < 10; i++)
	{
		print("Lambda test passed");
	}
	return 1;
}

main()
{
    print("sussylambda : %i", TestLambda());
}
```