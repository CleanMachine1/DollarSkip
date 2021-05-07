# DollarSkip

## What is DollarSkip

DollarSkip is a short piece of C code designed to ignore the dollar symbol at the start of commands.

It aims to solve the annoyance of copying commands and having the annoying error

`$: command not found`

## Installation

You must be running Linux and have Git installed.

To install, run the following commands in a terminal:

```bash
cd ~/ # Or your place of choice for Git repos
git clone https://github.com/CleanMachine1/DollarSkip
cd DollarSkip
make #This makes the binary
sudo make install
make clean
```

After you can test to see if it works.

Open a terminal and run the command:

`$ echo 1`

If you get

`1`

it works!

If you get

`$: command not found`

please report an issue in the repo.

## Uninstallation

```bash
cd ~/DollarSkip
sudo make uninstall
cd .. 
sudo rm -r ./DollarSkip
```

## How this works

DollarSkip makes a binary file called $, in return whenever the first word of a command is $ on its own, Linux see this as a application, since when installing, the $ file is moved to /usr/bin

It can have side effects and if any occur, just run the uninstallation and tell me what went wrong!

## Side Note

This project was a learning experience for me, since my C needs to improve!
