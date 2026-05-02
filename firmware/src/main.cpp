#include <Arduino.h>
#include "config.h"
#include "wifi_manager.h"
#include "ai_handler.h"
#include "display_manager.h"
#include "audio_manager.h"

String currentPersonality = "assistant";

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("\n=== EMO V1 Starting ===");
  
  connectWiFi(WIFI_SSID, WIFI_PASSWORD);
  initAI(GROQ_API_KEY);
  initDisplay(OLED_SDA, OLED_SCL);
  initMicrophone(MIC_WS, MIC_SCK, MIC_SD);
  initSpeaker(SPK_BCLK, SPK_LRC, SPK_DIN);
  
  showEmotion("happy");
  Serial.println("\n=== EMO Ready ===");
  Serial.println("Type to chat or 'funny'/'serious'/'assistant' to switch modes\n");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    
    if (input == "funny" || input == "serious" || input == "assistant") {
      currentPersonality = input;
      Serial.println("Mode: " + currentPersonality);
      showText("Mode:\n" + currentPersonality);
      delay(1500);
      showEmotion("happy");
      return;
    }
    
    Serial.println("You: " + input);
    showEmotion("thinking");
    
    String response = chatWithAI(input, currentPersonality);
    
    Serial.println("EMO: " + response);
    showEmotion("happy");
    
    delay(2000);
  }
}