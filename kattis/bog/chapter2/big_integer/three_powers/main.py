while True:
	n = int(input())
	if n == 0:
		break
	n -= 1
	print("{", end='')
	x = 1
	first = True
	while n > 0:
		if n%2 == 1:
			if not first:
				print(",", end='')
			print(" " + str(x), end='')
			first = False
		n //= 2
		x *= 3
	print(" }")
