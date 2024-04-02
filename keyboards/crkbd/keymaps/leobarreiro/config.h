#pragma once

enum layers { _QWERTY, _LOWER, _RAISE, _ADJUST };

// #define USE_MATRIX_I2C

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// #define QUICK_TAP_TERM 0
// #define TAPPING_TERM 100

#define RGBLIGHT_LAYERS

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    undef RGBLIGHT_EFFECT_TWINKLE
#    undef RGBLIGHT_EFFECT_ALTERNATING
#    undef RGBLIGHT_EFFECT_CHRISTMAS
#    undef RGBLIGHT_EFFECT_KNIGHT
#    undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#    undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    undef RGBLIGHT_EFFECT_RGB_TEST
#    undef RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_LIMIT_VAL 120
#    define RGBLIGHT_HUE_STEP 5
#    define RGBLIGHT_SAT_STEP 5
#    define RGBLIGHT_VAL_STEP 5
#endif

#ifdef OLED_ENABLE
#    define SPLIT_LAYER_STATE_ENABLE
#    define SPLIT_LED_STATE_ENABLE
#    define SPLIT_MODS_ENABLE
#    define SPLIT_OLED_ENABLE
#    ifdef OLED_FONT_H
#        undef OLED_FONT_H
#    endif // OLED_FONT_H
#    define OLED_FONT_H "keyboards/crkbd/keymaps/leobarreiro/glcdfont.c"
#    define OLED_TIMEOUT 30000
#endif
