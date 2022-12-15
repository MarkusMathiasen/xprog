def read_element(line, pos):
    while (line[pos] == ','):
        pos += 1
    if line[pos] == '[':
        npos = pos
        cnt = 1
        while cnt > 0:
            npos += 1
            if line[npos] == '[':
                cnt += 1
            elif line[npos] == ']':
                cnt -= 1
        return read_list(line[pos+1:npos]), npos + 1
    else:
        npos = pos + 1
        while npos < len(line) and line[npos] not in ',]':
            npos += 1
        return int(line[pos:npos]), npos

def read_list(list_str):
    pos = 0
    res = []
    while pos < len(list_str):
        element, pos = read_element(list_str, pos)
        res += [element]
    return res

def compare(l1, l2):
    if (type(l1) == int and type(l2) == int):
        return l1 - l2
    if (type(l1) == int):
        l1 = [l1]
    if (type(l2) == int):
        l2 = [l2]
    for i in range(min(len(l1), len(l2))):
        c = compare(l1[i], l2[i])
        if c != 0:
            return c
    return len(l1) - len(l2)

res = 1
lists = []
for i in range(1, 1000000):
    l1 = input()
    if l1 == '':
        break
    l2 = input()
    l1, l2 = read_list(l1[1:-1]), read_list(l2[1:-1])
    lists += [l1, l2]
    input()

import functools
lists += [read_list("[2]"), read_list("[6]")]
lists = sorted(lists, key=functools.cmp_to_key(compare))
for i in range(len(lists)):
    if lists[i] in [[[2]], [[6]]]:
        res *= i + 1

print(res)