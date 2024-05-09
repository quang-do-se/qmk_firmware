#include "process_records.h"
#include "print.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t kc;

    // Store the current modifier state in the variable for later reference
    uint8_t mod_state = get_mods();

    switch (keycode) {

    case QD_BASE:
        if (record->event.pressed) {
            layer_move(_BASE);
            print("Turn on BASE layer");
        }
        return false; // Skip all further processing of this key

    case QD_FUNCTION:
        if (record->event.pressed) {
            layer_move(_FUNCTION);
            print("Turn on FUNCTION layer");
        }
        return false; // Skip all further processing of this key

    case QD_RGB:
        if (record->event.pressed) {
            layer_move(_RGB);
            print("Turn on RGB layer");
        }
        return false; // Skip all further processing of this key


    case QD_SWITCH:
        if (record->event.pressed) {
            layer_move(_SWITCH);
            print("Turn on SWITCH layer");
        }
        return false; // Skip all further processing of this key

    case QD_ENTERTAINMENT:
        if (record->event.pressed) {
            layer_move(_ENTERTAINMENT);
            print("Turn on ENTERTAINMENT layer");
        }
        
        return false; // Skip all further processing of this key

    default:
        return true; //Process all other keycodes normally
    }
}
