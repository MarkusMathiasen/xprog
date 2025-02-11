T=int(input())
for _ in range(T):
    n,m=map(int,input().split())
    A=list(map(int,input().split()))
    b=int(input())
    A[0] = min(A[0], b-A[0])
    for i in range(1,n):
        if A[i-1] <= b-A[i] and b-A[i] < A[i]:
            A[i] = b-A[i]
    if all(A[i] <= A[i+1] for i in range(n-1)):
        print('YES')
    else:
        print('NO')
