A = set(tuple(map(int, input().split())) for _ in range(5))
changed = True
res = 0
while changed and len(A) > 1:
    X,Y = zip(*A)
    X = list(X)
    Y = list(Y)
    changed = False
    for x,y in A:
        if x == min(X) and X.count(x) == 1:
            A.remove((x,y))
            changed = True
            X.remove(x)
            newx = min(X)
            A.add((newx,y))
            res += abs(newx-x)
            break
        if y == min(Y) and Y.count(y) == 1:
            A.remove((x,y))
            changed = True
            Y.remove(y)
            newy = min(Y)
            A.add((x,newy))
            res += abs(newy-y)
            break
        if x == max(X) and X.count(x) == 1:
            A.remove((x,y))
            changed = True
            X.remove(x)
            newx = max(X)
            A.add((newx,y))
            res += abs(newx-x)
            break
        if y == max(Y) and Y.count(y) == 1:
            A.remove((x,y))
            changed = True
            Y.remove(y)
            newy = max(Y)
            A.add((x,newy))
            res += abs(newy-y)
            break
res += 2*(max(X)-min(X)+max(Y)-min(Y))
happened = 0
for a in A:
    x,y = a
    if min(X) < x < max(X) and min(Y) < y < max(Y):
        res += min(max(X)-min(X), max(Y)-min(Y))
        happened += 1
assert happened <= 1
print(res)

