dic = input()
input()
img = []
while True:
	s = input()
	if s == "":
		break
	img.append(s)

def printImg(img):
	for s in img:
		print(s)
	print()

for k in range(2):
	img2 = []
	for i in range(-1, len(img)+1):
		img2.append("")
		for j in range(-1, len(img[0])+1):
			cnt = -1
			idx = 0
			for x in range(i+1, i-2, -1):
				for y in range(j+1, j-2, -1):
					cnt += 1
					print("cnt:", cnt)
					if 0 <= x and x < len(img) and 0 <= y and y < len(img[0]):
						if img[x][y] == '#':
							idx |= 1<<cnt
			print(idx)
			img2[-1] += dic[idx]
	printImg(img)
	img = img2
printImg(img)

res = 0
for s in img:
	for c in s:
		res += c == '#'
print(res)

