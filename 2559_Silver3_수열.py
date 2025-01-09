N, K = map(int, input().split())
S = [0,*map(int, input().split())]

for i in range(2, N+1) :
    S[i] += S[i-1]

T = []
for i in range(N-K+1) :
    T.append(S[i+K] - S[i])
print(max(T))