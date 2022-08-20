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


#if __Pawn >= 0x0400
    #error [DETUtils]: (error) - Library does not support Pawn 4.0.x yet.
#elseif __Pawn < 0x0300
    #error [DETUtils]: (error) - Library does not support Pawn 2.0.x/1.0.x yet.
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

#define __DETUtils 0x205
#define __DETUtilsRelease 0x1

#define DETUTILS_VERSION_MAJOR 2
#define DETUTILS_VERSION_MINOR 0
#define DETUTILS_VERSION_PATCH 5
#define DETUTILS_VERSION_RELEASE 1