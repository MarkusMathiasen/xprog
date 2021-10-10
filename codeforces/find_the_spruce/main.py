t = int(input())
n, m = map(int, input().split())
table = [input() for _ in range(n)]
dp = [[0 for _ in range(m)] for __ in range(n)]
res = 0
for i in range(n-1, -1, -1):
	for j in range(0, m):
		if table[i][j] == '*':
			if i == n-1 or j == 0 or j == m-1:
				dp[i][j] = 1
			else:
				dp[i][j] = 1+min(dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1])
			res += dp[i][j]
print(res)
