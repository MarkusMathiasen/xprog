W, H, F, N = map(int, input().split())
words = []
for _ in range(N):
    words += list(input().split())

for i in range(len(words)):
    if len(words[i]) > W:
        words[i] = words[i][:W]

text = [words[0]]
words = words[1:]

for w in words:
    if len(text[-1]+' '+w) <= W:
        text[-1] += ' '+w
    else:
        text[-1] += ' '*(W-len(text[-1]))
        text.append(w)
text[-1] += ' '*(W-len(text[-1]))

L = len(text)
T = (H-3)*F//(L-H)

# Now, just print the result
print(f"+{'-'*W}+-+")
for i in range(F, F+H):
    print(f"|{text[i]}|{'^' if i == F else 'v' if i == F+H-1 else 'X' if i-F-1 == T else ' '}|")
print(f"+{'-'*W}+-+")