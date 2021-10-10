L = []
for c in range(ord('a'), ord('z')+1):
	print(chr(c)*4, flush=True)
	a, b = map(int, input().split())
	L += [a+b]


