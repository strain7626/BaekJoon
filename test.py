import sys
input = sys.stdin.readline


L = [1, 2, 5, 7, 11, 20]
N = int(input())

def binary(n) :
    s, e = 0, len(L)-1

    while s < e :
        m = (s+e)//2
        if n > L[m] : s = m+1
        else : e = m # <----- 이게 실행될때는 무슨 경우지?
    return e



print (binary(N))