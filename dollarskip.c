#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv)
{
	char command[8096] = {0};
	if(argc>1) {
		char shell[10], *env=getenv("SHELL"); //get the env var 'SHELL'
		if(strcmp(env, "")) { //if env != ""
			strcpy(shell, env); //copy env to shell
			strcat(shell, " -c \'"); //add " -c '"
			strcat(command, shell); //add it to command
			for (int i=1; i<argc; i++){
				strcat(strcat(command,argv[i])," ");
			} //add all the command (cmd args) to command
			command[strlen(command) - 1] = '\0';
			strcat(command, "\'");// add "'"
		} else {
			for (int i=1; i<argc; i++){
				strcat(strcat(command,argv[i])," ");
			}
			command[strlen(command) - 1] = '\0';
		}
		system(command);// run the command
	}
}
