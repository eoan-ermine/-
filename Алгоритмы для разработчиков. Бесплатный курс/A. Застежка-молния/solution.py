n = int(input())
a = [int(e) for e in input().split()]
b = [int(e) for e in input().split()]
r = [str(it) for s in [[a[i], b[i]] for i in range(n)] for it in s]
print(" ".join(r))