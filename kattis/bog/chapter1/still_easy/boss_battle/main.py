n = int(input())
a = -2
b = n-3
res = 0
while a+1 < b:
	res += 1
	b += 1
	a += 2
print(max(1, res))
