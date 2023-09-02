#include "process_records.c"
#include "tap_dance.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
                     QK_GRAVE_ESCAPE , KC_1       , KC_2   , KC_3    , KC_4   , KC_5  , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC, QT_MUTE,
                     KC_TAB          , KC_Q       , KC_W   , KC_E    , KC_R   , KC_T  , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS, KC_VOLU,
                     KC_LCTL         , KC_A       , KC_S   , KC_D    , KC_F   , KC_G  , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT         , QT_RCTL, KC_VOLD,
                     QT_LSFT         , KC_Z       , KC_X   , KC_C    , KC_V   , KC_B  , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT         , KC_UP  , KC_RGUI,
                     MO(_FUNCTION)   , KC_LGUI    , KC_LALT,                    KC_SPC,                            KC_RALT, QT_FN  ,          KC_LEFT, KC_DOWN, KC_RGHT
                     ),
    [_FUNCTION] = LAYOUT(
                    KC_GRAVE        , KC_F1      , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  ,  KC_F10 , KC_F11 , KC_F12 , KC_DEL , KC_HOME,
                    _______         , _______    , KC_UP  , _______, _______, _______, _______, _______, KC_UP  , _______, _______ , _______, _______, _______, KC_PGUP,
                    _______         , KC_LEFT    , KC_DOWN, KC_RGHT, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______ , _______         , _______, KC_PGDN,
                    _______         , _______    , _______, _______, _______, _______, _______, _______, _______, _______, _______ , _______         , _______, KC_END,
                    _______         , _______    , _______,                   _______,                            _______, QT_FN   ,          _______, _______, _______
                    ),
    [_SWITCH] = LAYOUT(
                    QD_BASE         , QD_FUNCTION, _______, _______, _______, _______, _______, _______, _______, _______, _______ , _______, _______, _______, QT_BOOT,
                    _______         , _______    , _______, _______, _______, _______, _______, _______, _______, _______, _______ , _______, _______, _______, _______,
                    _______         , _______    , _______, _______, _______, _______, _______, _______, _______, _______, _______ , _______         , _______, _______,
                    _______         , _______    , _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______ , _______         , _______, _______,
                    _______         , _______    , _______,                   _______,                            _______, QT_FN   ,          _______, _______, _______
                    )
};
