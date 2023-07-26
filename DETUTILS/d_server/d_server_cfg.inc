/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - A library which is providing
 *   generally server-related functions.
 *
 *
 */

new DET_g_ServerConfigContent[8000];

stock DET_s_ParseConfig(const code[], destln[][], delimiter)
{
    new 
        i, 
        start,
        index,
        len;

    while(i <= strlen(code))
    {
        if(code[i] == delimiter || i == strlen(code))
        {
            len = strmid(destln[index], code, start, i, 128);
            destln[index][len] = 0;
            start = i+1;
            index++;
        }
        i++;
    }
    return 1;
}

stock DET_s_ReadServerConfig()
{
    new File:file = fopen("../server.cfg", io_read), rlen;
    for(new i; i < MAX_SERVERCFG_OPTIONS; i++)
    {
    	DET_g_ConfigCache[i][DET_e_Valid] = 0;
    }
    if(file)
    {
        while(rlen = fread(file, DET_g_ServerConfigContent))
        {
            //dpp_debug("Executing:\n\n%s", DET_g_ServerConfigContent);
            for(new i; i < 1024; i++)
            {
                DET_s_ProcessConfig(DET_g_ServerConfigContent);
            }
        }
    }

    return 1;
}

stock DET_s_ProcessConfig(const line[])
{
    //PROJECT_NAME=D++ testing
    new address[2][512];
    DET_s_ParseConfig(line,address,' ');

    for(new i; i < MAX_SERVERCFG_OPTIONS; i++)
    {
    	if(DET_g_ConfigCache[i][DET_e_Valid] == 0)
    	{
    		strmid(DET_g_ConfigCache[i][DET_e_Name],address[0],0,64,64);
    		strmid(DET_g_ConfigCache[i][DET_e_Value],address[1],0,1024,1024);
    		return 1;
    	}
    }
    return 1;
}

stock GetServerConfigValue(const config[], dest[])
{
	DET_s_ReadServerConfig();
	for(new i; i < MAX_SERVERCFG_OPTIONS; i++)
    {
    	if(DET_g_ConfigCache[i][DET_e_Valid] == 1)
    	{
    		if(!strcmp(DET_g_ConfigCache[i][DET_e_Name], config))
    		{
    			strmid(dest,DET_g_ConfigCache[i][DET_e_Value],0,1024,1024);
    			return 1;
    		}
    	}
    }
	return 1;
}