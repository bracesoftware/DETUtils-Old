/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which provides 
 *   a YAML file management.
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
new yamlcontent2[4096];
stock __yamlset(const filename[], const key[], const value[])
{
    new newfilename[64], linestr[512];
    format(newfilename, sizeof newfilename, "%s.yaml", filename);
    new File:file = fopen(newfilename, io_append);
    
    #if defined DETUTILS_DEBUG_MODE
        printf("[DETUtils]: (parse) - yaml :: %s%s", 
        file ? "Successfully opened : " : "Failed to open : ", newfilename);
    
    #endif

    format(linestr, sizeof linestr, "%s: %s\r\n", key, value);
    fwrite(file, linestr);

    #if defined DETUTILS_DEBUG_MODE
        printf("[DETUtils]: (parse) - yaml :: Value of '%s' updated to '%s'.", key, value);
    #endif

    fclose(file);
    return 1;
}

// "set" functions
stock yamlsetint(const filename[], const key[], value)
{
    new yamlvalue[256];
    format(yamlvalue, sizeof yamlvalue, "%i", value);
    return __yamlset(filename, key, yamlvalue);
}

stock yamlsetbool(const filename[], const key[], bool:value)
{
    new yamlvalue[256];
    format(yamlvalue, sizeof yamlvalue, "%s", value ? "true" : "false");
    return __yamlset(filename, key, yamlvalue);
}

stock yamlsetfloat(const filename[], const key[], Float:value)
{
    new yamlvalue[256];
    format(yamlvalue, sizeof yamlvalue, "%f", value);
    return __yamlset(filename, key, yamlvalue);
}

stock yamlsetstr(const filename[], const key[], const value[])
{
    new yamlvalue[256];
    format(yamlvalue, sizeof yamlvalue, "%s", value);
    return __yamlset(filename, key, yamlvalue);
}

stock yamlwritecomment(const filename[], const comment[])
{
    new newfilename[64];
    if(!yamlexist(filename)) return 0;
    format(newfilename, sizeof newfilename, "%s.yaml", filename);
    new File:file = fopen(newfilename, io_append);
    #if defined DETUTILS_DEBUG_MODE
    printf("[DETUtils]: (comment) - yaml :: %s%s", 
        file ? "Successfully opened : " : "Failed to open : ", newfilename);
    #endif
    new linestr[512];
    if(file)
    {
        format(linestr, sizeof linestr, "# %s", comment);
        fwrite(file, linestr);
        fwrite(file, "\r\n");
        #if defined DETUTILS_DEBUG_MODE
        printf("[DETUtils]: (comment) - yaml :: Successfully wrote comment : '%s'.", comment);
        #endif
        fclose(file);
        return 1;
    }
    fclose(file);
    return 0;
}