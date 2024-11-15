#!/usr/bin/env /usr/bin/python3
# --------------------------------------------------------------------------- #
# import the various client implementations
# --------------------------------------------------------------------------- #
import pymodbus.client as ModbusClient
from pymodbus import (
    ExceptionResponse,
    FramerType,
    ModbusException,
    pymodbus_apply_logging_config,
)

if __name__ == "__main__":
    # activate debugging
#    pymodbus_apply_logging_config("DEBUG")

    client = ModbusClient.ModbusSerialClient(
        port='/dev/serial/by-id/usb-1a86_USB2.0-Serial-if00-port0',
#        framer=framer,
        timeout=1,
        retries=3,
        baudrate=9600,
        bytesize=8,
        parity="E",
        stopbits=1,
        handle_local_echo=False,
    )
    
    print ("connecting")
    client.connect()

    print ("read holding registers")
    try:
        holding_regs = client.read_holding_registers(0, 2, slave=1)
    except ModbusException as exc:
        print(f"Received ModbusException({exc}) from library")
    if holding_regs.isError():
        print(f"Received Modbus library error({holding_regs})")
    elif isinstance(holding_regs, ExceptionResponse):
        print(f"Received Modbus library exception ({holding_regs})")
        # THIS IS NOT A PYTHON EXCEPTION, but a valid modbus message
    else:
        print (holding_regs.registers)

    print ("close connection")
    client.close()


