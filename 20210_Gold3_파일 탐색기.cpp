#include <bits/stdc++.h>

using namespace std;

struct cell{
    string s;
    bool isN() {
        return '0'<=s[0]&&s[0]<='9';
    }
    bool operator<(cell x) {
        if (isN()&&x.isN()) {
            string t1=s,t2=x.s;
            if (t1.size()>t2.size()) t2=string(t1.size()-t2.size(),'0')+t2;
            else t1=string(t2.size()-t1.size(),'0')+t1;
            return t1==t2?s.size()<x.s.size():t1<t2;
        }
        if (isN()) return 1;
        if (x.isN()) return 0;

        char a=s[0],b=x.s[0];
        bool c=0,d=0;
        if (a>='a') a-=('a'-'A'),c=1;
        if (b>='a') b-=('a'-'A'),d=1;

        return (a==b?c&!d:a<b);
    }
};

int N;
vector<cell> S[100];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;for(int i=0;i<N;i++){
        string T;cin>>T;
        for(char t:T){
            bool isN='0'<=t&&t<='9';
            if(!S[i].empty()&&isN&&S[i].back().isN())S[i].back().s=S[i].back().s+t;
            else S[i].push_back({string(1,t)});
        }
    }
    sort(S,S+N);

    for (int i=0;i<N;i++,cout<<'\n') for (auto j:S[i]) cout<<j.s;
}