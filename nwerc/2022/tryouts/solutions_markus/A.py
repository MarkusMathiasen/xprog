T = int(input())
for _ in range(T):
	N, M = map(int, input().split())
	a, b, d = map(int, input().split())
	a -= 1
	b -= 1
	if (b+(b-a)+d)%N >= N-M:
		print("NO")
	else:
		print("YES")
