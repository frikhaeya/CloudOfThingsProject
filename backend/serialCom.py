
#!/usr/bin/env python3
import serial
import paho.mqtt.client as paho

broker="127.0.0.1"
port=1883

def publish(client,topic,msg):
    client.publish(topic,msg)
def subscribe(client,topic):
    client.subscribe(topic)
def connect(broker,port):
    clt=paho.Client("client0")
    clt.connect(broker,port)
    return clt

if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyACM0',9600,timeout=1)
    ser.reset_input_buffer();clt=connect(broker,port)
    while True:
    	if (ser.in_waiting > 0):
    	    line = ser.readline().decode('utf-8').rstrip()
    	    print(line);publish(clt,"test",line)
