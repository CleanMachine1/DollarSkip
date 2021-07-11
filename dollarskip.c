#include <stdio.h> //perror
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //execvp
#include <errno.h> //errno (error handling)
#include <sys/wait.h> //waitpid

char **parse(char *input) {
    //will hold the command
    char **command=malloc(sizeof(char *)*8096);
    //the separator for strtok
    char *separator=" ";
    //will hold the parsed output from strtok
    char *parsed;
    int index=0;

    //strtok returns the first word in 'input' before the space
    parsed=strtok(input, separator);
    //while that word isn't NULL
    while(parsed!=NULL) {
        command[index]=parsed; //copy it to command[index]
        index++; //increment index
        parsed=strtok(NULL, separator); //get the next word from strtok
    }

    command[index]=NULL;
    return command;
}

int main(int argc, char **argv)
{
	char input[8096];
	char **command;
	pid_t child_pid;
	int exit=0, stat_loc;

	if(argc>1) {
		strcpy(input, argv[1]);
		for(int i = 2; i<argc; i++) {
			strcat(input, " ");
			strcat(input, argv[i]);
		}
		command = parse(input);
		//fork the shell process
		child_pid = fork();
		if(child_pid == 0) { //when the child process gets here, its 'child_pid' is 0 because it has no child
			if(execvp(command[0], command) == -1) { //execvp will only return if it fails
				perror("DollarSkip"); //error handling
				exit=1; //set exit to 1 for 'if' statement at the end
			}
		} else if(child_pid < 0) {
			perror("DollarSkip");
		} else {
			waitpid(child_pid, &stat_loc, WUNTRACED); //parent process waits until child has finished
		}
		free(command);
	}
	//if exit is 1 (set if the command failed to run), return from the child process
	if(exit==1) {
		return 1;
	}
	return 0;
}
