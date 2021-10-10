p = int(input())
for _ in range(p):
	t, f = input().split()
	a, b = map(int, f.split("/"))
	l = []
	while (a != 1 or b != 1):
		if a < b:
			b -= a
			l += [0]
		else:
			a -= b
			l += [1]
	res = 1
	for i in reversed(l):
		if i == 0:
			res *= 2
		else:
			res = res*2 + 1
	print(t, res)
