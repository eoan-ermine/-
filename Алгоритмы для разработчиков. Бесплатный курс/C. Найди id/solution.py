n = int(input())
students = [int(e) for e in input().split()]
print(" ".join([str(e) for e in range(1, n + 1) if e not in students]))