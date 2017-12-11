#include "9key.h"

// Tap Dance Declarations
enum {
  FOUR_1 = 0,
  FIVE_2,
  SIX_3,
  BACK
};

// Macro Declarations
enum {
  ARTB = 0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* LAYER 0
 * ,-----------------------.
 * |   7   |   8   |BSPC/9 | Dbl Tap for 9
 * |-------+-------+-------|
 * |  4/1  |  5/2  |  6/3  | Dbl Tap 4 for 1, 5 for 2, 6 for 3
 * |-------+-------+-------|
 * | LT(2) |    TOG(1)     | 7/0 = Dbl Tap 7 for 0  -  9/FN = Hold 9 for FN
 * `-----------------------'
 */
[0] = KEYMAP( \
  KC_7,        KC_8,       TD(BACK),   \
  TD(FOUR_1),  TD(FIVE_2), TD(SIX_3),  \
  LT(2, KC_0), TG(1), 	   TG(1) 	   \
),

/* LAYER 1
 * ,-----------------------.
 * |  F6   |   I   |   P   |
 * |-------+-------+-------|
 * |STROKE | ARTB  |   V   |
 * |-------+-------+-------|
 * | PATHF |       |       |
 * `-----------------------'
 */
[1] = KEYMAP( \
  KC_F6, 			 KC_I, 	  KC_P,   \
  LCTL(KC_F10), 	 ARTB, 	  KC_V,   \
  LCTL(LSFT(KC_F9)), KC_TRNS, KC_TRNS \
),

/* LAYER 2
 * ,-----------------------.
 * | RGBMOD |  SAI  |GRADT |
 * |--------+-------+------|
 * | RGBTOG |BREATH |PLAIN |
 * |--------+-------+------|
 * |        |    GRADT     |
 * `-----------------------'
 */
[2] = KEYMAP( \
  RGB_MOD, RGB_HUI, RGB_SAI, \
  RGB_TOG, RGB_HUD, RGB_MODE_BREATHE, \
  KC_TRNS, RGB_MODE_PLAIN, RGB_MODE_PLAIN  \
)

};

qk_tap_dance_action_t tap_dance_actions[] = {
  [FOUR_1] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_1),
  [FIVE_2] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_2),
  [SIX_3] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_3),
  [BACK] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_BSPC)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case ARTB:
                SEND_STRING(SS_LCTRL(SS_LALT("p")));
				SEND_STRING(SS_LALT("d"));
                return false; break;
        }
    }
    return true;
};

void matrix_init_user(void) {
}