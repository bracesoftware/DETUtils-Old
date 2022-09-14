# Extra stuff
- After including any of DET Utils includes, those includes also import some extra stuff to your code as well. That *extra* stuff can be anything, functions, callbacks and more.

[Go back to home page...](README.md)

## Handy features
- Read information about each feature below.
### **String functions**
#### strtok
- **SA:MP DET-Utils** provides few new functions which are *extensions* to standard Pawn and SA:MP libraries.

- *strtok* function is one of them, example:

```pawn
decl Command:mycmd(playerid, params[])
{
    new param[128], idx, num;
    param = strtok(params, idx);
    if(strlen(param) == 0) return SendClientMessage(playerid, -1, "Usage: /mycmd <num>");
    num = strval(param);
    if(num == 1)
    {
        return SendClientMessage(playerid, -1, "This works!");
    }
    return 1;
}
```
#### strrest
- Almost same as *strtok*.

```php
public OnPlayerCommandText(playerid, cmdtext[])
{
    new cmd[256+1];
	new message[256+1];
	new	tmp[256+1];
	new	idx;

	cmd = strtok(cmdtext, idx);

    // Action commands
	if(!strcmp("/me", cmd, true))
	{
  	    message = strrest(cmdtext,idx);
  	    if(!strlen(message)) {
			CmdUsageMessage(playerid, "/me [action]");
			return 1;
		}
		ProcessActionText(playerid, message, ACTION_ME);
		return 1;
	}
    return 0
}
```
**NOTE**: This code is the code from *gl_chat.pwn* originally written by SA-MP team.
