import math
primes = []
def isPrime(x):
	global primes
	for i in primes:
		if x % i == 0:
			return False
	primes += [x]
	print(x)
	return True
	
res = 1
for i in range(3, 775147, 2):
	if isPrime(i):
		if 600851475143 % i == 0:
			res = i
print(res)
