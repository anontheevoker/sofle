#include QMK_KEYBOARD_H

/* home row mods */
#define LALT_A LALT_T(KC_A)
#define LGUI_R LGUI_T(KC_R)
#define LSFT_S LSFT_T(KC_S)
#define LCTRL_T LCTL_T(KC_T)

#define RCTRL_N RCTL_T(KC_N)
#define RSFT_E RSFT_T(KC_E)
#define LGUI_I LGUI_T(KC_I)
#define RALT_O RALT_T(KC_O)

/* space when tapped, layer 2 when held */
#define SPC_MO2 LT(2, KC_SPC)

/* enter when tapped, layer 2 when held */
#define ENT_MO2 LT(2, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT(
  KC_GRV,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
  KC_TILD, KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQL,
  KC_MINS, LALT_A, LGUI_R,  LSFT_S,  LCTRL_T, KC_G,                      KC_M,    RCTRL_N, RSFT_E,  LGUI_I,  RALT_O,  KC_QUOT,
  KC_UNDS, KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,    KC_MUTE, XXXXXXX, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_DQT,
           DF(1),  KC_CAPS, KC_ESC,  KC_BSPC, SPC_MO2,                   ENT_MO2, KC_TAB,  KC_DEL,  KC_LBRC, KC_RBRC
),

[1] = LAYOUT(
  KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,   KC_5,                     KC_6,   KC_7,    KC_8,    KC_9,   KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,                     KC_Y,   KC_U,    KC_I,    KC_O,   KC_P,    KC_DEL,
  KC_LCTRL, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,                     KC_H,   KC_J,    KC_K,    KC_L,   KC_SCLN, KC_RCTRL,
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_MUTE, XXXXXXX, KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
            DF(0),   KC_LGUI, KC_LALT, KC_SPC, MO(3),                    KC_ENT, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT
),

[2] = LAYOUT(
  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_FIND, KC_PSCR, XXXXXXX,                   XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_F12,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MENU, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
  XXXXXXX, KC_UNDO, KC_CUT,  KC_COPY, XXXXXXX, KC_PSTE, XXXXXXX, XXXXXXX, KC_HELP, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[3] = LAYOUT(
  KC_TILD, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_N,    KC_M,    XXXXXXX, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)

};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print layout
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);

    switch (get_highest_layer(default_layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("WRITE"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("VIDYA"), false);
            break;
        default:
            oled_write_P(PSTR("UNDF"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
        case 1:
            oled_write_P(PSTR("BASE\n"), false);
            break;
        case 2:
        case 3:
            oled_write_P(PSTR("FUNC"), false);
            break;
        default:
            oled_write_ln_P(PSTR("UNDF"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("CAPS ") : PSTR("    "), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_BRID);
        } else {
            tap_code(KC_BRIU);
        }
    }
    return true;
}

#endif
