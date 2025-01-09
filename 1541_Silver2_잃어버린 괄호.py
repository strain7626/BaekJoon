S = input()
total = 0
Nums = []
Cals = []
i = 1
while i < len(S):
    if S[i] in '+-' :
        Nums.append(int(S[:i]))
        Cals.append(S[i])
        S = S[i+1:]
        i = 0
    i += 1
Nums.append(int(S))
total += Nums[0]

for i in range(1,len(Nums)) :
    if Cals[i-1] == '+' :
        total += Nums[i]
    else :
        total -= sum(Nums[i:])
        break
print(total)