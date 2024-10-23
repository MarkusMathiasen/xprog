import random

N=200000
M = 200000
print(N, M)
for i in range(N):
    a,b=0,0
    while a==b:
        a=random.randint(0, M-1)
        b = (a+15)%M
    print(a,b)