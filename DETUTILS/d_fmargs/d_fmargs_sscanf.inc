/*
 * 
 * SA:MP DEntisT's Utilities
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which provides 
 *   Pawn implementation
 *   of 'sscanf'.
 *
 */

#if defined DETUTIS_NO_SSCANF

	#endinput

#endif

#if !defined DETUTILS_SSCANF_DELIMITER

 	#define DETUTILS_SSCANF_DELIMITER ' '

#endif

#define SSCANF_INCLUDED

/*
										 
88                                   88  
88                                   88  
88                                   88  
88  88,dPYba,,adPYba,   8b,dPPYba,   88  
88  88P'   "88"    "8a  88P'    "8a  88  
88  88      88      88  88       d8  88  
88  88      88      88  88b,   ,a8"  88  
88  88      88      88  88`YbbdP"'   88  
------------------------88-------------  
------------------------88-------------

*/

#define @DETUTILSSSCANF_KEYWORD__@%0\32; @DETUTILSSSCANF_KEYWORD__@
#define sscanf @DETUTILSSSCANF_KEYWORD__@

#define @DETUTILSSSCANF_KEYWORD__@do%0(%1,%2) DET__do_sscanf(%1,%2)
#define @DETUTILSSSCANF_KEYWORD__@String%0(%1,%2,%3) strmid(%1,%2,0,%3)
#define @DETUTILSSSCANF_KEYWORD__@Integer%0(%1) strval(%1)
#define @DETUTILSSSCANF_KEYWORD__@Float%0(%1) floatstr(%1)

#define SSCANF_FAIL 0
#define SSCANF_SUCCESS 1

stock DET__do_sscanf(const source[], dest[][])
{
    new 
    	i, 
    	start,
    	index,
    	len,
    	scount;
    
    for(new ii; ii < strlen(source); ii++)
    {
    	new count = strfind(source, " ", false, ii);
    	if(count == SSCANF_SUCCESS) scount ++;
    }
    if(scount == SSCANF_FAIL)
    {
    	return scount;
    }
    while(i <= strlen(source))
    {
        if(source[i] == DETUTILS_SSCANF_DELIMITER || i == strlen(source))
        {
            len = strmid(dest[index], source, start, i, 128);
            dest[index][len] = SSCANF_FAIL;
            start = i + 1;
            index ++;
        }
        i++;
    }
    return SSCANF_SUCCESS;
}