#ifndef STATE_H_
#define STATE_H_

#include <stm8s_gpio.h>

#define BOARD_LED_PORT GPIOC
#define BOARD_LED_PIN GPIO_PIN_7
#define BOARD_LED_MODE GPIO_MODE_OUT_PP_HIGH_SLOW

#define EXTERNAL_LED_PORT GPIOC
#define EXTERNAL_LED_PIN GPIO_PIN_6
#define EXTERNAL_LED_MODE GPIO_MODE_OUT_PP_HIGH_SLOW

#define UP_BUTTON_PORT GPIOD
#define UP_BUTTON_PIN GPIO_PIN_4
#define UP_BUTTON_MODE GPIO_MODE_IN_FL_NO_IT

#define ENABLE_BUTTON_PORT GPIOD
#define ENABLE_BUTTON_PIN GPIO_PIN_5
#define ENABLE_BUTTON_MODE GPIO_MODE_IN_FL_NO_IT

#define DOWN_BUTTON_PORT GPIOD
#define DOWN_BUTTON_PIN GPIO_PIN_6
#define DOWN_BUTTON_MODE GPIO_MODE_IN__NO_IT

typedef struct State_struct
{
  GPIO_TypeDef *gpioPort;
  GPIO_Pin_TypeDef gpioPin;
  GPIO_Mode_TypeDef gpioMode;
  bool value;

} State_t;

void State_init();
void State_setup(State_t *state);
void State_setValue(State_t *state, bool value);
bool State_readValue(State_t *state);

#endif /* STATE_H_ */
