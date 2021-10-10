n = int(input())
res = 0
for i in range(n):
	if i % 2 == 0:
		res -= int(input())
	else:
		res += int(input())
if n % 2 != 0:
	print("still running")
else:
	print(res)
