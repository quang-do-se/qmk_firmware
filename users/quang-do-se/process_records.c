#include "process_records.h"

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

    case QD_RGB:
        if (record->event.pressed) {
            layer_move(_RGB);
        }
        return false; // Skip all further processing of this key    

    default:
        return true; //Process all other keycodes normally
    }
}
