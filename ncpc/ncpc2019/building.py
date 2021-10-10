res = 0
res, a1, b1, a2, b2, a3, b3 = 0, 0, 0, 0, 0, 0, 0
def oper():
	global res, a1, b1, a2, b2, a3, b3
	res = min(res, max(a1, a2+a3) * (b1 + max(b2, b3)))
	res = min(res, max(a1, b2+a3) * (b1 + max(a2, b3)))
	res = min(res, max(b1, a2+a3) * (a1 + max(b2, b3)))
	res = min(res, max(b1, b2+a3) * (a1 + max(a2, b3)))

	res = min(res, max(a1, a2+b3) * (b1 + max(b2, a3)))
	res = min(res, max(a1, b2+b3) * (b1 + max(a2, a3)))
	res = min(res, max(b1, a2+b3) * (a1 + max(b2, a3)))
	res = min(res, max(b1, b2+b3) * (a1 + max(a2, a3)))


	res = min(res, max(a1, a2, a3) * (b1 + b2 + b3))
	res = min(res, max(b1, a2, a3) * (a1 + b2 + b3))
	res = min(res, max(a1, b2, a3) * (b1 + a2 + b3))
	res = min(res, max(a1, a2, b3) * (b1 + b2 + a3))

	res = min(res, max(a1, b2, b3) * (b1 + a2 + a3))
	res = min(res, max(b1, a2, b3) * (a1 + b2 + a3))
	res = min(res, max(b1, b2, a3) * (a1 + a2 + b3))
	res = min(res, max(b1, b2, b3) * (a1 + a2 + a3))
	return res
	
t = int(input())
while t > 0:
	t -= 1
	a1, b1, a2, b2, a3, b3 = map(int, input().split())
	res = float("inf")
	oper()
	a1, b1, a3, b3 = a3, b3, a1, b1
	oper()
	a1, b1, a2, b2 = a2, b2, a1, b1
	oper()
	a1, b1, a3, b3 = a3, b3, a1, b1
	oper()
	a1, b1, a2, b2 = a2, b2, a1, b1
	oper()

	print(res)
