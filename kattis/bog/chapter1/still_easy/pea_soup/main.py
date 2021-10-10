n = int(input())
for _ in range(n):
	k = int(input())
	name = input()
	s = set(["pancakes", "pea soup"])
	for __ in range(k):
		s -= set([input()])
	if len(s) == 0:
		print(name)
		exit(0)
print("Anywhere is fine I guess")
