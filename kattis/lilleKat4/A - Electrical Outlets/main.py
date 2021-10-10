T = int(input())
for _ in range(T):
	l = [int(i) for i in input().split()]
	print(sum(l[1:])-l[0]+1)
