# d_colours.inc

## How to start to use?

- Start to use by declaring a specific colour!

You do it using ``decl`` keyword and ``Colour:`` or ``StrColour:`` tags - tag usage depends on the colour type you want to declare:

Code:
```pawn
decl Colour:gray = 223435231; // Not an actual colour, just an example integer.

// ... or:

decl StrColour:gray[20] = "{B9C9BF}"; // This is an actual colour code I found this morning... xD
```

... or:

```pawn
decl Color:gray = 223435231; // Not an actual colour, just an example integer.

// ... or:

decl StrColor:gray[20] = "{B9C9BF}"; // This is an actual colour code I found this morning... xD
```

- After declaring a colour, you need to use it. You do it using **Return(Str)Colour**.

Code:
```pawn
SendClientMessage(playerid, ReturnColour(gray), "I am gray-coloured text.");

// ... or:

SendClientMessage(playerid, -1, "%sHello, %s!", ReturnStrColour(gray), ReturnPlayerName(playerid));
```

## API (programming interface)

- Everything has been shown above. Only what I forgot to say that I made aliases for **Return(Str)Colour** functions and they're *Return(Str)* **Color**.

## Messages from creator

### Warnings

#### Declaring colours

- Colours can be only declared globally. Not in functions and callbacks!
