#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;cin>>T;for(int t=1;t<=T;t++){
        int N,S[500],ans=0;
        cin >> N;
        for (int i=0;i<N;i++) cin >> S[i];

        for (int k=0;k<N;k++) {
            vector<int> L;
            
            for (int i=k;i<N;i++) {
                if (L.empty()) L.push_back(S[i]);
                else {
                    auto it=lower_bound(L.begin(),L.end(),S[i]);
                    if (it==L.end()) L.push_back(S[i]);
                    else *it=S[i];
                }
                ans+=L.size();
            }
        }

        cout << "Case #" << t << ": " << ans << '\n';
    }
}