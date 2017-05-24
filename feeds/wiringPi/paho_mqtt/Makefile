#
# Copyright (C) 2017 OpenWrt.org
#
# Author: Nico Maas <mail@nico-maas.de>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=paho_mqtt
PKG_VERSION:=1.2.3
PKG_RELEASE:=1

#PKG_SOURCE:=paho-mqtt-$(PKG_VERSION).tar.gz
#PKG_SOURCE_URL:=https://pypi.python.org/packages/ce/27/28ac0859fb8d63754ec51659be265bf3b89d1568c5f6736d21026e11ea85/
#PKG_MD5SUM:=4bd192ea24e7aa347f6d240101ef82f6
#PKG_BUILD_DIR:=$(BUILD_DIR)/paho-mqtt-$(PKG_VERSION)

# added for build on local src
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)

PKG_BUILD_DEPENDS:=python

include $(INCLUDE_DIR)/package.mk
$(call include_mk, python-package.mk)

define Package/paho_mqtt
 SUBMENU:=Python
 SECTION:=lang
 CATEGORY:=Languages
 TITLE:=paho_mqtt
 #URL:=
 DEPENDS:=+python
endef

define Package/paho_mqtt/description
 This package contains Python bindings for mqtt
endef

# added for build on local src
define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/src/* $(PKG_BUILD_DIR)/
endef

define Build/Compile
  $(call Build/Compile/PyMod,,install --root="$(PKG_INSTALL_DIR)" --prefix="/usr")
endef

define Package/paho_mqtt/install
	$(INSTALL_DIR) $(1)$(PYTHON_PKG_DIR)
	$(CP) \
	$(PKG_INSTALL_DIR)$(PYTHON_PKG_DIR)/* \
	$(1)$(PYTHON_PKG_DIR)
endef

$(eval $(call BuildPackage,paho_mqtt))
