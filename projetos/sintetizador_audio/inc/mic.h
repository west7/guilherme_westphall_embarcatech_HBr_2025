#ifndef MIC_H
#define MIC_H

#include "pico/stdlib.h"
#include "hardware/dma.h"
#include "hardware/adc.h"

#define MIC_CHANNEL 2
#define MIC_PIN (26 + MIC_CHANNEL)
#define ADC_CLK_DIV 6000
#define SAMPLE_RATE 8000
#define SAMPLES (SAMPLE_RATE * 5)

void adc_dma_setup();
/* void record_mic(uint16_t *adc_buffer);
*/
void record_mic_start(uint16_t *adc_buffer);
bool record_mic_is_finished();
void record_mic_stop();

#endif