#!/bin/bash

function error() {
	echo -e "\e[1;31m$1\e[0m"
	exit 1
}

#installs the packages provided using the package manager that your system uses
function pkg-install() {
	if command -v apt >/dev/null ; then
		sudo apt install -y $@
	elif command -v pacman >/dev/null ; then
		sudo pacman -S --noconfirm $@
	else
		error "No package manager found! please report this."
	fi
}

# array that will contain all the packages to install
depends=()

#add the needed packages to the array decalred above if they are not installed
if ! command -v make >/dev/null; then
	depends+=("make")
fi

if ! command -v gcc >/dev/null ; then
	depends+=("gcc")
fi

if ! command -v git >/dev/null; then
	depends+=("git")
fi

# if the array isn't empty, install the packages using the package names it contains and the 'pkg-install' function
if [[ "${depends[@]}" != "" ]]; then
	pkg-install ${depends[@]}
fi

if [[ ! -d DollarSkip ]]; then
	git clone https://github.com/CleanMachine1/DollarSkip.git || error "Failed to clone DollarSkip repository!"
	cd DollarSkip || error "Failed to enter DollarSkip folder!"
else
	cd DollarSkip || error "Failed to enter DollarSkip folder!"
	git pull || error "Failed to update repository!"
fi
clear -x 
make || error "Failed to run \"make\"!"
sudo make install || error "Failed to run \"sudo make install\"!"
make clean

echo "If you see 'It Works!', then it works!"
sleep 1 
$ echo "It Works!" || error "DollarSkip has failed!"
exit
