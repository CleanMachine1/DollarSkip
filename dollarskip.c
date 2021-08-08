#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv)
{
	//declare the command variable, an array of 8096 characters that will be used to store the command string later
	char command[8096] = {0};
	//if more than 1 argument is provided (1 means no arguments because the program itself being called is 1)
	if(argc>1) {
		//declare the shell variable and store the value of the SHELL environment variable in env, a char pointer
		char shell[128] = {0}, *env=getenv("SHELL"); //get the env var 'SHELL'
		if(strcmp(env, "")) { //if env != ""
			strcpy(shell, env); //copy env to shell
			strcat(shell, " -c \'"); //add " -c '"
			strcat(command, shell); //add it to command
			for (int i=1; i<argc; i++){
				strcat(strcat(command,argv[i])," ");
			} //add all the command (cmd args) to command
			/****
    			* remove the space from the end of the command
    			* for example the command is "ls -l", it takes up 5 characters from the array (command variable) + a space at the end caused by the for loop above + a character at the end that is reserved for a NUL character.
    			* in this case 'strlen(command)' will return 6, remove 1, and you get the location of the character in the array containing the extra space.
    			* replace the space with NUL (null terminator), the end of the string.
   	 		****/
			command[strlen(command) - 1] = '\0';
			strcat(command, "\'");// add "'"
		} else { //if the SHELL env var doesn't exist or contain anything,
			for (int i=1; i<argc; i++){ //put the command in 'command',
				strcat(strcat(command,argv[i])," ");
			}
			command[strlen(command) - 1] = '\0'; // and remove the NULL space at the end.
		}
		//finally run the command using the system function and return the value that the system function returns
    		//possible return values: the return value of the command run: 127 means that the command failed. -1 if system() failed.
		system(command);// run the command
	}
}
