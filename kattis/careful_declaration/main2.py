l1 = [i for i in input().split()]
while (l1[0] != "."):
	l2 = [i for i in input().split()]
	dp = [[0 for _ in range(len(l2)+1)] for __ in range(len(l1)+1)]
	nxt = [[(0, 0) for _ in range(len(l2)+1)] for __ in range(len(l1)+1)]
	for i in range(len(l1)+1):
		dp[i][len(l2)] = len(l1)-i
		nxt[i][len(l2)] = (i+1, len(l2))
	for i in range(len(l2)+1):
		dp[len(l1)][i] = len(l2)-i
		nxt[len(l1)][i] = (len(l1), i+1)
	for i in range(len(l1)-1, -1 -1):
		for j in range(len(l2)-1, -1, -1):
			if l1[i] == l2[j]:
				dp[i][j] = dp[i-1][j-1]+1
				nxt[i][j] = (i, j-1)
			elif dp[i-1][j] == dp[i][j-1]:
				dp[i][j] = dp[i-1][j]+1
				if l1[i-1] <= l2[j-1]:
					prev[i][j] = (i-1, j)
				else:
					prev[i][j] = (i, j-1)
			elif dp[i-1][j] < dp[i][j-1]:
				dp[i][j] = dp[i-1][j]+1
				prev[i][j] = (i-1, j)
			else:
				dp[i][j] = dp[i][j-1]+1
				prev[i][j] = (i, j-1)
	print(dp[len(l1)][len(l2)])
	i = len(l1)
	j = len(l2)
	res = []
	while i > 0 or j > 0:
		if prev[i][j] == (i-1, j-1):
			res += [l1[i-1]]
			i -= 1
			j -= 1
		elif prev[i][j] == (i-1, j):
			res += [l1[i-1]]
			i -= 1
		elif prev[i][j] == (i, j-1):
			res += [l2[j-1]]
			j -= 1
	for i in reversed(res):
		print(i, end=" ")
	print()


	'''
	res = []
	i = len(l1)
	j = len(l2)
	while i > 0 and j > 0:
		if l1[i-1] == l2[j-1]:
			res += [l1[i-1]]
			i -= 1
			j -= 1
		elif dp[i-1][j] == dp[i][j-1]:
			if l1[i-1] > l2[j-1]:
				res += [l1[i-1]]
				i -= 1
			else:
				res += [l2[j-1]]
				j -= 1
		elif dp[i-1][j] < dp[i][j-1]:
			res += [l1[i-1]]
			i -= 1
		else:
			res += [l2[j-1]]
			j -= 1
	while i > 0:
		res += [l1[i-1]]
		i -= 1
	while j > 0:
		res += [l2[j-1]]
		j -= 1
	for i in range(len(res)-1, -1, -1):
		print(res[i], end=" ")
	print()
	'''
	l1 = [i for i in input().split()]
