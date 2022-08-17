# d_discordutils.inc
Discord Utils - A library which is basically an extension to the Discord Connector plugin, providing more functions and callbacks.

[Go back to home page...](README.md)

## How to start to use?
### Commands
```pawn
@command(.type = DISCORD_COMMAND) dctest(DCC_Guild:guild, DCC_Channel:channel, DCC_Message:message, DCC_User:author, params)
{
	DCC_SendChannelMessage(channel, "this fucking works");
	return 1;
}
```
- This creates a basic text command.
