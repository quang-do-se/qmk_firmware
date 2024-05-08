#pragma once
#include "quang-do-se.h"

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))
#define MODS_GUI  (get_mods() & MOD_BIT(KC_LGUI) || get_mods() & MOD_BIT(KC_RGUI))

enum custom_keys {
    QD_ESC = SAFE_RANGE,    // default: escape,  shift: ~
    QD_BASE,                // layout 0
    QD_FUNCTION,            // layout 1
    QD_RGB,                 // layout 2
    QD_ENTERTAINMENT,       // layout 3
    QD_SWITCH               // layout 4
};
