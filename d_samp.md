# SA:MP | DET-Utils *Entry file*

What is d_samp.inc? This is SA:MP | DET-Utils *Entry file* - obviously. It's usage is really simple, all you need is to include it - after you include *d_samp* in your code, it will pull all DETUtils includes and their dependencies itself, automatically.

- Code:

```pawn

// Pre-defines for DETUtils (examples):
#define DETUTILS_COMPATIBILITY_MODE
#define detutils_debug

// Includes:

#include <a_samp>

#include <other-libraries>

#include <DETUTILS\d_samp>

```

[Go back...](README.md)


## Seriously, why though?

- Well, at first, this was supposed to be *samp-stdlib* but extended - **stdlibEx**. After few days from the day I created the repository, I was thinking and *stdlibEx* sounded really weird. But, then I changed my mind - but it was too late since I made all things separately, so I made this.
