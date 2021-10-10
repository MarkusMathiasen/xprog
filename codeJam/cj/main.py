T = int(input())
for t in range(1, T+1):
    x, y, s = input().split()
    x = int(x)
    y = int(y)
    res = 0
    prev = '?'
    for c in s:
        if c == 'C':
            if prev == 'J':
                res += y
            prev = 'C'
        if c == 'J':
            if prev == 'C':
                res += x
            prev = 'J'
    if len(s) > 1 and s[-1] == '?':
        if x < y and s[-2] in ['C', '?']:
            res = min(res, res+x)
        if y < x and s[-2] in ['J', '?']:
            res = min(res, res+y)
    
    res2 = 0
    prev = '?'
    for c in s:
        if c == 'C':
            if prev == 'J':
                res2 += y
            prev = 'C'
        if c == 'J':
            if prev == 'C':
                res2 += x
            prev = 'J'
        if c == '?':
            if prev == 'C':
                prev = 'J'
                res2 += x
            elif prev == 'J':
                prev = 'C'
                res2 += y
            elif prev == '?':
                prev = 'C'
    if len(s) > 1 and s[-1] == '?':
        if x < y and s[-2] in ['J', '?']:
            res2 = min(res2, res2-y)
        if y < x and s[-2] in ['C', '?']:
            res2 = min(res2, res2-x)
            
    res3 = 0
    prev = '?'
    for c in s:
        if c == 'C':
            if prev == 'J':
                res3 += y
            prev = 'C'
        if c == 'J':
            if prev == 'C':
                res3 += x
            prev = 'J'
        if c == '?':
            if prev == 'C':
                prev = 'J'
                res3 += x
            elif prev == 'J':
                prev = 'C'
                res3 += y
            elif prev == '?':
                prev = 'J'
    if len(s) > 1 and s[-1] == '?':
        if x < y and s[-2] in ['J', '?']:
            res3 = min(res3, res3-y)
        if y < x and s[-2] in ['C', '?']:
            res3 = min(res3, res3-x)
    
    print(f"Case #{t}:", min(res, res2, res3))
