# yas62

ACHTUNG:  
Dies ist nicht nur eine Keymap, sondern ein komplett neues PCB, welches so nicht im QMK Repository existiert.  
WIP: Matrix

Original yas62 konfig von 2019 mit altem QMK:
yas62_old.7z

Pfad: /keyboards/yas62/
Konfiguration: all in keyboard.json

Siehe: https://docs.qmk.fm/porting_your_keyboard_to_qmk

Keyboard Layout:  
Immich Photo: 22. September 2019
Matrix (Col/Rows) Definition:
#define LAYOUT_all( \
    k00, k01, k02, k03, k04,   k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, k0E, \
    k10, k11, k12, k13, k14,   k15, k16, k17, k18, k19, k1A, k1B, k1C, k1D,      \
    k20, k21, k22, k23, k24,   k25, k26, k27, k28, k29, k2A, k2B, k2C, k2D,      \
    k30, k31, k32, k33, k34,   k35, k36, k37, k38, k39, k3A, k3B, k3E, k3C,      \
    k40, k41, k42, k46, k48, k49, k4B, k4C, k4D, k4E, k4F                                     \
) \
{ \
    { k00,   k01,   k02,   k03,   k04,   k05,   k06,   k07,   k08,   k09,   k0A,   k0B, k0C, k0D,   k0E,   KC_NO  }, \
    { k10,   k11,   k12,   k13,   k14,   k15,   k16,   k17,   k18,   k19,   k1A,   k1B, k1C, k1D,   KC_NO, KC_NO  }, \
    { k20,   k21,   k22,   k23,   k24,   k25,   k26,   k27,   k28,   k29,   k2A,   k2B, k2C, k2D,   KC_NO, KC_NO  }, \
    { k30,   k31,   k32,   k33,   k34,   k35,   k36,   k37,   k38,   k39,   k3A,   k3B, k3C, KC_NO, k3E,   KC_NO  }, \
    { k40,   k41,   k42,   KC_NO, KC_NO, KC_NO, k46,   KC_NO, k48,   k49,   KC_NO, k4B, k4C, k4D,   k4E,   k4F  }, \
}

Make example for this keyboard (after setting up your build environment):

    make yas62:default

Flashing example for this keyboard:

    make yas62:default:flash

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
