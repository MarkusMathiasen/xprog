l,w,n,r = map(int, input().split())
k = set()
for _ in range(n):
	x,y = map(int, input().split())
	t = 0
	t += 1*(x*x+(y-(w/2))*(y-(w/2)) <= r*r)
	t += 2*(x*x+(y+(w/2))*(y+(w/2)) <= r*r)
	t += 4*((x-(l/2))*(x-(l/2))+y*y <= r*r)
	t += 8*((x+(l/2))*(x+(l/2))+y*y <= r*r)
	k.add(t)
for t in k:
	if t == 15:
		print(1)
		exit(0)
for t1 in k:
	for t2 in k:
		if (t1 | t2) == 15:
			print(2)
			exit(0)
for t1 in k:
	for t2 in k:
		for t3 in k:
			if (t1 | t2 | t3) == 15:
				print(3)
				exit(0)
for t1 in k:
	for t2 in k:
		for t3 in k:
			for t4 in k:
				if (t1 | t2 | t3 | t4) == 15:
					print(4)
					exit(0)
print("Impossible")


