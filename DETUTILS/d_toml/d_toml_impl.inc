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

// fexist
stock tomlexist(const filename[])
{
    new newfilename[64];
    format(newfilename, sizeof newfilename, "%s.toml", filename);
    return fexist(newfilename);
}

// fremove
stock tomlremove(const filename[])
{
    new newfilename[64];
    format(newfilename, sizeof newfilename, "%s.toml", filename);
    return fremove(newfilename);
}

// fwrite
stock tomlcreate(const filename[])
{
    if(tomlexist(filename)) return 0;
    new newfilename[64];
    format(newfilename, sizeof newfilename, "%s.toml", filename);
    new File:file = fopen(newfilename, io_write);
    if(file)
    {
        fwrite(file, "[toml]");
        fwrite(file, "\r\n");
        fclose(file);
        return 1;
    }
    return 0;
}

// fread
new tomlcontent[4096];
stock __tomlget(const filename[], const key[])
{
    new newfilename[64], ret[256];
    format(ret, sizeof ret, " ");
    if(!tomlexist(filename)) return ret;
    format(newfilename, sizeof newfilename, "%s.toml", filename);
    new File:file = fopen(newfilename, io_read);
    #if defined DETUTILS_DEBUG_MODE
    printf("[DETUtils]: (parse) - toml :: %s%s", 
        file ? "Successfully opened : " : "Failed to open : ", newfilename);
    #endif
    new parse[2][256];
    if(file) do
    {
        /*for(new i = 1; i < strlen(tomlcontent); i++)
        {
            if(tomlcontent[i] == '=')
            {
                tomlcontent[i+1] = 0;
                tomlcontent[i-1] = 0;
            }
        }*/
        __parsetomlline(tomlcontent, parse);
        #if defined DETUTILS_DEBUG_MODE
        printf("[DETUtils]: (parse) - toml :: 0 : %s, 1 : %s", parse[0], parse[1]);
        #endif
        if(!strcmp(parse[0], key))
        {
            format(ret, sizeof ret, "%s", parse[1]);
            for(new i; i < strlen(ret); i++)
            {
                if(ret[i] == '\n') ret[i] = 0;
                if(ret[i] == '\r') ret[i] = 0;
            }
            fclose(file);
            return ret;
        }
    }
    while(fread(file, tomlcontent));
    fclose(file);
    return ret;
}

// "get" functions
stock tomlgetint(const filename[], const key[])
{
    return strval(__tomlget(filename, key));
}

stock bool:tomlgetbool(const filename[], const key[])
{
    new ret[256];
    format(ret, sizeof ret, "%s", __tomlget(filename, key));
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

stock Float:tomlgetfloat(const filename[], const key[])
{
    return floatstr(__tomlget(filename, key));
}

stock tomlgetstr(const filename[], const key[])
{
    new ret[256];
    format(ret, sizeof ret, __tomlget(filename, key));
    for(new i; i < strlen(ret); i++)
    {
        if(ret[i] == '\"') ret[i] = 0;
    }
    return ret;
}