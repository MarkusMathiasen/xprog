n = int(input())
s = input()
for i in range(n, 0, -1):
	if i > 2:
		print(f"{i} bottles of {s} on the wall, {i} bottles of {s}.\nTake one down, pass it around, {i-1} bottles of {s} on the wall.\n")
	elif i == 2:
		print(f"2 bottles of {s} on the wall, 2 bottles of {s}.\nTake one down, pass it around, 1 bottle of {s} on the wall.\n")
	else:
		print(f"1 bottle of {s} on the wall, 1 bottle of {s}.\nTake it down, pass it around, no more bottles of {s}.")
	
