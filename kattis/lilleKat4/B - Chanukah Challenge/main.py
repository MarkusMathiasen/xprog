T = int(input())
for _ in range(T):
	a, b = map(int, input().split())
	print(a, (b*(b+1))//2 + b)
