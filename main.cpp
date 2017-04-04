#include <stdio.h>  // for printf, fopen, fseek, fread, fclose
#include <stdlib.h> // for system
#include <string.h> // for strncpy

char version_name[64] = "";
char _game_name[64] = "";

bool ValidateVersion()
{
	FILE *hFile = fopen("peds.col", "rb");
	char buff[128];
	
	if ( hFile )
	{
		fseek(hFile, 100, SEEK_SET);
		
		for ( int i = 0; i < 128; i++ )
		{
			fread(&buff[i], 1, sizeof(char), hFile);
			buff[i] -= 23;
			if ( buff[i] == '\0' )
				break;
			fseek(hFile, 99, SEEK_CUR);
		}
		
		strncpy(_game_name, buff, 15);
		strncpy(version_name, &buff[15], 64);
		fclose(hFile);
		return true;
	}
	return false;
}

int main(int argc, char **argv)
{	
	if ( ValidateVersion() )
		printf("game_name: %s\nversion_name: %s\n", _game_name, version_name);
	else
		printf("peds.col does not exits\n");

	system("pause");
}