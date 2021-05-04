Gapcoin Core integration/staging tree


Current Unique Gapcoin Upgrades

Worlds First Crypto-Currency to implement Source Code wide HMAC 512 Bit Keys to prevent Live attacks against Transactions!

Worlds First Bitcoin Clone to adopt a 64 Bit HMAC murmurhash to generate it's Sha-512 512 Bit Keys



Gapcoin Version 9 2021-2030 Roadmap

(Please Contribute Code to the Roadmap)


1)  By 2023 Adopt Lattice SSL 512-571 Bit Private Keys.  

    (Please code and after I verify it works and for bugs it will surely be implemented A.S.A.P.)

    (A lot of it is easy and done already except the refinement and rewriting the C Code to keep the legacy 256 Bit Private Keys)

    (I would like to thank the NSA future coders to hijack older private keys as a Bug Bounty (But don't claim them all at once))


2)  By year 2030 Try to adopt a Hard Fork implementing SHA-512 Hash Algo with SHA-512 HMAC with 512 Bit keys along with 512-571 Bit Lattice SSL Private Keys.


3)  Develop a In-Wallet GPU Computer Graphics built in wallet miner supporting dual CPU/GPU mining and solo GPU or Solo CPU mining in wallet!

4)  By the year 2050 authorize a the Ceasar's Gapcoin Cipher.

    (The Gapcoin Ceasar's Cipher will employ a Multi-Shift Block, Multi-COlor Block Programming language for 2 bit smart contracts)

    (Example the miner will submit multiple shifts into 1 block that is calculations for a Star Mapping)

5)  By Unlimited 

    (Implement a Hard Fork Authorized upon the Julia Lang Programming Code using all the previous features)


6)  Each Authorized Hard Fork will adopt it's own blockchain to increase the adopting of blockchain pruning!


7)  The Gapcoin Master Record Version 9 Blockchain will only upgrade along with Trisquel Operating System needs required to compile the Gapcoin Wallet Miner






=====================================

https://www.gapcoin.org


Copyright (c) 2009-2021 Bitcoin Core Developers
<br>
Copyright (c) 2014-2021 The Satoshi Gapcoin Clan Core Developers

**What is Gapcoin?**
----------------

Gapcoin is an experimental new digital currency that enables instant payments to
anyone, anywhere in the world. Gapcoin uses peer-to-peer technology to operate
with no central authority: managing transactions and issuing money are carried
out collectively by the network. Gapcoin Core is the name of open source
software which enables the use of this currency.

For more information of the Gapcoin Core software, see https://www.gapcoin.org


**Gapcoin Trisquel 9.0 OS Compiling/Build Instructions**


Trisquel 9 Download https://trisquel.info/

https://distrowatch.com/table-mobile.php?distribution=trisquel


If using M.2 Hard Drives it is Recommended to use URUK 3.0 Operating System

https://distrowatch.com/table.php?distribution=uruk

Download

https://sourceforge.net/projects/urukos/files/

**From Linux Command Line Terminal 1 LINE ITEM AT A TIME**

**Remove unwanted programs that waste time updating.**

sudo apt remove libreoffice-common icedove orca

**Update the Operating System**

sudo apt update && sudo apt dist-upgrade


**Start Gapcoin Install**


sudo apt-get install git synaptic gdebi pkg-config

sudo apt-get install build-essential libtool autotools-dev autoconf libssl-dev libgmp-dev libmpfr-dev

sudo apt-get install libboost-all-dev libminiupnpc-dev libqt4-dev libprotobuf-dev protobuf-compiler

sudo apt-get install libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev libqrencode-dev

sudo apt install libcanberra-gtk-module libcanberra-gtk3-module

sudo apt install db5.3-util libdb5.3++-dev libdb5.3-dev


**git clone https://gitlab.com/Gapcoin/gapcoin.git**

Go into gapcoin repository after cloned, CTRL H to view hidden folders, Cut and paste the included 
.gapcoin file into your Linux Home Directory where gapcoin repository is located.

NOTE .GAPCOIN IS SEPERATE FROM THE GAPCOIN REPOSITORY CODE WHERE GAPCOIN IS CLONED

**cd gapcoin**

**git submodule init**

**git submodule update --remote --merge**

**./autogen.sh**

**./configure --with-incompatible-bdb --without-miniupnpc**

**make**







**How to start the QT wallet after compiling!**


Open Command Line Terminal

cd gapcoin/src/qt

./gapcoin-qt

To Run the Daemon 

cd gapcoin/src

./gapcoind

It will auto generate RPCUsername and RPCPassword which will be REQUIRED to copy paste into gapcoin.conf file YOU NEED TO MAKE inside .gapcoin folder after you make .gapcoin or it will make itself after first wallet launch.  Blockchain, and wallet are stored in .gapcoin!

In Linux to view .gapcoin folders with the . you need to go your home folder and click **CTRL H** to show the hiddin files.  That is where .gapcoin is stored.



**Disable CPU Hyper-Threading in the Bios.  Lower voltages to stable.  Remove memory OR remove the Bios battery to reset the bios until your changes are perfectly stable.**

**2 GB R.A.M. Memory Required per 1 CPU core.**





From the Gapcoin QT GUI Wallet

Click **HELP**
Click **DEBUG WINDOW**
Click **CONSOLE**

This is where you input commands for mining and other info

This command uses all cores to mine

**setgenerate true**

This command uses specified amount of CPU cores to mine with

**setgenerate true 14**

This command gives mining info

**getmininginfo**

This command gives peer connections

**getpeerinfo**

Those are the most common useful commands.  Type help for the full libboost



To Mine using the Gapcoind local daemon from Linux Command Line Terminal

After starting ./gapcoind

New Terminal

cd gapcoin/src 

Type
./gapcoin-cli setgenerate true 

Type ./gapcoin-cli and all the commands from the QT debug are valid here.  Use ./gapcoin-cli help for full libboost




**Prime GAP's can be bought/sold here!**

https://freiexchange.com/market/GAP/BTC

https://freebitcoins.com/xchange/market/Bitcoin-Gapcoin/







For ADD NODES 

Cut and paste the included .gapcoin file into your Linux Home Directory.  This is where Gapcoin will create it automatically, but it can be done manually with the added seed nodes already done!

If gapcoin already created, and you need the seed nodes use CTRL H to reveal hidden folders (.gapcoin), then cut and paste the gapcoin.conf file into it.





