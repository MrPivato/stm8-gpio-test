#ifndef ANALOG_H_
#define ANALOG_H_

#include <stm8s_adc1.h>

#define ADC_READ_TO_VOLTS_SCALAR (5.0 / 1023.0)

#define ANALOG_A_PORT GPIOC
#define ANALOG_A_PIN GPIO_PIN_4
#define ANALOG_A_MODE GPIO_MODE_IN_FL_NO_IT

#define ANALOG_B_PORT GPIOD
#define ANALOG_B_PIN GPIO_PIN_2
#define ANALOG_B_MODE GPIO_MODE_IN_FL_NO_IT

#define ANALOG_C_PORT GPIOD
#define ANALOG_C_PIN GPIO_PIN_3
#define ANALOG_C_MODE GPIO_MODE_IN_FL_NO_IT

typedef struct Analog_struct {
  GPIO_TypeDef *gpioPort;
  GPIO_Pin_TypeDef gpioPin;
  GPIO_Mode_TypeDef gpioMode;
  ADC1_Channel_TypeDef ADC1_Channel;
  ADC1_SchmittTrigg_TypeDef ADC1_SchmittTriggerChannel;
  uint16_t rawValue;
} Analog_t;

void Analog_init();
void Analog_setup(Analog_t *analog);
uint16_t Analog_read(Analog_t *analog);
uint16_t Analog_readingToVolts(uint16_t reading);

#endif /* ANALOG_H_ */
