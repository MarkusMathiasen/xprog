n = int(input())
count = 0
times = set()

def ev(s):
	if s == "*":
		return list(range(0, 60))
	vals = s.split(",")
	res = []
	for v in vals:
		if v.find("-") == -1:
			res += [int(v)]
		else:
			two = v.split("-")
			res += list(range(int(two[0]), int(two[1])+1))
	return res

for _ in range(n):
	h, m, s = input().split()
	hours = []
	if h == "*":
		hours = list(range(0, 24))
	else:
		hours = ev(h)
	minutes = ev(m)
	seconds = ev(s)
	for a in hours:
		for b in minutes:
			for c in seconds:
				count += 1
				times.add((a, b, c))
print(len(times), count)
