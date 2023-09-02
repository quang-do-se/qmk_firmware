#include "tap_dance.h"

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
        layer_on(_FUNCTION);
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
    switch (td_function_switch_tap_state.state) {
    case TD_SINGLE_TAP:
        layer_off(_FUNCTION);
        break;
    case TD_SINGLE_HOLD:  // if the key was held down and now is released then switch off the layer
        layer_off(_FUNCTION);
        break;
    default:
        break;
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
