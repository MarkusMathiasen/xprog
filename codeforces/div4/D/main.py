for _ in range(int(input())):
    n,m=map(int,input().split())
    A=[]
    for i in range(n):
        A.append(list(map(int,input().split())))
    for i in range(n):
        A[i] = (sum(A[i]), sum((m-j)*A[i][j] for j in range(m)))
    A.sort()
    print(sum(A[i][0]*i*m + A[i][1] for i in range(n)))