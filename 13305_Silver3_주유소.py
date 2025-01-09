N = int(input())
loads = tuple(map(int,input().split()))
citys = tuple(map(int,input().split()))
low = citys[0]
result = 0
for i in range(N-1) :
    if citys[i] < low : low = citys[i]
    result += low*loads[i]
print(result)