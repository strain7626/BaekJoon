import sys
input = sys.stdin.readline

I = str(input().strip())
L = [int(i) for i in I]

print(*sorted(L,reverse=True), sep='')