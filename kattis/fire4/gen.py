import random

N = 7
M = 20

print(N, M)
for i in range(N):
    a,b=0,0
    while a==b:
        a,b=random.randint(0, M-1),random.randint(0, M-1)
    print(a,b)