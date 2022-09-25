# d_ascii.inc
Pawn ASCII - ASCII character predefines.

[Go back to the home page...](../README.md)

## How to start to use?

```pawn
print("Character <NAME>: %i", CHARACTER_<NAME>);
```

## API

### `GetCharacterType`

```pawn
native GetCharacterType(charid);
```

- If the character ID is in range of 0 to 31, the character is a `CHARACTER_TYPE_CONTROL`, if the character ID is in range of 32 to 127 - the character is a printable character, or `CHARACTER_TYPE_PRINTABLE`, or if the character ID is in range of 128 to 255 - the character is a `CHARACTER_TYPE_EXTENDED`, otherwise, function will return `CHARACTER_TYPE_UNKNOWN` or simply `-1`.