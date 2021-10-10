rooms = int(input())
teams = int(input())
for i in range(rooms):
	if i < teams % rooms:
		print("*"*((teams//rooms)+1))
	else:
		print("*"*(teams//rooms))
