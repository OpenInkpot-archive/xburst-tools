AM_CFLAGS = -pedantic -Wall -W -std=gnu99 -DDATADIR=\"$(pkgdatadir)\"

xbboot_version.h:
	echo -e '#ifndef XBBOOT_VERSION' \
	'\n#define XBBOOT_VERSION "20100427-1"' \
	'\n#endif' > xbboot_version.h
BUILT_SOURCES = xbboot_version.h

bin_PROGRAMS = xbboot
xbboot_SOURCES = host_main.c

pkgdatadir = $(datadir)/xburst-tools/

if COND_FIRMWARE
pkgdata_DATA = ../target-stage1/stage1.bin
endif

EXTRA_DIST = $(pkgdatadir)

CROSS_COMPILE ?= mipsel-openwrt-linux-
../target-stage1/stage1.bin:
	$(MAKE) CROSS_COMPILE=$(CROSS_COMPILE) -C ../target-stage1
