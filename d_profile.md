# d_profile.inc
Pawn Profiling - A library which is which is providing the code profiling macros.

[Go back to home page...](README.md)

## How to start to use?

- Profiling is a basic process, simply getting how much time it takes to execute a part of certain code. But although it is a simple process, it is hard to get accurate results, because the time it takes to execute the code depends on various factors.

- This is how to make a profiler function, in which you will put code you want to execute:
```pawn
@profile(.format = {""}) Callback()
{
	print("some code to get profiled.");
	@profile(.value = 1) return;
}
```

- Let's do an explanation of the stuff above. `@profile(.format = {""}) Callback()` declares a profiling public function, and `@profile(.value = 1) return` ends the profiling process (ends the profiling timer).

- Though, this is not automatic, so you'll need to run the profiler manually using:

```pawn
CallProfiler("Callback", "i", arg);
```

- After the profiler is called, you should get the following message in the console:

```
 [samp-detutils]: (profiling) - Code 'Callback' took 27 ticks to execute.
```

- Obviously, the ticks the code takes to execute depends on the code you profile.
