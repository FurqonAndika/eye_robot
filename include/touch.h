#include <Arduino.h>
#define TOUCH_PIN 2  // pin OUT dari modul touch sensor

#define TAP 1
#define DOUBLE_TAP 2
#define LONG_TOUCH 3

void touch_init();
int detect_touch_gesture();