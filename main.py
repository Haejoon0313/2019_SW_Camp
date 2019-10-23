import os, serial

COMPORT = ''
BAUDRATE = 9600

raw_data=""
data=[]

def monitor():
    global raw_data
    global data
    ser = serial.Serial(COMPORT, BAUDRATE, timeout=0)

    try:
        while(True):
            line=ser.read()
            if(len(line)>0):
                raw_data = raw_data + str(line)[2:-1]
                if(raw_data[-1] == 'n'):
                    raw_data=raw_data[0:-4]
                    data.append(int(raw_data))
                    raw_data=""
    except KeyboardInterrupt:
        return data



""" -------------------------------------------
MAIN APPLICATION
"""

COMPORT = input("Enter Port Number: ")

print("Start Serial Monitor")


sensor_data = monitor()
print(sensor_data)

os.system("Pause")
