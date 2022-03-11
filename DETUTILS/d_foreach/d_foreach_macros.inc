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

#if defined __DETUTILS_DEFAULT_ITERATORS

 	#error [samp-detutils]: (iter error) - Compile option `__DETUTILS_DEFAULT_ITERATORS` is not available yet.

#endif

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
#define @DETUTILSFOREACH_KWORD__@%0\32; @DETUTILSFOREACH_KWORD__@
#define foreach @DETUTILSFOREACH_KWORD__@
#define @DETUTILSFOREACH_KWORD__2@%0\32; @DETUTILSFOREACH_KWORD__2@
#define iterator @DETUTILSFOREACH_KWORD__2@
#define iter iterator

// Prefixes!
#define itr_%0\32; itr_
#define iid_%0\32; iid_
#define ite_%0\32; ite_
#define fii_%0\32; fii_
#define dpp_%0\32; dpp_
#define @for for
#define itridx%0\32; itridx

// Core preprocessor.
#define DETUTILSFOREACH_DO_DECL:#${%0..%1} enum ite_%0{__retvls[%1]};
#define DETUTILS_ITER__decl:<%0..?||$$|#> new iid_%0;new itr_%0[ite_%0]
#define DETUTILS_ITER__SIZE:|||%1..$||| sizeof(itr_%1[__retvls])
#define @d_ADD<%1,%2> itridx%1++,%2=itr_%1[__retvls][--itridx%1]
#define @d_FUNC<%1> itridx%1<iterator sizeof(%1)
#define @d_NEW<%1> new itridx%1
#define @d_VAL_C<%1> itr_%1[__retvls][itridx%1]!=-1

// Iterator preprocessor.
#define @DET_FOREACH_PP_1<%1> for(new dpp_%1;dpp_%1<iterator sizeof(%1);dpp_%1++)
#define @DET_FOREACH_PP_2<%1..%2> if(itr_%1[__retvls][dpp_%1]==%2)itr_%1[__retvls]
#define @DET_FOREACH_PP_3<$%1..#> [dpp_%1]=-1;break;

// Iterators and iterator functions.
#define @DETUTILSFOREACH_KWORD__2@new%0<%1> DETUTILSFOREACH_DO_DECL:#${%0..%1} DETUTILS_ITER__decl:<%0..?||$$|#>
#define @DETUTILSFOREACH_KWORD__2@sizeof%0(%1) DETUTILS_ITER__SIZE:|||%1..$|||
#define @DETUTILSFOREACH_KWORD__2@add%0(%1,%2) itr_%1[__retvls][iid_%1]=%2;iid_%1++
#define @DETUTILSFOREACH_KWORD__2@remove%0(%1,%2)%3; @DET_FOREACH_PP_1<%1> \
{@DET_FOREACH_PP_2<%1..%2>@DET_FOREACH_PP_3<$%1..#>}
#define @DETUTILSFOREACH_KWORD__2@init%0(%1) for(new fii_%1;fii_%1<iterator sizeof(%1);fii_%1++) \
itr_%1[__retvls][fii_%1]=-1;iterator add(%1,-1)

// Actual `foreach do`.
#define @DETUTILSFOREACH_KWORD__@do%0(%3new%2:%1) new %2;@for(@d_NEW<%1>; \
@d_FUNC<%1>;@d_ADD<%1,%2>)if(@d_VAL_C<%1>)