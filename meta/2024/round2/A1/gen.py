import random
T = 100000
print(T)
for i in range(T):
    A = random.randint(0, 10)
    B = A+1000
    M = random.randint(1, 5)
    print(A, B, M)
