#include <iostream>
#define endl "\n"
using namespace std;

// 재귀함수 형태로 제작
string Solve(string S) {
    if (S.length()==1) return S;

    int idx = S.length()-1;

    //뒤에서 첫번째 항 찾기
    string first;
    if (S[idx] == ')') {
        int cnt = 1;
        while (idx--) {
            if (S[idx] == '(' && !--cnt) {
                first = S.substr(idx--);
                break;
            } else if (S[idx] == ')') cnt++;
        }
    } else {
        first = S.substr(idx--);
    }

    if (idx == 0) return Solve(first.substr(1,first.length()-2)); //괄호가 처음부터 끝인 것 괄호 벗기기

    //첫번째 연산자 찾기
    char cal = S[idx--];
    if (cal == '+' || cal == '-') return Solve(S.substr(0,idx)) + Solve(first) + cal;

    char 
    if ()

    

    return first+cal;
}

int main() {    
    cin.tie(0);
    
    string S; cin >> S;
    cout << Solve(S);
}