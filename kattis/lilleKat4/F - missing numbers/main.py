n = int(input())
cur = 1
found = False
for _ in range(n):
	x = int(input())
	while cur < x:
		found = True
		print(cur)
		cur += 1
	cur += 1
if not found:
	print("good job")

