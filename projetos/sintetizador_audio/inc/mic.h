#ifndef MIC_H
#define MIC_H

#include "pico/stdlib.h"
#include "hardware/dma.h"
#include "hardware/adc.h"

#define MIC_CHANNEL 2
#define MIC_PIN (26 + MIC_CHANNEL)
#define ADC_CLK_DIV 6000
#define SAMPLE_RATE 16000
#define SAMPLES (SAMPLE_RATE * 3)
#define ADC_BIAS 2048

void adc_dma_setup();
void record_mic(uint16_t *adc_buffer);


#endif