N, K = map(int, input().split())
says = [[i for i in input().split()] for _ in range(K)]

perm = [1]*N # 1 = truther, 2 = fabulist, 3 = charlatan

def eval(l, p): # returns (result, end)
	w = says[l][p]
	if w == "truther":
		return (perm[int(says[l][p+1])-1] == 1, p+1)
	if w == "fabulist":
		return (perm[int(says[l][p+1])-1] == 2, p+1)
	if w == "charlatan":
		return (perm[int(says[l][p+1])-1] == 3, p+1)
	if w == "not":
		e1 = eval(l, p+1)
		return (not e1[0], e1[1])
	if w == "and":
		e1 = eval(l, p+1)
		e2 = eval(l, e1[1]+1)
		return (e1[0] and e2[0], e2[1])
	if w == "xor":
		e1 = eval(l, p+1)
		e2 = eval(l, e1[1]+1)
		return (e1[0] ^ e2[0], e2[1])
	return (False, 0)

def inc(i):
	global perm
	global N
	if i == N:
		return False
	if perm[i] == 3:
		perm[i] = 1
		return inc(i+1)
	perm[i] += 1
	return True

perm[0] = 0
while (inc(0)):
	maySay = []
	for i in perm:
		maySay += [i]
	for l in range(K):
		pers = int(says[l][0])-1
		t = eval(l, 1)[0]
		if maySay[pers] == 1:
			if t:
				continue
			else:
				maySay[pers] = 7
				break
		if maySay[pers] == 2:
			if t:
				maySay[pers] = 7
				break
			else:
				continue
		if maySay[pers] == 3:
			if t:
				maySay[pers] = 4
				continue
			else:
				maySay[pers] = 7
				break
		if maySay[pers] == 4:
			if t:
				continue
			else:
				maySay[pers] = 5
				continue
		if maySay[pers] == 5:
			if t:
				maySay[pers] = 7
				break
			else:
				continue
	valid = True
	for c in maySay:
		if c == 1 or c == 2 or c == 5:
			continue
		valid = False
	if valid:
		break
	
for c in perm:
	if c == 1:
		print("truther")
	if c == 2:
		print("fabulist")
	if c == 3:
		print("charlatan")










		

