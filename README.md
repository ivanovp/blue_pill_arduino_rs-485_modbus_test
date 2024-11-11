# blue_pill_arduino_rs-485_modbus_test
This is a simple Modbus device which uses Blue Pill (STM32F103) development board and Arduino framework.
Two registers can be read from this device, register #0 and #1, they contain 1234 and 5678.
Baud rate 9600, 8 data bits, even parity, 1 stop bit. Device address is 1.

Schematic:
![Schematic](https://github.com/ivanovp/blue_pill_arduino_rs-485_modbus_test/blob/master/hardware/blue_pill_rs-485_bb.png?raw=true)

Bill of Materials:

Blue Pill (STM32F103C8, 64KiB flash):
https://www.hestore.hu/prod_10043289.html

Blue Pill (STM32F103C6, 32KiB flash):
https://pepita.hu/muszaki-cikk-elektronika-outlet-c6343/stm32f103c6t6-mikrokontroller-fejleszto-modul-p10464316

ST-Link V2:
https://www.hestore.hu/prod_10037590.html

