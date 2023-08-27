#pragma once

#include QMK_KEYBOARD_H

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))
#define MODS_GUI  (get_mods() & MOD_BIT(KC_LGUI) || get_mods() & MOD_BIT(KC_RGUI))

//Define a type for as many tap dance states as you need
enum {
    TD_NONE = 0,
    TD_SINGLE_TAP = 1,
    TD_SINGLE_HOLD = 2,
    TD_DOUBLE_TAP = 3
};

enum layers {
    _BASE,
    _FUNCTION,
    _SWITCH,
    _LAST
};

const char* layerNames [] = {
    [_BASE] = "Base",
    [_FUNCTION] = "Function",
    [_SWITCH] = "Switch"
};

enum custom_keys {
    QD_ESC = SAFE_RANGE,    // default: escape,  shift: ~
    QD_BASE,                // layout 0
    QD_FUNCTION             // layout 1
};


//Tap Dance Declarations
enum tap_dances {
    TD_RCTL_ENT = 0,
    TD_LSFT_CAPS,
    TD_FUNCTION_SWITCH,
    TD_BOOT,
    TD_MUTE
};


typedef struct {
    bool is_press_action;
    int state;
} tap;


//Function associated with all tap dances
int get_current_dance_state(tap_dance_state_t *state);

//Functions associated with individual tap dances
void td_function_switch_finished (tap_dance_state_t *state, void *user_data);
void td_function_switch_reset (tap_dance_state_t *state, void *user_data);
void td_safe_reboot (tap_dance_state_t *state, void *user_data);
void td_safe_mute_finished (tap_dance_state_t *state, void *user_data);
void td_safe_mute_reset (tap_dance_state_t *state, void *user_data);

