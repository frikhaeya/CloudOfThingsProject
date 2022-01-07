
These scipts will be launched automatically when giving the Rasberry Pi power.
  
  They are meant to:
  
    - Run the mosquitto broker on the Raspberry Pi through this command:
             sudo mosquitto -v -c /usr/share/doc/mosquitto/examples/mosquitto.conf
             
    - mosquitto_pub to create and launch the MQTT publisher ( We are collecting the data from the sensors and sending it to the "BROKER" so it can be sent to all the subscribers ).
    
      This will be garuanteed with the SerialCom.py running ( Task that we automated and will be launched directly when giving the Raspberry pi power ).
      
      Some of the steps that we have to deal with so that we decided to automated the task are:
           - Finding the right port
           - giving the concerned port the rights to execute such a file : sudo chmod 777 /dev/ttyACM0
           - Killing the process already in use from the last broker : ps -ef | grep mosquitto
           - Launching the commands : python3 serialCom.py
    - mosquitto_sub on my pc / localhost machine so that it can be a client that will subscribe to topics and print the messages that it receives.
             
 Requirements for these tasks:
   - sudo apt-get install -y mosquitto mosquitto-clients
   - sudo pip install paho-mqtt
