#include <bits/stdc++.h>

using namespace std;

int N,A[1000000],pre[1000000];
vector<int> LIS;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];

    for(int i=0;i<N;i++) {
        int l=0,r=LIS.size();
        while(l<r) {
            int m=(l+r)/2;
            if(A[i]>A[LIS[m]]) l=m+1;
            else r=m;
        }

        if(l==LIS.size()) LIS.push_back(i); else LIS[l]=i;
        if(l>0) pre[i]=LIS[l-1]; else pre[i]=-1;
    }
    
    int cur=LIS.back();
    vector<int> ans;
    while(cur!=-1) {
        ans.push_back(A[cur]);
        cur=pre[cur];
    }

    cout<<ans.size()<<'\n';
    reverse(ans.begin(),ans.end());
    for(int i:ans) cout<<i<<' ';
}