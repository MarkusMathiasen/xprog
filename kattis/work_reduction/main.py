t = int(input())
for case in range(1, t+1):
	N, M, L = map(int, input().split())
	agents = []
	for _ in range(L):
		a = []
		line = input().split(":")
		a += [line[0]]
		nums = line[1].split(",")
		a += [int(i) for i in nums]
		agents += [a]
	
	prices = []
	for i in range(L):
		price = 0
		n = N
		while n > M:
			if n//2 >= M:
				if agents[i][2] < agents[i][1]*(n - n//2):
					price += agents[i][2]
				else:
					price += agents[i][1]*(n - n//2)
				n //= 2
			else:
				price += agents[i][1]*(n-M)
				n = M
		prices += [[price, agents[i][0]]]
	prices.sort()
	print("Case", case)
	for i in prices:
		print(i[1], i[0])
