import sys
input = sys.stdin.readline

S = input().strip()
q = int(input().strip())

Dict = dict()
l = len(S)
for i in 'abcdefghijklmnopqrstuvwxyz' :
    temp = [0]
    for c in S :
        temp.append(temp[-1]+1 if c == i else temp[-1])
    Dict[i] = temp

for _ in range(q) :
    c, r, l = input().split()
    l = int(l)
    r = int(r)
    R = Dict[c]
    print(R[l+1]-R[r])