#include QMK_KEYBOARD_H
#include "../../../quantum/keymap_extras/keymap_german.h"


#define LSPO_KEYS KC_LSFT, KC_LSFT, KC_8

const uint16_t PROGMEM numblock_combo[] = {KC_S, KC_F, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(numblock_combo, MO(5)),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// layer Mac
[0] = LAYOUT_75_ansi(
    KC_ESC,     KC_BRID,   KC_BRIU,     KC_MCTL,   MAC_SEARCH, MAC_VOICE,   MAC_DND,   KC_MPRV,    KC_MPLY,     KC_MNXT,   KC_MUTE,    KC_VOLD,    KC_VOLU,     MAC_PRTA,   KC_INS,     KC_DEL,
    KC_GRV,     KC_1,      KC_2,        KC_3,      KC_4,       KC_5,        KC_6,      KC_7,       KC_8,        KC_9,      KC_0,       KC_MINS,    KC_EQL,                  KC_BSPC,    KC_PGUP,
    KC_TAB,     KC_Q,      KC_W,        KC_E,      KC_R,       KC_T,        KC_Y,      KC_U,       KC_I,        KC_O,      KC_P,       KC_LBRC,    KC_RBRC,                 KC_BSLS,    KC_PGDN,
    KC_CAPS,    KC_A,      KC_S,        KC_D,      KC_F,       KC_G,        KC_H,      KC_J,       KC_K,        KC_L,      KC_SCLN,    KC_QUOT,                             KC_ENT,     KC_HOME,
    SC_LSPO,               KC_Z,        KC_X,      KC_C,       KC_V,        KC_B,      KC_N,       KC_M,        KC_COMM,   KC_DOT,     KC_SLSH,                 KC_RSFT,    KC_UP,      KC_END,
    KC_LCTL,    KC_LALT,   KC_LGUI,                                         KC_SPC,                             KC_RGUI,   MO(1),      KC_RCTL,                 KC_LEFT,    KC_DOWN,    KC_RGHT),

// layer Mac Fn
[1] = LAYOUT_75_ansi(
    _______,    KC_F1,      KC_F2,      KC_F3,     KC_F4,      KC_F5,       KC_F6,     KC_F7,      KC_F8,       KC_F9,     KC_F10,     KC_F11,     KC_F12,      SYS_PRT,    _______,    _______,
    _______,    LNK_BLE1,   LNK_BLE2,   LNK_BLE3,  LNK_RF,     _______,     _______,   _______,    _______,     _______,   _______,    _______,	   _______,                 _______,    _______,
    _______,    _______,    _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    DEV_RESET,  _______,                 BAT_SHOW,   _______,
    _______,    _______,    _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,                             _______,    _______,
    _______,                _______,    _______,   _______,    _______,     BAT_NUM,   _______,    MO(4),       RGB_SPD,   RGB_SPI,    _______,                 _______,    _______,    _______,
    _______,    _______,    _______,                                        _______,                            _______,   MO(1),      _______,                 RM_NEXT,    _______,    RM_HUEU),

// layer win
[2] = LAYOUT_75_ansi(
    KC_ESC,     KC_F1,     KC_F2,       KC_F3,     KC_F4,      KC_F5,       KC_F6,     KC_F7,      KC_F8,       KC_F9,     KC_F10,     KC_F11,     KC_F12,      KC_PSCR,    KC_INS,     KC_DEL,
    KC_GRV,     KC_1,      KC_2,        KC_3,      KC_4,       KC_5,        KC_6,      KC_7,       KC_8,        KC_9,      KC_0,       KC_MINS,    KC_EQL,                  KC_BSPC,    KC_PGUP,
    KC_TAB,     KC_Q,      KC_W,        KC_E,      KC_R,       KC_T,        KC_Y,      KC_U,       KC_I,        KC_O,      KC_P,       KC_LBRC,    KC_RBRC,                 KC_BSLS,    KC_PGDN,
    LT(6,KC_ESC), KC_A,    KC_S,        KC_D,      KC_F,       KC_G,        KC_H,      KC_J,       KC_K,        KC_L,   LT(7,KC_SCLN), KC_QUOT,                       CTL_T(KC_ENT),    KC_HOME,
    SC_LSPO,               KC_Z,        KC_X,      KC_C,       KC_V,        KC_B,      KC_N,       KC_M,        KC_COMM,   KC_DOT,     KC_SLSH,                 SC_RSPC,    KC_UP,      KC_END,
    KC_LCTL,    KC_LGUI,   KC_LALT,                                         KC_SPC,                             KC_RALT,   MO(3),      KC_RCTL,                 KC_LEFT,    KC_DOWN,    KC_RGHT),

// layer win Fn
[3] = LAYOUT_75_ansi(
    _______,    KC_BRID,    KC_BRIU,    KC_CALC,   _______,    _______,     _______,   KC_MPRV,    KC_MPLY,     KC_MNXT,   KC_MUTE,    KC_VOLD,    KC_VOLU,     _______,    _______,    _______,
    _______,    LNK_BLE1,   LNK_BLE2,   LNK_BLE3,  LNK_RF,     _______,     _______,   _______,    _______,     _______,   _______,    _______,	   _______,                 _______,    _______,
    _______,    _______,    _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    DEV_RESET,  _______,                 BAT_SHOW,   _______,
    _______,    _______,    _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,                             _______,    _______,
    _______,                _______,    _______,   _______,    _______,     BAT_NUM,   _______,    MO(4),       RGB_SPD,   RGB_SPI,    _______,                 _______,    _______,    _______,
    _______,    _______,    _______,                                        _______,                            _______,   MO(3),      _______,                 RM_NEXT,    _______,    RM_HUEU),

// layer 4
[4] = LAYOUT_75_ansi(
    _______,    RM_VALD,    RM_VALU,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,     _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,     _______,                _______,    _______,
    _______,    _______,    _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,     SLEEP_MODE,             _______,    _______,
    _______,    _______,    KB_SLP,     DB_TOGG,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,                             _______,    _______,
    _______,                LINK_TO,    _______,   RGB_TEST,   _______,     _______,   _______,    _______,     SIDE_SPD,  SIDE_SPI,   _______,                 _______,    SIDE_VAI,   _______,
    _______,    _______,    _______,                                        _______,                            _______,   MO(4),      _______,                 SIDE_MOD,	SIDE_VAD,   SIDE_HUI),

// layer 5 (numberblock)
[5] = LAYOUT_75_ansi(
    _______,    _______,    _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,     _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,     _______,                _______,    _______,
    _______,    _______,    _______,    _______,   _______,    _______,     _______,   KC_7,       KC_8,        KC_9,      _______,    _______,     _______,                _______,    _______,
    _______,    _______,    _______,    _______,   _______,    _______,     ALGR(KC_NUBS), KC_4,   KC_5,        KC_6,      _______,    _______,                             _______,    _______,
    _______,                _______,    _______,   _______,    _______,     _______,   _______,    KC_1,        KC_2,      KC_3,       _______,                 _______,    _______,    _______,
    _______,    _______,    _______,                                        KC_0,                               _______,   _______,    _______,                 _______,	_______,    _______),

// layer 6 (tab layer)
[6] = LAYOUT_75_ansi(
    _______,    _______,    _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,     _______,                _______,    _______,
    KC_GRV,     KC_F1,      KC_F2,      KC_F3,     KC_F4,      KC_F5,       KC_F6,     KC_F7,      KC_F8,       KC_F9,     KC_F10,     KC_F11,      KC_F12,     _______,    _______,    _______,
     _______, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0),   _______,     _______,                _______,    _______,
    _______,    _______,    _______,    _______,   _______,    _______,     KC_LEFT, KC_DOWN,    KC_UP,        KC_RIGHT  , KC_BSPC,   DE_EQL,                               _______,    _______,
    _______,                _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,                 _______,    _______,    _______,
    _______,    _______,    _______,                                        _______,                            _______,   _______,    _______,                 _______,	_______,    _______),

// layer 7 (oe layer)
[7] = LAYOUT_75_ansi(
    _______,    _______,    _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,     _______,                _______,    _______,
    KC_GRV,     KC_F1,      KC_F2,      KC_F3,     KC_F4,      KC_F5,       KC_F6,     KC_F7,      KC_F8,       KC_F9,     KC_F10,     KC_F11,      KC_F12,     _______,    _______,    _______,
    _______, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0),    _______,     _______,                _______,    _______,
    _______, DE_LABK,   DE_RABK,     DE_LCBR,    DE_RCBR,    DE_LBRC,   DE_RBRC,    KC_HOME,    KC_END,     KC_DEL  ,   _______,      _______,                              _______,    _______,
    _______,                _______,    _______,   _______,    _______,     _______,   _______,    KC_BSLS,     _______,   _______,    _______,                 _______,    _______,    _______,
    _______,    _______,    _______,                                        LSFT(KC_BSLS),                      _______,   _______,    _______,                 _______,	_______,    _______),
};
