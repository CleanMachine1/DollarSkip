# DollarSkip
![https://img.shields.io/badge/Made%20in-C-%23808080](https://img.shields.io/badge/Made%20in-C-%23808080)
[![Build](https://github.com/CleanMachine1/DollarSkip/actions/workflows/build.yml/badge.svg)](https://github.com/CleanMachine1/DollarSkip/actions/workflows/build.yml)
## What is DollarSkip

DollarSkip is a short piece of C code designed to ignore the dollar symbol at the start of commands.

It aims to solve the annoyance of copying commands and having the annoying error

`$: command not found`

## Installation

### 1-Liner install

__You need to have **wget** installed to run this command__

To install, run the following command in a terminal:

```
wget -qO- https://git.io/JsAqw | bash
```

The link is shortened version of https://raw.githubusercontent.com/CleanMachine1/DollarSkip/master/install.sh.

### Arch Based

- https://aur.archlinux.org/packages/dollarskip/

The package can be installed with an AUR helper such as yay:

```
yay -S dollarskip
```

### Other

__To download and compile DollarSkip you need **Git** (to download the files) and **Make** (to make compilation easier)__

<details>
<summary>To install DollarSkip without Git or Make</summary>

If you don't want to use Git and Make, you can download the zip from [here](https://github.com/CleanMachine1/DollarSkip/archive/refs/heads/master.zip) or you can download the most stable version [here](https://github.com/CleanMachine1/DollarSkip/archive/refs/tags/3.1.zip) and compile `dollarskip.c` with `gcc dollarskip.c -o temp` then move `temp` to `/usr/local/bin/$` with `sudo mv temp /usr/local/bin/\$`.

</details>

To install, run the following commands in a terminal:

```shell
cd ~/ # Or your place of choice for Git repositories
git clone https://github.com/CleanMachine1/DollarSkip # Or use SSH
cd DollarSkip 
make # This makes the binary
sudo make install # This copies the binary to /usr/local/bin and names it '$'
make clean # Removes the binary created above since it has already been moved
```

After you can test to see if it works.

Run the following command, see the output and compare.

```shell
$ echo 1
1
```

If you get a different output, please explain your situation and any error messages attached.

## Uninstallation

```shell
cd ~/DollarSkip # Or where you put the Git directory
sudo make uninstall # Remove the binary in /usr/local/bin/
cd .. 
rm -rf ./DollarSkip

# If the DollarSkip directory doesn't exist, simply run the following command:

sudo rm /usr/local/bin/\$ # or /usr/bin/\$ (depending on when you installed).
```

## How this works

DollarSkip makes a binary file called $, in return whenever the first word of a command is $ on its own, Linux see this as a application, since when installing, the $ file is moved to /usr/local/bin/

It can have side effects and if any occur, just run the uninstallation and tell me what went wrong!

## Side Note

This project was a learning experience for me, since my C needs to improve!

__I am not responsible for any damage to your system!__
Max character count in a single command is 8000!
Anything over may create a segmentation fault!

In no event shall:
The authors or copyright holders be liable for any claim, damages or other
liability, whether in an action of contract, tort or otherwise, arising from,
out of or in connection with the software or the use or other dealings in the
software. (MIT license)

If you decided to run a stupid command which creates a buffer overflow, expect a system crash!
