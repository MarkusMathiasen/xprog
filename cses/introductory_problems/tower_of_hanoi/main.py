n = int(input())
res = 0
seq = []

def move(num, a, b):
	if num == 1:
		global res, seq
		res += 1
		seq += [(a, b)]
		return
	other = 6 - a - b
	move(num-1, a, other)
	move(1, a, b)
	move(num-1, other, b)

move(n, 1, 3)
print(res)
for t in seq:
	print(t[0], t[1])
