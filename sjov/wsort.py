A = [0] + [int(i) for i in input().split()]

def heapify(pos):
	if pos >= (len(A)+1)//2: return 
	maxkid = 0
	if pos >= len(A)//2 or A[pos*2] > A[pos*2+1]: maxkid = pos*2
	else: maxkid = pos*2+1
	if A[pos] >= A[maxkid]: return 
	A[pos], A[maxkid] = A[maxkid], A[pos]
	heapify(maxkid)

for i in range(len(A), 0, -1):
	heapify(i)
print(A)
print(list(range(len(A))))


class Node():
	def __init__(self, val):
		self.l = None
		self.r = None
		self.val = val
		self.p = None

root = Node(A[1])
pos = root

def insert(i):
	
