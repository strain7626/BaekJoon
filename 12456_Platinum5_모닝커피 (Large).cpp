#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using tl3 = tuple<ll,ll,ll>;

struct cmp {
    bool operator() (tl3 a,tl3 b) {
        return get<1>(a)<get<1>(b);
    }  
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int T;cin>>T;
    for (int X=1;X<=T;X++) {
        ll Y=0,D=0,N,K;
        priority_queue<tl3,vector<tl3>,cmp> PQ;
        
        cin>>N>>K;
        for (int i=0;i<N;i++) {
            ll c,t,s;cin>>c>>t>>s;
            PQ.push({c,min(t,K),s});
        }

        while (!PQ.empty()) {
            ll c1,t1,s1;tie(c1,t1,s1)=PQ.top();PQ.pop();
            while (!PQ.empty()) {
                ll c2,t2,s2;tie(c2,t2,s2)=PQ.top();
                if (t1-c1>=t2) break;
                PQ.pop();

                if (s1>s2) {
                    if (t1-c1>0) PQ.push({c2,t1-c1,s2});
                } else {
                    Y+=s1*(t1-t2);
                    if (t2-c2>0) PQ.push({c1-(t1-t2),t2-c2,s1});
                    c1=c2,t1=t2,s1=s2;
                }
            }
            Y+=s1*min(c1,t1);
        }

        cout << "Case #" << X << ": " << Y << '\n';
    }
}