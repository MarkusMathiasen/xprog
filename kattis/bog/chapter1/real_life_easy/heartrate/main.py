n = int(input())
for test in range(n):
	b,t = map(float, input().split())
	print(60*(b-1)/t, 60*b/t, 60*(b+1)/t)
