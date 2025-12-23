#ifndef CUSTOMWATCH_H
#define CUSTOMWATCH_H

#include <Arduino.h>
#include <ChronosESP32.h>


void connectionCallback(bool state);

void notificationCallback(Notification notification);

void ringerCallback(String caller, bool state);


void configCallback(Config config, uint32_t a, uint32_t b);


void dataCallback(uint8_t *data, int length);

void watch_init();


#endif // CUSTOMWATCH_H