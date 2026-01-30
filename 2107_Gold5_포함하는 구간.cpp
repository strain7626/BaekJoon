#include <bits/stdc++.h>

using namespace std;

int N,ans[25000];
pair<int,int> A[25000];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i=0;i<N;i++) cin >> A[i].first >> A[i].second;

    sort(A,A+N);
    for (int i=0;i<N;i++) for (int j=i+1;j<N;j++) ans[i]+=(A[j].second<A[i].second);
    cout << *max_element(ans,ans+N);
}