/*
 * SA:MP | DEntisT's Utilites 
 * Library tags
 *
 *
 * Thanks to:
 *
 *
 * @DEntisT (me) - the include
 *
 */

#if defined d_extra_included
    #endinput
#endif

#define d_extra_included

/*
                                                
88888888ba,                                     
88      `"8b                 ,d                 
88        `8b                88                 
88         88  ,adPPYYba,  MM88MMM  ,adPPYYba,  
88         88  ""     `Y8    88     ""     `Y8  
88         8P  ,adPPPPP88    88     ,adPPPPP88  
88      .a8P   88,    ,88    88,    88,    ,88  
88888888Y"'    `"8bbdP"Y8    "Y888  `"8bbdP"Y8  
                                                
*/

#define MAX_INTERIORS 300
#define InteriorData:[%0] gDETUtils_InteriorData[MAX_INTERIORS][%0]

#define MAX_FUNC_NAME (32)

/*
                                                                      
88888888888                                                           
88                          ,d                                        
88                          88                                        
88aaaaa      8b,     ,d8  MM88MMM  8b,dPPYba,  ,adPPYYba,  ,adPPYba,  
88"""""       `Y8, ,8P'     88     88P'   "Y8  ""     `Y8  I8[    ""  
88              )888(       88     88          ,adPPPPP88   `"Y8ba,   
88            ,d8" "8b,     88,    88          88,    ,88  aa    ]8I  
88888888888  8P'     `Y8    "Y888  88          `"8bbdP"Y8  `"YbbdP"'  
                                                                      
                                                                      
*/

new DETUtils_g_Shifthour, DETUtils_g_Timeshift = 0;

gDETUtils_FixHourData(DETUtils_f_Hour)
{
    DETUtils_f_Hour = DETUtils_g_Timeshift+DETUtils_f_Hour;

    if(DETUtils_f_Hour < 0)
    {
        DETUtils_f_Hour = DETUtils_f_Hour+24;
    }
    else if(DETUtils_f_Hour > 23)
    {
        DETUtils_f_Hour = DETUtils_f_Hour-24;
    }
    DETUtils_g_Shifthour = DETUtils_f_Hour;
    return 1;
}

stock SaveLogIntoFile( const DETUtils_FileName[], const DETUtils_Log[]) 
{
    new DETUtils_Entry[ 128 ], s, m, se, day, year, month;

    getdate( year, month, day );

    gettime( s, m, se );

    gDETUtils_FixHourData( s );

    s = DETUtils_g_Shifthour;
    
    format( DETUtils_Entry, sizeof( DETUtils_Entry ), 
        "%d/%d/%d | %d/%d/%d | %s\r\n", day, month, year, s, m, se, DETUtils_Log );

    new File:DETUtils_File;
    DETUtils_File = fopen( DETUtils_FileName, io_append );

    fwrite( DETUtils_File, DETUtils_Entry );

    fclose( DETUtils_File );
}