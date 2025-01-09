N = int(input())
lst = list(map(int, input().split()))
lst.sort()

r = 0
dif = -1
for i in range(1,len(lst)) :
    if r < (lst[i] - lst[i-1])//2 :
        r = (lst[i] - lst[i-1])//2
        dif = lst[i-1] + r
print(dif)