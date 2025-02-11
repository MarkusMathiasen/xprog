for _ in range(int(input())):
    n,m,k=map(int,input().split())
    n_bigger = n > m
    if abs(n-m) > k or k > max(n,m):
        print(-1)
        continue
    s = ''
    for __ in range(k):
        s += '0' if n_bigger else '1'
        if n_bigger: n-=1
        else: m-=1
    while n > 0 or m > 0:
        if n > m or (s[-1] == '1' and n == m):
            s += '0'
            n-=1
        else:
            s += '1'
            m-=1
    print(s)