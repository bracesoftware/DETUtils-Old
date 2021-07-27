# Extra stuff
- After including any of DET Utils includes, those includes also import some extra stuff to your code as well. That *extra* stuff can be anything, functions, callbacks and more.

[Go back to home page...](README.md)

## Handy features
- Read information about each feature below.
### API ( programming interface )
#### **Pawn Language extensions**
------------------------------------------
#### until(...)
- **SA:MP DET-Utils** also provides new loop known as *until* loop.
- Example:
```pawn
command untiltest(playerid, params[])
{
    new i;
    until(i = 50)
    {
        i++;
    }
    SendClientMessage(playerid, -1, "i is now 50.");
    return 1;
}
```
#### **Command Processor Features**
------------------------------------------
#### CallLocalPrefixedCommand
- This function simply calls the prefixed command as a function. Very useful if you are creating prefixed command alias.

- Example:

```pawn
CallLocalPrefixedCommand("mycmd", "is", playerid, string);
```
#### CallRemotePrefixedCommand
- This one is same as previous one, but the command function call be called even from another file.
------------------------------------------
#### **Client Check Features**
#### IsPlayerUsingPCClient
- This function checks if is player using PC to play SA:MP.

- Example:

```php
if(IsPlayerUsingPCClient(playerid)) return SendClientMessage(playerid, -1, "Welcome to server.);
```

- So, if player is using original client client message saying **"Welcome to server."** will appear.

#### IsPlayerUsingAndroidClient

- Opposite of previous one.

```php
if(IsPlayerUsingAndroidClient(playerid)) return Ban(playerid);
```

**NOTE**: Android SA-MP client is not legal at the moment, so I recommend banning its users.

#### ``public`` OnPlayerClientCheckReceived

- Called when client check is started.

- Example:

```php
public OnPlayerClientCheckReceived(playerid)
{
  printf("Performing client check on player id %i...", playerid);
  return 1;
}
```
