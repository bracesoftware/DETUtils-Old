/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - An excel-like table management system.
 *
 *
 */

#define @DETUTILSTABLES_KWORD__@%0\32; @DETUTILSTABLES_KWORD__@
#define @table%0(%1) @DETUTILSTABLES_KWORD__@
#define @DETUTILSTABLES_KWORD__1@%0\32; @DETUTILSTABLES_KWORD__1@
#define @column%0(%1) @DETUTILSTABLES_KWORD__1@
#define @DETUTILSTABLES_KWORD__2@%0\32; @DETUTILSTABLES_KWORD__2@
#define @datarow%0(%1) @DETUTILSTABLES_KWORD__2@
#define @DETUTILSTABLES_KWORD__3@%0\32; @DETUTILSTABLES_KWORD__3@
#define @cell%0(%1) @DETUTILSTABLES_KWORD__3@
/*
                                                                                      
88b           d88              88                         db         88888888ba   88  
888b         d888              ""                        d88b        88      "8b  88  
88`8b       d8'88                                       d8'`8b       88      ,8P  88  
88 `8b     d8' 88  ,adPPYYba,  88  8b,dPPYba,          d8'  `8b      88aaaaaa8P'  88  
88  `8b   d8'  88  ""     `Y8  88  88P'   `"8a        d8YaaaaY8b     88""""""'    88  
88   `8b d8'   88  ,adPPPPP88  88  88       88       d8""""""""8b    88           88  
88    `888'    88  88,    ,88  88  88       88      d8'        `8b   88           88  
88     `8'     88  `"8bbdP"Y8  88  88       88     d8'          `8b  88           88  
                                                                                      
                                                                                      
*/

#define @DETUTILSTABLES_KWORD__@Create%0(%1) __CreateTable(%1)
#define @DETUTILSTABLES_KWORD__@Remove%0(%1) __DeleteTable(%1)
#define @DETUTILSTABLES_KWORD__@Preview%0(%1) __PreviewTable(%1)

#define @DETUTILSTABLES_KWORD__1@Add%0(%1) __CreateColumn(%1)
#define @DETUTILSTABLES_KWORD__1@Remove%0(%1) __DeleteColumn(%1)

#define @DETUTILSTABLES_KWORD__2@Add%0(%1) __CreateRow(%1)
#define @DETUTILSTABLES_KWORD__2@Remove%0(%1) __DeleteRow(%1)

#define @DETUTILSTABLES_KWORD__3@Set%0(%1) __SetCellValue(%1)
#define @DETUTILSTABLES_KWORD__3@Get%0(%1) __GetCellValue(%1)