def find(k):
	num = 0
	i = 0
	while num + 9*10**i * (i+1) <= k:
		num += 9*10**i * (i+1)
		i += 1
	i += 1
	k -= num
	num = k // i + 10**(i-1)
	rest = k % i
	res = (num % (10**(i-rest))) // (10**(i-rest-1))
	return res

q = int(input())
for i in range(q):
	print(find(int(input())-1))
