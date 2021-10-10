n = int(input())
upper = 10
lower = 0
while upper-lower > 1e-8:
	m = (upper + lower) / 2
	if (m**m > n):
		upper = m
	else:
		lower = m
print(lower)

