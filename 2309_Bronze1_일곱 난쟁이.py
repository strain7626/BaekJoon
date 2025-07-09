import sys
input = sys.stdin.readline

H = [int(input()) for _ in range(9)]
H.sort()

flag = False

d = []
for i in range(1, 9) :
    for j in range(i) :
        if sum(H) - (H[i]+H[j]) == 100:
            d = [i,j]
            flag = True
            break
    if flag : break

r = [H[x] for x in range(9) if x not in d]
print(*r, sep='\n')