/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which provides
 *   textdraw animations.
 *
 *
 */

#define TEXTDRAW_HIDE_ANIMATION_SHRINK 0 //normal td shrinks to small size
#define TEXTDRAW_HIDE_ANIMATION_EXPAND 1 //normal td expands to big size
#define TEXTDRAW_SHOW_ANIMATION_SHRINK 2 //set big td shrinks to small size
#define TEXTDRAW_SHOW_ANIMATION_EXPAND 3 //very small td expands to big size

#define TEXTDRAW_ANIMATION_TYPE_TEXT 0 //apply animation to text
#define TEXTDRAW_ANIMATION_TYPE_BOX 1 //apply animation to box

enum DET__TextDrawInfo
{
	Float:TextSize[2],
	Float:LetterSize[2]
}

new DET_g_TextDrawData[_:MAX_TEXT_DRAWS][DET__TextDrawInfo];

enum DET__PlayerTextDrawInfo
{
	Float:TextSize[2],
	Float:LetterSize[2]
}

new DET_g_PlayerTextDrawData[_:MAX_PLAYER_TEXT_DRAWS][DET__PlayerTextDrawInfo];

// Hooks:

//[GLOBAL TDS]
stock DET_g_Anim_TextDrawTextSize(Text:text, Float:x, Float:y)
{
	DET_g_TextDrawData[_:text][TextSize][0] = x;
	DET_g_TextDrawData[_:text][TextSize][1] = y;
    return TextDrawTextSize(text,x,y);
}

#if defined _ALS_TextDrawTextSize
    #undef TextDrawTextSize
#else
    #define _ALS_TextDrawTextSize
#endif

#define TextDrawTextSize DET_g_Anim_TextDrawTextSize

stock DET_g_Anim_TextDrawLetterSize(Text:text, Float:x, Float:y)
{
	DET_g_TextDrawData[_:text][LetterSize][0] = x;
	DET_g_TextDrawData[_:text][LetterSize][1] = y;
    return TextDrawLetterSize(text,x,y);
}

#if defined _ALS_TextDrawLetterSize
    #undef TextDrawLetterSize
#else
    #define _ALS_TextDrawLetterSize
#endif

#define TextDrawLetterSize DET_g_Anim_TextDrawLetterSize

//[PLAYER TDS]
stock PlayerText:DET_g_Anim_CreatePlayerTextDraw(playerid, Float:x, Float:y, text[])
{
    return textid;
}

#if defined _ALS_CreatePlayerTextDraw
    #undef CreatePlayerTextDraw
#else
    #define _ALS_CreatePlayerTextDraw
#endif

#define CreatePlayerTextDraw DET_g_Anim_CreatePlayerTextDraw

// Functions:

stock ApplyTextDrawAnimation(Text:textid, animationid, animation_type)
{
	if(animationid == TEXTDRAW_HIDE_ANIMATION_SHRINK)
	{
		return TEXTDRAW_HIDE_ANIMATION_SHRINK;
	}
	return 1;
}

stock ApplyPlayerTextDrawAnimation(playerid, PlayerText:playertextid, animationid, animation_type)
{
	if(animationid == TEXTDRAW_HIDE_ANIMATION_SHRINK)
	{
		return TEXTDRAW_HIDE_ANIMATION_SHRINK;
	}
	return 1;
}

// Timers:

forward DET_g_TDAnimationTimer();
public DET_g_TDAnimationTimer()
{
	return 1;
}