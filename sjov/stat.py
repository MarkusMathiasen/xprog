import random

random.seed(13)
def trade():
	if random.randint(1, 10000) > 473:
		return 0
	else:
		return random.randint(4, 8)

res = 0
for _ in range(10000):
	tradeCount = 0
	goodTrades = 0
	while tradeCount < 262:
		itemCount = 0
		while itemCount < 11:
			items = trade()
			itemCount += items
			if items > 0:
				goodTrades += 1
			tradeCount += 1
	if goodTrades >= 30:
		res += 1
print(res)


