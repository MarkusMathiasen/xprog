T = int(input())
for t in range(1, T+1):
    n, c = map(int, input().split())
    L = list(range(1, n+1))
    r = n-1
    pos = False
    for i in range(n-2, -1, -1):
        if r+n-i-1 < c:
            L = L[:i] + list(reversed(L[i:]))
            r += n-i-1
        else:
            L = L[:i] + list(reversed(L[i:i+c-r+1])) + L[i+c-r+1:]
            pos = True
            break
    if pos and r <= c:
        print(f"Case #{t}", " ".join([str(i) for i in L]))
    else:
        print(f"Case #{t}", "IMPOSSIBLE")
