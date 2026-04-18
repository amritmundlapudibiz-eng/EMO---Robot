\# EMO Companion Robot



An autonomous AI companion robot with natural language processing, emotion expression, and real-time interaction capabilities.



\## Overview



EMO is a companion robot built on a dual-processor architecture, combining edge AI processing with real-time motor control. The system features local speech recognition, conversational AI, and synchronized servo-driven expressions.



\## Technical Architecture



\### Compute Platform

\- \*\*Primary Processor\*\*: Raspberry Pi 5 (8GB) - AI inference and behavior orchestration

\- \*\*Real-time Controller\*\*: ESP32-S3 - Motor control and sensor processing

\- \*\*Communication\*\*: UART serial protocol (115200 baud, JSON)



\### AI Stack

\- \*\*Speech-to-Text\*\*: Whisper Tiny (local inference, \~200ms latency)

\- \*\*Language Model\*\*: Llama 3.2 1B (local inference)

\- \*\*Text-to-Speech\*\*: Piper TTS (local synthesis)



\### Hardware Components

\- 6x MG90S metal gear servos (4-DOF legs, 2-DOF head)

\- 2-inch IPS LCD display (ST7789 driver)

\- MPU6050 6-axis IMU

\- USB microphone array

\- 3W amplified speaker



\## Repository Structure



├── firmware/          ESP32-S3 firmware (C++/PlatformIO)

├── brain/             Raspberry Pi software stack (Python)

├── hardware/          Mechanical designs and schematics

├── docs/              Technical documentation

└── scripts/           Development and deployment tools



\## Documentation



\- System Architecture

\- Communication Protocol

\- Setup Guide



\## License



MIT License

