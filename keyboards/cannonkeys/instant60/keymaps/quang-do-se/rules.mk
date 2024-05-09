# MCU name
MCU = STM32F072

# Build Options
#   comment out to disable the options.
#
BOOTLOADER = stm32-dfu

BOOTMAGIC_ENABLE = yes     # Virtual DIP switch configuration

BACKLIGHT_ENABLE = yes      # Enable keyboard backlight functionality
EXTRAKEY_ENABLE = yes       # Audio control and System control
NKRO_ENABLE = yes           # USB Nkey Rollover

MOUSEKEY_ENABLE = no        # Mouse keys
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
CUSTOM_MATRIX = no          # Custom matrix file
BLUETOOTH_ENABLE = no       # Bluetooth support
AUDIO_ENABLE = no           # Audio output
MIDI_ENABLE = no            # MIDI support
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
UNICODE_ENABLE = no         # Unicode

RGBLIGHT_ENABLE = no        # Disable keyboard RGB underglow
RGB_MATRIX_DRIVER = WS2812
WS2812_DRIVER = spi         # spi or pwm - https://github.com/qmk/qmk_firmware/blob/master/docs/ws2812_driver.md

LAYOUTS = 60_ansi

DFU_SUFFIX_ARGS = -p FFFF -v FFFF            # Wildcard to allow APM32 MCU

OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE    # Enter lower-power sleep mode when on the ChibiOS idle thread

TAP_DANCE_ENABLE= yes

CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration

VIA_ENABLE = no
