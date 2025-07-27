import machine
import urequests 
from machine import Pin
import network, time
import utime

HTTP_HEADERS = {'Content-Type': 'application/json'} 
THINGSPEAK_WRITE_API_KEY = 'YFARKCD869VFA86U'  

ssid = 'Virus#404'
password = 'password2'

# Configure Pico W as Station
sta_if=network.WLAN(network.STA_IF)
sta_if.active(True)

if not sta_if.isconnected():
    print('connecting to network...')
    sta_if.connect(ssid, password)
    while not sta_if.isconnected():
        pass
print('network config:', sta_if.ifconfig()) 

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
    distance = int(distance)
    usreading = {'field1':distance,'field2':(distance/2.54)}
    print("The distance from object is ",distance,"cm\n")
    print("The distance from object is ",distance/2.54,"in\n")

    request = urequests.post( 'http://api.thingspeak.com/update?api_key=' + THINGSPEAK_WRITE_API_KEY, json = usreading, headers = HTTP_HEADERS )
    request.close() 
while True:
    ultra()
    utime.sleep(1)