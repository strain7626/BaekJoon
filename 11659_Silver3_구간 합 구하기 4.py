N, M = map(int, input().split())
S = [0,*map(int, input().split())]
for i in range(1, N+1) :
    S[i] += S[i-1]
for _ in range(M) :
    i, j = map(int, input().split())
    print(S[j]-S[i-1])