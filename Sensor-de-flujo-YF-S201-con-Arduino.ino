/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  WEB https://www.proyecto-teos.com
*/

volatile uint32_t sensorPulsesT;
uint32_t litersPerHourT;
const uint16_t pinFlowSensorT = 2, intervalT = 1000, pulsesPerLiterT = 403;
unsigned long previousMillisT, accumulatedPulsesT;
String resultSerialT;
float litersT;

void flowISRT() {
  sensorPulsesT++;
}

void setup() {
  pinMode(pinFlowSensorT, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(pinFlowSensorT), flowISRT, RISING);
  interrupts();
  previousMillisT = millis();
}

void loop() {
  if (millis() - previousMillisT > intervalT) {
    accumulatedPulsesT += sensorPulsesT;
    litersPerHourT = (sensorPulsesT * 60 / 6.67);
    sensorPulsesT = 0;
    litersT = accumulatedPulsesT * 1.0 / pulsesPerLiterT;
    resultSerialT = "Litros acumulados: " + String(litersT);
    Serial.println(resultSerialT);
    previousMillisT = millis();
  }
}
