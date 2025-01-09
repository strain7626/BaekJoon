import sys
input = sys.stdin.readline

N = int(input())
lst = []

def put(num:int) :
    i = 0
    while i < len(lst) :
        if lst[i] > num : break
        i += 1
    lst.insert(i,num)
    return

for i in range(N) :
    put(int(input()))
    print(lst[i//2])