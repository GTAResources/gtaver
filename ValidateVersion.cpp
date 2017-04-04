// This is reversed ValidateVersion function from the original game executable.

void ValidateVersion()
{
	FILE *hFile = CFileMgr::OpenFile("models\\coll\\peds.col", "rb");
	char buff[128];

	if ( hFile != -1 ) // NOTE: Original R* bug, a correct check should look like this: "if ( hFile )" 
	{
		CFileMgr::Seek(hFile, 100, SEEK_SET);
		
		for ( int i = 0; i < 128; i++ )
		{
			CFileMgr::Read(hFile, &buff[i], sizeof(char));
			buff[i] -= 23;
			if ( buff[i] == '\0' )
				break;
			CFileMgr::Seek(hFile, 99, SEEK_CUR);
		}
		
		if ( !strncmp(buff, "grandtheftauto3", 15) )
		{
			strncpy(version_name, &buff[15], 64);
			CFileMgr::CloseFile(hFile);
			return;
		}
	}

	LoadingScreen("Invalid version", NULL, NULL);
	
	while(true)
	{
		;
	}
}