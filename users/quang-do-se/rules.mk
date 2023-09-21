
# Build Options: change yes to no to disable

BOOTMAGIC_ENABLE = yes     # Virtual DIP switch configuration
EXTRAKEY_ENABLE = yes       # Audio control and System control
NKRO_ENABLE = yes           # USB Nkey Rollover
MOUSEKEY_ENABLE = no        # Mouse keys

CUSTOM_MATRIX = no          # Custom matrix file
BLUETOOTH_ENABLE = no       # Bluetooth support
AUDIO_ENABLE = no           # Audio output
MIDI_ENABLE = no            # MIDI support
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
UNICODE_ENABLE = no         # Unicode

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE    

TAP_DANCE_ENABLE= yes

CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration

RGBLIGHT_ENABLE = no        # Disable keyboard RGB underglow (may conflict with VIA)
VIA_ENABLE = yes
