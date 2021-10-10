n = int(input())
x = 1
possible = True
for b in map(int, input().split()):
	x *= 2
	x -= b
	possible &= x >= 0
if possible:
	print(x%1000000007)
else:
	print("error")
