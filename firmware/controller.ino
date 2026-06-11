#include "USB.h"
#include "USBHIDGamepad.h"

USBHIDGamepad Gamepad;

#define BTN_UP 17
#define BTN_DOWN 11
#define BTN_LEFT 12
#define BTN_RIGHT 13
#define BTN_A 9
#define BTN_B 6
#define BTN_X 37
#define BTN_Y 48
#define BTN_L 39
#define BTN_R 0
#define BTN_START 15
#define BTN_SELECT 7
#define BTN_SYS 40

#define HID_BTN_A 1
#define HID_BTN_B 2
#define HID_BTN_X 3
#define HID_BTN_Y 4
#define HID_BTN_L 5
#define HID_BTN_R 6
#define HID_BTN_SELECT 7
#define HID_BTN_START 8
#define HID_BTN_SYS 9

void setup()
{
    pinMode(BTN_UP, INPUT_PULLUP);
    pinMode(BTN_DOWN, INPUT_PULLUP);
    pinMode(BTN_LEFT, INPUT_PULLUP);
    pinMode(BTN_RIGHT, INPUT_PULLUP);
    pinMode(BTN_A, INPUT_PULLUP);
    pinMode(BTN_B, INPUT_PULLUP);
    pinMode(BTN_X, INPUT_PULLUP);
    pinMode(BTN_Y, INPUT_PULLUP);
    pinMode(BTN_L, INPUT_PULLUP);
    pinMode(BTN_R, INPUT_PULLUP);
    pinMode(BTN_START, INPUT_PULLUP);
    pinMode(BTN_SELECT, INPUT_PULLUP);
    pinMode(BTN_SYS, INPUT_PULLUP);

    Gamepad.begin();
    USB.begin();
    delay(1000);
}

void loop()
{
    bool up = !digitalRead(BTN_UP);
    bool down = !digitalRead(BTN_DOWN);
    bool left = !digitalRead(BTN_LEFT);
    bool right = !digitalRead(BTN_RIGHT);

    int hatAngle = -1;
    if (up && right)
        hatAngle = 45;
    else if (down && right)
        hatAngle = 135;
    else if (down && left)
        hatAngle = 225;
    else if (up && left)
        hatAngle = 315;
    else if (up)
        hatAngle = 0;
    else if (right)
        hatAngle = 90;
    else if (down)
        hatAngle = 180;
    else if (left)
        hatAngle = 270;

    Gamepad.hat(hatAngle);

    if (!digitalRead(BTN_A))
        Gamepad.press(HID_BTN_A);
    else
        Gamepad.release(HID_BTN_A);
    if (!digitalRead(BTN_B))
        Gamepad.press(HID_BTN_B);
    else
        Gamepad.release(HID_BTN_B);
    if (!digitalRead(BTN_X))
        Gamepad.press(HID_BTN_X);
    else
        Gamepad.release(HID_BTN_X);
    if (!digitalRead(BTN_Y))
        Gamepad.press(HID_BTN_Y);
    else
        Gamepad.release(HID_BTN_Y);
    if (!digitalRead(BTN_L))
        Gamepad.press(HID_BTN_L);
    else
        Gamepad.release(HID_BTN_L);
    if (!digitalRead(BTN_R))
        Gamepad.press(HID_BTN_R);
    else
        Gamepad.release(HID_BTN_R);
    if (!digitalRead(BTN_SELECT))
        Gamepad.press(HID_BTN_SELECT);
    else
        Gamepad.release(HID_BTN_SELECT);
    if (!digitalRead(BTN_START))
        Gamepad.press(HID_BTN_START);
    else
        Gamepad.release(HID_BTN_START);
    if (!digitalRead(BTN_SYS))
        Gamepad.press(HID_BTN_SYS);
    else
        Gamepad.release(HID_BTN_SYS);

    Gamepad.send();
    delay(10);
}