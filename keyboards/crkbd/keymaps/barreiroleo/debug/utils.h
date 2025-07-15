#pragma once
#include QMK_KEYBOARD_H

// Debug function designed to be hooked into process_record_user
void debug_process_record_user(uint16_t keycode, keyrecord_t *record);

// Debug function designed to be hooked into keyboard_post_init_user
void debug_keyboard_post_init_user(void);

// Debug function designed to be hooked into rgb_matrix_indicators_user
void debug_rgb_matrix_indicators_user(void);
