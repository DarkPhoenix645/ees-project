from machine import Pin, ADC, UART
import time
import utime
import bluetooth
from ble_simple_peripheral import BLESimplePeripheral

# Creating the Bluetooth Low Energy (BLE) object
ble = bluetooth.BLE()
sp = BLESimplePeripheral(ble)
adc = ADC(4)

uart = UART(1, baudrate=9600, tx=Pin(4), rx=Pin(5))
uart.init(bits=8, parity=None, stop=2)

while True:
    # Transmission of 's' character ignifies start of communication:
    uart.write('t')
    if sp.is_connected():
        if uart.any(): 
            data = uart.read() 
            if data:
                print(data)
                sp.send(data)
             
    time.sleep(1)