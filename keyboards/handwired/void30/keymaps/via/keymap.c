/* Copyright 2020 Victor Lucachi
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
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _FN1,
    _FN2,
    _FN3,
    _FN4,
    _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,---------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |    T    |     Y  |   U  |   I  |   O  |    P  |
 * |------+------+------+------+---------+--------+------+------+------+-------|
 * |   A  |   S  |   D  |   F  |    G    |     H  |   J  |   K  |   L  |  ESC  |
 * |------+------+------+------+---------+--------+------+------+------+-------|
 * |Ctrl/Z|Alt/X |GUI/C |FN3/V |FN2/BSPC|FN1/SPACE|FN4/B |Alt/N |Ctrl/M|Sft/Ent|
 * `---------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_3x10(
    KC_Q,          KC_W,          KC_E,         KC_R,          KC_T,             KC_Y,            KC_U,          KC_I,         KC_O,         KC_P,
    KC_A,          KC_S,          KC_D,         KC_F,          KC_G,             KC_H,            KC_J,          KC_K,         KC_L,         KC_ESC,
    LCTL_T(KC_Z),  LALT_T(KC_X),  LGUI_T(KC_C), LT(_FN3, KC_V), LT(_FN2, KC_BSPC), LT(_FN1, KC_SPC), LT(_FN4, KC_B), RALT_T(KC_N), RCTL_T(KC_M), RSFT_T(KC_ENT)
),

/* FN1
 * ,---------------------------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  |
 * |------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  DEL |      |      |      |      |      |
 * `---------------------------------------------------------------------'
 */
[_FN1] = LAYOUT_ortho_3x10(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,    KC_7,    KC_8,     KC_9,     KC_0,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,   KC_F7,   KC_F8,    KC_F9,    KC_F10,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS
),

/* FN2
 * ,---------------------------------------------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------+------+------+------+------+------|
 * |  F11 |  F12 |      |      |      |      |      |      |      |  `~  |
 * |------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |
 * `---------------------------------------------------------------------'
 */
[_FN2] = LAYOUT_ortho_3x10(
    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,
    KC_F11,     KC_F12,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_GRV,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
),

/* FN3
 * ,---------------------------------------------------------------------.
 * |      |      |      |      |      |   -  |   =  |  [   |   ]  |   \  | 
 * |------+------+------+------+------+------+------+------+------+------|
 * |  TAB |      |      |      |      |   ,  |   .  |   /  |   ;  |   '  |
 * |------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | LEFT | DOWN |  UP  |RIGHT |
 * `---------------------------------------------------------------------'
 */
[_FN3] = LAYOUT_ortho_3x10(
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,     KC_MINS,    KC_EQL,     KC_LBRC,    KC_RBRC,    KC_BSLS,
    KC_TAB,     KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,     KC_COMM,    KC_DOT,     KC_SLSH,    KC_SCLN,    KC_QUOT,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,     KC_TRNS,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT
),

/* FN4
 * ,---------------------------------------------------------------------.
 * |      |      |      |      |      |   _  |   +  |  {   |   }  |   |  | 
 * |------+------+------+------+------+------+------+------+------+------|
 * |  TAB |      |      |      |      |   <  |   >  |   ?  |   ;  |   "  |
 * |------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | HOME | PGDN | PGUP |  END |
 * `---------------------------------------------------------------------'
 */
[_FN4] = LAYOUT_ortho_3x10(
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_UNDS,    KC_PLUS,    KC_LCBR,    KC_RCBR,    KC_PIPE,
    KC_TAB,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_LABK,    KC_RABK,    KC_QUES,    KC_COLN,    KC_DQUO,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END
),

/* ADJUST
 * ,---------------------------------------------------------------------.
 * | RESET|      |      |      |      |      |      |      |      | PSCR | 
 * |------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |
 * `---------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_3x10(
    RESET,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_PSCR,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _FN2, _FN1, _ADJUST);
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
