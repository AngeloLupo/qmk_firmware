#include QMK_KEYBOARD_H
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _QWERTY = 0,
  _FLOCK,
  _MOUSE,
  _BROWSER,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  FLOCK = SAFE_RANGE,
  MOUSE,
  BROWSER,
  LOWER,
  RAISE,
  ADJUST,
  RGBRST
};

enum tapdances{
  TD_ESFL = 0,
  TD_ESQW,
};

// Fillers to make layering more clear
#define KC_CT11 LCTL_T(KC_F11)
#define KC_SF12 SFT_T(KC_F12)
#define KC_LOEN LT(_LOWER, KC_ENT)
#define KC_RASP LT(_RAISE, KC_SPC)

#define KC_RTAB LCTL(KC_TAB)
#define KC_LTAB LCTL(LSFT(KC_TAB))
#define KC_CTAB LCTL(KC_W)
#define KC_RETAB LCTL(LSFT(KC_T))

#define KC_TGMO TG(_MOUSE)
#define KC_TGBR TG(_BROWSER)
#define KC_BSAD LT(_ADJUST, KC_BSPC)

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_ESFL] = ACTION_TAP_DANCE_DUAL_ROLE(KC_ESC, _FLOCK),
  [TD_ESQW] = ACTION_TAP_DANCE_DUAL_ROLE(KC_ESC, _QWERTY),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_with_nafuda(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.      |--------------------------|
  TD(TD_ESFL),    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,                 KC_TGMO,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |--------+--------+--------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, JP_LBRC,        KC_BSAD,   KC_UP, KC_TGBR,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |--------+--------+--------|
     KC_LCTRL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L, JP_MINS, JP_RBRC,        KC_LEFT, KC_DOWN,KC_RIGHT,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |--------------------------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M, JP_COMM,  JP_DOT, JP_SLSH, JP_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
               KC_LEFT,KC_RIGHT, KC_LGUI, KC_MHEN, KC_LOEN, KC_BSPC,  KC_DEL, KC_RASP, KC_HENK, KC_LALT, KC_DOWN,   KC_UP
          //`------------------------------------------------------------------------------------------------------------'
  ),

  [_FLOCK] = LAYOUT_with_nafuda(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.      |--------------------------|
  TD(TD_ESQW),   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,                 _______,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,        _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,        _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |--------------------------|
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
          //`------------------------------------------------------------------------------------------------------------'
  ),

  [_MOUSE] = LAYOUT_with_nafuda(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.      |--------------------------|
  TD(TD_ESFL),    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,                 KC_TGMO,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,        KC_BTN1, KC_MS_U, KC_BTN2,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,        KC_MS_L, KC_MS_D, KC_MS_R,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |--------------------------|
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ 
          //`------------------------------------------------------------------------------------------------------------'
  ),

  [_BROWSER] = LAYOUT_with_nafuda(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.      |--------------------------|
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,                 KC_CTAB,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,       KC_RETAB, KC_WH_U, KC_TGBR,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,        KC_LTAB, KC_WH_D, KC_RTAB,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |--------------------------|
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ 
          //`------------------------------------------------------------------------------------------------------------'
  ),

  [_LOWER] = LAYOUT_with_nafuda(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.      |--------------------------|
       KC_ESC,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,                 KC_TGMO,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |--------+--------+--------|
      JP_COLN, JP_EXLM, JP_QUES, JP_LBRC, JP_RBRC, JP_TILD,                      KC_6,    KC_7,    KC_8,    KC_9, JP_ASTR, JP_SLSH,        KC_BSAD,   KC_UP, KC_TGBR,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |--------+--------+--------|
      JP_QUOT, JP_HASH,  JP_DQT, JP_LPRN, JP_RPRN,   JP_AT,                   XXXXXXX,    KC_4,    KC_5,    KC_6, JP_MINS,  JP_EQL,        KC_LEFT, KC_DOWN,KC_RIGHT,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |--------------------------|
      JP_CIRC, JP_PERC, JP_AMPR, JP_SCLN, JP_COLN, JP_PIPE,                      KC_0,    KC_1,    KC_2,    KC_3, JP_PLUS,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, KC_ZKHK,   LOWER, _______, _______,   RAISE,    KC_0,  JP_DOT, _______, _______
          //`------------------------------------------------------------------------------------------------------------'
  ),

  [_RAISE] = LAYOUT_with_nafuda(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.      |--------------------------|
       KC_ESC,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,                 KC_TGMO,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |--------+--------+--------|
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6, XXXXXXX,   KC_UP, XXXXXXX, KC_PGUP,  KC_DEL,        KC_BSAD,   KC_UP, KC_TGBR,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |--------+--------+--------|
      KC_CT11,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                   XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, KC_LSFT,  KC_ENT,        KC_LEFT, KC_DOWN,KC_RIGHT,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |--------------------------|
      KC_SF12,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ 
          //`------------------------------------------------------------------------------------------------------------'
  ),

  [_ADJUST] = LAYOUT_with_nafuda( /* Base */
  //,-----------------------------------------------------|                 |-----------------------------------------------------.      |--------------------------|
       KC_ESC,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,                 RGB_VAD,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |--------+--------+--------|
      _______,   RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX,LALT(KC_PSCR),    ADJUST, RGB_SAD, RGB_VAI,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |--------+--------+--------|
     KC_LCTRL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, KC_PSCR,        RGB_MOD, RGB_TOG, RGB_SAI,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|      |--------------------------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,LCA(KC_DEL),
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
          //`------------------------------------------------------------------------------------------------------------'
  )
};

static inline void update_change_layer(bool pressed, uint8_t layer1, uint8_t layer2, uint8_t layer3) {

  pressed ? layer_on(layer1) : layer_off(layer1);
  IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2) ? layer_on(layer3) : layer_off(layer3);
}

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  bool result = false;
  switch (keycode) {
    case LOWER:
      update_change_layer(record->event.pressed, _LOWER, _RAISE, _ADJUST);
      break;
    case RAISE:
      update_change_layer(record->event.pressed, _RAISE, _LOWER, _ADJUST);
        break;
    #ifdef RGBLIGHT_ENABLE
      case RGB_MOD:
          if (record->event.pressed) {
            rgblight_mode(RGB_current_mode);
            rgblight_step();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
      case RGBRST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
    #endif
    default:
      result = true;
      break;
  }

  return result;
}

void matrix_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
  #endif
}