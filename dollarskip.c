#include <stdlib.h>
#include <string.h>
char command[8096] = {0};
int main(int argc, char **argv)
{
	if(argc>1) {
	char shell[10], *env=getenv("SHELL");
	strcpy(shell, env);
	strcat(shell, " -c \'");
	strcat(command, shell);
	for (int i=1; i<argc; i++){
		strcat(strcat(command,argv[i])," ");
	}
	command[strlen(command) - 1] = '\0';
	strcat(command, "\'");
	system(command);
	}
}
