#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int L, C;
char Chars[15];
char aeiou[5] = {'a','e','i','o','u'};

void solution(int l, int cnt, char result[15], int ct1, int ct2) {
    if (cnt == 0 && ct1 >= 1 && ct2 >= 2) {cout << result << endl;return;}
    for (int i = l; i < C-cnt+1; i++) {
        result[L-cnt] = Chars[i];
        cout << *find(aeiou, aeiou+5, Chars[i]) << endl;
        if (find(aeiou, aeiou+5, Chars[i]) == &Chars[i]){
            solution(i+1, cnt-1, result, ct1+1, ct2);
            cout << "Hello";
        }
        else solution(i+1, cnt-1, result, ct1, ct2+1);
    } 
    return;
}

int main() {
    cin >> L >> C;
    for (int i = 0; i < C; i++)
        cin >> Chars[i];
    sort(Chars,Chars+C);

    char a[15];
    solution(0, L, a, 0, 0);
}