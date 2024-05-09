#include "tap_dance.h"
#include "print.h"

// Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_RCTL_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_RCTL, KC_ENT),
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_MUTE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_safe_mute_finished, td_safe_mute_reset),
    [TD_FUNCTION_SWITCH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_function_switch_finished, td_function_switch_reset),
    [TD_BOOT] = ACTION_TAP_DANCE_FN(td_safe_reboot),
    [TD_RGUI] = ACTION_TAP_DANCE_DOUBLE(KC_RGUI, KC_MUTE)
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
        print("td function switch: single tap detected\n");
        layer_on(_FUNCTION);
        print("td function switch: turn on FUNCTION layer\n");
        break;
    case TD_SINGLE_HOLD:
        print("td function switch: single hold detected\n");
        layer_on(_FUNCTION);
        print("td function switch: turn on FUNCTION layer\n");
        break;
    case TD_DOUBLE_TAP:
        print("td function switch: double tap detected\n");
        //check to see if the layer is already set
        if (layer_state_is(_SWITCH)) {
            print("td function switch: current layer is SWITCH. Do nothing.\n");
        } else {
            print("td function switch: current layer is not SWITCH\n");
            //if not already set, then switch the layer on
            layer_move(_SWITCH);
            print("td function switch: move to SWITCH layer\n");
        }
        break;
    default:
        break;
    }
}

void td_function_switch_reset (tap_dance_state_t *state, void *user_data) {
    switch (td_function_switch_tap_state.state) {
    case TD_SINGLE_TAP:
        print("td function switch: single tap released\n");
        layer_off(_FUNCTION);
        print("td function switch: turn off FUNCTION layer\n");
        break;
    case TD_SINGLE_HOLD:  // if the key was held down and now is released then switch off the layer
        print("td function switch: single hold released\n");
        layer_off(_FUNCTION);
        print("td function switch: turn off FUNCTION layer\n");
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
    td_safe_reboot_tap_state.state = TD_NONE;
}

void td_safe_mute_finished(tap_dance_state_t *state, void *user_data) {
    td_safe_mute_tap_state.state = get_current_dance_state(state);

    switch (td_safe_mute_tap_state.state) {
    case TD_SINGLE_TAP:
        register_code(KC_MEDIA_PLAY_PAUSE);
        break;
    case TD_SINGLE_HOLD:
        register_code(KC_RGUI);
        break;
    case TD_DOUBLE_TAP:
        register_code(KC_MUTE);
        break;
    default:
        break;
    }
}

void td_safe_mute_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_safe_mute_tap_state.state) {
    case TD_SINGLE_TAP:
        unregister_code(KC_MEDIA_PLAY_PAUSE);
        break;
    case TD_SINGLE_HOLD:
        unregister_code(KC_RGUI);
        break;
    case TD_DOUBLE_TAP:
        unregister_code(KC_MUTE);
        break;
    default:
        break;
    }
    td_safe_mute_tap_state.state = TD_NONE;
}
