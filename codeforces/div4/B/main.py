n=int(input())
for i in range(n):
    s=input()
    if any(s[i]==s[i+1] for i in range(len(s)-1)):
        print(1)
    else:
        print(len(s))