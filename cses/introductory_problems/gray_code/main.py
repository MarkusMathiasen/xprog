n = int(input())
A = 0

def gray(i):
	global A
	if i < 0:
		print(f"{A:0{n}b}")
		return
	gray(i-1)
	A ^= (1 << i)
	gray(i-1)

gray(n-1)
