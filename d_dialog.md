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
---------------------------------
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

### Dialog functions
---------------------------------
### `public` OnPlayerDialogReceived
- Called when a player receives the certain dialog.

```pawn
public OnPlayerDialogReceived(playerid, dialog[])
{
    SendClientMessage(playerid, -1, "You received dialog '%s'", dialog);
    return 1;
}
```
### `public` OnPlayerDialogHide
- You can hide a dialog, when you do that, this callback gets called.

```pawn
public OnPlayerDialogHide(playerid, dialog[])
{
    SendClientMessage(playerid, -1, "'%s' hidden.", dialog);
    return 1;
}
```
### `public` OnPlayerDialogResponse
- This is simply a replacement for `OnDialogResponse`.

```pawn
public OnPlayerDialogResponse(playerid, dialog[], response, listitem, inputtext[])
{
    SendClientMessage(playerid, -1, 
        "You responded to dialog '%s', response: %i, listitem: %i, inputtext: %i", 
        dialog, response, listitem, inputtext);
    return 1;
}
```
### `ShowDialogForPlayer`
- Show a dialog for player.

### `GetDialogStyle`
- Get a style (type) of a dialog. Returns `-1` if the dialog does not exist. Returns values such as `DIALOG_STYLE_MSGBOX`.

```pawn
new style = GetDialogStyle("HiDialog");
```
### `HideDialogForPlayer`
- Hide a shown dialog.

```pawn
HideDialogForPlayer(playerid);
```

### `GetPlayerDialog`
- Get player's shown dialog. If there is no dialog shown, function will return `0`. Returns a name of a dialog.

```pawn
GetPlayerDialog(playerid);
```
## Messages from creator
### Warnings
### Notes
