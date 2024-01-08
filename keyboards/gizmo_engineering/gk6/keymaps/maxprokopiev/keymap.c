/* Copyright 2021 Gizmo Engineering
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

enum layers {
  _BASE,
  _LOWER, // NUMPAD
  _RAISE, // SYMBOLS
  _VIM,   // HJKL
  _RESET, // QWERTY
  _ADJUST // MEDIA/KEYBOARD CONTROLS
};

#define LOWER LT(_LOWER,KC_A)
#define RAISE LT(_RAISE,KC_SCLN)
#define VIM LT(_VIM,KC_F)
#define ADJUST MO(_ADJUST)
#define SPACES_LEFT LGUI(LSFT(KC_H))
#define SPACES_RIGHT RGUI(RSFT(KC_L))
#define CMD_SHIFT_8 RGUI(LSFT(KC_8))
#define CMD_SHIFT_9 RGUI(LSFT(KC_9))
#define CMD_SHIFT_0 RGUI(LSFT(KC_0))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  | Vol- | Vol+ | Play |   4  |   5  |   6  |   7  |Wcentr|WRight|WLeft | RCST |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |Bspc  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | CTRL | A|LWR|   S  |   D  | F|VIM|   G  |   H  |   J  |   K  | L|RSE|   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  <-  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  ->  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | <--- | L_ADJ|  Alt |  <-  | Esc  |Space |Shift | Cmd  |  ->  | RCST | L_RST| ---> |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_ortho_5x12(
  KC_GRV,        KC_VOLD, KC_VOLU, KC_MPLY,       KC_4,   KC_5,   KC_6,    KC_7,    CMD_SHIFT_8,    CMD_SHIFT_9,  CMD_SHIFT_0, RALT(KC_SPC),
  KC_TAB,        KC_Q,    KC_W,    KC_E,          KC_R,   KC_T,   KC_Y,    KC_U,    KC_I,           KC_O,         KC_P,        KC_BSPC,
  KC_LCTL,       LOWER,   KC_S,    KC_D,          VIM,    KC_G,   KC_H,    KC_J,    KC_K,           KC_L,         RAISE,       KC_ENTER,
  LALT(KC_LEFT), KC_Z,    KC_X,    KC_C,          KC_V,   KC_B,   KC_N,    KC_M,    KC_COMM,        KC_DOT,       KC_SLASH,    RALT(KC_RIGHT),
  SPACES_LEFT,   ADJUST,  KC_LALT, LALT(KC_LEFT), KC_ESC, KC_SPC, KC_RGUI, KC_RSFT, RALT(KC_RIGHT), RALT(KC_SPC), TG(_RESET),  SPACES_RIGHT
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * | Vol- | Vol+ | Play |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   -  |   =  |   [  |   ]  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |RGB_TG|RGB_M |RGB_HU|RGB_SI|RGB_VI|RGB_SP|      |      |      |   |  |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Debug |      |      |      |      |      |      |      |      |      |      |R Alt |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_5x12(
  KC_VOLD, KC_VOLU,  KC_MPLY, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______,  _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
  _______, _______,  _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
  _______, RGB_TOG,  RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, KC_PIPE, KC_BSLS,
  DB_TOGG, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RALT
),

/* Reset
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RESET] = LAYOUT_ortho_5x12(
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_A,           KC_TRANSPARENT, KC_TRANSPARENT, KC_F,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SCLN,        KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  +   |  7   |  8   |  9   |  *   |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |  0   |  4   |  5   |  6   |  .   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |  =   |  1   |  2   |  3   |  \   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_5x12(
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PLUS,        KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_0,           KC_4,           KC_5,           KC_6,           KC_KP_DOT,      KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_BSLS,        KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  !   |  @   |  #   |  &   |      |  {   |  }   |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  0   |  |   |  "   |  $   |      |  (   |  )   |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  `   |  ~   |  '   |  %   |      |  [   |  ]   |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_5x12(
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_DQUO,        KC_AMPR,        KC_TRANSPARENT, KC_LCBR,        KC_RCBR,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_0,           KC_PIPE,        KC_UNDS,        KC_MINUS,       KC_DLR,         KC_TRANSPARENT, KC_LPRN,        KC_RPRN,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_GRAVE,       KC_TILD,        KC_CIRC,        KC_QUOTE,       KC_PERC,        KC_TRANSPARENT, KC_LBRC,        KC_RBRC,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
),

/* Vim
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | LEFT | DOWN |  UP  |RIGHT |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_VIM] = LAYOUT_ortho_5x12(
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
),

};

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_user(void) {
    rgb_matrix_set_color(25, 0, 0, 0);
    rgb_matrix_set_color(36, 0, 0, 0);
    rgb_matrix_set_color(42, 0, 0, 0);
    return false;
}

void keyboard_pre_init_user(void) {
    // 5, 9,  14, 19, 24, 30, 35, 40, 46, 51, 55, 60
    g_led_config.matrix_co[4][0] = 5;
    g_led_config.matrix_co[4][1] = 9;
    g_led_config.matrix_co[4][2] = 14;
    g_led_config.matrix_co[4][3] = 19;
    g_led_config.matrix_co[4][4] = 24;
    g_led_config.matrix_co[4][5] = 30;
    g_led_config.matrix_co[4][6] = 35;
    g_led_config.matrix_co[4][7] = 41;
    g_led_config.matrix_co[4][8] = 47;
    g_led_config.matrix_co[4][9] = 52;
    g_led_config.matrix_co[4][10] = 57;
    g_led_config.matrix_co[4][11] = 62;
}
#endif
