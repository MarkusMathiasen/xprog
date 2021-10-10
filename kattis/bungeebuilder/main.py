n = int(input())
A = [int(i) for i in input().split()]
left = [A[0]]
for i in A[1:]:
	left.append(max(i, left[-1]))
right = [A[-1]] * n
for i in range(n-2, 0, -1):
	right[i] = max(A[i], right[i+1])
res = 0
for i in range(1, n-1):
	res = max(res, min(left[i-1], right[i+1]) - A[i])
print(res)
