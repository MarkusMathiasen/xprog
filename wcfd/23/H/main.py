s = input()
res = True
for i in range(1, len(s)):
    if len(s)%i != 0: continue
    diff = False
    for j in range(i, len(s), i):
        diff |= s[:i] != s[j:j+i]
    res &= diff

A=[False]*len(s)
for i,c in enumerate(s):
    A[(i+int(c))%len(A)] = True
res &= all(A)
if res: print("VALID")
else: print("INVALID")