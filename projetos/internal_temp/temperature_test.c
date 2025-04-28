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
    TEST_ASSERT_FLOAT_WITHIN(0.5, 30.0, adc_2_celsius(876));
}

int main()
{
    UNITY_BEGIN();

    RUN_TEST(spec_adc_2_celsius);

    return UNITY_END();
}