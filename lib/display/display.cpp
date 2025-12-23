
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_SH110X.h>
#include "display.h"
#include <Wire.h>

#define OLED_1_3_INCH true // ubah sesuai jenis layar

#if OLED_1_3_INCH
Adafruit_SH1106G oled = Adafruit_SH1106G(128, 64, &Wire, -1);
#else
Adafruit_SSD1306 oled(128, 64, &Wire, -1);
#endif

unsigned long lastFrameTime = 0;
int current_scene = SCENE_IDLE;
int current_frame = 0;
int direction = 1;     // 1 = maju, -1 = mundur
int delay_frame = 100; // ms
boolean finished = false;

void display_init()
{
    Wire.begin(SDA_PIN, SCL_PIN);
    if (OLED_1_3_INCH)
    {
        oled.begin(0x3C, true); // address, reset=true
    }
    else
    {
        oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    }
    oled.clearDisplay();

    oled.display();
}

void set_scene(int scene)
{
    current_scene = scene;
    current_frame = 0; // mulai dari frame pertama
    lastFrameTime = millis();
}

void display_update()
{
    // ganti frame sesuai delay konfigurasi scene
    if (millis() - lastFrameTime < delay_frame)
        return;
    lastFrameTime = millis();

    oled.clearDisplay();

    // SCENE IDLE — tidak pakai animasi
    if (current_scene == SCENE_IDLE)
    {
        oled.setCursor(0, 0);
        oled.println("Idle");
        oled.display();
        return;
    }

    // ================================
    // 1) PILIH ARRAY FRAME BERDASARKAN SCENE
    // ================================
    const unsigned char *const *frames = nullptr;
    int TOTAL_FRAMES = 0;

    switch (current_scene)
    {
    case SCENE_SLEEPY:
        frames = scenes_sleepy;
        TOTAL_FRAMES = sizeof(scenes_sleepy) / sizeof(scenes_sleepy[0]);
        delay_frame = int(2000 / TOTAL_FRAMES);
        break;

    case SCENE_LOVE:
        frames = scenes_love;
        TOTAL_FRAMES = sizeof(scenes_love) / sizeof(scenes_love[0]);
        delay_frame = int(1500 / TOTAL_FRAMES);
        break;

    case SCENE_ANGRY:
        frames = scenes_angry;
        TOTAL_FRAMES = sizeof(scenes_angry) / sizeof(scenes_angry[0]);
        delay_frame = int(1000 / TOTAL_FRAMES);
        break;

    case SCENE_BLINK:
        frames = scenes_blink;
        TOTAL_FRAMES = sizeof(scenes_blink) / sizeof(scenes_blink[0]);
        delay_frame = int(1000 / TOTAL_FRAMES);
        break;

        // case SCENE_SLIT_EYE:
        //     frames = scenes_slit_eye;
        //     TOTAL_FRAMES = sizeof(scenes_slit_eye) / sizeof(scenes_slit_eye[0]);
        //     delay_frame = int(1000/TOTAL_FRAMES);
        //     break;
    }

    if (TOTAL_FRAMES <= 0)
        return;

    // ================================
    // 2) GAMBAR FRAME
    // ================================
    oled.drawBitmap(0, 0, frames[current_frame], 128, 64, 1);

    // ================================
    // 3) PING–PONG ANIMATION
    // ================================
    static bool reached_end = false;
    static bool reached_start = false;

    if (direction == 1) // maju →
    {
        if (current_frame >= TOTAL_FRAMES - 1)
        {
            direction = -1;
            current_frame = TOTAL_FRAMES - 2;
            reached_end = true;
        }
        else
            current_frame++;
    }
    else // mundur ←
    {
        if (current_frame <= 0)
        {
            direction = 1;
            current_frame = 1;
            reached_start = true;
        }
        else
            current_frame--;
    }

    // ================================
    // 4) LOOP SELESAI? (end → start)
    // ================================
    if (reached_end && reached_start)
    {
        reached_end = false;
        reached_start = false;

        finished = true; // lapor ke sistem
    }

    oled.display();
}

void set_white()
{
    oled.clearDisplay();
    oled.fillScreen(SSD1306_WHITE);
    oled.display();
}
