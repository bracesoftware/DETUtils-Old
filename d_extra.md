# Extra stuff
- After including any of DET Utils includes, those includes also import some extra stuff to your code as well. That *extra* stuff can be anything, functions, callbacks and more.

[Go back to home page...](README.md)

## Handy features
- Read information about each feature below.
### API ( programming interface )
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
  printf("Successfully performed client check on player id %i.", playerid);
  return 1;
}
```
