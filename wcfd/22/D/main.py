n, m = map(int, input().split())
drinks = [input() for _ in range(n)]
d = {}
for _ in range(m):
	person = input()
	if not person in d:
		d[person] = 0
	print(drinks[d[person]])
	d[person] += 1
