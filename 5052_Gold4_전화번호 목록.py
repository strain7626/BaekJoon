for _ in range(int(input())) :
    
    n = int(input())
    callBook = []
    for _ in range(n) :
        callBook.append(input())
    callBook.sort(key=lambda x:x+'0'*(10-len(x)))
    
    Check = False
    for i in range(n-1) :
        if len(callBook[i]) > len(callBook[i+1]) : continue
        elif callBook[i] == callBook[i+1][:len(callBook[i])] :
            print('NO')
            Check = True
            break
    
    if not Check : print('YES')