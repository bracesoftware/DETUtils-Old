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

// fexist
stock yamlexist(const filename[])
{
    new newfilename[64];
    format(newfilename, sizeof newfilename, "%s.yaml", filename);
    return fexist(newfilename);
}

// fremove
stock yamlremove(const filename[])
{
    new newfilename[64];
    format(newfilename, sizeof newfilename, "%s.yaml", filename);
    return fremove(newfilename);
}

// fwrite
stock yamlcreate(const filename[])
{
    if(yamlexist(filename)) return 0;
    new newfilename[64];
    format(newfilename, sizeof newfilename, "%s.yaml", filename);
    new File:file = fopen(newfilename, io_write);
    if(file)
    {
        fwrite(file, "# yaml");
        fwrite(file, "\r\n");
        fclose(file);
        return 1;
    }
    return 0;
}

// fread
new yamlcontent[4096];
stock __yamlget(const filename[], const key[])
{
    new newfilename[64], ret[256];
    format(ret, sizeof ret, " ");
    if(!yamlexist(filename)) return ret;
    format(newfilename, sizeof newfilename, "%s.yaml", filename);
    new File:file = fopen(newfilename, io_read);
    #if defined DETUTILS_DEBUG_MODE
    printf("[DETUtils]: (parse) - yaml :: %s%s", 
        file ? "Successfully opened : " : "Failed to open : ", newfilename);
    #endif
    new parse[2][256];
    if(file) do
    {
        /*for(new i = 1; i < strlen(yamlcontent); i++)
        {
            if(yamlcontent[i] == '=')
            {
                yamlcontent[i+1] = 0;
                yamlcontent[i-1] = 0;
            }
        }*/
        __parseyamlline(yamlcontent, parse);
        #if defined DETUTILS_DEBUG_MODE
        printf("[DETUtils]: (parse) - yaml :: 0 : %s, 1 : %s", parse[0], parse[1]);
        #endif
        if(!strcmp(parse[0], key))
        {
            format(ret, sizeof ret, "%s", parse[1]);
            //ret[0] = 0;
            for(new i; i < strlen(ret); i++)
            {
                if(ret[i] == '\n') ret[i] = 0;
                if(ret[i] == '\r') ret[i] = 0;
                if(ret[i] == '\t') ret[i] = 0;
            }
            fclose(file);
            return ret;
        }
    }
    while(fread(file, yamlcontent));
    fclose(file);
    return ret;
}

// "get" functions
stock yamlgetint(const filename[], const key[])
{
    return strval(__yamlget(filename, key));
}

stock bool:yamlgetbool(const filename[], const key[])
{
    new ret[256];
    format(ret, sizeof ret, "%s", __yamlget(filename, key));
    if(!strcmp(ret, "false"))
    {
        format(ret, sizeof ret, "0");
    }
    if(!strcmp(ret, "true"))
    {
        format(ret, sizeof ret, "1");
    }
    return bool:strval(ret);
}

stock Float:yamlgetfloat(const filename[], const key[])
{
    return floatstr(__yamlget(filename, key));
}

#define yamlgetstr __yamlget