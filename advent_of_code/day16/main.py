hexa = input()
s = "{0:b}".format(int(hexa, 16)).zfill(len(hexa)*4)
def packet(pos):
	v = int(s[pos:pos+3], 2)
	pos += 3
	t = int(s[pos:pos+3], 2)
	pos += 3
	if (t == 4):
		done = False
		num = ""
		while not done:
			done = s[pos] == '0'
			num += s[pos+1:pos+5]
			pos += 5
		return pos, int(num, 2)
	else:
		op = {
			0: lambda x,y: x+y,
			1: lambda x,y: x*y,
			2: lambda x,y: min(x,y),
			3: lambda x,y: max(x,y),
			5: lambda x,y: x > y,
			6: lambda x,y: x < y,
			7: lambda x,y: x == y
		}[t]
		lt = s[pos]
		pos += 1
		res = 0
		if (lt == '1'):
			packNum = int(s[pos:pos+11], 2)
			pos += 11
			pos, res = packet(pos)
			for _ in range(packNum-1):
				pos, nxt = packet(pos)
				res = op(res, nxt)
		else:
			length = int(s[pos:pos+15], 2)
			pos += 15
			end = pos+length
			pos, res = packet(pos)
			while pos < end:
				pos, nxt = packet(pos)
				res = op(res, nxt)
		return pos, res
pos, res = packet(0)
print(int(res))
