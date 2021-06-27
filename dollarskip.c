#include <stdlib.h>
#include <string.h>
char command[8096] = {0};
int main(int argc, char **argv)
{
for (int i=1; i<argc; i++){
    strcat(strcat(command,argv[i])," ");
    
}
command[strlen(command) - 1] = '\0';

system(command);
}
