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

int last_scene_1 = -1;
int last_scene_2 = -1;

void choose_new_scene()
{
  int new_scene;

  while (true)
  {
    new_scene = random(1, 5); // 1–3 (blink/love/happy)

    // jangan 3x berturut2 sama
    if (new_scene != last_scene_1 || new_scene != last_scene_2)
      break;
  }

  // update history
  last_scene_2 = last_scene_1;
  last_scene_1 = new_scene;

  // ganti scene
  set_scene(new_scene);
  Serial.print("Scene dipilih: ");
  Serial.println(new_scene);
}

void setup()
{
  Serial.begin(115200);

  // initialize system components
  system_init();

  Serial.println("System Started.");
  // set_white();
  set_scene(4);
}

void loop()
{

  //  const unsigned char happy_9 [] PROGMEM
  // watch.loop(); // handles internal routine functions

  int type_tap = detect_touch_gesture();
  if (type_tap != 0)
  {
    Serial.print("Detected gesture type: ");
    Serial.println(type_tap);
  }

  if (type_tap == TAP)
  {
    Serial.println("Sentuh 1x");
    set_scene(SCENE_LOVE);
  }
  else if (type_tap == DOUBLE_TAP)
  {
    Serial.println("Sentuh 2x");
    set_scene(SCENE_BLINK);
  }
  else if (type_tap == LONG_TOUCH)
  {
    Serial.println("Elus / tahan lama");
    set_scene(SCENE_MENU);
  }

  display_update();
  if (finished)
  {
    finished = false;
    choose_new_scene();
  }
};




/*
#include <Arduino.h>
#include "initiation.h"


// ==================================================
// Global Menu
// ==================================================

int counter_value = 0;

bool in_menu = false;

// ==================================================

void enter_menu()
{
    in_menu = true;
    menu_index = 0;
    set_scene(SCENE_MENU);
    Serial.println("Masuk menu");
}

void exit_menu()
{
    in_menu = false;
    set_scene(SCENE_IDLE);
    Serial.println("Keluar menu");
}

void menu_next_item()
{
    menu_index++;
    if (menu_index >= MENU_TOTAL) menu_index = 0;
    set_scene(SCENE_MENU);
}

void menu_select()
{
    switch (menu_index)
    {
        case 0: set_scene(SCENE_MENU_CLOCK); break;
        case 1: set_scene(SCENE_MENU_COUNTER); break;
        case 2: set_scene(SCENE_MENU_WEATHER); break;
        case 3: set_scene(SCENE_MENU_NAVIGATE); break;
    }
}

// ==================================================



int last_scene_1 = -1;
int last_scene_2 = -1;

void choose_new_scene()
{
  int new_scene;

  while (true)
  {
    new_scene = random(1, 5); // 1–3 (blink/love/happy)

    // jangan 3x berturut2 sama
    if (new_scene != last_scene_1 || new_scene != last_scene_2)
      break;
  }

  // update history
  last_scene_2 = last_scene_1;
  last_scene_1 = new_scene;

  // ganti scene
  set_scene(new_scene);
  Serial.print("Scene dipilih: ");
  Serial.println(new_scene);
}

void setup()
{
    Serial.begin(115200);
    system_init();
    set_scene(SCENE_IDLE);
}

void loop()
{
    watch.loop();
    int type_tap = detect_touch_gesture();

    if (type_tap != 0) {
        Serial.print("Gesture: ");
        Serial.println(type_tap);
    }

    // -----------------------------
    // MENU MODE
    // -----------------------------
    if (in_menu)
    {
        if (type_tap == TAP)
        {
            menu_next_item();
        }
        else if (type_tap == DOUBLE_TAP)
        {
            menu_select();
        }
        else if (type_tap == LONG_TOUCH)
        {
            exit_menu();
        }

        display_update();
        return;
    }

    // -----------------------------
    // NORMAL (ANIMASI)
    // -----------------------------
    if (type_tap == TAP)
        set_scene(SCENE_LOVE);

    else if (type_tap == DOUBLE_TAP)
        set_scene(SCENE_BLINK);

    else if (type_tap == LONG_TOUCH)
        enter_menu();

    // animasi selesai → pilih scene acak
    if (finished)
    {
        finished = false;
        choose_new_scene();
    }

    display_update();
}
*/