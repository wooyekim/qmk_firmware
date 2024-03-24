// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_4x2(
        KC_A,    KC_R,    KC_T,    KC_S,
        KC_E,    KC_Y,    KC_I,    KC_O
    )
};
