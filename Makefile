.SILENT:

MAKEFLAGS += --no-print-directory

##############################
# 			VARS 		 	 #
##############################

QMK_USERSPACE := $(patsubst %/,%,$(dir $(shell realpath "$(lastword $(MAKEFILE_LIST))")))
ifeq ($(QMK_USERSPACE),)
	QMK_USERSPACE := $(shell pwd)
endif

QMK_FIRMWARE_ROOT = $(shell qmk config -ro user.qmk_home | cut -d= -f2 | sed -e 's@^None$$@@g')
ifeq ($(QMK_FIRMWARE_ROOT),)
	$(error Cannot determine qmk_firmware location. `qmk config -ro user.qmk_home` is not set)
endif

##############################
#			TARGETS			 #
##############################

.PHONY: default setup build flash clean

all: setup build

setup:
	qmk setup -H ~/.local/share/qmk/qmk_firmware
	qmk config user.overlay_dir="$(shell realpath .)"

build:
	qmk compile -kb crkbd/rev1 -km barreiroleo --compiledb -j 0

flash:
	@echo "Flashing LEFT side and then RIGHT side..."
	qmk flash -kb crkbd/rev1 -km barreiroleo -j 0
	qmk flash -kb crkbd/rev1 -km barreiroleo -j 0

flash-eehands:
	@echo "Flashing Handness to EEPROM..."
	@echo "Connect the left hand first and press RESET."
	qmk flash -kb crkbd/rev1 -km barreiroleo -bl avrdude-split-left -j 0
	@echo "Connect the right hand first and press RESET."
	qmk flash -kb crkbd/rev1 -km barreiroleo -bl avrdude-split-right -j 0

clean:
	echo QMK userspace:		$(QMK_USERSPACE)
	echo QMK firmware root:	$(QMK_FIRMWARE_ROOT)
	rm -rf $(QMK_FIRMWARE_ROOT)/.build/

%:
	+$(MAKE) -C $(QMK_FIRMWARE_ROOT) $(MAKECMDGOALS) QMK_USERSPACE=$(QMK_USERSPACE)
