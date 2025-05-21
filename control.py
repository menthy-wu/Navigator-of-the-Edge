import serial
import time
from pynput import keyboard

arduino = serial.Serial(
    port = '/dev/cu.usbmodem11101',  # change this to your computer usb port
    baudrate = 9600,
    bytesize=serial.EIGHTBITS,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    timeout=5,
    xonxoff=False,
    rtscts=False,
    dsrdtr=False,
    write_timeout=2
)

def on_press(key):
    try:
        if(key == keyboard.Key.left):
            arduino.write("LEFT|".encode())
            print("LEFT")
        elif(key == keyboard.Key.right):
            arduino.write("RIGHT|".encode())
            print("RIGHT")
        elif(key == keyboard.Key.up):
            arduino.write("FORWARD|".encode())
            print("FORWARD")
        elif(key == keyboard.Key.down):
            arduino.write("BACKWARD|".encode())
            print("BACKWARD")
    except AttributeError:
        print('special key {0} pressed'.format(
            key))

def on_release(key):
    arduino.write("STOP|".encode())
    print("STOP")

# Collect events until released
with keyboard.Listener(
        on_press=on_press,
        on_release=on_release) as listener:
    listener.join()

listener = keyboard.Listener(
    on_press=on_press,
    on_release=on_release)
listener.start()
