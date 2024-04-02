#include QMK_KEYBOARD_H

// Light all underglow LEDs [left{0,6}, right{27,33}] when caps locks is acive
const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 6, HSV_RED}, {27, 6, HSV_RED});

// Light the right col in left split when keyboard layer 1 is active
const rgblight_segment_t PROGMEM layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS({6, 4, HSV_CYAN});

// Light the left col in right split when keyboard layer 2 is active
const rgblight_segment_t PROGMEM layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS({33, 4, HSV_CYAN});

// Light left & right cols in both splits when keyboard layer 3 is active
const rgblight_segment_t PROGMEM layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS({6, 4, HSV_CYAN}, {33, 4, HSV_CYAN});

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(capslock_layer,
                                                                            layer1_layer, // Overrides caps lock layer
                                                                            layer2_layer, // Overrides other layers
                                                                            layer3_layer  // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    oled_invert(led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
    return state;
}
