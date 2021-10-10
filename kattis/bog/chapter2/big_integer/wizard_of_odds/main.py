n, k = map(int, input().split())
if k >= 350:
	print("You will become a flying monkey!")
else:
	x = 1
	for _ in range(k):
		x *= 2
	if x < n:
		print("You will become a flying monkey!")
	else:
		print("Your wish is granted!")

