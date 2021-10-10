n, m, a = map(int, input().split())

def splitOne(n, m, a):
	return a % n == 0 or a % m == 0

if splitOne(n, m, a):
	print(1)
	quit()

for i in range(1, n):
	if i * m < a:
		if splitOne(n-i, m, a-(i*m)):
			print(2)
			quit()
	elif splitOne(i, m, a):
		print(2)
		quit()

for i in range(1, m):
	if i * n < a:
		if splitOne(n, m-i, a-(i*n)):
			print(2)
			quit()
	elif splitOne(n, i, a):
		print(2)
		quit()

print(3)
