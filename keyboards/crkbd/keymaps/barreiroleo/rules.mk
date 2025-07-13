# Build Options
#   change yes to no to disable
#

DEFAULT_FOLDER = crkbd/rev1

RGBLIGHT_ENABLE = yes
TAP_DANCE_ENABLE = yes
OLED_ENABLE = yes
# OLED_DRIVER = ssd1306

SRC += ./oled.c ./rgb_layers.c
