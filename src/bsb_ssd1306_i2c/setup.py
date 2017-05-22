#!/usr/bin/env python

from distutils.core import setup, Extension

classifiers = ['Development Status :: 5 - Production/Stable',
               'Operating System :: POSIX :: Linux',
               'License :: OSI Approved :: GNU General Public License v2 (GPLv2)',
               'Intended Audience :: Developers',
               'Programming Language :: Python :: 2.7',
               'Topic :: Software Development',
               'Topic :: System :: Hardware',
               'Topic :: System :: Hardware :: Hardware Drivers']

setup(	name	= "ssd1306_i2c",
	version		= "0.3",
	description	= "Python bindings for SSD1306 OLED display via I2C bus",
	# long_description = open('README.md').read() + "\n" + open('CHANGELOG.md').read(),
	author		= "Aliaksei",
	author_email	= "mail@aliaksei.org",
	maintainer	= "Aliaksei",
	maintainer_email= "mail@aliaksei.org",
	license		= "GPLv2",
	classifiers	= classifiers,
	url		= "https://github.com/polkabana/bsb_ssd1306_i2c",
	ext_modules	= [Extension("ssd1306_i2c", ["ssd1306_i2c_module.c"])]
)
