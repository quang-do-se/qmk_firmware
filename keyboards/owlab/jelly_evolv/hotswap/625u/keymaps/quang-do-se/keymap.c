/* 
 * Copyright 2023 owlab
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "process_records.c"
#include "tap_dance.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT(
		KC_ESC       , KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10 , KC_F11,  KC_F12,            KC_RGUI,
		KC_GRAVE     , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0   , KC_MINS, KC_EQL,  KC_BSPC,  QT_MUTE,
		KC_TAB       , KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,  KC_VOLU,
		KC_LCTL      , KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          QT_RCTL,  KC_VOLD,
		QT_LSFT      , KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,
		MO(_FUNCTION), KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, QT_FN  ,          KC_LEFT, KC_DOWN, KC_RGHT
	),
    [_FUNCTION] = LAYOUT(
		KC_GRAVE     , _______, _______, _______ , _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_HOME,
		_______      , KC_F1  , KC_F2  , KC_F3   , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_DEL , KC_END ,
		_______      , _______, KC_UP  , _______ , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP,
		_______      , KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_PGDN, 
		_______      , _______, _______, _______ , _______, _______, _______, _______, _______, _______, _______, _______,          _______, 
		_______      , _______, _______,                    _______,                            _______, QT_FN  ,          _______, _______, _______
    ),
	[_RGB] = LAYOUT(
		_______      , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______      , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______      , RGB_TOG, RGB_MOD, RGB_RMOD,RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,
		_______      , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, 
		_______      , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, 
		_______      , _______, _______,                   _______,                            _______, QT_FN  ,          _______, _______, _______
    ),
    [_SWITCH] = LAYOUT(
		_______      , _______    , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          QT_BOOT,
		QD_BASE      , QD_FUNCTION, QD_RGB , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______      , _______    , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______      , _______    , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, 
		_______      , _______    , _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______, _______,          _______, 
		_______      , _______    , _______,                   _______,                            _______, QT_FN  ,          _______, _______, _______
    ),

};
