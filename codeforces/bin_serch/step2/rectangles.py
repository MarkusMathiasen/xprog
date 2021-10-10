w, h, n = map(int, input().split())
lower = 0
upper = int(1e14)
while (lower < upper):
	mid = (lower + upper) // 2
	if (mid//w) * (mid//h) < n:
		lower = mid+1
	else:
		upper = mid
print(lower)
