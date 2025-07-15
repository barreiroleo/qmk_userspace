#include QMK_KEYBOARD_H
#pragma once

// This condition is always false; it's a trick used only for syntax highlighting.
// This file is included only if CONSOLE_ENABLE is defined previously.
#ifndef CONSOLE_ENABLE
#    define CONSOLE_ENABLE
#endif

#ifdef CONSOLE_ENABLE
#    define DEBUG_MATRIX_SCAN_RATE // How long it took to scan the matrix

// Which matrix position is this keypress?
// Call from into debug_process_record_user(uint16_t keycode, keyrecord_t *record)
[[maybe_unused]] static void inspect_keypress_matrix_position(uint16_t keycode, keyrecord_t *record) {
    // Print the matrix position and status of each key press.
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
}

// Which keycode is this keypress?
// Call from into debug_process_record_user(uint16_t keycode, keyrecord_t *record)
[[maybe_unused]] static void inspect_keypress_keycode(uint16_t keycode, keyrecord_t *record) {
    // Log human-readable keycodes, e.g., LT(2, KC_D).
    uprintf("kc: %s\n", get_keycode_string(keycode));
}

// Inspect the layer state: 0-Normal, 1-LOWER, 2-RAISE, 3-ADJUST.
[[maybe_unused]] static void inspect_layer_state(void) {
    uprintf("[rgb_matrix_indicators_user] layer_state: 0x%08lX, highest: %u\n", (uint32_t)layer_state, get_highest_layer(layer_state));
}

// Sweep all RGB matrix indices: blink one key at a time and print its index to the console.
[[maybe_unused]] static void sweep_rgb_matrix_indices(void) {
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
}

#endif
