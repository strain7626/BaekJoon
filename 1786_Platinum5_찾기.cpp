#include <bits/stdc++.h>

using namespace std;

string A,B;
vector<int> pi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    getline(cin,A);
    getline(cin,B);

    pi.resize(B.size());pi[0]=0;
    
    int cnt=0;
    for(int i=1;i<B.size();i++) {
        while(cnt&&B[i]!=B[cnt]) cnt=pi[cnt-1];
        if(B[cnt]==B[i]) cnt++;
        pi[i]=cnt;
    }
    
    cnt=0;
    vector<int> ans;
    for(int i=0;i<A.size();i++) {
        while(cnt&&A[i]!=B[cnt]) cnt=pi[cnt-1];
        if(B[cnt]==A[i]) cnt++;
        
        if(cnt==B.size()) ans.push_back(i-cnt+2),cnt=pi[cnt-1];
    }

    cout<<ans.size()<<'\n';
    for(int i:ans) cout<<i<<' ';
}