import serial
import time

def extract_numbers(input_string, delimiter=" "):
    numbers = [int(num) for num in input_string.split(delimiter) if num.isdigit()]
    if numbers != []:
        return numbers
    
def read():

	ser = serial.Serial(
		port='/dev/cu.usbmodem101',
		baudrate=9600,
		parity=serial.PARITY_NONE,
		stopbits=serial.STOPBITS_ONE,
		bytesize=serial.EIGHTBITS,
		timeout=0.1
	)

	numeric_data_list = []
	count = 1

	while True:
		data = ser.readline().decode('utf-8').strip()
		if data:
			values = data.split(',')
			for value in values:
				k = extract_numbers(value)
				if k != None:
					numeric_data_list.append(k[0])
			count += 1

		if count >= 5:  # Change 10 to the desired number of readings
			break
		time.sleep(0.03)

	return [{'Temperature': numeric_data_list[4],
		   	 'Water_Height': numeric_data_list[1],
			 'Moisture_Level': numeric_data_list[2],
			 'Wind': numeric_data_list[5],
			 'Light_In': numeric_data_list[0]}]
