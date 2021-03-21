import serial
import json
import requests
ser = serial.Serial('COM3', baudrate=9600, timeout=2)  # настройка порта


class COMPORTREAD():
    while 1:
        arduinoData = ser.readline()
        arduinoData = arduinoData.decode('utf-8')
        print(arduinoData)
        if (arduinoData != ""):
            parsed = json.loads(arduinoData)
            get_params = {
                "dat1": parsed[0],
                "dat2": parsed[1],
                "dat3": parsed[2]
            }
            r = requests.get('http://localhost/addtodb.php', params=get_params)
            print(r.text)
