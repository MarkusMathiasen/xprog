d = len(input().split())
t1, t2 = [], [] 
kc = int(input())
names = [input() for _ in range(kc)]

curr = 0
team1 = True
while names:
	curr = (curr+d-1) % len(names)
	if team1:
		t1.append(names.pop(curr))
	else: 
		t2.append(names.pop(curr))
	team1 = not team1

print(len(t1))
for n in t1:
	print(n)
print(len(t2))
for n in t2:
	print(n)
