#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Arduino.h>

void initDisplay(int sdaPin, int sclPin);
void showEmotion(String emotion);
void showText(String text);
void clearDisplay();

#endif