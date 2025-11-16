/*
This main.cpp file is part of the eye_robot project by Furqon Andika and Mulyadi. First created on 16th November 2025.
this project is developed using the C++11 standard and is intended to run on an ESP32 microcontroller.
  
  eye_robot is an interactive robotic eye system that responds to touch gestures
  by changing its displayed expressions. It utilizes a touch sensor for gesture detection
  and an OLED display to render various eye animations.

  Let's make robots 
  */
// boot esp32
#define ARDUINO_USB_CDC_ON_BOOT 1

// standard includes
#include <Arduino.h>

// project includes 
#include "initiation.h"

void setup() {
  Serial.begin(115200);

  // initialize system components
  system_init();

  Serial.println("System Started.");
  // set_white();
  set_scene(SCENE_HAPPY);
}

void loop() {
 
  
  int type_tap = detect_touch_gesture();
  if (type_tap == TAP) {
    Serial.println("Sentuh 1x");
    set_scene(SCENE_IDLE);


  }
  else if (type_tap == DOUBLE_TAP) {
    Serial.println("Sentuh 2x");
    set_scene(SCENE_HAPPY);
  }
  else if (type_tap == LONG_TOUCH){
    Serial.println("Elus / tahan lama");
  } 
 
  // random scene change every 5 seconds
  // it will update soon


  display_update();
}
