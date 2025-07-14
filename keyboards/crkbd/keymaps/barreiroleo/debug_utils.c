#include QMK_KEYBOARD_H

#ifdef CONSOLE_ENABLE
#    include "print.h"
#    include "timer.h"
#    define DEBUG_MATRIX_SCAN_RATE // How long it took to scan the matrix
#endif

void debug_process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    // Which matrix position is this keypress?
    // If console is enabled, it will print the matrix position and status of each key pressed
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);

    // Which keycode is this keypress?
    // Log human-readable keycodes like: LT(2,KC_D)
    // uprintf("kc: %s\n", get_keycode_string(keycode));
#endif // CONSOLE_ENABLE
}

void debug_keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
    debug_enable = true;
    debug_matrix = true;
    // debug_keyboard=true;
    // debug_mouse=true;
#endif // CONSOLE_ENABLE
}

// Sweep all RGB matrix indices: blink one key at a time and print the index to console
void sweep_rgb_matrix_indices(void) {
#ifdef CONSOLE_ENABLE
    static uint16_t last_sweep  = 0;
    static uint8_t  sweep_index = 0;
    uint16_t        now         = timer_read();
    // Only update every 1000ms
    if (now - last_sweep < 1000) return;
    last_sweep = now;

    // Turn all LEDs off
    for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        rgb_matrix_set_color(i, 0, 0, 0);
    }
    // Blink current LED
    rgb_matrix_set_color(sweep_index, 255, 255, 255);
    uprintf("[SWEEP] LED index: %u\n", sweep_index);
    sweep_index = (sweep_index + 1) % RGB_MATRIX_LED_COUNT;
#endif
}

// Inspect the layer state:
// 0 - Normal, 1 - LOWER, 2 - RAISE, 3 - _ADJUST
void inspect_layer_state(void) {
#ifdef CONSOLE_ENABLE
    uprintf("[rgb_matrix_indicators_user] layer_state: 0x%08lX, highest: %u\n", (uint32_t)layer_state, get_highest_layer(layer_state));
#endif
}
