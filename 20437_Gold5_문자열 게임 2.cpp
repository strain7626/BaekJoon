#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int T;cin>>T;while(T--){
        string W;int K,M=0,m=1e9;vector<int> A[26];
        cin>>W>>K;K--;
        for (int i=0;i<W.size();i++) A[W[i]-'a'].push_back(i);
        for (auto &a:A) for (int i=0;i+K<a.size();i++) M=max(M,a[i+K]-a[i]+1),m=min(m,a[i+K]-a[i]+1);
        if (M) cout<<m<<' '<<M;
        else cout<<-1;
        cout<<'\n';
    }
}