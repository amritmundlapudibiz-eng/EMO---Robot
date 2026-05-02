#include "audio_manager.h"

void initMicrophone(int wsPin, int sckPin, int sdPin) {
  Serial.println("Mic pins: WS=" + String(wsPin) + " SCK=" + String(sckPin) + " SD=" + String(sdPin));
  Serial.println("Mic init - waiting for hardware");
}

void initSpeaker(int bclkPin, int lrcPin, int dinPin) {
  Serial.println("Speaker pins: BCLK=" + String(bclkPin) + " LRC=" + String(lrcPin) + " DIN=" + String(dinPin));
  Serial.println("Speaker init - waiting for hardware");
}