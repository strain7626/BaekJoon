#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int             N;
vector<bool>    A;
vector<int>     B;
pair<int,ll>    ans;
vector<vector<ll>> DP;

int main() {
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    
    cin >> N;
    A.resize(N); B.resize(N); DP.resize(N); for (auto& dp : DP) dp.resize(N);

    for (int i = 0; i < N; i++) {
        bool t;
        cin >> t;
        A[i] = t;
    }
    for (int& b : B) cin >> b;


}




/*
input :
1 1 0 0 1
1 2 3 4 5

prefix sum :
1 3 6 10 15 ->
1 3 0 -4 1






*/