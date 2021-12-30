package main

import (
	"os"      // for capturing argv
	"os/exec" // for running the commands
	"strings" // editing the strings such as removing square brackets and adding spaces
)

func main() {
	input := os.Args[1:] // collects given arguments and 1: removes the binary name

	var1 := strings.Join(input, " ") // convert to string rather than type string[] from args
	var2 := strings.Trim(var1, "[]") // Remove square brackets from using 1: earlier

	cmd := exec.Command(`bash`, `-c`, var2) // execute the command
	cmd.Stderr = os.Stderr
	cmd.Stdout = os.Stdout
	cmd.Stdin = os.Stdin
	cmd.Run()

}
