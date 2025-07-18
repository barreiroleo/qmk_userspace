BOOTLOADER = caterina

DEFAULT_FOLDER = crkbd/rev1
CONSOLE_ENABLE = no

RGBLIGHT_ENABLE   = no
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = ws2812

OLED_ENABLE = yes
OLED_DRIVER = ssd1306

TAP_DANCE_ENABLE = yes

SRC += ./oled.c ./rgb_layers.c ./debug/utils.c
