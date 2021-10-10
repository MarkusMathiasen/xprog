res = 0
for i in range(1, 1001):
	res += i**i
	res %= 10000000000
print(res)
