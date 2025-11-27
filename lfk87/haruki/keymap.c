#include QMK_KEYBOARD_H

#include "action_layer.h"
#include "../../../../../quantum/keymap_extras/keymap_german.h"

/*keys for space cadet: */





//#define _______ KC_TRNS


enum keymap_layout {
    VANILLA = 0,
    GAMING,
    LEFT_LAYER,
    RIGHT_LAYER,
    F_LAYER,
    NUM_LAYER,
    FUNC,         // 0x02
    SETTINGS,     // 0x04
    MISC,
};



//Tap Dance Declarations
enum {
  TD_COMM_EQL = 0,
  TD_CAPS = 1,
  TD_END = 2
};

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_HOLD = 4,
  TRIPLE_HOLD = 6,
  QUAD_HOLD = 8
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

int cur_dance (tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || state->pressed==0) return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    if (state->pressed) return DOUBLE_HOLD;
    else return SINGLE_TAP;
  }
  else if (state->count == 3) {
  	if (state->pressed) return TRIPLE_HOLD;
  	else return SINGLE_TAP;
  }
  else if (state->count == 4) {
  	if (state->pressed) return QUAD_HOLD;
  	else return SINGLE_TAP;
  }
  else return 10; //magic number. At some point this method will expand to work for more presses
}

/* instanz */
static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};


void dance_capslock_finished (tap_dance_state_t *state, void *user_data) {
xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: register_code(KC_ESC); break;
    case SINGLE_HOLD: layer_on(LEFT_LAYER); break;
    case DOUBLE_HOLD: layer_on(LEFT_LAYER); register_code(KC_LSFT); break;
    case TRIPLE_HOLD: layer_on(LEFT_LAYER); register_code(KC_LCTL); break;
    case QUAD_HOLD:   layer_on(LEFT_LAYER); register_code(KC_LSFT); register_code(KC_LCTL);
  }
}

void dance_capslock_reset (tap_dance_state_t *state, void *user_data) {
switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_ESC); break;
    case SINGLE_HOLD: layer_off(LEFT_LAYER); break;
    case DOUBLE_HOLD: layer_off(LEFT_LAYER); unregister_code(KC_LSFT); break;
    case TRIPLE_HOLD: layer_off(LEFT_LAYER); unregister_code(KC_LCTL); break;
    case QUAD_HOLD: layer_off(LEFT_LAYER); unregister_code(KC_LSFT); unregister_code(KC_LCTL);
  }
  xtap_state.state = 0;
}




//Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_COMM_EQL]  = ACTION_TAP_DANCE_DOUBLE(KC_COMM, DE_EQL),
  [TD_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_capslock_finished, dance_capslock_reset),
  [TD_END] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_END)
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM numblock_combo[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM fblock_combo[] = {KC_A, KC_F, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(numblock_combo, MO(NUM_LAYER)),
    COMBO(fblock_combo, MO(F_LAYER)),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap VANILLA: (Base Layer) Default Layer
     * ,-----------------------------------------------------------------------------.
     * |Esc  |f1| f2| f3| f4|  | f5| f6| f7| f8|   | f9|f10|f11|f12|  |Prnt|ScLk|Paus|
     * |-----------------------------------------------------------|  |--------------|
     * | ~ | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |  0| - | = |Backsp |  | Ins|Home|PgUp|
     * |-----------------------------------------------------------|  |--------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  Ret|  | Del| End|PgDn|
     * |--------------------------------------------------------.  |  `--------------'
     * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  # |  |
     * |-----------------------------------------------------------|        ,----.
     * |Shft| \ |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |        | Up |
     * |-----------------------------------------------------------|   ,-------------.
     * |Ctrl|Gui |Alt |      Space            |ALT |GUI | Func|CTRL|   |Lft| Dn |Rig |
     * `-----------------------------------------------------------'   `-------------'
     */
    [VANILLA] = LAYOUT_tkl_iso(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,       KC_PSCR, KC_LSCR, KC_PAUS,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC,      KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                KC_DEL,  KC_END,  KC_PGDN,
        LT(LEFT_LAYER, KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, LT(RIGHT_LAYER,KC_SCLN), TD(KC_END), KC_NUHS,  CTL_T(KC_ENT),
        SC_LSPO, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,           SC_RSPC,               KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, MO(FUNC), MO(MISC),      KC_LEFT, KC_DOWN, KC_RGHT
    ),

	[GAMING] = LAYOUT_tkl_iso(
		KC_ESC,             KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,   KC_PSCR,KC_SCRL,KC_PAUS,
		KC_GRV,  KC_1,      KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,  KC_INS, KC_HOME,KC_PGUP,
		KC_TAB,  KC_Q,      KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,  KC_DEL, KC_END, KC_PGDN,
		_______, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,TD_END,CTL_T(KC_ENT),
		SC_LSPO, KC_NUBS,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,KC_COMM,KC_DOT, KC_SLSH,        SC_RSPC,          KC_UP,
		KC_LCTL, KC_LGUI,   KC_LALT,                       KC_SPC,                          KC_RALT,KC_RGUI,KC_NO,MO(MISC),   KC_LEFT,KC_DOWN,KC_RGHT),


	[LEFT_LAYER] = LAYOUT_tkl_iso(
		_______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,   _______,_______,_______,
		_______,KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,_______,             _______,_______,_______,
		_______,LSFT(KC_1),LSFT(KC_2),LSFT(KC_3),LSFT(KC_4),LSFT(KC_5),LSFT(KC_6),LSFT(KC_7),LSFT(KC_8),LSFT(KC_9),LSFT(KC_0),LSFT(KC_MINS),LSFT(KC_EQL),LSFT(KC_NO),_______,_______,_______,
		_______,KC_PSCR,_______,_______,_______,_______,KC_LEFT,KC_DOWN,KC_UP, KC_RGHT ,KC_BSPC,DE_EQL ,        TG(GAMING),
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,           _______,
		_______,_______,_______,                        KC_DEL,                        _______,_______,_______  ,_______,   _______,_______,_______
    ),



	[RIGHT_LAYER] = LAYOUT_tkl_iso( \
		_______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,   _______,_______,_______, \
		_______,KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,_______,   _______,_______,_______, \
		_______,LSFT(KC_1),LSFT(KC_2),LSFT(KC_3),LSFT(KC_4),LSFT(KC_5),LSFT(KC_6),LSFT(KC_7),LSFT(KC_8),LSFT(KC_9),LSFT(KC_0), LSFT(KC_MINS), LSFT(KC_EQL), LSFT(KC_NO),   _______,_______,_______, \
		_______,DE_LABK,DE_RABK,DE_LCBR,DE_RCBR,DE_LBRC,DE_RBRC,KC_HOME,KC_END,_______,_______,_______,        _______,                            \
		_______,_______,_______,_______,_______,_______,_______,KC_PGDN,_______,_______,_______,_______,        _______,           _______,         \
		_______,_______,_______,                        KC_INS,                        _______,_______,_______  ,_______,   _______,_______,_______),

	[F_LAYER] = LAYOUT_tkl_iso( \
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
		_______,_______,_______,_______,_______,_______,_______,KC_F7, KC_F8, KC_F9, KC_F10,_______,_______,_______,   _______,_______,_______, \
		_______,_______,_______,_______,_______,_______,_______,KC_F4, KC_F5, KC_F6,KC_F11,_______,        _______,                            \
		_______,_______,_______,_______,_______,_______,_______,_______,KC_F1, KC_F2, KC_F3,KC_F12,        _______,           _______,         \
		_______,_______,_______,                        _______,                        _______,_______,_______  ,_______,   _______,_______,_______),

	[NUM_LAYER] = LAYOUT_tkl_iso( \
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
		_______,_______,_______,_______,_______,_______,_______,KC_7, KC_8, KC_9, KC_0,_______,_______,_______,   _______,_______,_______, \
		_______,_______,_______,_______,_______,_______,_______,KC_4, KC_5, KC_6,_______,_______,        _______,                            \
		_______,_______,_______,_______,_______,_______,_______,_______,KC_1, KC_2, KC_3,_______,        _______,           _______,         \
		_______,_______,_______,                        KC_0,                        _______,_______,_______  ,_______,   _______,_______,_______),

	/* Misc Layer: Function layer */
	[MISC] = LAYOUT_tkl_iso( \
		_______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,   KC_WAKE,KC_PWR, KC_SLEP, \
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,   _______,_______,KC_VOLU, \
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,   _______,_______,KC_VOLD, \
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,                            \
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,           KC_MPLY,         \
		_______,_______,_______,                        _______,                        _______,_______,QK_BOOT  ,_______,   KC_MPRV,KC_MSTP,KC_MNXT),





    /* Keymap FUNCTION: Function Layer
     * ,-------------------------------------------------------------.  ,--------------.
     * |     |f1| f2| f3| f4|  | f5| f6| f7| f8|   | f9|f10|f11|f12  |  |Prnt|ScLk|Paus|
     * |-------------------------------------------------------------|  |--------------|
     * |   |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Delete   |  |    |    |    |
     * |-------------------------------------------------------------|  |--------------|
     * |Tab  |   |PgU|   |   |   |   |   | Up|   |   |   |   |   |   |  |    |    |    |
     * |---------------------------------------------------------.   |  `--------------'
     * |Control|Hme|PgD|End|   |   |   |Lft|Dwn|Rgt|   |   |     |   |
     * |-------------------------------------------------------------|       ,----.
     * |Shift|  |   |Del|   |   |   |   |Mute|V- |V+ |  |TG(SETTINGS)|       | Up |
     * |-------------------------------------------------------------'   ,-------------.
     * |Func|Win |Alt |         PgD             |ALT |GUI | Func|CTRL|   |Lft| Dn |Rig |
     * `-------------------------------------------------------------'   `-------------'
     */
    [FUNC] = LAYOUT_tkl_iso(
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           KC_PSCR, KC_SCRL, KC_PAUS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,            _______, _______, _______,
        XXXXXXX, XXXXXXX, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    _______, _______, _______,
        _______, KC_HOME, KC_PGDN, KC_END,  XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,          TG(SETTINGS),               _______,
        _______, _______, _______,                            KC_PGDN,                            _______, _______, _______, _______,           _______, _______, _______
    ),

    /* Keymap SETTINGS: Settings Layer
     * ,-----------------------------------------------------------.     ,-------------.
     * |Esc  |f1| f2| f3| f4|  | f5| f6| f7| f8|   | f9|f10|f11|f12  |  |Prnt|ScLk|Paus|
     * |-------------------------------------------------------------|  |--------------|
     * |FN3 |BL0|BL1|BL2|BL3|   |   |   |   |  |   |BL-|BL+|BL Togl|    |RGB Tog |Val+|
     * |-----------------------------------------------------------|    |-------------|
     * |Debug|   |   |   |   |   |   |   |   |   |   |   |   | RST |    |RGB Mode|Val-|
     * |--------------------------------------------------------.  |    `-------------'
     * |LayrClr|Hz+|MS+|   |   |   |   |   |   |   |   |   |    |  |
     * |-----------------------------------------------------------|  ,----.
     * |ClickTgl|Hz-|MS-|   |   |   |   |   |   |   |   |Layer Clr |  |Hue+|
     * |------------------------------------------------------------------------.
     * |    |    |    |                             |    |    |  |  |Sat-|Hue-|Sat+|
     * `------------------------------------------------------'  `--------------'
     */
    [SETTINGS] = LAYOUT_tkl_iso(
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BL_DOWN,      XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BL_DOWN, BL_UP,   BL_TOGG,      UG_TOGG, UG_VALU, XXXXXXX,
        MU_NEXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               UG_NEXT, UG_VALD, XXXXXXX,
        AU_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MU_TOGG, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,               UG_HUEU,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      UG_SATD, UG_HUED, UG_SATU
    )
};
