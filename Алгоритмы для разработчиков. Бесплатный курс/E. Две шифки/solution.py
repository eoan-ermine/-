n = int(input())
s = [int(e) for e in input().split()]
f = int(input())

finished = False
for a in range(n):
    for b in range(a + 1, n):
        if s[a] + s[b] == f:
            print(s[a], s[b])
            finished = True
            break
    if finished:
        break

if not finished:
    print(None)