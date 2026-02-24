#include <bits/stdc++.h>

using namespace std;

int N;
string A[1000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> N;
    for (int i=0;i<N;i++) cin >> A[i];

    sort(A,A+N,[](string a,string b){return a+b>b+a;});

    if (A[0]=="0") cout << '0';
    else for (int i=0;i<N;i++) cout << A[i];
}