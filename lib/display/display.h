#ifndef DISPLAY_H
#define DISPLAY_H
#include "animation/sleepy_animation.h"
#include "animation/love_animation.h"
#include "animation/angry_animation.h"
#include "animation/blink_animation.h"
#include "animation/sliteye_animation.h"




void display_init();
void display_update();      // non-blocking animation update
void set_scene(int scene);  // ganti wajah
void set_white(); 
extern bool finished;


// extern int menu_index;
// extern const int MENU_TOTAL;




const unsigned char* const scenes_sleepy[] PROGMEM = {
    sleepy_0,
    sleepy_1,
    sleepy_2,    
    sleepy_3,
    sleepy_4,
    sleepy_5,
    sleepy_6,        
    sleepy_7,
    sleepy_8,
    sleepy_9,
    sleepy_010,
    sleepy_011,
    sleepy_012,
    sleepy_013,
    sleepy_014,
    sleepy_015,
    sleepy_016,
    sleepy_017,

};

const unsigned char* const scenes_love[] PROGMEM = {
    love_370,
	love_371,
	love_372,
	love_373,
	love_374,
	love_375,
	love_376,
	love_377,
	love_378,
	love_379,
	love_380,
	love_381,
	love_382,
	love_383,
	love_384,
	love_385,
	love_386,
	love_387,
	love_388,
	love_389,
	love_390,
	love_391,
	love_392,
	love_393,
	love_394,
	love_395,
	love_396,
	love_397,
	love_398,
	love_399,
	love_400,
	love_401,
	love_402,
	love_403,
	love_404,
	love_405,
	love_406,
	love_407,
	love_408,
	love_409,
	love_410,
	love_411,
	love_412,
	love_413,
};


const unsigned char* const scenes_angry[] PROGMEM = {
	angry_1506,
	angry_1507,
	angry_1508,
	angry_1509,
	angry_1510,
	angry_1511,
	angry_1512,
	angry_1513,
	angry_1514,
	angry_1515,
	angry_1516,
	angry_1517,
	angry_1518,
	angry_1519,
	angry_1520,
	angry_1521,
	angry_1522,
	angry_1523,
	angry_1524,
	angry_1525,
	angry_1526,
	angry_1527,
	angry_1528,
	angry_1529,
	angry_1530,
	angry_1531,
	angry_1532,
	angry_1533,
	angry_1534,
	angry_1535,
	angry_1536,
	angry_1537,
	angry_1538,
	angry_1539,
	angry_1540,
	angry_1541,
	angry_1542,
	angry_1543,
	angry_1544,
	angry_1545
};

const unsigned char* const scenes_blink[] PROGMEM= {
	blink_000,
	blink_001,
	blink_002,
	blink_003,
	blink_004,
	blink_005,
	blink_006,
	blink_007,
	blink_008,
	blink_009,
	blink_010,
	blink_011,
	blink_012,
	blink_013,
	blink_014,
	blink_015,
	blink_016,
	blink_017,
	blink_018,
	blink_019,
	blink_020,
	blink_021,
	blink_022,
	blink_023,
	blink_024,
	blink_025,
	blink_026,
	blink_027,
	// loop
	blink_000,
	blink_001,
	blink_002,
	blink_003,
	blink_004,
	blink_005,
	blink_006,
	blink_007,
	blink_008,
	blink_009,
	blink_010,
	blink_011,
	blink_012,
	blink_013,
	blink_014,
	blink_015,
	blink_016,
	blink_017,
	blink_018,
	blink_019,
	blink_020,
	blink_021,
	blink_022,
	blink_023,
	blink_024,
	blink_025,
	blink_026,
	blink_027,
};

/*
const unsigned char* const scenes_slit_eye[] PROGMEM= {
	slit_eye_012,
	slit_eye_014,
	slit_eye_016,
	slit_eye_018,
	slit_eye_020,
	slit_eye_022,
	slit_eye_024,
	slit_eye_026,
	slit_eye_028,
	slit_eye_030,
	slit_eye_032,
	slit_eye_034,
	slit_eye_036,
	slit_eye_038,
	slit_eye_040,
	slit_eye_042,
	slit_eye_044,
	slit_eye_046,
};
*/

// list scene
#define SCENE_IDLE 0
#define SCENE_SLEEPY 1
#define SCENE_LOVE 2
#define SCENE_ANGRY 3
#define SCENE_BLINK 4
#define SCENE_SLIT_EYE 5




#define SCENE_MENU          100
#define SCENE_MENU_CLOCK    101
#define SCENE_MENU_COUNTER  102
#define SCENE_MENU_WEATHER  103
#define SCENE_MENU_NAVIGATE 104

#define SDA_PIN 8
#define SCL_PIN 9

#endif