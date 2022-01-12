# d_commands.inc
SA:MP Commands - a "built-in" fast and easy way to create commands.

![cmd-processing](img/d_commands.png)

[Go back to home page...](README.md)

## How to start to use?

### Command declaration
------------------------------------------
To declare a command, you need to use ``command`` keyword.

Let's see how it works:

```php

command mycommand(playerid, params[])
{
  SendClientMessage(playerid, -1, "{ffffff}Your very first command works!");
  return 1;
}

```

... and - that's it, command is declared, and whenever someone sends */mycommand* to chat, a message saying "Your very first command works!" appears.

### Bonus
-----------------------------------------

- Creating commands now, also - can be done just using ``decl`` and ``Command:`` tag.
- Let's take a look:

```pawn
decl Command:tagtest(playerid,params[])
{
    SendClientMessage(playerid, -1, "Tag command worked.");
    return 1;
}
```

### Command aliasing
------------------------------------------
There is also way to declare alias of a specific command.

You can do it using ``alias`` keyword, an example:

```pawn

alias command mycmd(playerid, params[]) = mycommand;

// ... or:

decl CommandAlias:mycmd(playerid, params[]) = mycommand;

```

### Command debugging
------------------------------------------
There is also a way to debug commands!

Advanced debugging can be done using ``OnCommandStateChange`` and ``OnPrefixedCommandStateChange`` - depends on command type.

Example:

```pawn
public OnCommandStateChange(playerid, cmdtext[], stateid)
{
	printf("Command state changed. Command: %s", cmdtext[]);
	return 1;
}

// ... or:

public OnPrefixedCommandStateChange(playerid, cmdtext[], stateid)
{
	printf("Custom prefixed command state changed. Command: %s", cmdtext[]);
	return 1;
}
```
### Debug states
------------------------------------------
- For advanced debugging, one ``print`` isn't enough - right? That is why I added command debug states. Command debug is called 3 times after player submits to execute a command, so there are three debug states.

- Debug states:

- ``COMMAND_DEBUG_STATE_RECEIVED`` - command processor received command and command parameters
- ``COMMAND_DEBUG_STATE_READY`` - command is ready to be performed
- ``COMMAND_DEBUG_STATE_PERFORMED`` - command performed successfully

**How to use states?**
------------------------------------------
- To use states, you need to use **publics shown above**. Here's how to do it:

```pawn
public OnCommandStateChange(playerid, cmdtext[], stateid) 
{
    if(stateid == COMMAND_DEBUG_STATE_RECEIVED)
    {
        printf("Command %s received.", cmdtext);
        return 1;
    }
    else if(stateid == COMMAND_DEBUG_STATE_READY)
    {
        printf("Command %s ready.", cmdtext);
        return 1;
    }
    else if(stateid == COMMAND_DEBUG_STATE_PERFORMED)
    {
        printf("Command %s performed.", cmdtext);
        return 1;
    }
    return 1;
}

// ... or:

public OnPrefixedCommandStateChange(playerid, cmdtext[], stateid) 
{
    if(stateid == COMMAND_DEBUG_STATE_RECEIVED)
    {
        printf("Custom prefixed command %s received.", cmdtext);
        return 1;
    }
    else if(stateid == COMMAND_DEBUG_STATE_READY)
    {
        printf("Custom prefixed command %s ready.", cmdtext);
        return 1;
    }
    else if(stateid == COMMAND_DEBUG_STATE_PERFORMED)
    {
        printf("Custom prefixed command %s performed.", cmdtext);
        return 1;
    }
    return 1;
}
```

### Admin commands
------------------------------------------
*d_commands* also lets you to create admin commands.

You can do it easily and fast mixing ``admin`` and ``command`` keywords.

Example:

```pawn
admin command admincheck(playerid,params[])
{
  SendClientMessage(playerid, -1, "You're admin.");
  return 1;
}
```

**INFO**: If player is not logged in as RCON administrator, function will return *false* (0) and send client message saying: **"SERVER: Unknown command."**

### Commands with custom prefix
------------------------------------------
*d_commands* also arrive with brand new system with custom-prefixed commands.
Create commands like those using two keywords and one extra parameter - fast and easy.

- Let's see how to do it:

```pawn
prefixed command mycmd(playerid, params[], "!")
{
  SendClientMessage(playerid, -1, "This worked, %s.", ReturnPlayerName(playerid));
  return 1;
}

// ... or:

decl PrefixedCommand:mycmd(playerid, params[], "!")
{
  SendClientMessage(playerid, -1, "This worked, %s.", ReturnPlayerName(playerid));
  return 1;
}
```

Now, whenever player sends ``!mycmd`` to chat, command will be executed (performed).

**INFO**: To use custom-prefixed commands, you also need to use new built-in **/chatmode** command. This built-in command toggles the ability of a player to execute these commands.

#### What's so-called chat mode thing?

- It's, simply said, variable which controls the function of normal SA-MP chat. There are two chat modes, **CHAT_MODE_PLAIN_TEXT_MESSAGES (with ID 0)** and **CHAT_MODE_PREFIXED_COMMANDS (with ID 1)**. Player can execute custom prefixed commands only if their chat mode is **CHAT_MODE_PREFIXED_COMMANDS**. Players can switch their chat mode using mentioned **/chatmode** command.

- You can also use these two functions in order to manage player's chat mode.

**GetPlayerChatMode**

- Used to get information about which chat mode certain player is using.

```pawn
new chatmode = GetPlayerChatMode(playerid);
```

**SetPlayerChatMode**

- Uset to set chat mode for certain player.

```pawn
if(chatmode == CHAT_MODE_PLAIN_TEXT_MESSAGES)
{
	SetPlayerChatMode(playerid, CHAT_MODE_PREFIXED_COMMANDS);
	SendClientMessage(playerid, -1, "Now you can use custom-prefixed commands.");
}

```

### Commands with custom permissions
------------------------------------------
*d_commands* also allows you to create commands that require certain permissions / conditions to be executed. This is really nice feature if you're making administrator system, V.I.P. system or anything else that has to do with the user system.

- Let's see how to create **roles**. To create role you need to use ``create role`` keywords.

- Let's declare some variables:

```pawn
enum Enums
{
  Money,
  Bank,
  Deaths,
  Kills,
  Admin
}

new Player[MAX_PLAYERS][Enums];
```

- Now, let's create a role.

```pawn
create role AdminRole(playerid, Player[playerid][Admin] == 1);

// ... or:

decl Role:AdminRole(playerid, Player[playerid][Admin] == 1);
```

- Now, we have our role - let's use it in our command.
- To create role commands, you need to use ``role command`` keywords.

```php
role command clearchat(playerid, params[], AdminRole)
{
	for(new i; i < 20; i++)
		SendClientMessage(playerid, -1, "");

	SendClientMessage(playerid, -1, "You cleared the chat.");
	return 1;
}

// ... or:

decl RoleCommand:clearchat(playerid, params[], AdminRole)
{
	for(new i; i < 20; i++)
		SendClientMessage(playerid, -1, "");

	SendClientMessage(playerid, -1, "You cleared the chat.");
	return 1;
}
```

Now, we created a command which requires ``AdminRole`` role to be executed - performed.

**NOTE**: If role command's conditions are not met, command will return ``0`` (false) and will send client message saying: **"SERVER: Unknown command."**

## API ( programming interface )

### Functions
------------------------------------------
*d_commands.inc* also contains some handy functions, let's see.

**CallLocalCommand**
------------------------------------------
- This function does nothing besides returning command function call.

Parameters:

   - command_name (string)
   - specifiers (string)
   - command_firstparam (integer)
   - command_secparam (string)
  
Example:

```pawn
CallLocalCommand("mycommand", "is", playerid, inputtext);
```

**CallRemoteCommand**
------------------------------------------
- Simply, *CallRemoteCommand* works same as *CallLocalCommand* (it has same parameters etc.) - but the command can be called from anywhere. Even, from another file.

**CallLocalPrefixedCommand**
------------------------------------------

- Used to call local prefixed command.

Example:

```pawn
CallLocalPrefixedCommand("sayhi", "is", playerid, text);
```

**WARNING:** In command name parameter (in this case - it is this **"sayhi"** thing), you only need to put command name - not a prefix!

**CallRemotePrefixedCommand**
------------------------------------------

- Used to call remote prefixed command.

Example:

```pawn
CallRemotePrefixedCommand("sayhi", "is", playerid, text);
```

**WARNING:** In command name parameter (in this case - it is this **"sayhi"** thing), you only need to put command name - not a prefix!

**Command processing**
------------------------------------------
A simple script:

```pawn
// When player enters prefixed command:
public OnPrefixedCommandReceived(playerid, cmdtext[])
{
    SendClientMessage(playerid, -1, "%s, your command was received. (%s)", ReturnPlayerName(playerid), cmdtext);
    return 1;
}

// When command text goes trough processor
public OnPrefixedCommandPerformed(playerid, cmdtext[], success)
{
	// If command doesn't exist:
    if(!success)
    {
        SendClientMessage(playerid, -1, "Command %s doesn't exist.", cmdtext);
    }
    // Else just return 1.
    return 1;
}

// When player submits a regular command:
public OnPlayerCommandReceived(playerid, cmdtext[])
{
    SendClientMessage(playerid, -1, "%s, your command was received. (%s)", ReturnPlayerName(playerid), cmdtext);
    return 1;
}

// When command goes trough processor:
public OnPlayerCommandPerformed(playerid, cmdtext[], success)
{
	// If command does not exist:
    if(!success)
    {
        SendClientMessage(playerid, -1, "Command %s doesn't exist.", cmdtext);
    }
    // else return 1
    return 1;
}
```

## Messages from creator
------------------------------------------
### Warnings
------------------------------------------
1. Make sure that whenever you create commands using the ``command`` keyword, the command name does not contain capital letters. Otherwise, unfortunately - server will recognize the command as unknown. But - this does not need to make you sad because this type of commands are not case-sensitive.
2. Custom-prefixed commands are case-sensitive. Also, command names can contain capital letters.
3. ``params[]`` custom-prefixed command parameter won't work with *sscanf*. The parameter is here to follow normal command standards and can be used like a *local* string variable.

### Notes
------------------------------------------
***Backwards compatibility***
- d_commands also have backwards compatibility, incase you are upgrading from iZCMD/ZCMD, the ``CMD:`` keyword will still work as nothing changed. But, I still recommend creating your future commands using methods shown in tutorials and examples above.
- Also, ``YCMD:`` and ``COMMAND:`` keywords will work.
------------------------------------------
***Making filterscript with d_commands?***

- Well, I have good news for you, because there is also new filterscript support feature. 

- So, if you're making a filterscript - make sure you use:

```pawn
#define FILTERSCRIPT
```
... before including *d_commands*.
