import os
import serial
import plotly.graph_objs as go
import plotly


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

def graph_draw(sensor_data):
    data = [
        go.Line(
            x=list(range(len(sensor_data))),
            y=sensor_data
        )
    ]
     
    layout = plotly.graph_objs.Layout(
        title='sleeping_pattern_chart'
    )
     
    figure = plotly.graph_objs.Figure(
        data=data, layout=layout
    )
     
    plotly.offline.plot(
    figure, filename='sleeping_pattern_chart.html'
    )

""" -------------------------------------------
MAIN APPLICATION
"""

COMPORT = input("Enter Port Number: ")

print("Start Serial Monitor")


sensor_data = monitor()
graph_draw(sensor_data)

os.system("Pause")
