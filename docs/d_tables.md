# d_tables.inc
Pawn Tables - Excel-like column, row and cell management system.

[Go back to home page...](README.md)

## How to start to use?

- The usage of this library is really simple. Firstly, let's use a `tablecreate` function to initialize the table!

```pawn
tablecreate("accounts", 10, 2);
```

- Now we didn't really create the table, we just initialized it - or in other words, loaded it. So, we initialized the table `accounts` which currently has 10 previewable columns and 2 previewable rows. Note that the column and row IDs start from `0`! You could do `setcellvalue` even before initializing the table - but the data would not appear on the table preview. Now, let's set the cell values, use the `setcellvalue` function for that. Do the following:

```pawn
setcellvalue("accounts", 4, 0, "4c0r");
setcellvalue("accounts", 4, 1, "4c1r");
```

- In first line, we set a cell value `4c0r` for a cell located in column 4 and row 0, and in the second line - we set a cell value `4c1r` for a cell located in column 4 and row 1. After we set the values, we can display the table. Use `previewtable` function now!

```pawn
previewtable("accounts");
```

- Make sure your code looks like this:

```pawn
tablecreate("accounts", 10, 2);

setcellvalue("accounts", 4, 0, "4c0r");
setcellvalue("accounts", 4, 1, "4c1r");

previewtable("accounts");
```

- After we execute the script, the output should be the following text:

```
[18:15:27] =============================================
[18:15:27]  
[18:15:27]  
[18:15:27] TABLE PREVIEW | Previewing: accounts
[18:15:27]  
[18:15:27]  
[18:15:27] ROW: 0 | (empty) | (empty) | (empty) | (empty) | 4c0r | (empty) | (empty) | (empty) | (empty) | (empty) | 
[18:15:27] ROW: 1 | (empty) | (empty) | (empty) | (empty) | 4c1r | (empty) | (empty) | (empty) | (empty) | (empty) | 
[18:15:27]  
[18:15:27]  
[18:15:27] =============================================
```

- Note that you don't really need to use the initialization function unless you want to preview your table like this. You can set the values for cells without initializing.
