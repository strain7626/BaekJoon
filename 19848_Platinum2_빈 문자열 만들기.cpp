#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string S; cin>>S;

    vector<int> p={1};
    for(int i=1;i<S.size();i++) if(S[i]==S[i-1]) p.back()++; else p.emplace_back(1);
    p.emplace_back(0);
    p.emplace_back(0);

    vector<pair<int,int>> s,ans;
    for(int i=0;i<p.size();i++) {
        if(s.size()>2||(!p[i]&&s.size()>1)) {
            auto [p1,l1]=s.back(); s.pop_back();
            auto [p2,l2]=s.back(); s.pop_back();
            int m=min(l1,l2);

            ans.emplace_back(p2+l2-m,p2+l2+m-1);

            if(l1<l2) p[i]+=l2-l1;
            if(l1>l2) { if(s.empty()) s.emplace_back(1,l1-l2); else s.back().second+=l1-l2; }
        }
        s.emplace_back(s.empty()?1:s.back().first+s.back().second,p[i]);
    }
    
    cout<<ans.size()<<'\n';
    for(auto [b,e]:ans) cout<<b<<' '<<e<<'\n';
}