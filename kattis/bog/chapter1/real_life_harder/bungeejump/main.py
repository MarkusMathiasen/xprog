import math
from decimal import Decimal
g = Decimal("9.81")
while True:
	k, l, s, w = map(Decimal, input().split())

	if not (k or l or s or w):
		break
	vs = g*s*2 - (s-l)*(s-l)*k / w
	if vs < 0:
		print("Stuck in the air.")
	elif math.sqrt(vs) <= 10:
		print("James Bond survives.")
	else:
		print("Killed by the impact.")
