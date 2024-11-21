import subprocess

d = {}
start = 0

def read_permutation():
    global d,start
    for i in range(100):
        a, b = map(int, input().split())
        d[a] = b
        if i == 0:
            start = a
    return d

def answer(s):
    global d
    if s[0] == '?':
        _, a, b = s.split()
        a, b = int(a), int(b)
        assert 1 <= a <= 100 and 0 <= b <= 100
        res = a
        for i in range(b):
            res = d[res]
        return res
    elif s[0] == '!':
        _, a = s.split()
        a = int(a)
        assert 1 <= a <= 100
        print(a)
        exit(0)
    else:
        assert False


def main():
    global d,start
    d = read_permutation()

    process = subprocess.Popen(['./main'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

    get_back = f"? {start} 0"
    q = 0
    while q < 15:
        ans = answer(get_back)
        # print(ans)
        process.stdin.write(str(ans)+'\n')
        process.stdin.flush()
        get_back = process.stdout.readline().strip()
        # print(get_back)
    
    print("Used too many queries!")
    exit(1)

if __name__ == "__main__":
    main()