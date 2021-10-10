n, m, s, d = map(int, input().split())
f = [int(x) for x in input().split()]
ans = [0] * s
coolSoda = sum(f)

while n > 0:
	mi = f.index(min(f))
	ans[mi] += min(d-f[mi], n)
	n -= min(d-f[mi], n)
	if f[mi] == d:
		break
	coolSoda -= f[mi]
	f[mi] = d
if coolSoda >= m:
	for soda in ans:
		print(soda, end=" ")
	print()
else:
	print("impossible")
