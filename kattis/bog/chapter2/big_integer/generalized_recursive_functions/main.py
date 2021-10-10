n = int(input())
for _ in range(n):
	l1 = list(map(int, input().split()))
	l2 = list(map(int, input().split()))
	c = l1[-2]
	d = l1[-1]
	dp = [[-1 for _ in range(100)] for __ in range(100)]
	def f(x, y):
		global l1, c, d
		if (x <= 0 or y <= 0):
			return d
		if dp[x][y] != -1:
			return dp[x][y]
		res = 0
		for i in range(0, len(l1)-2, 2):
			res += f(x - l1[i], y - l1[i+1])
		dp[x][y] = res+c
		return res + c
	for i in range(0, len(l2), 2):
		print(f(l2[i], l2[i+1]))
	print()
