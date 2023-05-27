#include "state.h"

State_t boardLed = {BOARD_LED_PORT, BOARD_LED_PIN, BOARD_LED_MODE};
State_t externalLed = {EXTERNAL_LED_PORT, EXTERNAL_LED_PIN, EXTERNAL_LED_MODE};
State_t upButton = {UP_BUTTON_PORT, UP_BUTTON_PIN, UP_BUTTON_MODE};
State_t enableButton = {ENABLE_BUTTON_PORT, ENABLE_BUTTON_PIN, ENABLE_BUTTON_MODE};
State_t downButton = {DOWN_BUTTON_PORT, DOWN_BUTTON_PIN, DOWN_BUTTON_MODE};

void State_init(){
  State_setup(&boardLed);
  State_setup(&externalLed);
  State_setup(&upButton);
  State_setup(&enableButton);
  State_setup(&downButton);
}

void State_setup(State_t *state){
  GPIO_Init(state->gpioPort, state->gpioPin, state->gpioMode);
}

void State_setValue(State_t *state, bool value){
  state->value = value;

  if (state->value)
    state->gpioPort->ODR |= (uint8_t)state->gpioPin;
  else
    state->gpioPort->ODR &= (uint8_t)(~state->gpioPin);
}

bool State_readValue(State_t *state){
  state->value = ((BitStatus)(state->gpioPort->IDR & (uint8_t)state->gpioPin));
  return state->value;
}
