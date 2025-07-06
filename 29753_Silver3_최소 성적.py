grade = [
    ["F",  0.00],
    ["D0", 1.00],
    ["D+", 1.50],
    ["C0", 2.00],
    ["C+", 2.50],
    ["B0", 3.00],
    ["B+", 3.50],
    ["A0", 4.00],
    ["A+", 4.50]
]
r = 0
r2 = 0

def get_grade_score(grade_str):
    for i in grade:
        if i[0] == grade_str:
            return i[1]
    return 0.0

N, X = map(float, input().strip().split(" "))
X+=0.01
for _ in range(int(N)-1) :
    c, g = map(str, input().strip().split())
    c = int(c)
    g = get_grade_score(g)
    r += c*g
    r2 += c
L = int(input().strip())
 
for i, j in grade :
    result = (r + L*j)/(r2+L)
    if result >= X :
        print(i)
        break
else :   
    print('impossible')