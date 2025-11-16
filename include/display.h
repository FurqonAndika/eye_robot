#ifndef DISPLAY_H
#define DISPLAY_H

void display_init();
void display_update();      // non-blocking animation update
void set_scene(int scene);  // ganti wajah
void set_white();   


// list scene
#define SCENE_IDLE 0
#define SCENE_HAPPY 1
#define SCENE_ANGRY 2

#define SDA_PIN 8
#define SCL_PIN 9

#endif