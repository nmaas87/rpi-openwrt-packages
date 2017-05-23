#
# Copyright (C) 2017 OpenWrt.org
#
# Author: Nico Maas <mail@nico-maas.de>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-wiringpi2
PKG_VERSION:=2.44.0
PKG_RELEASE:=1

#PKG_SOURCE:=wiringpi-$(PKG_VERSION).tar.gz
#PKG_SOURCE_URL:=https://pypi.python.org/packages/04/ab/0474d6775c2416a3523a8db5e017a44cb1f0fe8df0629cf469cb21675691/
#PKG_MD5SUM:=da30ec2869b4f1974d85672c511b4b1a

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)

#PKG_BUILD_DIR:=$(BUILD_DIR)/wiringpi-$(PKG_VERSION)
PKG_BUILD_DEPENDS:=python

include $(INCLUDE_DIR)/package.mk
$(call include_mk, python-package.mk)

define Package/python-wiringpi2
  SUBMENU:=Python
  SECTION:=lang
  CATEGORY:=Languages
  TITLE:=python-wiringpi2
  #URL:=
  DEPENDS:=+python +python-dev +python-setuptools +wiringPi +swig
endef

define Package/python-wiringpi2/description
  This package contains Python bindings for wiringpi2
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Build/Compile
        $(call Build/Compile/PyMod,,install --root="$(PKG_INSTALL_DIR)" --prefix="/usr")
endef

define Package/python-wiringpi2/install
	$(INSTALL_DIR) $(1)$(PYTHON_PKG_DIR)
	$(CP) \
	$(PKG_INSTALL_DIR)$(PYTHON_PKG_DIR)/* \
	$(1)$(PYTHON_PKG_DIR)
endef

$(eval $(call BuildPackage,python-wiringpi2))
