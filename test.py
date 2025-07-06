import sys
input = sys.stdin.readline

I = str(input().strip())
L = [int(i) for i in I]

print(*sorted(L,reverse=True), sep='')

solved.ac 해야됨 봐바 
설정같은거 켜야되나봐