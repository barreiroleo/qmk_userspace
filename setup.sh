#! /usr/bin/bash

qmk setup -H ~/.local/share/qmk/qmk_firmware
qmk generate-compilation-database -kb crkbd/rev1 -km leobarreiro
