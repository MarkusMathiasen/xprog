n = int(input())
days = [int(d) for d in input().split()]
d, t = -1, 100
for i in range(n-2):
	nt = max(days[i], days[i+2])
	if nt < t:
		t = nt
		d = i
print(d+1, t)
