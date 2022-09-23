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
	e_INIT
}

new DET_g_EntryMemory[DET_e_eMemory];

// Operands:
#define DET_o_SysInit 0

// Funcs.
stock ModifyDETUtilsMemory(operand, value)
{
	if(operand == DET_o_SysInit)
	{
		DET_g_EntryMemory[e_INIT] = value;
		printf("*** [DETUtils]: (memory) - Operand \"DET_o_SysInit\" has been updated to: \"%i\"", value);
	}
	return 1;
}