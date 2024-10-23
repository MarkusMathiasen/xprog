import random
T = 95
print(T)
for i in range(T):
    A = random.randint(0, 1000)
    B = A+999
    M = random.randint(1, 5)
    print(A, B, M)
