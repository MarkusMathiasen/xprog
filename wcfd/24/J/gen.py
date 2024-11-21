import random

cycle_len = int(input())
A1 = list(range(1, cycle_len+1))
A2 = list(range(cycle_len+1, 101))
B1 = list(range(2, cycle_len+1))
B1.append(1)
B2 = list(range(cycle_len+1, 101))
random.shuffle(B2)
assert len(A1) == len(B1) and len(A2) == len(B2)
assert(len(A1) + len(A2) == 100)
A = A1 + A2
B = B1 + B2

P = list(range(1, 101))
random.shuffle(P)
for i in range(0, 100):
    A[i] = P[A[i]-1]
    B[i] = P[B[i]-1]

d = {}
for i in range(0, 100):
    d[A[i]] = B[i]

for a,b in d.items():
    print(a, b)