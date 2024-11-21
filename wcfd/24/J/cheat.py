d={}
start=0

def read_permutation():
    global d,start
    for i in range(100):
        a, b = map(int, input().split())
        d[a] = b
        if i == 0:
            start = a
    return d

read_permutation()

x=start
while d[x] != start:
    x = d[x]
print(x)