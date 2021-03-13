n = input()
if n.startswith("-"):
    print(-int("".join(reversed(n))[:-1]))
else:
    print(int("".join(reversed(n))))