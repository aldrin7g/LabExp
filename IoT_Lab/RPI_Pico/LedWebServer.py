import network
import socket
from machine import Pin

# Define three LEDs
led1 = Pin(2, Pin.OUT)  # GPIO2
led2 = Pin(3, Pin.OUT)  # GPIO3
led3 = Pin(4, Pin.OUT)  # GPIO4

# Wi-Fi credentials
ssid = "Virus#404"
password = "password2"

# Connect to Wi-Fi
wifi = network.WLAN(network.STA_IF)
wifi.active(True)
wifi.connect(ssid, password)

while not wifi.isconnected():
    print('.', end = '')

print("\nIP: ", wifi.ifconfig()[0])

def control_leds(state):
    led1.value(state)
    led2.value(state)
    led3.value(state)

html = """
<!DOCTYPE html>
<html>
    <a href="/on"><button>Turn ON LEDs</button></a>
    <a href="/off"><button>Turn OFF LEDs</button></a>
</html>
"""

s = socket.socket()
s.bind(("", 80))
s.listen(1)

while True:
    conn, _ = s.accept()
    request = conn.recv(1024).decode()
    
    if "/on" in request:
        control_leds(1)
    elif "/off" in request:
        control_leds(0)
    
    conn.send("HTTP/1.1 200 OK\nContent-Type: text/html\n\n" + html)
    conn.close()