/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Provides lambda functions,
 *   small functions used in expressions,
 *   such as conditions, calls, etc.
 *
 *
 */

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

// Keywords.

#define @DETUTILSLAMBDA_KWORD__@%0\32; @DETUTILSLAMBDA_KWORD__@
#define lambda @DETUTILSLAMBDA_KWORD__@

#define @D_LM_%0\32; @D_LM_
#define @D_LMV_%0\32; @D_LMV_

#define Lambda:%1= @D_LMV_%1;@D_LM_%1();@D_LM_%1()

#define @DETUTILSLAMBDA_KWORD__@for%0=%1{%2} _D_LAMBDA_for__(%2)
#define @DETUTILSLAMBDA_KWORD__@while%0=%1{%2} _D_LAMBDA_while__(%2)
#define @DETUTILSLAMBDA_KWORD__@using%0=%1{%2} _D_LAMBDA_using__(%2)