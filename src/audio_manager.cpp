// CONTROLS MIC INPUT/OUPUT USING THE VIA I2S. COMPLETE PROGRAM FLOW WITH VOICE INPUT/OUPUT
#include "audio_manager.h"
#include <driver/i2s.h>

// I2S Port Numbers
#define I2S_PORT_MIC I2S_NUM_0
#define I2S_PORT_SPK I2S_NUM_1

// set up microphone to set up audio
void initMicrophone(int wsPin, int sckPin, int sdPin)
{

    // How the microphone should work
    i2s_config_t i2s_config_mic = {
        // config_t is the type and confg_mic is the variable
        .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX), // .Mode is how should I2S operate MASTER: ESP32 is the boss nand RX: Receive mode (Audio input)
        .sample_rate = 16000,                                // Sample rate must be 2X the highest frequency, Human voice frequency is 85-255Hz.
        .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,        // 16Bits = 65,536 possibel volume values more bits means better quality but at the same time more memory 8 and 24 bits would be way too short or long.
        .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,         // use only left channel(mono audio) Stereo has 2channels we have 1 Mic INM441 is mono we tell the ESP to ignore the right channel.
        .communication_format = I2S_COMM_FORMAT_STAND_I2S,   // Use the standard I2S protocol for comm STAND is the most common one used in INMP441 & MAX98357A.
        .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,            // Innterrupt priority to level 1 ESP32 needs to stop doing what it's doing and handle it tells CPU to handle this now level-1(medium priority not urgent but not important)
        .dma_buf_count = 8,                                  // Number of buffers in the DMA buffer pool. More buffers can help prevent data loss but also use more memory.
        .dma_buf_len = 64,                                   // Size of each buffer in the DMA buffer pool. Larger buffers can hold more data but also increase latency.
        .use_apll = false,                                   // Whether to use the Audio PLL for clock generation. APLL can provide more accurate clock but may consume more power.
    };
    i2s_pin_config_t pin_config_mic = {
        .bck_io_num = sckPin,
        .ws_io_num = wsPin,
        .data_out_num = -1,
        .data_in_num = sdPin};
    i2s_driver_install(I2S_PORT_MIC, &i2s_config_mic, 0, NULL);
    i2s_set_pin(I2S_PORT_MIC, &pin_config_mic);

    Serial.println("Microphone initialized");
}

void initSpeaker(int bclkPin, int lrcPin, int dinPin)
{

    i2s_config_t i2s_config_spk = {
        .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
        .sample_rate = 16000,
        .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
        .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
        .communication_format = I2S_COMM_FORMAT_STAND_I2S,
        .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
        .dma_buf_count = 8,
        .dma_buf_len = 64,
        .use_apll = false};

    i2s_pin_config_t pin_config_spk = {
        .bck_io_num = bclkPin,
        .ws_io_num = lrcPin,
        .data_out_num = dinPin,
        .data_in_num = -1};

    i2s_driver_install(I2S_PORT_SPK, &i2s_config_spk, 0, NULL);
    i2s_set_pin(I2S_PORT_SPK, &pin_config_spk);

    Serial.println("Speaker initialized");
}
