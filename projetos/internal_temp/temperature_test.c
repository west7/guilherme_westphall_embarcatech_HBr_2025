#include "unity.h"
#include "internal_temp.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void spec_adc_2_celsius(void)
{
    float temperature = adc_2_celsius(876);
    TEST_ASSERT_FLOAT_WITHIN(0.5, 27.0, temperature);
}

int main()
{
    UNITY_BEGIN();

    RUN_TEST(spec_adc_2_celsius);

    return UNITY_END();
}