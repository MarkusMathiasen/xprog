T = 1
N = 300000
G = 1

import random
E = [random.randint(N, 2*N) for _ in range(N)]

print(T)
print(N, G)
for E_i in E: print(E_i)
