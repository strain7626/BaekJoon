N = int(input())
P = list(map(int, input().split()))
P.sort()

print(sum(P[i]*(N-i) for i in range(N)))