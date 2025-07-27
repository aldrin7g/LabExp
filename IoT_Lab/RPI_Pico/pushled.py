from machine import Pin
import utime

# Define LEDs
led1 = Pin(2, Pin.OUT)  
led2 = Pin(3, Pin.OUT)  

button1 = Pin(10, Pin.IN)  
button2 = Pin(11, Pin.IN)  

while True:
    # Check Button 1
    if button1.value() == 1:  
        led1.on()
    else:
        led1.off()

    # Check Button 2
    if button2.value() == 1: 
        led2.on()
    else:
        led2.off()

    utime.sleep_ms(10)  
