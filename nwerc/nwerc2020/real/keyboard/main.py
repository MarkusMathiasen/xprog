s = input()
t = input()
cs = []
ct = []
res = []
for c in "abcdefghijklmnopqrstuvwxyz ":
	cs += [(c, s.count(c))]
	ct += [(c, t.count(c))]
for i in range(len(cs)):
	c1, k1 = cs[i]
	c2, k2 = ct[i]
	if (k1 != k2):
		res += [c1]
for c in set(res):
	print(c, end="")
print()
