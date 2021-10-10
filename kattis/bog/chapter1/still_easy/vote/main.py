t = int(input())
for _ in range(t):
	n = int(input())
	votes = []
	total = 0
	for __ in range(n):
		x = int(input())
		total += x
		votes += [x]
	best = max(votes)
	winner = votes.index(best) +1
	votes.sort()
	votes.reverse()
	if votes[0] == votes[1]:
		print("no winner")
	elif best > total//2:
		print("majority winner", winner)
	else:
		print("minority winner", winner)

