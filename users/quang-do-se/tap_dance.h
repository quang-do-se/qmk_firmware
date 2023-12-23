#pragma once
#include "quang-do-se.h"

//Define a type for as many tap dance states as you need
enum {
    TD_NONE = 0,
    TD_SINGLE_TAP = 1,
    TD_SINGLE_HOLD = 2,
    TD_DOUBLE_TAP = 3
};

//Tap Dance Declarations
enum tap_dances {
    TD_RCTL_ENT = 0,
    TD_LSFT_CAPS,
    TD_FUNCTION_SWITCH,
    TD_BOOT,
    TD_MUTE,
    TD_F11_PLAY,
    TD_F12_MUTE
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

#define QT_RCTL TD(TD_RCTL_ENT)
#define QT_LSFT TD(TD_LSFT_CAPS)
#define QT_FN   TD(TD_FUNCTION_SWITCH)
#define QT_BOOT TD(TD_BOOT)
#define QT_MUTE TD(TD_MUTE)
#define QT_F11  TD(TD_F11_PLAY)
#define QT_F12  TD(TD_F12_MUTE)
