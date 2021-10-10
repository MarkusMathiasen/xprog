prev = input()
l = int(input())
ani = [input() for _ in range(l)]

startWith = [0] * 26
for a in ani:
	startWith[ord(a[0])-97] += 1 

res = "?"
for a in ani:
	if a[0] != prev[-1]:
		continue
	if res == "?":
		res = a
	if startWith[ord(a[-1])-97] <= 1:
		if startWith[ord(a[-1])-97] == 1 and a[0] != a[-1]:
			continue
		res = a + "!"
		break
print(res)
