#include "process_records.h"
#include "print.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

    case QD_BASE:
        if (record->event.pressed) {
            layer_move(_BASE);
            print("Move to BASE layer\n");
        }
        return false; // Skip all further processing of this key

    case QD_FUNCTION:
        if (record->event.pressed) {
            layer_move(_FUNCTION);
            print("Move to FUNCTION layer\n");
        }
        return false; // Skip all further processing of this key

    case QD_RGB:
        if (record->event.pressed) {
            layer_move(_RGB);
            print("Move to RGB layer\n");
        }
        return false; // Skip all further processing of this key


    case QD_SWITCH:
        if (record->event.pressed) {
            layer_move(_SWITCH);
            print("Move to SWITCH layer\n");
        }
        return false; // Skip all further processing of this key

    case QD_ENTERTAINMENT:
        if (record->event.pressed) {
            layer_move(_ENTERTAINMENT);
            print("Move to ENTERTAINMENT layer\n");
        }
        
        return false; // Skip all further processing of this key

    default:
        return true; //Process all other keycodes normally
    }
}
