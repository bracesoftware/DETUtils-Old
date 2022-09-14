# d_timers.inc
Pawn Timers - A library which provides automatic and manual repeatable timers or **tasks** in this case.

[Go back to home page...](README.md)

## How to start to use?

- This library provides an usage of a `@task` decorator, with which you can create either automatic or manual timers. Examples of declaring both types of timers are below.
 
### Automatic timers

```pawn
@task(.type = AUTOMATIC, .interval = 1000) AutomaticTimer()
{
    print("Automatic timer works.");
    return 1;
}
```

- This timer will run itself when the code loads (it's deferred inside `OnDETUtilsInit`), so every 1 second - a message `"Automatic timer works."` in console will appear.

### Manual timers

```pawn
@task(.type = MANUAL, .interval = 1000, .repeating = true) ManualTimer()
{
    print("Manual timer works.");
    return 1;
}
```

- The example above is a manual timer, it needs to be triggered using a `DeferTask` macrofunction. Example of the function usage is below:

```pawn
@als() function OnGameModeInit()
{
    DeferTask("ManualTimer", "");
    return @als() break;
}
```

- Now every 1 second, the console message `"Manual timer works."` will appear.

## FAQ
- Frequently asked questions.

### Killing a manual timer
- Well, now you may ask - how to kill this timer. The answer is easy, the same way you did it before.

```pawn
new task = DeferTask("taskname", "");
KillTimer(task);
```

### Killing an automatic one
- This is impossible for now.
