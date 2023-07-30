/* Copyright 2015-2021 Jack Humbert
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
#include <stdlib.h>

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BASS,
  DISC,
  FIR,
  ANTI,
  DUE,
  ATMO,
  VAN,
  CD,
  MB,
  LIKE
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   V  |   v  |   l  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   n  |   L  |   ;  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'KC_QUOT
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_VOLU,    KC_VOLD,    LIKE,    MB,    ATMO,    BASS,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_MNXT,    CD,    DUE, FIR,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_MPRV, VAN,  DISC, ANTI,
    KC_A, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_MPLY
),



/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
)
};

//;P - play a random album that i have liked
//:O - play a random playlist that I have liked

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
switch (keycode) {
	case FIR:
		if (record->event.pressed){
			tap_code16(MEH(KC_I));
			//play_spotify_playlist_123();
		}
		return false; // do not perform default key action
		//break;
	case ANTI:
		if (record->event.pressed){
			tap_code16(MEH(KC_J));
			//play_spotify_playlist_bassed();
		}
		return false; // do not perform default key action
		//break;
	case DISC:
		if (record->event.pressed){
			tap_code16(MEH(KC_C));
			//play_spotify_playlist_bassed();
		}
		return false; // do not perform default key action
		//break;
	case BASS:
		if (record->event.pressed){
			tap_code16(MEH(KC_Z));
			//play_spotify_playlist_bassed();
		}
		return false; // do not perform default key action
		//break;
	case DUE:
		if (record->event.pressed){
			tap_code16(MEH(KC_U));
			//play_spotify_playlist_bassed();
		}
		return false; // do not perform default key action
		//break;
	case ATMO:
		if (record->event.pressed){
			tap_code16(MEH(KC_M));
			//play_spotify_playlist_bassed();
		}
		return false; // do not perform default key action
		//break;
	case VAN:
		if (record->event.pressed){
			tap_code16(MEH(KC_S));
			//play_spotify_playlist_bassed();
		}
		return false; // do not perform default key action
		//break;
	case CD:
		if (record->event.pressed){
			tap_code16(MEH(KC_E));
			//play_spotify_playlist_bassed();
		}
		return false; // do not perform default key action
		//break;
	case MB:
		if (record->event.pressed){
			tap_code16(MEH(KC_X));
			//play_spotify_playlist_bassed();
		}
		return false; // do not perform default key action
		//break;
	case LIKE:

		if (record->event.pressed){
			tap_code16(MEH(KC_B));	
			//like_song_spotify();
		}
		return false; // do not perform default key action
			      // break;


  }
  return true;

}
