a, b, c = map(int, input().split())
i, j, k = map(int, input().split())
rat = min(a/i, b/j, c/k)
print(a-i*rat, b-j*rat, c-k*rat)
