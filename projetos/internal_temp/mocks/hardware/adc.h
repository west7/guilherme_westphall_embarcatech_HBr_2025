#ifndef MOCK_HARDWARE_ADC_H
#define MOCK_HARDWARE_ADC_H

#include <stdbool.h>
#include <stdint.h>

#define ADC_TEMPERATURE_CHANNEL_NUM 4

static inline void adc_init() {}
static inline void adc_set_temp_sensor_enabled(bool enable) {}
static inline void adc_select_input(int channel) {}
static inline uint16_t adc_read() { return 876; } // valor simulado de ADC

#endif // MOCK_HARDWARE_ADC_H
