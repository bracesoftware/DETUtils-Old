# d_lambda.inc
Pawn Lambda - Provides short functions whose can be used in expressions. Or in other words lambda functions.

## How to start to use?

- The most common example is just calling the function:

### `lambda using`

```pawn
new
	Lambda:Func = {
		return print("My Func works!");
	}

main()
{
	lambda using = {"Func"};
}
```

- Where `lambda using` is a lambda function, and `Lambda:Func` is a lambda procedure. `lambda using` will just call a lambda procedure once. Output:

```
My Func works!
```

### `lambda for`

- `lambda for` will call the procedure several times.

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

- Output:

```
Lambda test passed!
Lambda test passed!
Lambda test passed!
Lambda test passed!
Lambda test passed!
Lambda test passed!
Lambda test passed!
Lambda test passed!
Lambda test passed!
Lambda test passed!
```

### `lambda while`

- `lambda while` will call the procedure while a certain condition or expression is true. 

```pawn
new 
    bool:MyCondition = true, 
    Lambda:TestLambda2 = {
        MyCondition = false;
        print("TestLambda2 called!");
        return 1;
    }

main()
{
    lambda while = {"TestLambda2", MyCondition};
}
```

- Output:

```
TestLambda2 called!
```

### `lambda task`

```pawn
new
    Lambda:Timer = {
        return print("Lambda Timer works.");
    }

main()
{
    lambda task = {"Timer", 1000, true};
}
```

- This will create a repeating task (timer) which will get called every 1 second. To kill this timer, use `KillTimer`.

```pawn
new
	timer;

main()
{
    timer = (lambda task = {"Timer", 1000, true});
}

// Somewhere in the code:
KillTimer(timer);
```