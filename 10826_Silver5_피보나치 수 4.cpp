#include <bits/stdc++.h>
using namespace std;

string fibo[10001] = {"0","1"};

string sumStr(string A, string B) {
    string result = "";
    if (B.size() > A.size()) A = '0' + A;

    bool carry = 0;
    for (int i = A.size()-1; i >= 0; i--) {
        int t = (A[i]-'0')+(B[i]-'0')+carry;
        carry = (t>=10);
        result = char(t%10+'0') + result;
    }
    
    if (carry) result = '1' + result;

    return result;
}

int main(){
    
    int N; cin >> N;
    for (int i = 2; i <= N; i++) fibo[i] = sumStr(fibo[i-2],fibo[i-1]);
    cout << fibo[N];
}