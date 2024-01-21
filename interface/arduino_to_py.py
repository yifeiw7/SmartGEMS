import serial
import time

    
def read():
	ser = serial.Serial(
		port='/dev/cu.usbmodem1101',
		baudrate=9600,
		parity=serial.PARITY_NONE,
		stopbits=serial.STOPBITS_ONE,
		bytesize=serial.EIGHTBITS,
	)


	data = ser.readline().decode('utf-8').strip()
	data = data.split(',')
	for i in range(len(data)):
		if data[i] != '':
			data[i] = int(data[i])

	print(data)

	return [{'Temperature': data[0],
		   	 'Water_Height': data[1],
			 'Moisture_Level': data[2],
			 'Wind': data[3],
			 'Light_In': data[4]}]

read()
