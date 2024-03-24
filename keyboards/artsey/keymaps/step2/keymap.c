// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
  LOCK_CTRL = SAFE_RANGE,
  LOCK_GUI,
  LOCK_ALT,
  LOCK_SHIFT,
  CLEAR_MODS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_4x2(
        KC_A,    KC_R,    KC_T,    KC_S,
        KC_E,    KC_Y,    KC_I,    KC_O
    )
};

// Alphabet characters
const uint16_t PROGMEM combo_b[] = {KC_E, KC_O, COMBO_END};
const uint16_t PROGMEM combo_c[] = {KC_E, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_d[] = {KC_A, KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM combo_f[] = {KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM combo_g[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM combo_h[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM combo_j[] = {KC_T, KC_S, COMBO_END};
const uint16_t PROGMEM combo_k[] = {KC_Y, KC_O, COMBO_END};
const uint16_t PROGMEM combo_l[] = {KC_E, KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM combo_m[] = {KC_Y, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_n[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_p[] = {KC_E, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_q[] = {KC_A, KC_T, KC_S, COMBO_END};
const uint16_t PROGMEM combo_u[] = {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM combo_v[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM combo_w[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM combo_x[] = {KC_R, KC_T, KC_S, COMBO_END};
const uint16_t PROGMEM combo_z[] = {KC_A, KC_R, KC_T, KC_S, COMBO_END};

// Special characters
const uint16_t PROGMEM combo_comm[] = {KC_A, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_dot[]  = {KC_A, KC_I, COMBO_END};
const uint16_t PROGMEM combo_slsh[] = {KC_A, KC_O, COMBO_END};
const uint16_t PROGMEM combo_quot[] = {KC_R, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_exlm[] = {KC_T, KC_I, COMBO_END};
const uint16_t PROGMEM combo_ques[] = {KC_S, KC_O, COMBO_END};

// Others
const uint16_t PROGMEM combo_spc[]  = {KC_E, KC_Y, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_bspc[] = {KC_R, KC_E, COMBO_END};
const uint16_t PROGMEM combo_del[]  = {KC_R, KC_I, COMBO_END};
const uint16_t PROGMEM combo_ent[]  = {KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM combo_esc[]  = {KC_A, KC_R, KC_O, COMBO_END};
const uint16_t PROGMEM combo_tab[]  = {KC_A, KC_R, KC_T, KC_O, COMBO_END};

// Modifiers
const uint16_t PROGMEM combo_lock_ctrl[]  = {KC_R, KC_E, COMBO_END};
const uint16_t PROGMEM combo_lock_gui[]   = {KC_R, KC_E, COMBO_END};
const uint16_t PROGMEM combo_lock_alt[]   = {KC_R, KC_I, COMBO_END};
const uint16_t PROGMEM combo_lock_sft[]   = {KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM combo_os_sft[]     = {KC_A, KC_R, KC_O, COMBO_END};
const uint16_t PROGMEM combo_clear_mods[] = {KC_A, KC_R, KC_T, KC_O, COMBO_END};

combo_t key_combos[] = {
    // Alphabet characters
    COMBO(combo_b, KC_B),
    COMBO(combo_c, KC_C),
    COMBO(combo_d, KC_D),
    COMBO(combo_f, KC_F),
    COMBO(combo_g, KC_G),
    COMBO(combo_h, KC_H),
    COMBO(combo_j, KC_J),
    COMBO(combo_k, KC_K),
    COMBO(combo_l, KC_L),
    COMBO(combo_m, KC_M),
    COMBO(combo_n, KC_N),
    COMBO(combo_p, KC_P),
    COMBO(combo_q, KC_Q),
    COMBO(combo_u, KC_U),
    COMBO(combo_v, KC_V),
    COMBO(combo_w, KC_W),
    COMBO(combo_x, KC_X),
    COMBO(combo_z, KC_Z),

    // Special characters
    COMBO(combo_comm, KC_COMM),
    COMBO(combo_dot,  KC_DOT),
    COMBO(combo_slsh, KC_SLSH),
    COMBO(combo_quot, KC_QUOT),
    COMBO(combo_exlm, KC_EXLM),
    COMBO(combo_ques, KC_QUES),

    // Others
    COMBO(combo_spc,  KC_SPC),
    COMBO(combo_bspc, KC_BSPC),
    COMBO(combo_del,  KC_DEL),
    COMBO(combo_ent,  KC_ENT),
    COMBO(combo_esc,  KC_ESC),
    COMBO(combo_tab,  KC_TAB),

    // Modifiers
    COMBO(combo_lock_ctrl,  LOCK_CTRL),
    COMBO(combo_lock_gui,   LOCK_GUI),
    COMBO(combo_lock_alt,   LOCK_ALT),
    COMBO(combo_lock_sft,   LOCK_SHIFT),
    COMBO(combo_os_sft,     OSM(MOD_LSFT)),
    COMBO(combo_clear_mods, CLEAR_MODS),
};

#define PROCESS_LOCK_MODIFIERS(keycode_, mod_keycode_) \
  case keycode_: \
    register_mods(MOD_BIT(mod_keycode_)); \
    return false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Do something on key release only
  if (record->event.pressed) return true;
  switch (keycode) {
    PROCESS_LOCK_MODIFIERS(LOCK_CTRL,  KC_LCTL)
    PROCESS_LOCK_MODIFIERS(LOCK_GUI,   KC_LGUI)
    PROCESS_LOCK_MODIFIERS(LOCK_ALT,   KC_LALT)
    PROCESS_LOCK_MODIFIERS(LOCK_SHIFT, KC_LSFT)
    case CLEAR_MODS:
      clear_mods();
      clear_oneshot_mods();
      return false;
  }
  return true;
}

