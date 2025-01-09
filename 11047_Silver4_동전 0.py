import sys
input = sys.stdin.readline
N, K = map(int, input().split())                                                                        
coins = [int(input().strip()) for _ in range(N)]
coins.reverse()

S = 0
for coin in coins :
    t = K // coin
    S += t
    K -= coin*t
print(S)