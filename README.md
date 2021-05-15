# DollarSkip

## What is DollarSkip

DollarSkip is a short piece of C code designed to ignore the dollar symbol at the start of commands.

It aims to solve the annoyance of copying commands and having the annoying error

`$: command not found`

while removing the need to then manually remove the "$" sign.

## Installation

Download newest binary from https://github.com/CleanMachine1/DollarSkip/releases/latest

To install, run the following commands in a terminal:

```bash
chmod +x "$"
sudo mv ~/Downloads/\$ /usr/bin/\$
```

### Manual compiling
You must be running Linux and have Git installed.

To compile, run these lines terminal:

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
sudo rm /usr/bin/\$
```

## How this works

DollarSkip makes a binary file called "$", in return whenever the first word of a command is $ on its own, Linux see this as a application, since when installing, the $ file is moved to /usr/bin. 

It can have side effects and if any occur, just run the uninstallation and tell me what went wrong!

## Side Note

This project was a learning experience for me, since my C needs to improve!

I am not responsible for any damage to your system!
max character count in a single command is 4000!
anything over may create a segmentation fault!

in no event shall the
authors or copyright holders be liable for any claim, damages or other
liability, whether in an action of contract, tort or otherwise, arising from,
out of or in connection with the software or the use or other dealings in the
software. (MIT license)
