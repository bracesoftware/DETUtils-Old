/*
 * 
 * SA:MP DEntisT's Utilities
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Entry files.
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

#define @DETUTILSFOREACH_KWORD__@%0\32; @DETUTILSFOREACH_KWORD__@
#define foreach @DETUTILSFOREACH_KWORD__@
#define @DETUTILSFOREACH_KWORD__2@%0\32; @DETUTILSFOREACH_KWORD__2@
#define iterator @DETUTILSFOREACH_KWORD__2@
#define itr_%0\32; itr_
#define ite_%0\32; ite_

#define DETUTILSFOREACH_DO_DECL:#${%0..%1} enum ite_%0{__retvls[%1]};
#define DETUTILS_ITER__decl:<%0..?||$$|#> new itr_%0[ite_%0]
#define DETUTILS_ITER__SIZE:|||%1..$||| sizeof(itr_%1[__retvls])

#define @DETUTILSFOREACH_KWORD__@do%0(%1) for(new idx=1;idx<=iterator sizeof(%1))
#define @DETUTILSFOREACH_KWORD__2@new%0<%1> DETUTILSFOREACH_DO_DECL:#${%0..%1} DETUTILS_ITER__decl:<%0..?||$$|#>
#define @DETUTILSFOREACH_KWORD__2@sizeof%0(%1) DETUTILS_ITER__SIZE:|||%1..$|||
#define @DETUTILSFIREACH_KWORD__2@add