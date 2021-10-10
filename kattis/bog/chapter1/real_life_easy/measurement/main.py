a, b, c, d = input().split()
A = float(a)
def g():
	global d, A
	if d == "th" or d == "thou":
		return
	A /= 1000
	if d == "in" or d == "inch":
		return
	A /= 12
	if d == "ft" or d == "foot":
		return
	A /= 3
	if d == "yd" or d == "yard":
		return
	A /= 22
	if d == "ch" or d == "chain":
		return
	A /= 10
	if d == "fur" or d == "furlong":
		return
	A /= 8
	if d == "mi" or d == "mile":
		return
	A /= 3


def f():
	global b,B
	if b == "th" or b == "thou":
		return
	B *= 1000
	if b == "in" or b == "inch":
		return
	B *= 12
	if b == "ft" or b == "foot":
		return
	B *= 3
	if b == "yd" or b == "yard":
		return
	B *= 22
	if b == "ch" or b == "chain":
		return
	B *= 10
	if b == "fur" or b == "furlong":
		return
	B *= 8
	if b == "mi" or b == "mile":
		return
	B *= 3
B = A
f()
A = B
g()
print(A)
