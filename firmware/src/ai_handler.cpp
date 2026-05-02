#include "ai_handler.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>

String GROQ_API_KEY;

void initAI(const char* apiKey) {
  GROQ_API_KEY = String(apiKey);
}

String chatWithAI(String userMessage, String personality) {
  HTTPClient http;
  http.begin("https://api.groq.com/openai/v1/chat/completions");
  http.addHeader("Content-Type", "application/json");
  http.addHeader("Authorization", "Bearer " + GROQ_API_KEY);
  
  StaticJsonDocument<1024> doc;
  doc["model"] = "llama-3.1-8b-instant";
  
  JsonArray messages = doc.createNestedArray("messages");
  
  JsonObject system = messages.createNestedObject();
  system["role"] = "system";
  system["content"] = getSystemPrompt(personality);
  
  JsonObject user = messages.createNestedObject();
  user["role"] = "user";
  user["content"] = userMessage;
  
  String requestBody;
  serializeJson(doc, requestBody);
  
  int httpCode = http.POST(requestBody);
  String response = "";
  
  if (httpCode == 200) {
    String payload = http.getString();
    StaticJsonDocument<4096> responseDoc;
    deserializeJson(responseDoc, payload);
    response = responseDoc["choices"][0]["message"]["content"].as<String>();
  } else {
    response = "API Error: " + String(httpCode);
  }
  
  http.end();
  return response;
}

String getSystemPrompt(String personality) {
  if (personality == "funny") {
    return "You are EMO, a funny robot. Keep responses 1-2 sentences. Be witty.";
  } else if (personality == "serious") {
    return "You are EMO, a professional assistant. Be concise and helpful.";
  } else {
    return "You are EMO, a friendly companion. Be warm and conversational.";
  }
}