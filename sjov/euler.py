import math
res = 1
num = 600851475143
for i in range(2, 10000000):
	if i > math.sqrt(num): break
	if num % i == 0: res = i
if res == 0: res = num
print(res)
