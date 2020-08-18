//
// By Zach Fox
// https://github.com/zfox23/LogitechPedalsToRudder
//

#include "Joystick.h"

Joystick_ Joystick(
  JOYSTICK_DEFAULT_REPORT_ID, // uint8_t hidReportId
  JOYSTICK_TYPE_JOYSTICK, // uint8_t joystickType
  0, // uint8_t buttonCount
  0, // uint8_t hatSwitchCount
  false, // bool includeXAxis
  false, // bool includeYAxis
  false, // bool includeZAxis
  false, // bool includeRxAxis
  false, // bool includeRyAxis
  false, // bool includeRzAxis
  true, // bool includeRudder
  false, // bool includeThrottle
  false, // bool includeAccelerator
  false, // bool includeBrake
  false // bool includeSteering
);

const int numSamples = 3;
int currentIndex;

int smoothedClutchPedalValue = 0;
int clutchPedalValues[numSamples];

int smoothedAcceleratorPedalValue = 0;
int acceleratorPedalValues[numSamples];

const bool initAutoSendState = true;

void setup() {
  Joystick.begin();
  Joystick.setRudderRange(-1000, 1000);
}

float average(int* array, int len) {
  long sum = 0L;
  for (int i = 0; i < len; i++) {
    sum += array[i];
  }
  return ((float) sum) / len;
}

void loop() {
  clutchPedalValues[currentIndex] = analogRead(A0); // From (0, 1023);
  acceleratorPedalValues[currentIndex] = analogRead(A2); // From (0, 1023);
  currentIndex = currentIndex + 1;

  if (currentIndex >= numSamples) {
    currentIndex = 0;
  }

  smoothedClutchPedalValue = average(clutchPedalValues, numSamples);
  smoothedAcceleratorPedalValue = average(acceleratorPedalValues, numSamples);

  Joystick.setRudder(smoothedClutchPedalValue - smoothedAcceleratorPedalValue);

  delay(50);
}
