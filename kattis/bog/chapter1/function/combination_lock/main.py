while True:
	x, a, b, c = map(int, input().split())
	if x == a and a == b and b == c and c == 0:
		break
	f = (x-a+40) % 40
	s = (b-a+40)%40
	t = (b-c+40)%40
	print((f+s+t+40+40+40)*9)
