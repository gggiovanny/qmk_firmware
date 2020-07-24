#include <stdint.h>
#include "annepro2.h"

enum anne_pro_layers {
  _BASE_LAYER,
  _FN1_LAYER,
  _FN2_LAYER,
  _KEYPAD,
};
enum custom_keys {
    KC_AP_LED_ON = AP2_SAFE_RANGE,
    KC_AP_LED_OFF,
    KC_AP_BRIGHT_UP,
    KC_AP_BRIGHT_DOWN,
    GG_END_SEMICOLON,
    CTL_LEFT,
    CTL_RIGHT,
    GG_EZ,
    ALT_Z,
};

/*tap dance declarations */
enum {
  TD_LSFT_CAPS,
  TD_ALT_TAB,
  TD_LBRC_HOME,
  TD_RBRC_END,
  TD_P_PSCR,
  TD_SLSH_ASTR,
  TD_SPC_UNDS,
  TD_SCLN_BSPC,
  TD_J_LEFT,
  TD_L_RIGHT,
  TD_I_UP,
  TD_K_DOWN,
};

/*tap dance definitions*/

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
  [TD_ALT_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, LALT(KC_TAB)),
  [TD_LBRC_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_HOME),
  [TD_RBRC_END] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_END),
  [TD_P_PSCR] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_PSCR),
  [TD_SLSH_ASTR] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_ASTR),
  [TD_SPC_UNDS] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_UNDS),
  [TD_SCLN_BSPC] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_BSPC),
  [TD_J_LEFT] = ACTION_TAP_DANCE_DOUBLE(KC_J, KC_LEFT),
  [TD_L_RIGHT] = ACTION_TAP_DANCE_DOUBLE(KC_L, KC_RIGHT),
  [TD_I_UP] = ACTION_TAP_DANCE_DOUBLE(KC_I, KC_UP),
  [TD_K_DOWN] = ACTION_TAP_DANCE_DOUBLE(KC_K, KC_DOWN),
};

/*
* Layer _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* | esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab TD |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | FN1     |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | ShiftTDCaps|  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
* |-----------------------------------------------------------------------------------------+
* |         |     |     |     |     |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |     |     |     |     |     |     |       UP       |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |                                 |  DEL  |  LEFT | DOWN  | RIGHT |
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE_LAYER] = KEYMAP( /* Base */
    KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    TD(TD_ALT_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, TD(TD_I_UP), KC_O, TD(TD_P_PSCR), TD(TD_LBRC_HOME), TD(TD_RBRC_END), KC_BSLS,
    TT(_FN1_LAYER), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, TD(TD_J_LEFT), TD(TD_K_DOWN), TD(TD_L_RIGHT), TD(TD_SCLN_BSPC), KC_QUOT, KC_ENT,
    TD(TD_LSFT_CAPS), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, TD(TD_SLSH_ASTR), RSFT_T(KC_UP),
    KC_LCTL, KC_LGUI, KC_LALT, TD(TD_SPC_UNDS), RALT_T(KC_DEL), LT(_FN1_LAYER,KC_LEFT), LT(_FN2_LAYER,KC_DOWN), RCTL_T(KC_RGHT)
),
  /*
  * Layer _FN1_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * | KEYPADL|  q  | UP  |  e  |  r  |  t  |  y  |  u  |  UP |  o  | PS | HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | FN1     |LEFT |DOWN |RIGHT|ALT_Z|  g  |  h  | LEFT|DOWN |RIGHT| PGUP|PGDN |END+SEMICOLON|
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |V-UP |V-DWN|MUTE |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN1_LAYER] = KEYMAP( /* Base */
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
    TT(_KEYPAD), KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_PSCR, KC_HOME, KC_END, KC_TRNS,
    KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, ALT_Z, KC_TRNS, KC_TRNS, CTL_LEFT, KC_DOWN, CTL_RIGHT, KC_PGUP, KC_PGDN, GG_END_SEMICOLON,
    KC_TRNS, KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_DEL, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_FN2_LAYER), KC_TRNS
),
  /*
  * Layer _FN2_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  ~  | BT1 | BT2 | BT3 | BT4 |NLOCK|  F6 |  F7 |LEDOF|LEDON| F10 |LEDDW|LEDUP|    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | FN2    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  UP |  o  | PS | HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | CAPS    |LEFT |DOWN |RIGHT|  f  |GG EZ|  h  |LEFT |DOWN |RIGHT| PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  z  |  x  |  c  |  v  |PREVT|V-DWN| V-UP|NEXTT|INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |         MEDIA PLAY-PAUSE        |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN2_LAYER] = KEYMAP( /* Base */
    KC_TRNS, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, KC_NUMLOCK, KC_TRNS, KC_TRNS, KC_AP_LED_OFF, KC_AP_LED_ON, KC_TRNS, KC_AP_BRIGHT_DOWN, KC_AP_BRIGHT_UP, KC_TRNS,
    MO(_FN2_LAYER), KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_PSCR, KC_HOME, KC_END, KC_TRNS,
    KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, GG_EZ, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, KC_PGDN, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MEDIA_PREV_TRACK, KC_VOLD, KC_VOLU, KC_MEDIA_NEXT_TRACK, KC_INS, KC_DEL, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_MEDIA_PLAY_PAUSE, KC_TRNS, MO(_FN1_LAYER), MO(_FN2_LAYER), KC_TRNS
 ),
/*
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |   Bksp    |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     |  7  |  8  |  9  |  /  |     |     |        |
* |-----------------------------------------------------------------------------------------+
* |         |     |     |     |     |     |  .  |  4  |  5  |  6  |  *  |     | KEYP ENTER  |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |  ,  |  1  |  2  |  3  |  -  |     |       =        |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |                 0               |   +   |       | NLock |       |
* \-----------------------------------------------------------------------------------------/
*/
 [_KEYPAD] = KEYMAP( /* KEYPAD */
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_SLASH, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_RGHT, KC_TRNS, KC_TRNS, KC_KP_DOT, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_ASTERISK, KC_TRNS, KC_KP_ENTER,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_COMMA, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_MINUS, KC_TRNS, KC_KP_EQUAL,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_0, KC_KP_PLUS, KC_TRNS, KC_NUMLOCK, KC_TRNS
),
};

/* EMPTY LAYER
 [_FN3_LAYER] = KEYMAP(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
*/

const uint16_t keymaps_size = sizeof(keymaps);


void matrix_init_user(void) {

}

void matrix_scan_user(void) {
}

layer_state_t layer_state_set_user(layer_state_t state) {

    switch (get_highest_layer(state)) {
    case _FN1_LAYER:
        annepro2LedLayerOn(1);
        break;
    case _FN2_LAYER:
        annepro2LedLayerOn(2);
        break;
    case _KEYPAD:
        annepro2LedLayerOn(3);
        break;
    default: //  for any other layers, or the default layer
        annepro2LedLayerOff();
        break;
    }
    return state;
}

/*!
 * @returns false   processing for this keycode has been completed.
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_AP_LED_OFF:
            if (record->event.pressed)
                annepro2LedDisable();
            return false;
        case KC_AP_LED_ON:
            if (record->event.pressed)
                annepro2LedEnable();
            return false;
        case KC_AP_BRIGHT_UP:
            if (record->event.pressed)
                annepro2LedBrightUp();
            return false;
        case KC_AP_BRIGHT_DOWN:
            if (record->event.pressed)
                annepro2LedBrightDown();
            return false;
        case GG_END_SEMICOLON:
            if (record->event.pressed)
                SEND_STRING(SS_TAP(X_END)";");
            break;
        case CTL_LEFT:
            if (record->event.pressed)
                SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_LEFT) SS_UP(X_LCTL));
            break;
        case CTL_RIGHT:
            if (record->event.pressed)
                SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_RIGHT) SS_UP(X_LCTL));
            break;
        case GG_EZ:
            if (record->event.pressed)
                SEND_STRING("gg ez");
            break;
        case ALT_Z:
            if (record->event.pressed)
                SEND_STRING(SS_LALT("z"));
            break;
        default:
            break;
    }
    return true;
}
