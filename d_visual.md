# d_visual.inc
- Library or libraries whose contain functions whose provide in-game visible effects.

[Go back to home page...](README.md)

## Usage

- Usage is really simple. *d_visual.inc* provides very few functions whose can be used for roleplay purposes!

**NOTE**: These libraries require *streamer*.

## API ( programming interface )

### CreateDroppedGun

- This function creates the gun object which can be picked up either destroyed by player.

Example:

```pawn
public OnGameModeInit()
{
  // Create AKM with 100 ammo on coordinates 811.1299, -1616.0647, 13.5469:
  CreateDroppedGun(30, 100, 811.1299, -1616.0647, 13.5469);
  return 1;
}
```
