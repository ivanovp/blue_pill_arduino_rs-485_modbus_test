#include <Arduino.h>
#include <ModbusRTUSlave.h>

#define LED_PIN                 PC13

/* PA0 .. PA7 cannot be used as their index becomes a negative number when
 * converted to int8_t!
 */
#define RS485_DIR_PIN           PB7

//                         RX    TX
HardwareSerial SerialRS485(PA3, PA2);

#define MODBUS_BAUD     9600
#define MODBUS_CONFIG   SERIAL_8E1
#define MODBUS_UNIT_ID  1

ModbusRTUSlave modbus(SerialRS485, RS485_DIR_PIN);

const uint8_t numCoils = 2;
const uint8_t numDiscreteInputs = 2;
const uint8_t numHoldingRegisters = 2;
const uint8_t numInputRegisters = 2;

bool coils[numCoils] = { false, false };
bool discreteInputs[numDiscreteInputs] = { true, true };
uint16_t holdingRegisters[numHoldingRegisters] = { 1234, 5678 };
uint16_t inputRegisters[numInputRegisters] = { 9876, 5432 };

void setup()
{
    Serial.begin(115200);
    Serial.print("\n\n\n");
    Serial.print("Blue Pill RS-485 ModBus slave started\n");
    Serial.print("Compiled on " __DATE__ " " __TIME__ "\n");

    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
    pinMode(RS485_DIR_PIN, OUTPUT);
    digitalWrite(RS485_DIR_PIN, LOW);

    modbus.configureCoils(coils, numCoils);
    modbus.configureDiscreteInputs(discreteInputs, numDiscreteInputs);
    modbus.configureHoldingRegisters(holdingRegisters, numHoldingRegisters);
    modbus.configureInputRegisters(inputRegisters, numInputRegisters);

    SerialRS485.begin(MODBUS_BAUD, MODBUS_CONFIG);
    modbus.begin(MODBUS_UNIT_ID, MODBUS_BAUD, MODBUS_CONFIG);

    Serial.print("Initialized\n");
}

void loop()
{
  modbus.poll();
}
