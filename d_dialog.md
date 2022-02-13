# d_dialog.inc
SA:MP Dialogs - Create dialogs using `@dialog` decorator and show them to players.

[Go back to home page...](README.md)
## How to start to use?
- Start by declaring a dialog.

```pawn
@dialog(.type = MESSAGE_BOX, .args = {"Hi", "Hello!", "OK", "NO"}) HiDialog(playerid);
```

- Show the dialog to a player.

```pawn
@command(.type = SLASH_COMMAND) dialogtest(playerid, params[]) 
{
    ShowDialogForPlayer(playerid, "HiDialog");
    return 1;
}
```
## API
### Dialog types
- Dialog styles are now dialog types.

```pawn
@dialog(.type = MESSAGE_BOX, .args = {"Hi", "Hello!", "OK", "NO"}) HiDialog(playerid);
```
So, instead of just `MESSAGE_BOX`, you can use following types:

- `MESSAGE_BOX` for `DIALOG_STYLE_MSGBOX`
- `INPUT_BOX` for `DIALOG_STYLE_INPUT`
- `LIST` for `DIALOG_STYLE_LIST`
- `PASSWORD_INPUT` for `DIALOG_STYLE_PASSWORD`
- `TABLIST` for `DIALOG_STYLE_TABLIST`
- `TABLIST_HEADERS` for `DIALOG_STYLE_TABLIST_HEADERS`
## Messages from creator
### Warnings
### Notes
