import serial
import struct

import numpy as np
import time

ser = serial.Serial(
    port='COM32',
    baudrate=9600)

while True:
    #data = ser.read()
    while True:
        inp = input(":")
        ser.write(inp.encode())
        
        data =ser.read_all()
        print(data.decode(), end ='')
        time.sleep(1)
