T = int(input())
for t in range(1, T+1):
    N, P = map(int, input().split())
    p = P/100
    q = p/p**(1/N)
    res = (q-p)*100
    print(f"Case #{t}: {res:.20f}")