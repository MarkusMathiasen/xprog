n = int(input())
tree = [[] for _ in range(n)]
for _ in range(n-1):
	a, b = [int(i)-1 for i in input().split()]
	tree[a] += [b]
	tree[b] += [a]

vis = [False] * n
res = 0

def dfs(v):
	if vis[v]: return 0;
	vis[v] = True
	routes = []
	for u in tree[v]:
		routes += [dfs(u)]
	routes.sort()
	global res
	res = max(res, routes[-1])
	if len(routes) > 1:
		res = max(res, routes[-1] + routes[-2])
	return routes[-1]+1
dfs(0)
print(res)
