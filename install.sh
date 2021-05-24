#!/bin/bash

function error() {
   echo -e "\e[1;31m$1\e[0m"
   exit 1
}

if ! command -v make > /dev/null; then
   while true; do
      echo -e "make not found! Install it? (y/n) \c"
      read -r answer
      if [[ "$answer" =~ [yY] ]]; then
         sudo apt install -y make || error "Failed to install make!"
         break
      else
         echo -e "\e[1;31mInvalid answer \"$REPLY\"!\e[0m"
      fi
   done
fi

if ! command -v git > /dev/null; then
   while true; do
      echo -e "git not found! Install it? (y/n) \c"
      read -r answer
      if [[ "$answer" =~ [yY] ]]; then
         sudo apt install -y git || error "Failed to install git!"
         break
      else
         echo -e "\e[1;31mInvalid answer \"$REPLY\"!\e[0m"
      fi
   done
fi

if [[ ! -d DollarSkip ]]; then
   git clone https://github.com/CleanMachine1/DollarSkip.git || error "Failed to clone DollarSkip repository!"
else
   while true; do
      echo -e "\e[1m\"DollarSkip\" folder already exists, would you like to update it (git pull)?\e[0m"
      read -r answer
      if [[ "$answer" =~ [yY] ]]; then
         cd DollarSkip || error "Failed to enter DollarSKip folder!"
         git pull || error "Failed to run \"git pull\"!"
         break
      else
         break
      fi
   done
fi
cd DollarSkip || error "Failed to enter DollarSkip folder!"
make || error "Failed to run \"make\"!"
sudo make install || error "Failed to run \"sudo make install\"!"
make clean

echo "If you see 'It Works!', then it works!"
sleep 1 
$ echo "It Works!" || error "DollarSkip has failed!"
exit
