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

Make example for this keyboard (after setting up your build environment):

    make yas62:default

Flashing example for this keyboard:

    make yas62:default:flash

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
