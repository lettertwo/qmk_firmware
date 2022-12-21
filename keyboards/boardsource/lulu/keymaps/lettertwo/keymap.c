// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _RAISE,
    _LOWER,
    _ADJUST
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define NEXT LGUI(KC_RBRC)
#define PREV LGUI(KC_LBRC)

#define SFT_ESC LSFT_T(KC_ESC)
#define SFT_ENT RSFT_T(KC_ENT)
#define CAP_WRD CAPS_WORD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ~   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LS/ESC|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |RS/Ent|
 * |------+------+------+------+------+------|  PLAY |    |  MUTE |------+------+------+------+------+------|
 * |LCtrl |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  '   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | PREV | LGUI |LOWER | /    _  /       \  _   \  |RAISE | RAlt | NEXT |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_UNDS,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  SFT_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, SFT_ENT,
  KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MPLY, KC_MUTE,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_QUOT,
                             PREV,    KC_LGUI, LOWER,   KC_SPC,   KC_SPC,   RAISE, KC_RALT,    NEXT
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ~   |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   ~  |   {  |   }  |   ^  |   |  |                    |      |      |  /   |   \  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |CapWrd|   !  |   (  |   )  |   =  |   &  |-------.    ,-------| Left | Down |  Up  |Right |   :  |      |
 * |------+------+------+------+------+------|  RGB  |    |  RGB  |------+------+------+------+------+------|
 * |LCrtl |   +  |   [  |   ]  |   -  |      |-------|    |-------|      |      |   <  |   >  |   ?  |  "   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | LGUI |LOWER | /    _  /       \  _   \  |RAISE | RAlt |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS,
  XXXXXXX, KC_TILD, KC_LCBR, KC_RCBR, KC_CIRC, KC_PIPE,                   XXXXXXX, XXXXXXX, KC_SLSH, KC_BSLS, XXXXXXX, XXXXXXX,
  CAP_WRD, KC_EXLM, KC_LPRN, KC_RPRN, KC_EQL,  KC_AMPR,                   KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_COLN, XXXXXXX,
  _______, KC_PLUS, KC_LBRC, KC_RBRC, KC_MINS, XXXXXXX, RGB_TOG, RGB_TOG, XXXXXXX, XXXXXXX,   KC_LT,   KC_GT, KC_QUES, KC_DQUO,
                             XXXXXXX, _______, _______, KC_UNDS, KC_UNDS, _______, _______, XXXXXXX
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ~   |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   ~  |   {  |   }  |   ^  |   |  |                    |      |      |  /   |   \  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |CapWrd|   !  |   (  |   )  |   =  |   &  |-------.    ,-------| Left | Down |  Up  |Right |   :  |      |
 * |------+------+------+------+------+------|  RGB  |    |  RGB  |------+------+------+------+------+------|
 * |LCrtl |   +  |   [  |   ]  |   -  |      |-------|    |-------|      |      |   <  |   >  |   ?  |  "   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | LGUI |LOWER | /    _  /       \  _   \  |RAISE | RAlt |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS,
  XXXXXXX, KC_TILD, KC_LCBR, KC_RCBR, KC_CIRC, KC_PIPE,                   XXXXXXX, XXXXXXX, KC_SLSH, KC_BSLS, XXXXXXX, XXXXXXX,
  CAP_WRD, KC_EXLM, KC_LPRN, KC_RPRN, KC_EQL,  KC_AMPR,                   KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_COLN, XXXXXXX,
  _______, KC_PLUS, KC_LBRC, KC_RBRC, KC_MINS, XXXXXXX, RGB_TOG, RGB_TOG, XXXXXXX, XXXXXXX,   KC_LT,   KC_GT, KC_QUES, KC_DQUO,
                             XXXXXXX, _______, _______, KC_UNDS, KC_UNDS, _______, _______, XXXXXXX
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |SLEEP |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | BOOT |      |      |      |      |      |-------.    ,-------|      | VOLD | VOLU |      |      |      |
 * |------+------+------+------+------+------|  RGB  |    |  RGB  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | LGUI |LOWER | / PLAY   /       \MUTE \  |RAISE | RAlt |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP,
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_TOG, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, KC_MPLY, KC_MUTE, _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
