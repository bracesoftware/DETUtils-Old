/*
 * 
 * DETUtils
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

stock ParseQueryContent(const source[], dest[][])
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
    ValidQuery,
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

static stock gDET_QueryID = 0;

stock CreateQuery(const name[], type, const dir[], const file[])
{
    for(new DET_QueryID = 1; 
        DET_QueryID < MAX_FILE_QUERIES; 
        DET_QueryID++)
        {
            if(g_QueryCache[DET_QueryID][ValidQuery] == 0)
            {
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
                g_QueryCache[DET_QueryID][ValidQuery] = 1;
                printf("[DETUtils]: (query created) - \
                    Query '%s'[id : %i] with type %i (loc : %s/%s) validated successfully.",
                    name, DET_QueryID, type, dir, file);
                break;
            }
        }
    return 1;
}

stock DestroyQuery(const name[])
{
    for(new i = 1; i < MAX_FILE_QUERIES; i++)
    {
        if(!strcmp(g_QueryCache[i][QueryName], name, false))
        {
            g_QueryCache[i][ValidQuery] = 0;
            strmid(g_QueryCache[i][QueryName], "_INVALID_QUERY_", 0, 30);
            strmid(g_QueryCache[i][QueryDir], "_INVALID_QDIR_", 0, 50);
            strmid(g_QueryCache[i][QueryFile], "_INVALID_QFILE_", 0, 50);
            g_QueryCache[i][QueryType] = INVALID_QUERY_TYPE;
            printf("[DETUtils]: (query destroyed) - \
                Destroyed the query '%s' [id : %i] successfully.", name, i);
            return 1;
        }
    }
    return 0;
}

stock FormatQuery(const name[], const content[])
{
    for(new i = 1; i < MAX_FILE_QUERIES; i++)
    {
        if(!strcmp(g_QueryCache[i][QueryName], name, false))
        {
            if(g_QueryCache[i][QueryType] == QUERY_TYPE_LOAD)
            {
                strmid(g_QueryCache[i][QueryContent], content, 
                0, 1024);
                return 0;
            }
            strmid(g_QueryCache[i][QueryContent], content, 
                0, 1024);
            g_QueryCache[i][formatted] = true;
            return 1;
        }
    }
    return 0;
}

stock QueryFileExist(const name[])
{
   for(new i = 1; i < MAX_FILE_QUERIES; i ++)
    {
        if(!strcmp(g_QueryCache[i][QueryName], name, false))
        {
            if(g_QueryCache[i][QueryType] != QUERY_TYPE_SAVE)
            {
                printf("[DETUtils]: (query error) - \
                    Cannot check if the file exists; query is not a SAVE query.");
                return false;
            }
            new dfpattern[100];
            format(dfpattern, 100, "%s/%s", 
                g_QueryCache[i][QueryDir], g_QueryCache[i][QueryFile]);
            return fexist(dfpattern);
        }
    }
    return -1; 
}

// Send the query to the specific file
stock SendQuery(const name[])
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
                if(!strfind("SAVE *", g_QueryCache[i][QueryContent], false))
                {
                    printf("[DETUtils]: (query error) - Expected token 'SAVE *'; but found a query data.");
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

                // SAVE * 1,1,1
                // 01234567
                strdel(query, 0, 7); // Delete the `SAVE *` command.

                fwrite(SaveFile, query);
                fclose(SaveFile);

                format(querylog, sizeof querylog,
                    "[DETUtils]: (query sent) - Query type: QUERY_TYPE_SAVE | \
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
                if(strcmp("LOAD *", g_QueryCache[i][QueryContent], false))
                {
                    printf("[DETUtils]: (query error) - Expected token 'LOAD *'; but found unknown content.");
                    return 0;
                }
                new loadedquery[128];
                if(!fexist(dirbose))
                {
                    printf("[DETUtils]: (query error) - \
                        Unable to load a query; file '%s' does not exist.", 
                        dirbose);
                }
                new File:file = fopen(dirbose, io_read);
                if(file)
                {
                    fread(file, loadedquery);
                    strmid(g_QueryCache[i][LoadedQuery], loadedquery, 0, 
                        sizeof loadedquery);
                    printf("[DETUtils]: (query compat) - \
                        loadedquery : %s, query from cache : %s", loadedquery, g_QueryCache[i][LoadedQuery]);
                    g_QueryCache[i][LoadedContent] = true;
                    fclose(file);
                }
                if(funcidx("OnFileQuerySend") != -1)
                {
                    CallLocalFunction("OnFileQuerySend", "sssi", 
                        g_QueryCache[i][QueryDir], 
                        g_QueryCache[i][QueryFile], 
                        g_QueryCache[i][QueryContent], 
                        QUERY_TYPE_LOAD);
                }
                return 1;
            }
        }
    }
    return 1;
}

stock GetLoadedQueryContent(const name[], dests[])
{
    for(new i = 1; i < MAX_FILE_QUERIES; i ++)
    {
        if(!strcmp(g_QueryCache[i][QueryName], name, false))
        {
            if(g_QueryCache[i][QueryType] != QUERY_TYPE_LOAD)
            {
                printf("[DETUtils]: (query error) - \
                    Query is not 'QUERY_TYPE_LOAD'; cannot load query content from file.");
                return 0;
            }
            else if(g_QueryCache[i][LoadedContent] == false) return 0;
            printf("[DETUtils]: (query content) - \
                Returned `%s` as a loaded query.", g_QueryCache[i][LoadedQuery]); 
            return strmid(dests, g_QueryCache[i][LoadedQuery], 0, 1024, 1024);
        }
    }
    return 1;
}

// Needed.
#if !defined floatstr
    native Float:floatstr(const string[]);
#endif

// Get the type of the last query sent.
// When Query_Send is called DET_g_LastQueryType is updated.

stock GetLastQueryType()
{
    return DET_g_LastQueryType;
}

// Set delimiter which will be used to PARSE
// query values. By default it is comma.

stock SetQueryDelimiter(delimiter)
{
    DET_g_QueryDelimiter = delimiter;
    if(delimiter == '.')
    {
        printf("[DETUtils]: (warning) - delimiter :: Delimiter '.' is successfully set; \n\
            though, having a '.' as a delimiter can cause problems while loading float values.");
    }
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

public OnDETUtilsInit()
{
    #if defined detutils_debug
    SaveLogIntoFile("detutils_queries.log", "[DETUtils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_queries.log", "[DETUtils]: (debug) - Loaded.");
    #endif
    LoadDETUtilsScript(DETUTILS_SCRIPT_FILEQUERIES);
    if(funcidx("d_fq_detutilsinit") != -1)
    {
        CallLocalFunction("d_fq_detutilsinit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsInit
    #undef OnDETUtilsInit
#else
    #define _ALS_OnDETUtilsInit
#endif

#define OnDETUtilsInit( d_fq_detutilsinit(

forward d_fq_detutilsinit();