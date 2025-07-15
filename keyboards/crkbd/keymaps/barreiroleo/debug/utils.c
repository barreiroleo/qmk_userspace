#include QMK_KEYBOARD_H
#include "./utils.h"

#ifdef CONSOLE_ENABLE
# include "print.h"
# include "timer.h"
# include "impl.h"
#endif

void debug_process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    // print_keypress_matrix_position(keycode, record);
    // print_keypress_keycode(keycode, record);
#endif
}

void debug_keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
    debug_enable = true;
    debug_matrix = true;
    // debug_keyboard=true;
    // debug_mouse=true;
#endif
}

void debug_rgb_matrix_indicators_user() {
#ifdef CONSOLE_ENABLE
    sweep_rgb_matrix_indices();
#endif
}

