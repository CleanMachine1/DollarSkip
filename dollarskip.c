#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	execvp(argv[1],argv + 1);
}
