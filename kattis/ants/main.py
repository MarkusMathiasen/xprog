t = int(input())
while t :
	l, n = map(int, input().split())
	A = []
	while len(A) < n:
		A += [int(i) for i in input().split()]
	low = 0
	high = 0
	for i in A:
		low = max(low, min(i, l-i))
		high = max(high, i, l-i)
	print(low, high)
	t -= 1
