#include "keymap.h"
/* #include "print.h" */

// Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_RCTL_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_RCTL, KC_ENT),
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_MUTE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_safe_mute_finished, td_safe_mute_reset),
    [TD_FUNCTION_SWITCH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_function_switch_finished, td_function_switch_reset),
    [TD_BOOT] = ACTION_TAP_DANCE_FN(td_safe_reboot)
};

// Ref: https://github.com/samhocevar-forks/qmk-firmware/blob/master/docs/feature_tap_dance.md#example-6-using-tap-dance-for-momentary-layer-switch-and-layer-toggle-keys
// Determine the current tap dance state
int get_current_dance_state (tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            return TD_SINGLE_TAP;
        } else {
            return TD_SINGLE_HOLD;
        }
    } else if (state->count == 2) {
        return TD_DOUBLE_TAP;
    }
    else return 8;
}

// Initialize tap structure associated with example tap dance key
static tap td_function_switch_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

static tap td_safe_mute_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

static tap td_safe_reboot_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void td_function_switch_finished (tap_dance_state_t *state, void *user_data) {
    td_function_switch_tap_state.state = get_current_dance_state(state);

    switch (td_function_switch_tap_state.state) {
    case TD_SINGLE_TAP:
        break;
    case TD_SINGLE_HOLD:
        layer_on(_FUNCTION);
        break;
    case TD_DOUBLE_TAP:
        //check to see if the layer is already set
        if (layer_state_is(_SWITCH)) {
            //if already set, then switch it off
            layer_off(_SWITCH);
        } else {
            //if not already set, then switch the layer on
            layer_on(_SWITCH);
        }
        break;
    default:
        break;
    }
}

void td_function_switch_reset (tap_dance_state_t *state, void *user_data) {
    // if the key was held down and now is released then switch off the layer
    if (td_function_switch_tap_state.state==TD_SINGLE_HOLD) {
        layer_off(_FUNCTION);
    }
    td_function_switch_tap_state.state = TD_NONE;
}


void td_safe_reboot(tap_dance_state_t *state, void *user_data) {
    td_safe_reboot_tap_state.state = get_current_dance_state(state);
    
    switch (td_safe_reboot_tap_state.state) {
    case TD_SINGLE_TAP:
        break;
    case TD_SINGLE_HOLD:
        break;
    case TD_DOUBLE_TAP:
        reset_keyboard();
        reset_tap_dance(state);
        break;
    default:
        break;
    }
}

void td_safe_mute_finished(tap_dance_state_t *state, void *user_data) {
    td_safe_mute_tap_state.state = get_current_dance_state(state);

    switch (td_safe_mute_tap_state.state) {
    case TD_SINGLE_TAP:
        break;
    case TD_SINGLE_HOLD:
        break;
    case TD_DOUBLE_TAP:
        register_code(KC_MUTE);
        break;
    default:
        break;
    }
}

void td_safe_mute_reset(tap_dance_state_t *state, void *user_data) {
    switch (get_current_dance_state(state)) {
    case TD_SINGLE_TAP:
        break;
    case TD_SINGLE_HOLD:
        break;
    case TD_DOUBLE_TAP:
        unregister_code(KC_MUTE);
        break;
    default:
        break;
    }
    td_safe_mute_tap_state.state = TD_NONE;
}

/* // Runs just one time when the keyboard initializes. */
/* void matrix_init_user(void) { */
/* }; */

/* // Runs constantly in the background, in a loop. */
/* void matrix_scan_user(void) { */
/* }; */

/* void print_layer(void) { */
/*     for ( int layerInt = _BASE; layerInt != _LAST; layerInt++ ) { */
/*         if (IS_LAYER_ON(layerInt)) { */
/*             printf("\nLayer %s\n", layerNames[layerInt]); */
/*         } */
/*     } */
/* } */


/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*     uint8_t current_layer = get_highest_layer(state); */

/*     printf("\nLayer %s\n", layerNames[current_layer]); *\/ */

/*     return state; */
/* } */


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t kc;

    // Store the current modifier state in the variable for later reference
    uint8_t mod_state = get_mods();

    switch (keycode) {

        // Does not work on Mac, but works on Linux
    case QD_ESC:
        if (record->event.pressed) {
            if (MODS_SHIFT) {
                del_mods(MOD_MASK_SHIFT);
                kc = KC_GRV;
            } else {
                kc = KC_ESCAPE;
            }

            register_code(kc);

            // restore mod state
            set_mods(mod_state);
        } else {
            unregister_code(kc);
        }
        return false; // Skip all further processing of this key

    case QD_BASE:
        if (record->event.pressed) {
            layer_move(_BASE);
        }
        return false; // Skip all further processing of this key

    case QD_FUNCTION:
        if (record->event.pressed) {
            layer_move(_FUNCTION);
        }
        return false; // Skip all further processing of this key

    default:
        return true; //Process all other keycodes normally
    }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        QK_GRAVE_ESCAPE , KC_1       , KC_2   , KC_3    , KC_4   , KC_5  , KC_6   , KC_7   , KC_8   , KC_9   , KC_0                  , KC_MINS, KC_EQL , KC_BSPC        , TD(TD_MUTE),
        KC_TAB          , KC_Q       , KC_W   , KC_E    , KC_R   , KC_T  , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P                  , KC_LBRC, KC_RBRC, KC_BSLS        , KC_VOLU        ,
        KC_LCTL         , KC_A       , KC_S   , KC_D    , KC_F   , KC_G  , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN               , KC_QUOT         , TD(TD_RCTL_ENT), KC_VOLD        ,
        TD(TD_LSFT_CAPS), KC_Z       , KC_X   , KC_C    , KC_V   , KC_B  , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH               , KC_RSFT         , KC_UP          , KC_RGUI        ,
        MO(_FUNCTION)   , KC_LGUI    , KC_LALT,                    KC_SPC,                            KC_RALT, TD(TD_FUNCTION_SWITCH),          KC_LEFT, KC_DOWN        , KC_RGHT
    ),
    [_FUNCTION] = LAYOUT(
        KC_GRAVE        , KC_F1      , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  ,  KC_F10               , KC_F11 , KC_F12 , KC_DEL         , KC_HOME        ,
        _______         , _______    , KC_UP  , _______, _______, _______, _______, _______, KC_UP  , _______, _______               , _______, _______, _______        , KC_PGUP        ,
        _______         , KC_LEFT    , KC_DOWN, KC_RGHT, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______               , _______         , _______        , KC_PGDN        ,
        _______         , _______    , _______, _______, _______, _______, _______, _______, _______, _______, _______               , _______         , _______        , KC_END         ,
        _______         , _______    , _______,                   _______,                            _______, TD(TD_FUNCTION_SWITCH),          _______, _______        , _______
    ),
    [_SWITCH] = LAYOUT(
        QD_BASE         , QD_FUNCTION, _______, _______, _______, _______, _______, _______, _______, _______, _______               , _______, _______, _______        , TD(TD_BOOT)    ,
        _______         , _______    , _______, _______, _______, _______, _______, _______, _______, _______, _______               , _______, _______, _______        , _______        ,
        _______         , _______    , _______, _______, _______, _______, _______, _______, _______, _______, _______               , _______         , _______        , _______        ,
        _______         , _______    , _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______               , _______         , _______        , _______        ,
        _______         , _______    , _______,                   _______,                            _______, TD(TD_FUNCTION_SWITCH),          _______, _______        , _______
    )
};
