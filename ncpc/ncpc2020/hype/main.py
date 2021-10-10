import math

n = int(input())
a = b = c = 0
for k in input().split():
	k = int(k)
	if k == 1:
		a += 1
	if k == 2:
		b += 1
	if k == 3:
		c += 1
print(a * math.factorial(b)
