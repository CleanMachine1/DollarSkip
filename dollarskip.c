#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#ifndef COMMAND_MAX_SIZE
#define COMMAND_MAX_SIZE 8096
#endif

/*** wrapped shell builtins ***/
int easter_egg() {
	printf("You found the DollarSkip easter egg!\n");
	return 0;
}

/*** handled and unhandled shell builtins checks ***/
const char *unhandled_shell_builtins[] = {
	"cd",
	"alias",
	"unalias",
	"pushd",
	"popd",
	"dirs",
	"read",
	"set",
	"readonly",
	"unset",
	"typeset",
	"declare",
	"disown",
	"enable",
	"export",
	"exit", // doesn't do anything when run through DollarSkip
	"fc",
	"history",
	"fg",
	"getopts",
	"hash", // we don't want it to report fake data dor the current shell (true for the shell in which it is run)
	"jobs", // same reason as the one for 'hash'
	"times", // same as above
	"local"
};
#define UNHANDLED_SHELL_BUILTINS_SIZE (sizeof(unhandled_shell_builtins) / sizeof(unhandled_shell_builtins[0]))

typedef int (*wrapperFn)();

typedef struct wrapper {
	wrapperFn func;
	const char *name; // name HAS to be a string literal
} Wrapper;

Wrapper handled_shell_builtins[] = {
	{easter_egg, "e_egg"} // DollarSkip easter egg
};
#define HANDLED_SHELL_BUILTINS_SIZE (sizeof(handled_shell_builtins) / sizeof(handled_shell_builtins[0]))

bool handled_shell_builtin(const char *cmd, int *return_value) {
	for(int i = 0; i < (int)HANDLED_SHELL_BUILTINS_SIZE; ++i) {
		if(!strcmp(cmd, handled_shell_builtins[i].name)) {
			if(return_value != NULL) {
				*return_value = handled_shell_builtins[i].func();
			} else {
				handled_shell_builtins[i].func();
			}
			return true;
		}
	}
	return false;
}

bool is_unhandled_shell_builtin(const char *cmd) {
	for(int i = 0; i < (int)UNHANDLED_SHELL_BUILTINS_SIZE; ++i) {
		if(!strcmp(cmd, unhandled_shell_builtins[i])) {
			return true;
		}
	}
	return false;
}

/*** Argument collecting and proccessing ***/
void check_args(char *args) {
	char *argsCopy = strdup(args);
	char *p = strtok(argsCopy, " ");
	int retval = 0;
	while(p != NULL) {
		if(handled_shell_builtin(p, &retval)) {
			free(args);
			free(argsCopy);
			exit(retval);
		} else if(is_unhandled_shell_builtin(p)) {
			fprintf(stderr, "\x1b[31;1m[ERROR: DollarSkip]: '\x1b[97m%s\x1b[0;1;31m': built-in shell commands aren't supported!\x1b[0m\n", p);
			free(args);
			free(argsCopy);
			exit(1);
		}
		p = strtok(NULL, " ");
	}
	free(argsCopy);
}

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
	if(argv_size != NULL)
		*argv_size = argv_len;

	// allocate memory for the argument string
	args = malloc(argv_len);
	if(args == NULL)
		exit(1);

	// copy all of argv (exluding argv[0]) to args and add a space after each argument
	for(int i = 1; i < argc; ++i) {
		strcat(args, argv[i]);
		strcat(args, " ");
	}
	// remove the space at the end
	args[argv_len - 1] = '\0';
	return args;
}

/*** main ***/
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
			// we check if the arguments are something we can execute
			// for example, we don't want to run built-in shell commands
			// (for example: cd) because running them won't change anything for the user
			// as they run in a separate shell.
			// but we want to handle shell built-ins we wrapped (for example: pwd)/
			// check_args() does that for us.
			check_args(args);
			// check that there is enough space in 'command'
			assert(argv_len + strlen(shell_env) + 6 < COMMAND_MAX_SIZE); // 6 = strlen(" -c ''")
			// and format them
			snprintf(command, COMMAND_MAX_SIZE, "%s -c \'%s\'", shell_env, args);
			free(args);
		} else { // if the default shell doesn't exist
			size_t argv_len = 0;
			// collect the arguments 
			char *args = collect_args(argc, argv, &argv_len);
			if(args == NULL) {
				return 1;
			}
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
