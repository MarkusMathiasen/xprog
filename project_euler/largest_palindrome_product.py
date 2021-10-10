def isPal(s):
	s = str(s)
	for i in range(len(s)//2):
		if s[i] != s[-1-i]:
			return False
	return True

res = 0
for i in range(100, 1000):
	for j in range(100, 1000):
		if isPal(i*j):
			res = max(res, i*j)
print(res)
