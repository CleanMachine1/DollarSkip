#!/bin/bash

function error() {
	echo -e "\e[1;31m$1\e[0m"
	exit 1
}

function pkg-manager() {
	if [[ $run != 1 ]]; then
		if command -v apt >/dev/null ; then
			pkg="apt"
		elif command -v pacman >/dev/null ; then
			pkg="pacman"
		else
			error "No package manager found! please report this."
		fi
		run=1
	fi
}

if ! command -v make >/dev/null; then
	pkg-manager
	if [[ "$pkg" == "apt" ]]; then
		sudo apt install -y make || error "Failed to install make!"
	elif [[ "$pkg" == "pacman" ]]; then
		sudo pacman -S --noconfirm make || error "Failed to install make!"
	fi
fi

if ! command -v gcc >/dev/null ; then
	pkg-manager
	if [[ "$pkg" == "apt" ]]; then
		sudo apt install -y gcc || error "Failed to install make!"
	elif [[ "$pkg" == "pacman" ]]; then
		sudo pacman -S --noconfirm gcc || error "Failed to install make!"
	fi
fi

if ! command -v git >/dev/null; then
	pkg-manager
	if [[ "$pkg" == "apt" ]]; then
		sudo apt install -y git || error "Failed to install git!"
	elif [[ "$pkg" == "pacman" ]]; then
		sudo pacman -S --noconfirm git || error "Failed to install git!"
	fi
fi

if [[ ! -d DollarSkip ]]; then
	git clone https://github.com/CleanMachine1/DollarSkip.git || error "Failed to clone DollarSkip repository!"
	cd DollarSkip || error "Failed to enter DollarSkip folder!"
else
	cd DollarSkip || error "Failed to enter DollarSkip folder!"
	git pull || error "Failed to update repository!"
fi
make || error "Failed to run \"make\"!"
sudo make install || error "Failed to run \"sudo make install\"!"
make clean

echo "If you see 'It Works!', then it works!"
sleep 1 
$ echo "It Works!" || error "DollarSkip has failed!"
exit
