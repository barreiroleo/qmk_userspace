#include QMK_KEYBOARD_H
#include "common.h"

const int T_INDEX     = 6;
const int G_INDEX     = 7;
const int B_INDEX     = 8;
const int SPACE_INDEX = 9;
const int Y_INDEX     = 33;
const int H_INDEX     = 34;
const int N_INDEX     = 35;
const int ENTER_INDEX = 36;

bool led_update_user(led_t led_state) {
    oled_invert(led_state.caps_lock);
    return true;
}

void set_caps_lock_indicator(uint8_t r, uint8_t g, uint8_t b) {
    // Set underglow LEDs (assuming positions 0-5 and 27-32 for CRKBD)
    for (uint8_t i = 0; i < 6; i++) {
        rgb_matrix_set_color(i, r, g, b);      // Left underglow
        rgb_matrix_set_color(27 + i, r, g, b); // Right underglow
    }
}

void set_lower_layer_color_indicator(uint8_t r, uint8_t g, uint8_t b) {
    // Set left split keys (t, g, b, space) to lower layer color, scaled by user brightness
    uint8_t brightness = rgb_matrix_get_val();
    uint8_t sr = (r * brightness) >> 8, sg = (g * brightness) >> 8, sb = (b * brightness) >> 8;
    rgb_matrix_set_color(T_INDEX, sr, sg, sb);
    rgb_matrix_set_color(G_INDEX, sr, sg, sb);
    rgb_matrix_set_color(B_INDEX, sr, sg, sb);
    rgb_matrix_set_color(SPACE_INDEX, sr, sg, sb);
}

void set_raise_layer_color_indicator(uint8_t r, uint8_t g, uint8_t b) {
    // Set right split keys (y, h, n, enter) to raise layer color, scaled by user brightness
    uint8_t brightness = rgb_matrix_get_val();
    uint8_t sr = (r * brightness) >> 8, sg = (g * brightness) >> 8, sb = (b * brightness) >> 8;
    rgb_matrix_set_color(Y_INDEX, sr, sg, sb);
    rgb_matrix_set_color(H_INDEX, sr, sg, sb);
    rgb_matrix_set_color(N_INDEX, sr, sg, sb);
    rgb_matrix_set_color(ENTER_INDEX, sr, sg, sb);
}

void handle_layer_indicators(void) {
    // Handle layer indicators using highest active layer
    switch (get_highest_layer(layer_state)) {
        case _LOWER:
            set_lower_layer_color_indicator(RGB_CYAN);
            break;
        case _RAISE:
            set_raise_layer_color_indicator(RGB_CYAN);
            break;
        case _ADJUST:
            set_lower_layer_color_indicator(RGB_CYAN);
            set_raise_layer_color_indicator(RGB_CYAN);
            break;
        default:
            break;
    }
}

bool rgb_matrix_indicators_user(void) {
    // Handle caps lock indicator - set all underglow LEDs to red
    if (host_keyboard_led_state().caps_lock) {
        set_caps_lock_indicator(RGB_RED);
    }
    handle_layer_indicators();

    return false;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    return state;
}
