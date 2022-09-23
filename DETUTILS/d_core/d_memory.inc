/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library core file.
 *
 *
 */


// Entry point.
#define @detmemory%0\32;%1\10;%3 ModifyDETUtilsMemory(%1);

// Internal.

enum DET_e_eMemory
{
	e_INIT,
	e_CREATED_PROPS,
	e_LAST_FQUERY_TYPE,
	e_FQUERY_DELIMITER
}

new DET_g_EntryMemory[DET_e_eMemory];

// Operands:
#define DET_o_SysInit 0
#define DET_o_CreatedProps 1
#define DET_o_LastFQueryType 2
#define DET_o_FQueryDelimiter 3

// Funcs.
stock ModifyDETUtilsMemory(operand, value)
{
	if(operand == DET_o_SysInit)
	{
		DET_g_EntryMemory[e_INIT] = value;
		printf("*** [DETUtils]: (memory) - Operand \"DET_o_SysInit\" has been updated to: \"%i\"", value);
	}
	if(operand == DET_o_CreatedProps)
	{
		DET_g_EntryMemory[e_CREATED_PROPS] = value;
		printf("*** [DETUtils]: (memory) - Operand \"DET_o_CreatedProps\" has been updated to: \"%i\"", value);
	}
	if(operand == DET_o_LastFQueryType)
	{
		DET_g_EntryMemory[e_LAST_FQUERY_TYPE] = value;
		printf("*** [DETUtils]: (memory) - Operand \"DET_o_LastFQueryType\" has been updated to: \"%i\"", value);
	}
	if(operand == DET_o_FQueryDelimiter)
	{
		DET_g_EntryMemory[e_FQUERY_DELIMITER] = value;
		printf("*** [DETUtils]: (memory) - Operand \"DET_o_FQueryDelimiter\" has been updated to: \"%i\"", value);
	}
	return 1;
}