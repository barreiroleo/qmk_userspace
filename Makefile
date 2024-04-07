.SILENT:

MAKEFLAGS += --no-print-directory

.PHONY: default crkbd clean
default: crkbd

QMK_USERSPACE := $(patsubst %/,%,$(dir $(shell realpath "$(lastword $(MAKEFILE_LIST))")))
ifeq ($(QMK_USERSPACE),)
    QMK_USERSPACE := $(shell pwd)
endif

QMK_FIRMWARE_ROOT = $(shell qmk config -ro user.qmk_home | cut -d= -f2 | sed -e 's@^None$$@@g')
ifeq ($(QMK_FIRMWARE_ROOT),)
    $(error Cannot determine qmk_firmware location. `qmk config -ro user.qmk_home` is not set)
endif


crkbd:
	$(MAKE) crkbd:leobarreiro

clean:
	echo QMK userspace:		$(QMK_USERSPACE)
	echo QMK firmware root:	$(QMK_FIRMWARE_ROOT)
	rm -rf $(QMK_FIRMWARE_ROOT)/.build/

%:
	+$(MAKE) -C $(QMK_FIRMWARE_ROOT) $(MAKECMDGOALS) QMK_USERSPACE=$(QMK_USERSPACE)
