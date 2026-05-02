#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <Arduino.h>

bool connectWiFi(const char* ssid, const char* password);
bool isWiFiConnected();
String getIPAddress();

#endif

#include "wifi_manager.h"
#include <WiFi.h>

bool connectWiFi(const char* ssid, const char* password) {
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(500);
    Serial.print(".");
    attempts++;
  }
  
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConnected!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
    return true;
  }
  
  Serial.println("\nFailed!");
  return false;
}

bool isWiFiConnected() {
  return WiFi.status() == WL_CONNECTED;
}

String getIPAddress() {
  return WiFi.localIP().toString();
}