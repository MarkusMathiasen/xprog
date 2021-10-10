import time
from playsound import playsound

timetal = int(input("Timetal for alarm: "))
minuttal = int(input("Minuttal for alarm: "))
sekundtal = int(input("Sekundtal for alarm: "))

alarm = False

while not alarm:
	timeNu = (int(time.strftime("%H", time.localtime())) - 2) % 24
	minutNu = int(time.strftime("%M", time.localtime()))
	sekundNu = int(time.strftime("%S", time.localtime()))
	alarm = timetal == timeNu and minuttal == minutNu and sekundtal == sekundNu

	print(timeNu, ":", minutNu, ":", sekundNu)
	time.sleep(1)
playsound('alarm.mp3')
