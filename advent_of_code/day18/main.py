import copy
def readList(s, i):
	if s[i] in "0123456789":
		return int(s[i]), i+1
	firstList, midPos = readList(s, i+1)
	secondList, endPos = readList(s, midPos+1)
	return [firstList, secondList], endPos+1

def addVal(l, v, direction):
	if type(l) == int:
		return l+v
	l[direction] = addVal(l[direction], v, direction)
	return l

def explode(l, depth=0):
	if type(l) == int:
		return 0, 0, l, False
	if depth == 4:
		return l[0], l[1], 0, True
	lv, rv1, l[0], did = explode(l[0], depth+1)
	l[1] = addVal(l[1], rv1, 0)
	if did:
		return lv, 0, l, did
	lv1, rv, l[1], did = explode(l[1], depth+1)
	l[0] = addVal(l[0], lv1, 1)
	return lv, rv, l, did

def mySplit(l):
	if type(l) == int:
		return (l, False) if l < 10 else ([l//2, l//2 + (l%2)], True)
	l[0], did = mySplit(l[0])
	if did:
		return l, did
	l[1], did = mySplit(l[1])
	return l, did

def add(l1, l2):
	l = [copy.deepcopy(l1), copy.deepcopy(l2)]
	while True:
		_, _, nl, did = explode(l)
		if did:
			continue
		nl, did = mySplit(nl)
		if did:
			continue
		break
	return l

def magnitude(l):
	if (type(l) == int):
		return l
	return magnitude(l[0])*3 + magnitude(l[1])*2

nums = []
while (True):
	s = ""
	s = input()
	if not len(s):
		break
	nums += [eval(s)]
res = 0
for x in nums:
	for y in nums:
		if x == y:
			continue
		res = max(res, magnitude(add(x, y)))
print(res)

"""
prev, _ = readList(input(), 0)
while (True):
	s = ""
	s = input()
	if not len(s):
		break
	prev = add(prev, eval(s))
print(magnitude(prev))
"""
