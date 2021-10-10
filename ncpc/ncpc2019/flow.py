n = int(input())
p = [0] + [int(i) for i in input().split()]
flow = [int(i) for i in input().split()]

kids = [[] for _ in range(n)]
for i in range(n-1):
	kids[p[i]] += [i]

q = list(range(n))
while q:
	v = q.pop()
	uk = -1
	kidsum = 0
	for k in kids[v]:
		if flow[k] == 0:
			if uk == -1:
				uk = k
			else:
				uk = -2   # We don't know anything
		kidsum += flow[k] # Add flow from child
	if uk == -2: continue
	elif uk == -1:
		flow[v] = kidsum
		if flow[p[v]] == 0:
			q.append(p[v])
	elif flow[v] != 0:
		flow[uk] = flow[v] - kidsum
		q.append(uk)

possible = True;
for i in range(n):
	if flow[i] == 0: possible = False
	if flow[i] != sum(kids[i]): possible = False

if not possible:
	print("impossible")
	quit()

for f in flow:
	print(f)
