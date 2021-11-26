#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifndef COMMAND_MAX_SIZE
#define COMMAND_MAX_SIZE 8096
#endif

/******
 * Collect all the arguments (argv) excluding the first one (argv[0]) into a single string.
 * returned string is heap allocated so you have to free() it.
 * 
 * @param argc argc from main()
 * @param argv argv from main()
 * @param argv_size pointer to an integer. if not NULL, the length of argv + 1 after each argument will be put in it.
 * 
 * @return A heap allocated string containing all of argv excluding argv[0]
 ******/
char *collect_args(int argc, char **argv, size_t *argv_size) {
	size_t argv_len = 0;
	char *args = NULL;

	// get the size of all of argv + a space after each argument (last one for the null terminator)
	for(int i = 1; i < argc; ++i) {
		argv_len += strlen(argv[i]) + 1; // 1 for the space and null terminator at the end
	}
	// if argv_size isn't NULL, dereference it and put argv_len in it.
	if(argv_size != NULL) *argv_size = argv_len;

	// allocate memory for the argument string
	args = malloc(argv_len);
	if(args == NULL) exit(1);

	// copy all of argv (exluding argv[0]) to args and add a space after each argument
	for(int i = 1; i < argc; ++i) {
		strcat(args, argv[i]);
		strcat(args, " ");
	}
	// remove the space at the end
	args[argv_len - 1] = '\0';
	return args;
}

int main(int argc, char **argv) {
	// if arguments are provided
	if(argc > 1) {
		char command[COMMAND_MAX_SIZE] = {0};
		// get the default system shell
		char *shell_env = getenv("SHELL");
		// if it exists
		if(shell_env != NULL && strcmp(shell_env, "")) {
			size_t argv_len = 0;
			// collect arguments
			char *args = collect_args(argc, argv, &argv_len);
			// check that there is enough space in 'command'
			assert(argv_len + strlen(shell_env) + 6 < COMMAND_MAX_SIZE); // 6 = strlen(" -c ''")
			// and format them
			snprintf(command, COMMAND_MAX_SIZE, "%s -c \'%s\'", shell_env, args);
			free(args);
		} else { // if the default shell doesn't exist
			size_t argv_len = 0;
			// collect the arguments 
			char *args = collect_args(argc, argv, &argv_len);
			// check that there is enough space in 'command'
			assert(argv_len < COMMAND_MAX_SIZE);
			// and copy them to the command variable unformatted
			strncpy(command, args, COMMAND_MAX_SIZE);
			free(args);
		}

		// finally run the command
		return system(command);
	}
	// if no arguments provided, do nothing and return 1
	return 1;
}
