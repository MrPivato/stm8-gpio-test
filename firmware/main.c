#include <stm8s.h>

#include "state.h"
extern State_t boardLed;
extern State_t externalLed;
extern State_t upButton;
extern State_t enableButton;
extern State_t downButton;

#include "analog.h"
extern Analog_t analogA;
extern Analog_t analogB;
extern Analog_t analogC;

void assert_failed(uint8_t* file, uint32_t line) {
  (void)file;
  (void)line;
}

void main(void)
{
  Analog_init();
  State_init();

  while(1) {
      State_readValue(&upButton);
      State_readValue(&enableButton);
      State_readValue(&downButton);

      State_setValue(&externalLed, upButton.value);
      State_setValue(&boardLed, downButton.value);

      Analog_read(&analogA);
      Analog_read(&analogB);
      Analog_read(&analogC);
  }
}
