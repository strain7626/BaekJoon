import sys
input = sys.stdin.readline

N, M = map(int, input().split())

table = [[0]*(N+1)]
for _ in range(N) :
    table.append([0,*map(int, input().split())])

for y in range(1,N+1) :
    for x in range(1,N+1) :
        table[x][y] += table[x][y-1] + table[x-1][y] - table[x-1][y-1]

for _ in range(M) :
    x1, y1, x2, y2 = map(int, input().split())
    x1-=1
    y1-=1
    
    print(table[x2][y2]-table[x2][y1]-table[x1][y2]+table[x1][y1])