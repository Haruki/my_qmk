// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "../../../quantum/keymap_extras/keymap_german.h"


#define LSPO_KEYS KC_LSFT, KC_LSFT, KC_8

enum _layer {
  MAIN,
  LAYER1,
  LAYER2,
  GAMING,
  MISC1,
  RESETLAYER
};

const uint16_t PROGMEM numblock_combo[] = {KC_S, KC_F, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(numblock_combo, MO(MISC1)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAIN] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL, KC_BSPC, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_NO,
        LT(LAYER1,KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    LT(LAYER2,KC_SCLN), KC_QUOT, KC_BSLS, CTL_T(KC_ENT),
        SC_LSPO, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_RSPC, SC_RSPC,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,KC_SPC,KC_SPC,KC_NO,                  KC_RALT, KC_RGUI, KC_APP,  LT(RESETLAYER,KC_RCTL)
    ),
    [RESETLAYER] = LAYOUT(
        QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______, _______, _______, _______,          _______, _______, _______, _______
    ),
    [LAYER2] = LAYOUT(
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______,
        _______, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), _______, _______, _______,
       _______, DE_LABK,DE_RABK,DE_LCBR,DE_RCBR,DE_LBRC,DE_RBRC,KC_HOME,KC_END,KC_DEL, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______, _______, LSFT(KC_BSLS),_______,           _______, _______, _______, _______
    ),
    [LAYER1] = LAYOUT(
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______,
        _______, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, KC_BSPC, DE_EQL,  _______, TG(GAMING),
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______, _______, _______, _______,          _______, _______, _______, _______
    ),
    [MISC1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_7, KC_8, KC_9, KC_0, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, ALGR(KC_NUBS), KC_4, KC_5, KC_6, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_1, KC_2, KC_3, _______, _______, _______,
        _______, _______, _______,                   _______, _______, KC_0, _______,          _______, _______, _______, _______
    ),
    [GAMING] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL, KC_BSPC, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_NO,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS, CTL_T(KC_ENT),
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,KC_SPC,KC_SPC,KC_NO,                  KC_RALT, KC_RGUI, KC_APP,  LT(RESETLAYER,KC_RCTL)
    )
};
