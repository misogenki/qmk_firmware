#include "9key.h"

// Tap Dance Declarations
enum {
  ENT_5 = 0,
  ZERO_7,
  ONE_4,
  TWO_5,
  THREE_6
};

// Macro Declarations
enum {
  DBL_0 = 0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* LAYER 0
 * ,-----------------------.
 * |   7   |   8   |   9   |
 * |-------+-------+-------|
 * |  4/1  |  5/2  |  6/3  | Dbl Tap 4 for 1, Dbl Tap 5 for 2, Dbl Tap 6 for 3
 * |-------+-------+-------|
 * | RGB/0 |     ENT/FN    | RGB/0 = Hold 0 for RGB controls  -  ENT/FN = Hold ENT for FN
 * `-----------------------'
 */
[0] = KEYMAP( \
  KC_7,       KC_8,        KC_9,          \
  TD(ONE_4),  TD(TWO_5),   TD(THREE_6),   \
  LT(2, KC_0), LT(1, KC_ENT), LT(1, KC_ENT)    \
),

/* LAYER 1
 * ,-----------------------.
 * |  ESC  |   +   |  BSPC |
 * |-------+-------+-------|
 * |  BSPC |   *   |   /   |
 * |-------+-------+-------|
 * |  00   |       |       |
 * `-----------------------'
 */
[1] = KEYMAP( \
  KC_ESC,   KC_PLUS, KC_BSPC, \
  KC_MINS,  KC_ASTR, KC_SLSH, \
  M(DBL_0), KC_TRNS, KC_TRNS  \
),

/* LAYER 2/RGB
 * ,-----------------------.
 * |  MOD  |  HUE+ | SAT+  |
 * |-------+-------+-------|
 * |  TOG  |  HUE- | BRTH  |
 * |-------+-------+-------|
 * |       |     PLAIN     | //RGB modes don't seem to work right now.
 * `-----------------------'
 */
[2] = KEYMAP( \
  RGB_MOD, RGB_HUI, RGB_SAI, \
  RGB_TOG, RGB_HUD, RGB_MODE_BREATHE, \
  KC_TRNS, RGB_MODE_PLAIN, RGB_MODE_PLAIN  \
)

};

qk_tap_dance_action_t tap_dance_actions[] = {
  [ENT_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_ENT),
  [ZERO_7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_0),
  [ONE_4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_1),
  [TWO_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_2),
  [THREE_6] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_3)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
      switch(id) {
          case DBL_0:
              SEND_STRING("00");
              return false;
      }
  }
  return MACRO_NONE;
};

void matrix_init_user(void) {
}