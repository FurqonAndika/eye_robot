/*
#include "touch.h"


unsigned long last_touch_time = 0;
unsigned long first_touch_time = 0;
int touch_count = 0;
bool is_touching = false;
bool long_touch_handled = false;  // flag untuk menghindari double-detect setelah long touch

// batas waktu (ms) — sesuaikan bila perlu
const unsigned long LONG_TOUCH_MS = 800;
const unsigned long DOUBLE_TAP_GAP_MS = 500;


void touch_init() {
  pinMode(TOUCH_PIN, INPUT);
}

int detect_touch_gesture() {
  int touch_value = digitalRead(TOUCH_PIN);
  unsigned long current_time = millis();

  // Jika sensor LOW (dilepas), reset kondisi tertentu
  if (touch_value == LOW) {
    // reset state is_touching — tapi jangan reset long_touch_handled di sini
    // karena kita hanya clear long_touch_handled saat benar-benar sudah dilepas
    is_touching = false;

    // Jika long touch sebelumnya sudah di-handle, kita clear flag ketika dilepas
    if (long_touch_handled) {
      long_touch_handled = false;
      touch_count = 0;         // pastikan count bersih setelah long touch
      return 0;                // nothing else to do right now
    }

    // Jika ada tap(s) yang belum diproses dan sudah lewat jeda, kembalikan hasilnya
    if (touch_count > 0 && (current_time - last_touch_time > DOUBLE_TAP_GAP_MS)) {
      int result = touch_count;
      touch_count = 0;
      return result; // 1 = single, 2 = double (atau lebih jika mau)
    }

    return 0;
  }

  // Jika sensor HIGH (ditekan) dan belum marked as touching
  if (touch_value == HIGH && !is_touching) {
    // Jika long touch sedang di-handle, abaikan deteksi baru sampai dilepas
    if (long_touch_handled) {
      // tetap menunggu sampai dilepas
      is_touching = true; // tetap set supaya kita tahu jari masih nempel
      return 0;
    }

    // normal tap detection
    is_touching = true;
    touch_count++;
    if (touch_count == 1) first_touch_time = current_time;
    last_touch_time = current_time;
  }

  // Jika masih menempel dan belum handled long-touch, periksa durasi
  if (is_touching && !long_touch_handled) {
    if (current_time - first_touch_time >= LONG_TOUCH_MS) {
      // laporkan elus / tahan lama
      long_touch_handled = true;
      is_touching = true;    // masih nempel, tapi sudah di-handle
      touch_count = 0;       // clear count supaya tidak muncul tap setelahnya
      return 3;              // 3 = elus / tahan lama
    }
  }

  // Jika tidak ada kasus lain, return 0
  return 0;
}

*/

#include "touch.h"

unsigned long last_touch_time = 0;
unsigned long first_touch_time = 0;
int touch_count = 0;
bool is_touching = false;
bool long_touch_handled = false;

// batas waktu (ms)
const unsigned long LONG_TOUCH_MS = 2000;
const unsigned long TAP_GAP_MS = 500;   // gap antar tap

void touch_init() {
  pinMode(TOUCH_PIN, INPUT);
}

int detect_touch_gesture() {
  int touch_value = digitalRead(TOUCH_PIN);
  unsigned long now = millis();

  // -----------------------------
  // RELEASED (LOW)
  // -----------------------------
  if (touch_value == LOW) {

    is_touching = false;

    // setelah long-touch, reset state ketika dilepas
    if (long_touch_handled) {
      long_touch_handled = false;
      touch_count = 0;
      return 0;
    }

    // Jika sudah lewat gap → berarti tap selesai
    if (touch_count > 0 && (now - last_touch_time > TAP_GAP_MS)) {
      int result = touch_count;  // 1..6
      touch_count = 0;
      return result;
    }

    return 0;
  }

  // -----------------------------
  // PRESSED (HIGH)
  // -----------------------------
  if (touch_value == HIGH && !is_touching) {

    if (long_touch_handled) {
      is_touching = true;
      return 0;
    }

    // normal tap
    is_touching = true;
    touch_count++;

    if (touch_count == 1) first_touch_time = now;

    last_touch_time = now;
  }

  // -----------------------------
  // LONG TOUCH DETECTION
  // -----------------------------
  if (is_touching && !long_touch_handled) {
    if (now - first_touch_time >= LONG_TOUCH_MS) {
      long_touch_handled = true;
      touch_count = 0;        // pastikan tidak terdeteksi sebagai tap
      return 7;               // gesture 7 = long touch
    }
  }

  return 0;
}
