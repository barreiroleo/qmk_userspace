#pragma once

#ifdef CONSOLE_ENABLE
#    include "print.h"
#    define DEBUG_MATRIX_SCAN_RATE // How long it took to scan the matrix
#endif

inline void debug_process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    // Which matrix position is this keypress?
    // If console is enabled, it will print the matrix position and status of each key pressed
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);

    // Which keycode is this keypress?
    // Log human-readable keycodes like: LT(2,KC_D)
    // uprintf("kc: %s\n", get_keycode_string(keycode));
#endif // CONSOLE_ENABLE
}

inline void debug_keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
    // Customise these values to desired behaviour
    debug_enable = true;
    debug_matrix = true;
    // debug_keyboard=true;
    // debug_mouse=true;
#endif // CONSOLE_ENABLE
}
