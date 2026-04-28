\# EMO V1 — Desktop AI Robot



A voice-interactive desktop companion featuring real-time AI conversation, dynamic personality modes, memory retention, and integrated mini-games.



\---



\## Overview



EMO V1 is a compact AI robot designed for natural voice interaction and emotional expression. Built on ESP32-S3 architecture with cloud-based AI processing, it serves as an intelligent desktop companion capable of learning user preferences and adapting its personality to context.



\---



\## Technical Specifications



\### Compute Architecture

\- ESP32-S3 dual-core processor (240 MHz)

\- 8 MB PSRAM for audio buffering

\- WiFi 802.11 b/g/n for cloud API communication



\### Display System

\- 2.4-inch OLED panel (128×64 resolution)

\- I2C interface (400 kHz)

\- Procedural emotion rendering engine



\### Audio Pipeline

\- I2S MEMS microphone (INMP441)

\- I2S digital amplifier (MAX98357A)

\- 3W 8Ω speaker element

\- 16-bit 16 kHz audio sampling



\### Input Interface

\- Three tactile push buttons

\- Debounced interrupt-driven input handling



\---



\## Software Architecture



\### AI Processing Stack

\- Speech-to-Text: OpenAI Whisper API

\- Language Model: Groq Llama 3.1 (8B parameters)

\- Text-to-Speech: Google Cloud TTS

\- Total latency: sub-2-second response time



\### Core Systems

\- Multi-personality framework (Funny, Serious, Assistant modes)

\- SPIFFS-based persistent memory storage

\- Real-time animation state machine

\- Game engine with 60 FPS rendering



\### Memory Capabilities

\- User preference tracking

\- Conversation history retention

\- Context-aware response generation



\---



\## Project Structure

EMO---Robot/

│

├── firmware/

│   ├── src/

│   │   ├── main.cpp

│   │   ├── ai\_module.cpp

│   │   ├── animation\_engine.cpp

│   │   └── game\_snake.cpp

│   ├── include/

│   │   ├── config.h

│   │   └── ai\_module.h

│   └── platformio.ini

│

└── hardware/

├── schematics/

└── wiring.md



\---



\## Development Roadmap



\### Phase 1 — Core AI Integration (Week 1)

\- WiFi connectivity and API authentication

\- Voice input/output pipeline

\- Basic emotion display system

\- Cloud AI integration testing



\### Phase 2 — Personality \& Games (Week 2)

\- Multi-mode personality implementation

\- Snake game development

\- Dynamic facial expression system

\- Button input handling



\### Phase 3 — Memory \& Polish (Week 3)

\- SPIFFS memory integration

\- User preference learning

\- Conversation context retention

\- Final system integration



\---



\## Installation



\### Prerequisites

\- PlatformIO IDE

\- Groq API key (free tier: groq.com)

\- Google Cloud account (free TTS tier)



\### Setup

1\. Clone repository

```bash

&#x20;  git clone https://github.com/amritmundlapudibiz-eng/EMO---Robot.git

&#x20;  cd EMO---Robot

```



2\. Configure credentials in `firmware/include/config.h`

```cpp

&#x20;  #define WIFI\_SSID "your\_network"

&#x20;  #define WIFI\_PASSWORD "your\_password"

&#x20;  #define GROQ\_API\_KEY "your\_groq\_key"

```



3\. Build and upload

```bash

&#x20;  pio run --target upload

```



\---



\## API Cost Analysis



| Service | Tier | Monthly Limit | Cost |

|---------|------|---------------|------|

| Groq Llama 3.1 | Free | 14,400 requests/day | $0.00 |

| Google Cloud TTS | Free | 1M characters | $0.00 |

| OpenAI Whisper | Pay-as-you-go | Unlimited | $0.006/min |



Estimated cost for 100 conversations: $0.30



\---



\## Hardware Bill of Materials



| Component | Specification | Quantity | Unit Cost |

|-----------|--------------|----------|-----------|

| ESP32-S3-DevKitC-1 | Dual-core 240 MHz, 8 MB PSRAM | 1 | $15.00 |

| OLED Display | 2.4" I2C SSD1306 | 1 | $12.00 |

| MEMS Microphone | INMP441 I2S | 1 | $5.00 |

| Audio Amplifier | MAX98357A I2S | 1 | $6.00 |

| Speaker | 3W 8Ω | 1 | $4.00 |

| Push Buttons | Tactile 12mm | 3 | $3.00 |

| Breadboard | 830 tie-points | 1 | $5.00 |

| Jumper Wires | Male-to-male assorted | 40 | $5.00 |

| USB-C Cable | Data + power | 1 | $5.00 |



Total: $60.00



\---



\## License



MIT License — Copyright (c) 2026



Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files, to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software.



\---



\## Contributors



Developed by Amrit and Rishav



Hardware integration partner: \[Rishav]



\---



\*\*Last Updated:\*\* April 2026  

\*\*Status:\*\* Active Development — Week 1  

\*\*Target Completion:\*\* May 2026

