import machine
import urequests 
from machine import Pin
import network, time
import utime

header = {'Content-Type': 'application/json'} 
api_key = 'xxxxxxxxxxxxxxx'  

ssid = 'Virus#404'
password = 'password2'

# Configure Pico W as Station
wifi=network.WLAN(network.STA_IF)
wifi.active(True)
wifi.connect(ssid, password)

while not wifi.isconnected():
    print('.', end = '')

print('\nIP:', wifi.ifconfig()) 

trigger = Pin(3, Pin.OUT)
echo = Pin(2, Pin.IN)

def ultra():
    trigger.low()
    utime.sleep_us(2)
    trigger.high()
    utime.sleep_us(5)
    trigger.low()
    while echo.value() == 0:
        signaloff = utime.ticks_us()
    while echo.value() == 1:
        signalon = utime.ticks_us()
    timepassed = signalon - signaloff
    distance = (timepassed * 0.0343) / 2
    # distance = int(distance)
    usreading = {'field1':distance,'field2':(distance/2.54)}
    print("Distance_CM: ",distance,"cm\n")
    print("Distance_IN: ",distance/2.54,"in\n")

    request = urequests.post( 'http://api.thingspeak.com/update?header=' + api_key, json = usreading, headers = header )
    request.close() 

while True:
    ultra()
    utime.sleep(1)