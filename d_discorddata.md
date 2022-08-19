# d_discorddata.inc
Discord Data - A library which provides guild, channel, user and application data management.

[Go back to home page...](README.md)

## How to start to use?

- This library provides the `@discord` decorator. The example of the decorator usage to set and get data is shown below.

- Set the data using;
```pawn
@discord(.entity = ENTITY) Set<DataType>Data(DCC_<EntityTag>:entity_lowercase_name, data_address[], DataTypeTag:value);
```
- ... and get the data using:
```pawn
@discord(.entity = ENTITY) Get<DataType>Data(DCC_<EntityTag>:entity_lowercase_name, data_address[], DataTypeTag:dest);
```

So, let's do a slight parameter explanation:

1. `ENTITY` is a kind of an 'object' you're assigning the data to, for example you can assign data to the following entities: `GUILD`, `CHANNEL` and `USER`.
2. `<DataType>` is the type of the data you are assigning to the certain entity, it can be: `Integer`, `Boolean`, `Float` and `String`. 
3. `<EntityTag>` is a Discord Connector variable tag. In these cases, it can be: `Guild`, `Channel`, `User`.
4. `entity_lowercase_name` is a name of your variable.
5. `data_address` is the name of the data you're assigning.
6. `DataTypeTag` is a Pawn data type tag, it can be: `_:` (nothing) for integers, `bool:` for booleans, `Float:` for floats and `_:` (nothing) for strings - since strings are just arrays - literal strings of integers.
7. `value` is the value you're assigning.
8. `dest` is another variable you'll assign the returned data to.
