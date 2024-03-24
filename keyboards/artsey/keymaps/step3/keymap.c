// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
  TG_CTRL = SAFE_RANGE,
  TG_GUI,
  TG_ALT,
  TG_SHIFT,
  CLEAR,
  TO_LAYER_BASE,
  TO_LAYER_MOUSE,
  TO_LAYER_NAV,
};

enum layers {
  LAYER_BASE = 0,
  LAYER_BRACKET,
  LAYER_NUMBER,
  LAYER_SYMBOL,
  LAYER_MOUSE,
  LAYER_NAV,
};

#define BASE_1_1 LT(LAYER_BRACKET, KC_A)
#define BASE_1_2 KC_R
#define BASE_1_3 KC_T
#define BASE_1_4 LT(LAYER_NUMBER, KC_S)
#define BASE_2_1 LT(LAYER_SYMBOL, KC_E)
#define BASE_2_2 KC_Y
#define BASE_2_3 KC_I
#define BASE_2_4 KC_O

#define MOUSE_1_1 KC_BTN1
#define MOUSE_1_2 KC_MS_UP
#define MOUSE_1_3 KC_BTN2
#define MOUSE_1_4 KC_WH_U
#define MOUSE_2_1 KC_MS_L
#define MOUSE_2_2 KC_MS_D
#define MOUSE_2_3 KC_MS_R
#define MOUSE_2_4 KC_WH_D

#define NAV_1_1 KC_HOME
#define NAV_1_2 KC_UP
#define NAV_1_3 KC_END
#define NAV_1_4 KC_PGUP
#define NAV_2_1 KC_LEFT
#define NAV_2_2 KC_DOWN
#define NAV_2_3 KC_RGHT
#define NAV_2_4 KC_PGDN

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT_ortho_4x2(
        BASE_1_1, BASE_1_2, BASE_1_3, BASE_1_4,
        BASE_2_1, BASE_2_2, BASE_2_3, BASE_2_4
    ),
    [LAYER_BRACKET] = LAYOUT_ortho_4x2(
        _______, KC_LPRN, KC_LBRC, KC_LCBR,
        XXXXXXX, KC_RPRN, KC_RBRC, KC_RCBR
    ),
    [LAYER_NUMBER] = LAYOUT_ortho_4x2(
        KC_1,    KC_2,    KC_3,    _______,
        KC_4,    KC_5,    KC_6,    XXXXXXX
    ),
    [LAYER_SYMBOL] = LAYOUT_ortho_4x2(
        KC_HASH, KC_GRV,  KC_SCLN, KC_BSLS,
        _______, KC_AT,   KC_MINS, KC_EQL
    ),
    [LAYER_MOUSE] = LAYOUT_ortho_4x2(
        MOUSE_1_1, MOUSE_1_2, MOUSE_1_3, MOUSE_1_4,
        MOUSE_2_1, MOUSE_2_2, MOUSE_2_3, MOUSE_2_4
    ),
    [LAYER_NAV] = LAYOUT_ortho_4x2(
        NAV_1_1, NAV_1_2, NAV_1_3, NAV_1_4,
        NAV_2_1, NAV_2_2, NAV_2_3, NAV_2_4
    ),
};

// Alphabet characters
const uint16_t PROGMEM combo_b[] = {BASE_2_1, BASE_2_4, COMBO_END};
const uint16_t PROGMEM combo_c[] = {BASE_2_1, BASE_2_2, COMBO_END};
const uint16_t PROGMEM combo_d[] = {BASE_1_1, BASE_1_2, BASE_1_3, COMBO_END};
const uint16_t PROGMEM combo_f[] = {BASE_1_1, BASE_1_2, COMBO_END};
const uint16_t PROGMEM combo_g[] = {BASE_1_2, BASE_1_3, COMBO_END};
const uint16_t PROGMEM combo_h[] = {BASE_2_1, BASE_2_3, COMBO_END};
const uint16_t PROGMEM combo_j[] = {BASE_1_3, BASE_1_4, COMBO_END};
const uint16_t PROGMEM combo_k[] = {BASE_2_2, BASE_2_4, COMBO_END};
const uint16_t PROGMEM combo_l[] = {BASE_2_1, BASE_2_2, BASE_2_3, COMBO_END};
const uint16_t PROGMEM combo_m[] = {BASE_2_2, BASE_2_3, BASE_2_4, COMBO_END};
const uint16_t PROGMEM combo_n[] = {BASE_2_3, BASE_2_4, COMBO_END};
const uint16_t PROGMEM combo_p[] = {BASE_2_1, BASE_2_3, BASE_2_4, COMBO_END};
const uint16_t PROGMEM combo_q[] = {BASE_1_1, BASE_1_3, BASE_1_4, COMBO_END};
const uint16_t PROGMEM combo_u[] = {BASE_2_2, BASE_2_3, COMBO_END};
const uint16_t PROGMEM combo_v[] = {BASE_1_2, BASE_1_4, COMBO_END};
const uint16_t PROGMEM combo_w[] = {BASE_1_1, BASE_1_4, COMBO_END};
const uint16_t PROGMEM combo_x[] = {BASE_1_2, BASE_1_3, BASE_1_4, COMBO_END};
const uint16_t PROGMEM combo_z[] = {BASE_1_1, BASE_1_2, BASE_1_3, BASE_1_4, COMBO_END};

// Special characters
const uint16_t PROGMEM combo_comm[] = {BASE_1_1, BASE_2_2, COMBO_END};
const uint16_t PROGMEM combo_dot[]  = {BASE_1_1, BASE_2_3, COMBO_END};
const uint16_t PROGMEM combo_slsh[] = {BASE_1_1, BASE_2_4, COMBO_END};
const uint16_t PROGMEM combo_quot[] = {BASE_1_2, BASE_2_2, COMBO_END};
const uint16_t PROGMEM combo_exlm[] = {BASE_1_3, BASE_2_3, COMBO_END};
const uint16_t PROGMEM combo_ques[] = {BASE_1_4, BASE_2_4, COMBO_END};

// Others
const uint16_t PROGMEM combo_spc[]  = {BASE_2_1, BASE_2_2, BASE_2_3, BASE_2_4, COMBO_END};
const uint16_t PROGMEM combo_bspc[] = {BASE_1_2, BASE_2_1, COMBO_END};
const uint16_t PROGMEM combo_del[]  = {BASE_1_2, BASE_2_3, COMBO_END};
const uint16_t PROGMEM combo_ent[]  = {BASE_1_1, BASE_2_1, COMBO_END};
const uint16_t PROGMEM combo_esc[]  = {BASE_1_1, BASE_1_2, BASE_2_4, COMBO_END};
const uint16_t PROGMEM combo_tab[]  = {BASE_1_1, BASE_1_2, BASE_1_3, BASE_2_4, COMBO_END};

// Modifiers: we need this from nav/mouse layers, too
const uint16_t PROGMEM combo_base_ctrl[]    = {BASE_1_2, BASE_2_1, COMBO_END};
const uint16_t PROGMEM combo_base_gui[]     = {BASE_1_2, BASE_2_1, COMBO_END};
const uint16_t PROGMEM combo_base_alt[]     = {BASE_1_2, BASE_2_3, COMBO_END};
const uint16_t PROGMEM combo_base_sft[]     = {BASE_1_1, BASE_2_1, COMBO_END};
const uint16_t PROGMEM combo_base_os_sft[]  = {BASE_1_1, BASE_1_2, BASE_2_4, COMBO_END};
const uint16_t PROGMEM combo_base_clear[]   = {BASE_1_1, BASE_1_2, BASE_1_3, BASE_2_4, COMBO_END};
const uint16_t PROGMEM combo_mouse_ctrl[]   = {MOUSE_1_2, MOUSE_2_1, COMBO_END};
const uint16_t PROGMEM combo_mouse_gui[]    = {MOUSE_1_2, MOUSE_2_1, COMBO_END};
const uint16_t PROGMEM combo_mouse_alt[]    = {MOUSE_1_2, MOUSE_2_3, COMBO_END};
const uint16_t PROGMEM combo_mouse_sft[]    = {MOUSE_1_1, MOUSE_2_1, COMBO_END};
const uint16_t PROGMEM combo_mouse_os_sft[] = {MOUSE_1_1, MOUSE_1_2, MOUSE_2_4, COMBO_END};
const uint16_t PROGMEM combo_mouse_clear[]  = {MOUSE_1_1, MOUSE_1_2, MOUSE_1_3, MOUSE_2_4, COMBO_END};
const uint16_t PROGMEM combo_nav_ctrl[]     = {NAV_1_2, NAV_2_1, COMBO_END};
const uint16_t PROGMEM combo_nav_gui[]      = {NAV_1_2, NAV_2_1, COMBO_END};
const uint16_t PROGMEM combo_nav_alt[]      = {NAV_1_2, NAV_2_3, COMBO_END};
const uint16_t PROGMEM combo_nav_sft[]      = {NAV_1_1, NAV_2_1, COMBO_END};
const uint16_t PROGMEM combo_nav_os_sft[]   = {NAV_1_1, NAV_1_2, NAV_2_4, COMBO_END};
const uint16_t PROGMEM combo_nav_clear[]    = {NAV_1_1, NAV_1_2, NAV_1_3, NAV_2_4, COMBO_END};

// Numbers
const uint16_t PROGMEM combo_7[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM combo_8[] = {KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM combo_9[] = {KC_4, KC_5, COMBO_END};
const uint16_t PROGMEM combo_0[] = {KC_5, KC_6, COMBO_END};

// Layer changes
const uint16_t PROGMEM combo_layer_mouse[] = {BASE_1_1, BASE_1_3, BASE_2_2, COMBO_END};
const uint16_t PROGMEM combo_layer_base1[] = {MOUSE_1_1, MOUSE_1_3, MOUSE_2_2, COMBO_END};
const uint16_t PROGMEM combo_layer_nav[]   = {BASE_1_2, BASE_2_1, BASE_2_3, COMBO_END};
const uint16_t PROGMEM combo_layer_base2[] = {NAV_1_2, NAV_2_1, NAV_2_3, COMBO_END};

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
    COMBO(combo_base_ctrl,    TG_CTRL),
    COMBO(combo_base_gui,     TG_GUI),
    COMBO(combo_base_alt,     TG_ALT),
    COMBO(combo_base_sft,     TG_SHIFT),
    COMBO(combo_base_os_sft,  OSM(MOD_LSFT)),
    COMBO(combo_base_clear,   CLEAR),
    COMBO(combo_mouse_ctrl,   TG_CTRL),
    COMBO(combo_mouse_gui,    TG_GUI),
    COMBO(combo_mouse_alt,    TG_ALT),
    COMBO(combo_mouse_sft,    TG_SHIFT),
    COMBO(combo_mouse_os_sft, OSM(MOD_LSFT)),
    COMBO(combo_mouse_clear,  CLEAR),
    COMBO(combo_nav_ctrl,     TG_CTRL),
    COMBO(combo_nav_gui,      TG_GUI),
    COMBO(combo_nav_alt,      TG_ALT),
    COMBO(combo_nav_sft,      TG_SHIFT),
    COMBO(combo_nav_os_sft,   OSM(MOD_LSFT)),
    COMBO(combo_nav_clear,    CLEAR),

    // Numbers
    COMBO(combo_7, KC_7),
    COMBO(combo_8, KC_8),
    COMBO(combo_9, KC_9),
    COMBO(combo_0, KC_0),

    // Layers
    COMBO(combo_layer_base1, TO_LAYER_BASE),
    COMBO(combo_layer_base2, TO_LAYER_BASE),
    COMBO(combo_layer_mouse, TO_LAYER_MOUSE),
    COMBO(combo_layer_nav,   TO_LAYER_NAV),
};

#define PROCESS_TG_MODIFIERS(keycode_, mod_keycode_) \
  case keycode_: \
    if (get_mods() & MOD_BIT(mod_keycode_)) { \
      register_mods(MOD_BIT(mod_keycode_)); \
    } else { \
      unregister_mods(MOD_BIT(mod_keycode_)); \
    } \
    return false;

#define PROCESS_TO_LAYER(keycode_, layer_) \
  case keycode_: \
    layer_move(layer_); \
    return false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Do something on key release only
  if (record->event.pressed) return true;
  switch (keycode) {
    PROCESS_TG_MODIFIERS(TG_CTRL,  KC_LCTL)
    PROCESS_TG_MODIFIERS(TG_GUI,   KC_LGUI)
    PROCESS_TG_MODIFIERS(TG_ALT,   KC_LALT)
    PROCESS_TG_MODIFIERS(TG_SHIFT, KC_LSFT)
    case CLEAR:
      layer_move(LAYER_BASE);
      clear_mods();
      clear_oneshot_mods();
      return false;
    PROCESS_TO_LAYER(TO_LAYER_BASE,  LAYER_BASE)
    PROCESS_TO_LAYER(TO_LAYER_MOUSE, LAYER_MOUSE)
    PROCESS_TO_LAYER(TO_LAYER_NAV,   LAYER_NAV)
  }
  return true;
}

