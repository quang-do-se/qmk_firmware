# Flash

- `qmk compile -kb owlab/jelly_evolv/hotswap/625u -km quang-do-se`

- Need to run as `sudo` for flash

- `sudo qmk flash -kb owlab/jelly_evolv/hotswap/625u -km quang-do-se`

- Unplug, hold the `b` key and plug in the USB cable to enter BootLoader mode

- Unplug, hold the `escape` key and plug in the USB cable to update the keymap

# Userspace

- Custom shared code: `qmk_firmware/users/quang-do-se/`

# Notes

Don't use `add_mods(MOD_RCTL);`. It sends both left control and right control for some unknown reasons.

Use:

- `register_code(KC_RCTL)`
- `add_mods(MOD_BIT(KC_RCTL));`
- `register_mods(MOD_BIT(KC_RCTRL));`

We have to handle the release for right control if the right control is not pressed.

# Debug

- Download `hid_listen` at https://www.pjrc.com/teensy/hid_listen.html

- Update `rules.mk` on include:

```
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
```

Add print statements to `keymap.c`, for example: 

``` c++
  #include "print.h"
  
  print("Keycode: ");
  printf("%d", keycode);
  print("\n");
```

Run: `sudo ~/Downloads/hid_listen`


# Layout

- Press `Fn + Alt + [ESC(0) or 1(1) or 2(2)]` to switch layout

- `Fn` will always switch to layer 1 temporarily.

- When `Fn` is released, it reverses back to the previous layout.

- If layout is changed during `Fn` is pressed, releasing `Fn` will do nothing.

- https://github.com/qmk/qmk_firmware/blob/master/docs/keymap.md#layer-precedence-and-transparency

- It's possible to have multiple active layers: https://docs.qmk.fm/#/feature_layers?id=functions


# Set Polling rate to 1000Hz in `config.h` file

- `#define USB_POLLING_INTERVAL_MS 1`
