N, P, S = map(int, input().split())
for _ in range(S):
	l = [int(i) for i in input().split()]
	print("KEEP" if P in l[1:] else "REMOVE")
