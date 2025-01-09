import sys
input = sys.stdin.readline

N = int(input())

cur = [ input().strip() for _ in range(N) ] 
N //= 2
nxt = [ [] for _ in range(N) ]
print(cur)
print(nxt)