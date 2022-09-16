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

#include "d_tables_macros"

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

/*

Simple preview

Preview of: test
----------------------------------
    Dentist | Bozo | xd
----------------------------------
money | 1000 | 1000 | 1000
----------------------------------
lvl | 3 | 4 | 8
----------------------------------
pw | retardedcosmos | ahahahah | ex
----------------------------------

*/

stock setcolumnamount(const __table[], value)
{
    new file_name[150], valstring[50];
    valstr(valstring, value);
    format(file_name, sizeof file_name,"columnnum_%s.ini", __table);
    new File: file2 = fopen(file_name, io_write);
    fwrite(file2, valstring);
    fclose(file2);
    return 1;
}

stock setrowamount(const __table[], value)
{
    new file_name[150], valstring[50];
    valstr(valstring, value);
    format(file_name, sizeof file_name,"rownum_%s.ini", __table);
    new File: file2 = fopen(file_name, io_write);
    fwrite(file2, valstring);
    fclose(file2);
    return 1;
}

stock getcolumnamount(const __table[])
{
    new file_name[150];
    format(file_name, sizeof file_name,
        "columnnum_%s.ini", __table);
    new returnstring[128];
    format(returnstring, sizeof returnstring, "0");
    if(!fexist(file_name)) return strval(returnstring);
    new File: file = fopen(file_name, io_read);
    if (file)
    {
        fread(file, returnstring);

        fclose(file);

        return strval(returnstring);
    }
    return strval(returnstring);
}

stock getrowamount(const __table[])
{
    new file_name[150];
    format(file_name, sizeof file_name,
        "rownum_%s.ini", __table);
    new returnstring[128];
    format(returnstring, sizeof returnstring, "0");
    if(!fexist(file_name)) return strval(returnstring);
    new File: file = fopen(file_name, io_read);
    if (file)
    {
        fread(file, returnstring);

        fclose(file);

        return strval(returnstring);
    }
    return strval(returnstring);
}

stock tablecreate(const name[], columns, rows)
{
    setcolumnamount(name, columns);
    setrowamount(name, rows);
    return 1;
}

stock previewtable(const name[])
{
    // a = rows
    // b = columns
    print("=============================================");
    print(" ");
    print(" ");
    printf("TABLE PREVIEW | Previewing: %s", name);
    print(" ");
    print(" ");
    new rowline[1024], cellvalue[50];
    for(new a; a < (getrowamount(name)); a++)
    {
        format(rowline, sizeof rowline, "ROW: %i | ", a);
        for(new b; b < (getcolumnamount(name)); b++)
        {
            format(cellvalue, sizeof cellvalue, 
                "%s | ", getcellvalue(name, b, a));
            strcat(rowline, cellvalue);
        }
        print(rowline);
        strdel(rowline, 0, sizeof rowline);
    }
    print(" ");
    print(" ");
    print("=============================================");
    return 1;
}

stock setcellvalue(const __table[], __column, __row, const value[])
{
    new file_name[150];
    format(file_name, sizeof file_name,
        "cell_%s_%i_%i.ini", 
        __table, __column, __row);
    new File: file2 = fopen(file_name, io_write);
    fwrite(file2, value);
    fclose(file2);
    return 1;
}

stock getcellvalue(const __table[], __column, __row)
{
    new file_name[150];
    format(file_name, sizeof file_name,
        "cell_%s_%i_%i.ini", __table, __column, __row);
    new returnstring[128];
    format(returnstring, sizeof returnstring, "(empty)");
    if(!fexist(file_name)) return returnstring;
    new File: file = fopen(file_name, io_read);
    if (file)
    {
        fread(file, returnstring);

        fclose(file);

        return returnstring;
    }
    return returnstring;
}

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

public OnDETUtilsInit()
{
    #if defined DETUTILS_DEBUG_MODE
    SaveLogIntoFile("detutils_tables.log", "[DETUtils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_tables.log", "[DETUtils]: (debug) - Loaded.");
    #endif
    LoadDETUtilsScript(DETUTILS_SCRIPT_TABLES);
    if(funcidx("d_tab_detutilsinit") != -1)
    {
        CallLocalFunction("d_tab_detutilsinit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsInit
    #undef OnDETUtilsInit
#else
    #define _ALS_OnDETUtilsInit
#endif

#define OnDETUtilsInit( d_tab_detutilsinit(

forward d_tab_detutilsinit();

// cleanup

public OnDETUtilsExit()
{
    UnloadDETUtilsScript(DETUTILS_SCRIPT_TABLES);
    if(funcidx("d_tab_detutilsexit") != -1)
    {
        CallLocalFunction("d_tab_detutilsexit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsExit
    #undef OnDETUtilsExit
#else
    #define _ALS_OnDETUtilsExit
#endif

#define OnDETUtilsExit( d_tab_detutilsexit(

forward d_tab_detutilsexit();