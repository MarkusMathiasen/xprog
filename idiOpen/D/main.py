a, b, c, d = map(int, input().split())
res = []
for op in range(4):
	ab = 0
	abchar = 'h'
	if op == 0:
		opchar = '+'
		ab = a + b
	if op == 1:
		opchar = '-'
		ab = a - b
	if op == 2:
		opchar = '*'
		ab = a * b
	if op == 3:
		if b == 0:
			continue
		opchar = '/'
		ab = a // b
	for op2 in range(4):
		cd = 0
		cdchar = 'l'
		if op2 == 0:
			op2char = '+'
			cd = c + d
		if op2 == 1:
			op2char = '-'
			cd = c - d
		if op2 == 2:
			op2char = '*'
			cd = c * d
		if op2 == 3:
			if d == 0:
				continue
			op2char = '/'
			cd = c // d
		if ab == cd:
			res += [f'{a} {opchar} {b} = {c} {op2char} {d}']

for s in sorted(res):
	print(s)
if len(res) == 0:
	print("problems ahead")
