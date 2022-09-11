/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which provides 
 *   a TOML file management.
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

// fwrite
new tomlcontent2[4096];
stock __tomlset(const filename[], const key[], const value[])
{
    new newfilename[64];
    if(!tomlexist(filename)) return 0;
    format(newfilename, sizeof newfilename, "%s.toml", filename);
    new File:file = fopen(newfilename);
    #if defined DETUTILS_DEBUG_MODE
    printf("[DETUtils]: (parse) - toml :: %s%s", 
        file ? "Successfully opened : " : "Failed to open : ", newfilename);
    #endif
    new parse[2][256];
    new linestr[512];
    if(file)
    {
        format(linestr, sizeof linestr, "%s=%s", key, value);
        fwrite(file, linestr);
        fwrite(file, "\r\n");
        #if defined DETUTILS_DEBUG_MODE
        printf("[DETUtils]: (parse) - toml :: Value of '%s' updated to '%s'.", parse[0], value);
        #endif
        fclose(file);
        return 1;
    }
    fclose(file);
    return 0;
}

// "set" functions
stock tomlsetint(const filename[], const key[], value)
{
    new tomlvalue[256];
    format(tomlvalue, sizeof tomlvalue, "%i", value);
    return __tomlset(filename, key, tomlvalue);
}

stock tomlsetbool(const filename[], const key[], bool:value)
{
    new tomlvalue[256];
    format(tomlvalue, sizeof tomlvalue, "%s", value ? "true" : "false");
    return __tomlset(filename, key, tomlvalue);
}

stock tomlsetfloat(const filename[], const key[], Float:value)
{
    new tomlvalue[256];
    format(tomlvalue, sizeof tomlvalue, "%f", value);
    return __tomlset(filename, key, tomlvalue);
}

stock tomlsetstr(const filename[], const key[], const value[])
{
    return __tomlset(filename, key, value);
}

stock tomlwritecomment(const filename[], const comment[])
{
    new newfilename[64];
    if(!tomlexist(filename)) return 0;
    format(newfilename, sizeof newfilename, "%s.toml", filename);
    new File:file = fopen(newfilename);
    #if defined DETUTILS_DEBUG_MODE
    printf("[DETUtils]: (comment) - toml :: %s%s", 
        file ? "Successfully opened : " : "Failed to open : ", newfilename);
    #endif
    new linestr[512];
    if(file)
    {
        format(linestr, sizeof linestr, "# %s", comment);
        fwrite(file, linestr);
        fwrite(file, "\r\n");
        #if defined DETUTILS_DEBUG_MODE
        printf("[DETUtils]: (comment) - toml :: Successfully wrote comment : '%s'.", comment);
        #endif
        fclose(file);
        return 1;
    }
    fclose(file);
    return 0;
}

stock tomlwritetable(const filename[], const table[])
{
    new newfilename[64];
    if(!tomlexist(filename)) return 0;
    format(newfilename, sizeof newfilename, "%s.toml", filename);
    new File:file = fopen(newfilename);
    #if defined DETUTILS_DEBUG_MODE
    printf("[DETUtils]: (table) - toml :: %s%s", 
        file ? "Successfully opened : " : "Failed to open : ", newfilename);
    #endif
    new linestr[512];
    if(file)
    {
        format(linestr, sizeof linestr, "[%s]", table);
        fwrite(file, linestr);
        fwrite(file, "\r\n");
        #if defined DETUTILS_DEBUG_MODE
        printf("[DETUtils]: (table) - toml :: Successfully wrote table : '%s'.", table);
        #endif
        fclose(file);
        return 1;
    }
    fclose(file);
    return 0;
}