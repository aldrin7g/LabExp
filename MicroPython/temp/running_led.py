import time
from machine import Pin

led1=Pin(2,Pin.OUT)
led2=Pin(3,Pin.OUT)
led3=Pin(4,Pin.OUT) #create LED object from pin13,Set Pin13 to output

while True:

  led1.value(1)            #Set led turn on
  time.sleep(0.5)
  led1.value(0)            #Set led turn off
  time.sleep(0.5)
  
  led2.value(1)            #Set led turn on
  time.sleep(0.5)
  led2.value(0)            #Set led turn off
  time.sleep(0.5)
  
  led3.value(1)            #Set led turn on
  time.sleep(0.5)
  led3.value(0)            #Set led turn off
  time.sleep(0.5)