import time
from machine import Pin

led1=Pin(2,Pin.OUT)
led2=Pin(3,Pin.OUT)
led3=Pin(4,Pin.OUT)

while True:
    led1.value(1)            
    led2.value(1)           
    led3.value(1)           
    time.sleep(0.5)

    led1.value(0)            
    led2.value(0)           
    led3.value(0)           
    time.sleep(0.5)