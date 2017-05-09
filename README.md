# rpi-openwrt-packages

Taken from https://sourceforge.net/projects/atomproducts/ svn to try to update wiringPi to new version

## How To:

### Update feeds.conf in root Directory, add:
src-git wiringPi https://github.com/nmaas87/rpi-openwrt-packages.git

### Update feeds:
./scripts/feeds update -a
./scripts/feeds install -a

### Make Menu:
make menuconfig

### Choose Packages:
####wiringpi_testbench 
- Category Atom
- Section Interfaces

####wiringPi
- Category Atom-GPL
- Section libs

####i2c-tools-clone
- Category Atom-GPL
- Section Utilities

####python-smbus
- Category Languages
- Section lang
- Submenu Python

####libi2c
- Category Libraries
- Section libs