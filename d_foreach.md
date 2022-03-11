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
- Before using an iterator, make sure to initialize it:

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
## Explanation
### Declaration
- So let's firstly explain how `iterator new` works, so:
```pawn
iterator new MyIterator<10>;
```
- This will declare an iterator, actually this is a macro, so in fact iterators are just arrays. This will code will generate into this:
```pawn
enum IteratorData
{
  returnvalues[SIZE]
};
new IteratorIndex;
new Iterator[IteratorData];
```
- `IteratorData` is an enumerator holding the information about the iterator, `IteratorIndex` is an index of `returnvalues` updated after `iterator add` is used.
### Initialization
```pawn
iterator init(MyIterator);
```
- This is REALLY important part, this actually prepares the iterator for it's iteration. If you don't initialize the iterator, your console will be full of zeros if you try to this:
```pawn
foreach do(new i : MyIterator)
{
  printf("%i", i);
}
```
### Add and remove values
```pawn
iterator add(MyIterator, 1);
```
```pawn
iterator remove(MyIterator, 1);
```
- These two are literally the point of this library - add and remove the iteration values. The good thing is that you can add any value to the iterator, because the number between `<` and `>` represents the number of slots. The slot number is actually the size of the iterator, but regardless its size any value can be added. So, this code is completely valid even if the size is for example only `10`:

```pawn
iterator add(MyIterator, 2437);
```
- Let's explain what `iterator add` does, it just adds the provided number to an index of `returnvalues` in `IteratorData`, that index is already mentioned `IteratorIndex` which is updated itself after the each iterator update. Removing the value is simple - almost the same process, just reversed.
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

### Iterator cleanup
- If you want to do an iterator cleanup for any reason, just re-initialize it using `iterator init`.
## Messages from creator
### Notes
- No notes yet.
### Warnings
- No warnings yet.
