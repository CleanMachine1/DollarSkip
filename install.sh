#!/bin/bash

if ! which make > /dev/null; then
   echo -e "make not found! Install it along with git? (y/n) \c"
   read
   if "$REPLY" = "y"; then
      sudo apt-get install -y git make
   fi
fi

git clone https://github.com/CleanMachine1/DollarSkip
cd DollarSkip
make 
sudo make install
make clean
cd ..
rm -rf DollarSkip/

echo "If you see 'It Works!', then it works!"
sleep 1 
$ echo "It Works!"
