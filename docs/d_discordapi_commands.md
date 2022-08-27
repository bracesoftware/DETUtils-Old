# d_discordapi_commands.inc
Discord Commands - A library which provides creation of Discord text and slash commands.

[Go back to home page...](d_discordapi.md)

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

- Coming soon as the Discord Connector plugin gets an update.
