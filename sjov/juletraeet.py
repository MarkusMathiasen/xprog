D = int(input())
for i in range(1, (D+1)//2 + 1):
	print(" "*((D+1)//2 - i) + "#"*(1 + (i-1)*2))
