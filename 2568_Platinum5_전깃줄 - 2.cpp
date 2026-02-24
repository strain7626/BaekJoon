#include <bits/stdc++.h>

using namespace std;
using pii=pair<int,int>;

int N,pre[100000];
pii AB[100000];
vector<int> LIS;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=0;i<N;i++) cin>>AB[i].first>>AB[i].second;
    sort(AB,AB+N);

    for(int i=0;i<N;i++) {
        int l=0,r=LIS.size();
        while(l<r) {
            int m=(l+r)/2;
            if(AB[i].second>AB[LIS[m]].second) l=m+1;
            else r=m;
        }

        if(l==LIS.size()) LIS.push_back(i); else LIS[l]=i;
        if(l>0) pre[i]=LIS[l-1]; else pre[i]=-1;
    }
    
    int cur=LIS.back();
    vector<int> chk,ans;
    while(cur!=-1) {
        chk.push_back(AB[cur].first);
        cur=pre[cur];
    }
    
    int idx=0;
    reverse(chk.begin(),chk.end());
    for(int i=0;i<N;i++) {
        if(AB[i].first!=chk[idx]) ans.push_back(AB[i].first);
        else idx++;
    }

    cout<<ans.size()<<'\n';
    for(int i:ans) cout<<i<<'\n';
}