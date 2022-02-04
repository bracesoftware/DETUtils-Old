/*
 * 
 * SA:MP DEntisT's Utilities
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which provides sending
 *   of file queries. Similar concept
 *   of SQL.
 *
 *
 */

#tryinclude "d_extra\d_libtags.inc"

#if !defined d_extra_included
    #error [samp-detutils]: (error) - You are missing "d_extra\d_libtags.inc" in your "include\DETUTILS" folder.
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

// Query types to send:
#define INVALID_QUERY_TYPE -1
#define QUERY_TYPE_SAVE 0
#define QUERY_TYPE_LOAD 1

new DET_g_LastQueryType = INVALID_QUERY_TYPE;
new DET_g_QueryDelimiter = ',';

// Really GENERIC entry since this is a function used to read data.
static d_ud_SplitString(const source[], dest[][])
{
    new i, li;
    new aNum;
    new len;
    while(i <= strlen(source))
    {
        if(source[i] == DET_g_QueryDelimiter || i == strlen(source))
        {
            len = strmid(dest[aNum], source, li, i, 128);
            dest[aNum][len] = 0;
            li = i+1;
            aNum++;
        }
        i++;
    }
    return 1;
}

// Callbacks:
forward OnFileQuerySend(directory[], file[], query[], type);

#if !defined MAX_FILE_QUERIES

    #define MAX_FILE_QUERIES 1000

#endif

enum enum_QueryData
{
    QueryName[32],
    QueryContent[1024],
    QueryType,
    bool:formatted,
    QueryDir[32],
    QueryFile[32],
    LoadedQuery[1024],
    bool:LoadedContent
}

new g_QueryCache[MAX_FILE_QUERIES][enum_QueryData];

static DET_QueryID = 0;

stock Query_Create(const name[], type, const dir[], const file[])
{
    DET_QueryID ++;
    strmid(g_QueryCache[DET_QueryID][QueryName], name, 0, 30);
    strmid(g_QueryCache[DET_QueryID][QueryDir], dir, 0, 50);
    strmid(g_QueryCache[DET_QueryID][QueryFile], file, 0, 50);
    g_QueryCache[DET_QueryID][QueryType] = type;
    if(g_QueryCache[DET_QueryID][QueryType] == QUERY_TYPE_SAVE)
    {
        g_QueryCache[DET_QueryID][formatted] = false;
    }
    else if(g_QueryCache[DET_QueryID][QueryType] == QUERY_TYPE_LOAD)
    {
        g_QueryCache[DET_QueryID][formatted] = true;
    }
    return 1;
}

stock Query_Format(const name[], const content[])
{
    for(new i = 1; i < MAX_FILE_QUERIES; i++)
    {
        if(!strcmp(g_QueryCache[i][QueryName], name, false))
        {
            if(g_QueryCache[DET_QueryID][QueryType] == QUERY_TYPE_LOAD)
            {
                printf(
                    "[samp-detutils]: (query error) - \
                    Unable to format queries with 'QUERY_TYPE_LOAD' type.")
                ;
                return 0;
            }
            strmid(g_QueryCache[DET_QueryID][QueryContent], content, 
                0, 1024);
            g_QueryCache[i][formatted] = true;
            return 1;
        }
    }
    return 0;
}

// Send the query to the specific file
stock Query_Send(const name[])
{
    for(new i = 1; i < MAX_FILE_QUERIES; i ++)
    {
        if(!strcmp(g_QueryCache[i][QueryName], name, false))
        {
            new dirbose[100];
                format(dirbose, 100,
                    "%s/%s", 
                    g_QueryCache[i][QueryDir], 
                    g_QueryCache[i][QueryFile]);

            new querylog[1024];

            if(g_QueryCache[i][QueryType] == QUERY_TYPE_SAVE)
            {
                if(!strfind("save", g_QueryCache[i][QueryContent], false))
                {
                    printf("[samp-detutils]: (query error) - Expected token 'save'; but found a query data.");
                    return 0;
                }
                new query[1024];
                format(query, 1024, "%s", g_QueryCache[i][QueryContent]);
                if(funcidx("OnFileQuerySend") != -1)
                {
                    CallLocalFunction("OnFileQuerySend", "sssi", 
                        g_QueryCache[i][QueryDir], 
                        g_QueryCache[i][QueryFile], 
                        g_QueryCache[i][QueryContent], 
                        QUERY_TYPE_SAVE);
                }

                DET_g_LastQueryType = QUERY_TYPE_SAVE;

                new File:SaveFile = fopen(dirbose, io_write);

                // save 1,1,1
                // 01234
                strdel(query, 0, 4);

                fwrite(SaveFile, query);
                fclose(SaveFile);

                format(querylog, sizeof querylog,
                    "[samp-detutils]: (query sent) - Query type: QUERY_TYPE_SAVE | \
                    Directory: %s | File: %s | Query code: %s", 
                    g_QueryCache[i][QueryDir], 
                    g_QueryCache[i][QueryFile], 
                    g_QueryCache[i][QueryContent]);
                SaveLogIntoFile("detutils_queries.log", querylog);

                print(querylog);
                return 1;
            }
            if(g_QueryCache[i][QueryType] == QUERY_TYPE_LOAD)
            {
                new loadedquery[128];
                if(!fexist(dirbose))
                {
                    printf("[samp-detutils]: (query error) - \
                        Unable to load a query; file '%s' does not exist.", 
                        dirbose);
                }
                new File: file = fopen(dirbose, io_read);
                if (file)
                {
                    fread(file, loadedquery);
                    strmid(g_QueryCache[i][LoadedQuery], loadedquery, 0, 
                        sizeof loadedquery, sizeof loadedquery);
                    g_QueryCache[i][LoadedContent] = true;
                    fclose(file);
                }
                return 1;
            }
        }
    }
    return 1;
}

stock Query_GetLoadedContent(const name[])
{
    for(new i = 1; i < MAX_FILE_QUERIES; i ++)
    {
        if(!strcmp(g_QueryCache[i][QueryName], name, false))
        {
            if(g_QueryCache[i][QueryType] != QUERY_TYPE_LOAD)
            {
                printf("[samp-detutils]: (query error) - \
                    Query is not 'QUERY_TYPE_LOAD'; cannot load query content from file.");
                return 0;
            }
            else if(g_QueryCache[i][LoadedContent] == false) return 0;
            return g_QueryCache[i][LoadedQuery];
        }
    }
    return 0;
}

// Needed.
#if !defined floatstr
    native Float:floatstr(const string[]);
#endif

// Get the type of the last query sent.
// When Query_Send is called DET_g_LastQueryType is updated.
stock Query_GetLastType()
{
    return DET_g_LastQueryType;
}

// Set delimiter which will be used to PARSE
// query values. By default it is comma.
stock Query_SetDelimiter(delimiter)
{
    DET_g_QueryDelimiter = delimiter;
    return 1;
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

static AnnounceLibraryLoaded_queries()
{
    LoadDETUtilsScript(DETUTILS_SCRIPT_FILEQUERIES);
}

#if !defined FILTERSCRIPT

main()
{
    #if defined detutils_debug
    SaveLogIntoFile("detutils_queries.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_queries.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    AnnounceLibraryLoaded_queries();
    a_queries_main();
}

#if defined _ALS_main
    #undef main
#else
    #define _ALS_main
#endif

#define main a_queries_main

#else

#define detutils_queries_TRUE 1

public OnFilterScriptInit()
{
    AnnounceLibraryLoaded_queries();
    #if defined detutils_debug
    SaveLogIntoFile("detutils_queries.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_queries.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    if(funcidx("a_queries_OnfsInit") != -1)
    {
        CallLocalFunction("a_queries_OnfsInit", "i", playerid);
    }
    return detutils_queries_TRUE;
}

#if defined _ALS_OnFilterScriptInit
    #undef OnFilterScriptInit
#else
    #define _ALS_OnFilterScriptInit
#endif

#define OnFilterScriptInit a_queries_OnfsInit

forward a_queries_OnfsInit();

#endif