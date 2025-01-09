import sys
input = sys.stdin.readline

yMax, xMax, Size = map(int, input().split())
O = [input().strip() for _ in range(yMax)]

isChanged = [[0]*(xMax+1) for _ in range(yMax+1)]
for y in range(yMax) :
    for x in range(xMax) :
        if (x+y)%2 == 0 and O[y][x] == 'W' :
            isChanged[y+1][x+1] = 1
        elif (x+y)%2 == 1 and O[y][x] == 'B' :
            isChanged[y+1][x+1] = 1

for y in range(1, yMax+1) :
    for x in range(1, xMax+1) :
        isChanged[y][x] += isChanged[y-1][x]+isChanged[y][x-1]-isChanged[y-1][x-1]

costTable = []
for y0 in range(1, yMax-Size+2) :
    for x0 in range(1, xMax-Size+2) :
        x1, y1 = x0-1, y0-1
        x2, y2 = x1+Size, y1+Size
        costTable.append(isChanged[y2][x2]-isChanged[y1][x2]-isChanged[y2][x1]+isChanged[y1][x1])

m = min(costTable)
M = max(costTable)
print(min(Size**2-M, m))