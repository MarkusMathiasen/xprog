def fifth(x):
	num = x
	digets = []
	while x > 0:
		digets += [x % 10]
		x //= 10
	return sum([i**5 for i in digets]) == num

res = 0
for i in range(2, 1000000):
	if fifth(i):
		res += i
		print(i)
print("res: ", res)
