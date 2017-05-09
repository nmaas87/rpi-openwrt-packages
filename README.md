# rpi-openwrt-packages

Taken from https://sourceforge.net/projects/atomproducts/

### Updated wiringpi 
from 2.21 ([10.10.2014](https://git.drogon.net/?p=wiringPi;a=commit;h=0a9fdeb29d31609ef834f050bdb8a7a65cd35e2b)) to 2.44 ([03.03.2017](https://git.drogon.net/?p=wiringPi;a=commit;h=96344ff7125182989f98d3be8d111952a8f74e15))

### Updated i2c-tools
from 3.10 ([07.07.2015](https://github.com/groeck/i2c-tools/commit/9726bed900c1e4a46b2c024a43dec987215570be)) to 3.12 ([03.04.2017](https://github.com/groeck/i2c-tools/commit/fe13737567e7733d8cbe587a08ccb7af5ff8ee8e))

## How To:

#### Update feeds.conf in root Directory, add:
src-git wiringPi https://github.com/nmaas87/rpi-openwrt-packages.git

#### Update feeds:
./scripts/feeds update -a
./scripts/feeds install -a

#### Make Menu:
make menuconfig

#### Choose Packages:

##### wiringPi
- Category Atom-GPL
- Section libs

##### i2c-tools-clone
- Category Atom-GPL
- Section Utilities

##### python-smbus
- Category Languages
- Section lang
- Submenu Python

##### libi2c
- Category Libraries
- Section libs
