#include <bits/stdc++.h>
#define MAXN 1000000
using namespace std;

int N, A[MAXN], DP[MAXN];
vector<pair<int,int>> LIS;

void LIS_insert(int val, int idx) {
    int start = 0, end = LIS.size()-1;
    
    while (start <= end) {
        int mid = (start+end)/2;
        if (LIS[mid].first >= val) end = mid-1;
        else start = mid+1;
    }

    if (LIS.size() == start) LIS.push_back({val,idx});
    else LIS[start] = {val,idx};

    if(start == 0) DP[idx] = -1;
    else DP[idx] = LIS[start-1].second;
}

void LIS_print() {
    vector<int> ans;
    int cur = LIS.back().second;
    ans.push_back(A[cur]);
    while (DP[cur] != -1) {
        cur = DP[cur];
        ans.push_back(A[cur]);
    }

    for (int i = ans.size()-1; i >= 0; i--) cout << ans[i] << " ";
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = 0; i < N; i++) LIS_insert(A[i],i);
    
    cout << LIS.size() << endl;
    LIS_print();
}