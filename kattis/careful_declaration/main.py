def calc(a, b):
	if l1[a+1] == l2[b+1]:
		nxt[a][b] = (a+1, b+1)
		dp[a][b] = dp[a+1][b+1]+1
	elif dp[a+1][b] < dp[a][b+1]:
		nxt[a][b] = (a+1, b)
		dp[a][b] = dp[a+1][b]+1
	elif dp[a+1][b] > dp[a][b+1]:
		nxt[a][b] = (a, b+1)
		dp[a][b] = dp[a][b+1]+1
	elif l1[a+1] < l2[b+1]:
		nxt[a][b] = (a+1, b)
		dp[a][b] = dp[a+1][b]+1
	else:
		nxt[a][b] = (a, b+1)
		dp[a][b] = dp[a][b+1]+1
	
	


l1 = [""]+[i for i in input().split()]
while (l1[1] != "."):
	l2 = [""]+[i for i in input().split()]
	dp = [[-1 for _ in range(len(l2)+1)] for __ in range(len(l1)+1)]
	nxt = [[0 for _ in range(len(l2)+1)] for __ in range(len(l1)+1)]
	for i in range(len(l2)+1):
		nxt[len(l1)-1][i] = (len(l1)-1, i+1)
		dp[len(l1)-1][i] = len(l2)-i-1
	for i in range(len(l1)+1):
		nxt[i][len(l2)-1] = (i+1, len(l2)-1)
		dp[i][len(l2)-1] = len(l1)-i-1
	for a in range(len(l1)-2, -1, -1):
		for b in range(len(l2)-2, -1, -1):
			calc(a, b)
	a = 0
	b = 0
	while (a != len(l1)-1 or b != len(l2)-1):
		if nxt[a][b] == (a+1, b):
			print(l1[a+1], end=" ")
			a += 1
		elif nxt[a][b] == (a, b+1):
			print(l2[b+1], end=" ")
			b += 1
		elif nxt[a][b] == (a+1, b+1):
			print(l1[a+1], end=" ")
			a += 1
			b += 1
	print()
	l1 = [""]+[i for i in input().split()]
