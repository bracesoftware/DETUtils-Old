# d_foreach.inc
SA:MP `foreach` - Provides `foreach` and `iterator` keywords to interact with this data structure and loop through iterators.

[Go back to home page...](README.md)
## How to start to use?
- Start using the library by creating a simple iterator.

```pawn
iterator new MyIterator<10>;
```
- You can use `iter` shortcut too

```pawn
iter new MyIterator<10>;
```
- Before using an iterator, make sure to initialise it:

```pawn
iterator init(MyIterator);
```
- After the iterator initialization, it's ready for a proper use - let's continue.

```pawn
iterator add(MyIterator, 1);
```
- We added a value `1` to a iterator. So, when we do this:

```pawn
foreach do(new i : MyIterator)
{
  printf("%i", i);
}
```
- The output will be:

```
1
```
- To remove a value, use `iterator remove`:

```pawn
iterator remove(MyIterator, 1);
```
## Facts
### Same value multiple times
- This one is completely possible and valid, but to remove the twice-applied value, you'll need logically think - just remove the value twice. So if you did this:

```pawn
iterator add(MyIterator, 1);
iterator add(MyIterator, 1);
```
- To remove `1` completely, just remove it twice:

```pawn
iterator remove(MyIterator, 1);
iterator remove(MyIterator, 1);
```
- This is possible since `iterator (add/remove)` highly rely on the standard `for` loop.
## Messages from creator
### Notes
- No notes yet.
### Warnings
- No warnings yet.
