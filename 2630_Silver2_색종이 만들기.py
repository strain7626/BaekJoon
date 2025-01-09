import sys
input = sys.stdin.readline

N = int(input())
ppr = [list(map(int, input().split())) for _ in range(N)]

blue = 0
white = 0

while N > 1 :   
    nxt = []
    for y in range(0,N,2) :
        nxt.append([])
        for x in range(0,N,2) :
            t = ppr[y][x] + ppr[y][x+1] + ppr[y+1][x] + ppr[y+1][x+1]
            if t == 0 :
                nxt[y//2].append(0)
            elif t == 4 :
                nxt[y//2].append(1)
            else :
                for i in range(4) :
                    if ppr[y+i%2][x+i//2] == 0 :
                        white += 1
                    elif ppr[y+i%2][x+i//2] == 1 :
                        blue += 1
                nxt[y//2].append(-5)
    ppr = [nxt[i].copy() for i in range(len(nxt))]
    N //= 2
if ppr[0][0] == 1 :
    blue += 1
elif ppr[0][0] == 0 :
    white += 1

print(white)
print(blue)