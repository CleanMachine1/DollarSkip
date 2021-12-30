package main

import (
	"os"      // for capturing argv
	"os/exec" // for running the commands
	"strings" // for unslicing the array
)

func main() {
	args := os.Args[1:]                               // collects given arguments and 1: removes the binary name
	unsliced_string := strings.Join(args, " ")        // convert to string rather than type []string from args
	shell := os.Getenv("SHELL")                       // Using the env, save the shell
	cmd := exec.Command(shell, `-c`, unsliced_string) // Define the command to be run
	cmd.Stderr = os.Stderr
	cmd.Stdout = os.Stdout
	cmd.Stdin = os.Stdin
	cmd.Run() // Run the command

}
