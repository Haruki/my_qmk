AUDIO_ENABLE = yes
WATCHDOG_ENABLE = no           # Resets keyboard if matrix_scan isn't run every 250ms
BOOTMAGIC_ENABLE = yes

TAP_DANCE_ENABLE = yes

COMBO_ENABLE = yes

ifndef QUANTUM_DIR
	include ../../../../../Makefile
endif
