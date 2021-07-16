/*

                            =============================
                              SA:MP DEntisT's Utilities
                            =============================

Legal:
    Version: MPL 1.1
    
    The contents of this file are subject to the Mozilla Public License Version 
    1.1 the "License"; you may not use this file except in compliance with 
    the License. You may obtain a copy of the License at 
    http://www.mozilla.org/MPL/
    
    Software distributed under the License is distributed on an "AS IS" basis,
    WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
    for the specific language governing rights and limitations under the
    License.
    
    The Original Code is SA:MP | DETUtils.
    
    The Initial Developer of the original code is DEntisT 'Unity' Brace.
    Portions created by the Initial Developer are Copyright C 2021
    the Initial Developer. All Rights Reserved.

Contributors:
    DEntisT

Thanks:
    open.mp team - ideas, support, help during development

Very special thanks to:
    Thiadmer - PAWN, whose limits continue to amaze me!
    Kye/Kalcor - SA:MP
    SA:MP Team past, present and future - SA:MP
    open.mp team present and future - SA:MP

Optional plugins:
    Incognito - streamer

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