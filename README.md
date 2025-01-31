add ssid and password to "Spresense_sender.ino" line 19,20 and upload 

#define SSID "ssid"
#define PASS "pass"

read serial monitor and check IP

replace that IP  "spresense_receiver.py" line 11 >> 
SPRESENSE_IP = "http://192.168.0.235/cam.jpg"

