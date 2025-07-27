from machine import Pin, PWM
import utime

# Define LED with PWM on GP15
led = PWM(Pin(15))
led.freq(1000)  # Set PWM frequency to 1kHz

while True:
    # Fade In (0 to 255)
    for duty in range(0, 256, 5):  # Increase brightness
        led.duty_u16(duty * 256)  
        utime.sleep(0.05)         

    # Fade Out (255 to 0)
    for duty in range(255, 0, -5):  # Decrease brightness
        led.duty_u16(duty * 256)     
        utime.sleep(0.05)
