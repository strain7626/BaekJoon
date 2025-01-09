N, M = map(int, input().split())
A = [0,*map(int, input().split())]

Counter = [0 for _ in range(M)]
for i in range(1,N+1) :
    t = (A[i]+A[i-1])%M
    Counter[t] += 1
    A[i] = t

point = Counter[0]
for i in range(M) :
    point += (Counter[i]*(Counter[i]-1))//2

print(point)