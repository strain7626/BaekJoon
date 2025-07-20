import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
O = list(map(int, input().split()))
M = -1000000000; m = 1000000000

def DFS(now, cnt) :
    global M, m
    if cnt == N : M = max(M, now); m = min(m, now)
    
    if O[0] : O[0]-=1; DFS(now+A[cnt], cnt+1); O[0]+=1
    if O[1] : O[1]-=1; DFS(now-A[cnt], cnt+1); O[1]+=1
    if O[2] : O[2]-=1; DFS(now*A[cnt], cnt+1); O[2]+=1
    if O[3] : O[3]-=1; DFS(now//A[cnt] if (now >= 0) else -(-now//A[cnt]), cnt+1); O[3]+=1

DFS(A[0], 1)
print(M, m, sep='\n')