import sys
input = sys.stdin.readline

N = int(input())
discuss = [tuple(map(int, input().split())) for _ in range(N)]

discuss.sort(key = lambda x : (x[1],x[0]))

last = 0
score = 0
for i in range(len(discuss)) :
    if discuss[i][0] >= last:
        score += 1
        last = discuss[i][1]
    
print(score)