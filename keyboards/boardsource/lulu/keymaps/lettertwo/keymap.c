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
#define CTL_QUO RCTL_T(KC_QUOT)
#define CTL_DQU RCTL_T(KC_DQUO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ~   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LS/ESC|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |RS/Ent|
 * |------+------+------+------+------+------| PREV  |    | NEXT  |------+------+------+------+------+------|
 * |LCtrl |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RCtl/'|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | / SPACE /       \ SPACE\  |RAISE | RGUI | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_UNDS,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  SFT_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, SFT_ENT,
  KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    PREV,       NEXT,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, CTL_QUO,
                             KC_LALT, KC_LGUI, LOWER,   KC_SPC,    KC_SPC,  RAISE, KC_RGUI, KC_RALT
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ~   |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   ~  |   (  |   )  |   ^  |   |  |                    |      |      |  /   |   \  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |CapWrd|   !  |   {  |   }  |   =  |   &  |-------.    ,-------| Left | Down |  Up  |Right |   :  |CapWrd|
 * |------+------+------+------+------+------|  RGB  |    |  RGB  |------+------+------+------+------+------|
 * |LCrtl |   -  |   [  |   ]  |   +  |      |-------|    |-------|      |      |   <  |   >  |   ?  |RCtl/"|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /    _  /       \  _   \  |RAISE | RGUI | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS,
  XXXXXXX, KC_TILD, KC_LPRN, KC_RPRN, KC_CIRC, KC_PIPE,                   XXXXXXX, XXXXXXX, KC_SLSH, KC_BSLS, XXXXXXX, XXXXXXX,
  CW_TOGG, KC_EXLM, KC_LCBR, KC_RCBR, KC_EQL,  KC_AMPR,                   KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_COLN, CW_TOGG,
  _______, KC_MINS, KC_LBRC, KC_RBRC, KC_PLUS, XXXXXXX, LUMINO,  LUMINO,  XXXXXXX, XXXXXXX,   KC_LT,   KC_GT, KC_QUES, CTL_DQU,
                             _______, _______, _______, KC_UNDS, KC_UNDS, _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ~   |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   ~  |   (  |   )  |   ^  |   |  |                    |      |      |  /   |   \  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |CapWrd|   !  |   {  |   }  |   =  |   &  |-------.    ,-------| Left | Down |  Up  |Right |   :  |CapWrd|
 * |------+------+------+------+------+------|  RGB  |    |  RGB  |------+------+------+------+------+------|
 * |LCrtl |   -  |   [  |   ]  |   +  |      |-------|    |-------|      |      |   <  |   >  |   ?  |RCtl/"|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /    _  /       \  _   \  |RAISE | RGUI | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS,
  XXXXXXX, KC_TILD, KC_LPRN, KC_RPRN, KC_CIRC, KC_PIPE,                   XXXXXXX, XXXXXXX, KC_SLSH, KC_BSLS, XXXXXXX, XXXXXXX,
  CW_TOGG, KC_EXLM, KC_LCBR, KC_RCBR, KC_EQL,  KC_AMPR,                   KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_COLN, CW_TOGG,
  _______, KC_MINS, KC_LBRC, KC_RBRC, KC_PLUS, XXXXXXX, LUMINO,  LUMINO,  XXXXXXX, XXXXXXX,   KC_LT,   KC_GT, KC_QUES, CTL_DQU,
                             _______, _______, _______, KC_UNDS, KC_UNDS, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |REBOOT|      |      |      |      |      |                    |      |      |      |      |      |SLEEP |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | BOOT |      |      |      |      |      |-------.    ,-------|      | VOLD | VOLU |      |      | WAKE |
 * |------+------+------+------+------+------|  RGB  |    |  RGB  |------+------+------+------+------+------|
 * |LCtrl |      |      |      |      |      |-------|    |-------|      | MUTE |      |      |      |RCtrl |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | / PLAY  /       \ MUTE \  |RAISE | RGUI | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  QK_RBT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP,
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, KC_WAKE,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RM_NEXT, RM_HUEU, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, KC_RCTL,
                             _______, _______, _______, KC_MPLY, KC_MUTE, _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
