s, t, n = map(int, input().split())
d = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
c = [int(i) for i in input().split()]
res = 0
for i in range(n):
	res += d[i]
	res += c[i] - ((s+res) % c[i]) if (s+res)%c[i] != 0 else 0
	res += b[i]
print("yes" if res+d[n] <= t-s else "no")
