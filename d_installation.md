# Library installation

- How to install SA:MP | DET Utilities on my server?
------------------------------------------
Let's find out.
 
 [Go back to home page...](README.md)
 
 ## Two ways of installation
 
 ### With *sampctl*
 ------------------------------------------
 Simply install to your project and begin using the library:
 
 ```bat
 sampctl package install DEntis-T/SA-MP-DETUtils
 ```
 
 ### Manual install
 ------------------------------------------
 Download all files from *master* branch and extract them to your *pawno\includes* folder.

## How to use?

- Include **d_samp** in your code and begin with using the library:
```pawn
#include <DETUTILS\d_samp>
```
- You can read the full documentation in order to understand the library and its components better.

## Include management

- If you don't want to use certain library, you can simply disable it! In order to do that, use ``DETUTILS_NO_(...)`` pre-define before using DETUtils:

```pawn
#define DETUTILS_NO_COMMANDS // Disable d_commands.inc

#include <a_samp>
// Other includes...
#include <DETUTILS\d_samp>
```

- ... other defines:

``DETUTILS_NO_PROPERTIES`` for disabling *d_properties.inc*.

``DETUTILS_NO_FMARGS`` for disabling *d_fmargs.inc*.

``DETUTILS_NO_VISUAL`` for disabling *d_visual.inc*.

``DETUTILS_NO_ANTICHEAT`` for disabling *d_anticheat.inc*.

``DETUTILS_NO_MAPEDITOR`` for disabling *d_mapeditor.inc*.
