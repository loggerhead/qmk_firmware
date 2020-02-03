/* spec: https://docs.qmk.fm/#/cli
 * keys definition: quantum/quantum_keycodes.h
 *
 * 1. compile: `qmk compile -kb ergodox_ez -km loggerhead`
 * 2. open `wally.app`
 * 3. press down little button on keyboard, and then release it.
 *    - `ioreg -p IOUSB` will output `IOUSBHostDevice`
 *    - NOTICE: if you use USB hub, you need unplug it to make keyboard rework
 * 4. drag `ergodox_ez_loggerhead.hex` to `wally.app`
 * 5. test your keyboard
 */
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define _LBASE 0 // default layer
#define _LHURT 1 // temp layer. Used only when my thumb feels bad.
#define _LFUNC 2 // function layer. such as: arrow keys

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE, // can always be here
    EPRM,
    VRSN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: basic layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   `    |   1  |   2  |   3  |   4  |   5  |  -   |           |   '  |   6  |   7  |   8  |   9  |   0  |   =    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   W  |   E  |   R  |   T  |  [   |           |   ]  |   Y  |   U  |   I  |   O  |   P  | BSPC   |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | Ctrl   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Gui/Ent|
     * |--------+------+------+------+------+------|  -   |           |   '  |------+------+------+------+------+--------|
     * | Shift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | \      |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |Alt   |      |      |      |Hyper |                                       |Hyper |      |      |      |CA_Del|
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,---------------.
     *                                        | Ins  | Right|       | VolD | VolU  |
     *                                 ,------|------|------|       |------+--------+------.
     *                                 | Gui  |      | Alt  |       | Mute |        |Shift |
     *                                 |   /  |Space |------|       |------| LFUNC  |  /   |
     *                                 | Esc  |      | LFUNC|       | VRSN |        |Space |
     *                                 `--------------------'       `----------------------'
     */
    [_LBASE] = LAYOUT_ergodox(
        // left hand
        KC_GRV,   KC_1,     KC_2,    KC_3,    KC_4,     KC_5,    KC_MINS,
        KC_TAB,   KC_Q,     KC_W,    KC_E,    KC_R,     KC_T,    KC_LBRC,
        KC_LCTL,  KC_A,     KC_S,    KC_D,    KC_F,     KC_G,
        KC_LSFT,  KC_Z,     KC_X,    KC_C,    KC_V,     KC_B,    KC_MINS,
        KC_LALT,  KC_NO,    KC_NO,   KC_NO,   ALL_T(KC_NO),
        // left thumb area
                       KC_INS,       KC_RIGHT,
                                     KC_LALT,
        GUI_T(KC_ESC), KC_SPACE,     MO(_LFUNC),

        // right hand
        KC_QUOT,  KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_EQL,
        KC_RBRC,  KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_BSPC,
                  KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN, RGUI_T(KC_ENTER),
        KC_QUOT,  KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_BSLS,
                   ALL_T(KC_NO),    KC_NO,   KC_NO,    KC_NO,   LCA(KC_DEL),
        // right thumb area
        KC_VOLD,  KC_VOLU,
        KC_MUTE,
        VRSN,    MO(_LFUNC), RSFT_T(KC_SPACE)
    ),

    /* Keymap 1: temp layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |      |      |      |      |      |  -   |           |   '  |      |      |      |      |      |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |      |      |      |      |      |  [   |           |   ]  |      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | Ctrl   |      |      |      |      |      |------|           |------|      |      |      |      |      |Hyper/Ent|
     * |--------+------+------+------+------+------| Gui  |           |      |------+------+------+------+------+--------|
     * | Shift  |      |      |      |      |      | Esc  |           |      |      |      |      |      |      |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |Alt   |      |      |      |      |                                       |      |      |      |      |CA_Del|
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,---------------.
     *                                        | Ins  | Right|       | VolD | VolU  |
     *                                 ,------|------|------|       |------+--------+------.
     *                                 | Gui  |      | Alt  |       | Mute |        |Shift |
     *                                 |   /  |Space |------|       |------|        |  /   |
     *                                 | Esc  |      |      |       | VRSN |        |Space |
     *                                 `--------------------'       `----------------------'
     */
    [_LHURT] = LAYOUT_ergodox(
        // left hand
        _______,  _______,  _______, _______, _______,  _______,    KC_MINS,
        _______,  _______,  _______, _______, _______,  _______,    KC_LBRC,
        KC_LCTL,  _______,  _______, _______, _______,  _______,
        KC_LSFT,  _______,  _______, _______, _______,  _______,    GUI_T(KC_ESC),
        KC_LALT,  KC_NO,    KC_NO,   KC_NO,   ALL_T(KC_NO),
        // left thumb area
                       KC_INS,       KC_RIGHT,
                                     KC_LALT,
        GUI_T(KC_ESC), KC_SPACE,     MO(_LFUNC),

        // right hand
        KC_QUOT,  _______,  _______,  _______, _______,  _______,   _______,
        KC_RBRC,  _______,  _______,  _______, _______,  _______,   _______,
                  _______,  _______,  _______, _______,  _______, ALL_T(KC_ENTER),
        KC_QUOT,  _______,  _______,  _______, _______,  _______,   _______,
                       ALL_T(KC_NO),    KC_NO,   KC_NO,    KC_NO,   LCA(KC_DEL),
        // right thumb area
        KC_VOLD,  KC_VOLU,
        KC_MUTE,
        VRSN,    MO(_LFUNC), RSFT_T(KC_SPACE)
    ),
    /* Keymap 31: function Layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           | F12  |  F6  |  F7  |  F8  |  F9  | F10  |  Ins   |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |      |      |  End |      |      |      |           |      |      |      |      |      |  Up  |  Del   |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        | Home |      |  Del | Right|      |------|           |------| BSPC |      |      |      |      |  Enter |
     * |--------+------+------+------+------+------|C_Ins |           | Mute |------+------+------+------+------+--------|
     * |        |      |      |      |      | Left |      |           |      | Down |      |      |      |      |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |  L0  |  L1  |      |      |                                       |      |      |      |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,---------------.
     *                                        | S_Ins| A_Ins|       | VolD |  VolU  |
     *                                 ,------|------|------|       |------+--------+------.
     *                                 |      |      |      |       |      |        |      |
     *                                 |      |      |------|       |------|        |      |
     *                                 |      |      |      |       |      |        |      |
     *                                 `--------------------'       `----------------------'
     */
    [_LFUNC] = LAYOUT_ergodox(
        // left hand
        _______,   KC_F1,      KC_F2,      KC_F3,      KC_F4,       KC_F5,     KC_F11,
        _______,   _______,    _______,    KC_END,     _______,     _______,   _______,
        _______,   KC_HOME,    _______,    KC_DEL,     KC_RIGHT,    _______,
        _______,   _______,    _______,    _______,    _______,     KC_LEFT,   LCTL(KC_INS),
        _______,   TO(_LBASE), TO(_LHURT), _______,    _______,
        // left thumb area
                   LSFT(KC_INS),  LALT(KC_INS),
                                  KC_MUTE,
        _______,   _______,       _______,

        // right hand
        KC_F12,       KC_F6,    KC_F7,      KC_F8,      KC_F9,       KC_F10,    KC_INS,
        _______,      _______,  _______,    _______,    _______,     KC_UP,     KC_DEL,
                      KC_BSPC,  _______,    _______,    _______,     _______,   KC_ENTER,
        KC_MUTE,      KC_DOWN,  _______,    _______,    _______,     _______,   _______,
                                _______,    _______,    _______,     _______,   _______,
        // right thumb area
        KC_VOLD,   KC_VOLU,
        _______,
        _______,   _______,  _______
    ),
};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
    switch (id) {
    case 0:
        if (record->event.pressed) {
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
    case 1:
        if (record->event.pressed) { // For resetting EEPROM
            eeconfig_init();
        }
        break;
    }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    // dynamically generate these.
    case EPRM:
        if (record->event.pressed) {
            eeconfig_init();
        }
        return false;
        break;
    case VRSN:
        if (record->event.pressed) {
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP "@" QMK_BUILDDATE "/" QMK_VERSION);
        }
        return false;
        break;
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
    case _LHURT:
        ergodox_board_led_on();
        break;
    default:
        break;
    }
};
