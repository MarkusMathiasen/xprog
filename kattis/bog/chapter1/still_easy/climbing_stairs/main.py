n, r, k = map(int, input().split())
res1 = n + r + (n%2 != r%2)
res2 = k*2
res3 = r*2
print(max(res1, res2, res3))
