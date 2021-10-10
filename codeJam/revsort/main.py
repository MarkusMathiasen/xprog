T = int(input())
for t in range(1, T+1):
	N = int(input())
	L = [int(i) for i in input().split()]
	res = 0
	for i, k in enumerate(sorted(L)):
		pos = L.index(k)
		res += pos+1-i
		L = L[:i] + list(reversed(L[i:pos+1])) + L[pos+1:]
	print(f"Case #{t}:", res-1)
