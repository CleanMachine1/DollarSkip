#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    //declare the command variable, an array of 8096 characters that will be used to store the command string later
    char command[8096] = {0};
    //put all the command line aguments (the command that will be run) together into the 'command' variable
    for (int i=1; i<argc; i++){
        strcat(strcat(command,argv[i])," ");
    
    }
    /****
    * remove the space from the end of the command
    * for example the command is "ls -l", it takes up 5 characters from the array (command variable) + a space at the end caused by the for loop above.
    * in this case 'strlen(command)' will return 6, remove 1, and you get the location of the character in the array containing the extra space.
    * replace the space with NUL (null terminator), the end of the string.
    ****/
    command[strlen(command) - 1] = '\0';
    //finally run the command using the system function and return the value that the system function returns 
    //possible return values: the return value of the command run: 127 means that the command failed. -1 if system() failed.
    return system(command);
}
