from machine import Pin, time_pulse_us
import utime
import network
import urequests

# WiFi Credentials
SSID = "Your_WiFi_SSID"
PASSWORD = "Your_WiFi_Password"

# ThingSpeak API
THINGSPEAK_API_KEY = "Your_ThingSpeak_API_Key"
THINGSPEAK_URL = "https://api.thingspeak.com/update"

# Initialize Ultrasonic Sensor (TRIG=GP3, ECHO=GP2)
trigger = Pin(3, Pin.OUT)
echo = Pin(2, Pin.IN)

# Connect to WiFi
wlan = network.WLAN(network.STA_IF)
wlan.active(True)
wlan.connect(SSID, PASSWORD)

print("Connecting to WiFi...", end="")
while not wlan.isconnected():
    print(".", end="")
    utime.sleep(1)
print("\nConnected to WiFi!")

# Function to measure distance
def get_distance():
    trigger.low()
    utime.sleep_us(2)
    trigger.high()
    utime.sleep_us(10)
    trigger.low()
    
    duration = time_pulse_us(echo, 1, 30000)  # Max wait 30ms
    if duration < 0:
        return None, None  # Timeout case
    
    distance_cm = (duration * 0.0343) / 2
    distance_in = distance_cm * 0.3937  # Convert cm to inches
    return round(distance_cm, 2), round(distance_in, 2)

# Send data to ThingSpeak
def send_to_thingspeak(cm, inches):
    url = f"{THINGSPEAK_URL}?api_key={THINGSPEAK_API_KEY}&field1={cm}&field2={inches}"
    try:
        response = urequests.get(url)
        print("ThingSpeak Response:", response.text)
        response.close()
    except Exception as e:
        print("Error sending data:", e)

# Main loop
while True:
    cm, inches = get_distance()
    if cm is not None:
        print(f"Distance: {cm} cm | {inches} inches")
        send_to_thingspeak(cm, inches)
    else:
        print("Sensor timeout!")
    utime.sleep(15)  # ThingSpeak allows updates every 15 sec
