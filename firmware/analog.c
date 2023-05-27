#include "analog.h"

Analog_t analogA = {
    ANALOG_A_PORT,
    ANALOG_A_PIN,
    ANALOG_A_MODE,
    ADC1_CHANNEL_2,
    ADC1_SCHMITTTRIG_CHANNEL3,
};

Analog_t analogB = {
    ANALOG_B_PORT,
    ANALOG_B_PIN,
    ANALOG_B_MODE,
    ADC1_CHANNEL_3,
    ADC1_SCHMITTTRIG_CHANNEL3,
};

Analog_t analogC = {
    ANALOG_C_PORT,
    ANALOG_C_PIN,
    ANALOG_C_MODE,
    ADC1_CHANNEL_4,
    ADC1_SCHMITTTRIG_CHANNEL4,
};
void Analog_init() {
  ADC1_DeInit();
  Analog_setup(&analogA);
  Analog_setup(&analogB);
  Analog_setup(&analogC);

  ADC1->CR1 |= ADC1_CR1_ADON; // ADC1 Enable
}

void Analog_setup(Analog_t *analog) {
  GPIO_Init(analog->gpioPort, analog->gpioPin, analog->gpioMode);
  ADC1_Init(ADC1_CONVERSIONMODE_CONTINUOUS,
	    analog->ADC1_Channel,
	    ADC1_PRESSEL_FCPU_D18,
	    ADC1_EXTTRIG_GPIO,
	    DISABLE,
	    ADC1_ALIGN_RIGHT,
	    analog->ADC1_SchmittTriggerChannel,
	    DISABLE
  );
}

uint16_t Analog_read(Analog_t *analog) {
  ADC1->CR2 |= ADC1_CR2_SCAN;
  ADC1->CR1 |= ADC1_CR1_ADON; // ADC1 Enable
  ADC1->CSR = analog->ADC1_Channel;

  while(ADC1_GetFlagStatus(ADC1_FLAG_EOC) == FALSE);
  ADC1_ClearFlag(ADC1_FLAG_EOC);

  analog->rawValue = ADC1_GetBufferValue(analog->ADC1_Channel);

  return analog->rawValue;
}

uint16_t Analog_readingToVolts(uint16_t reading) {
  return (uint16_t)(reading * ADC_READ_TO_VOLTS_SCALAR);
}
