#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int N,K;

struct Trie{
    int cnt;
    Trie* chd[2];

    Trie() {cnt=0;chd[0]=chd[1]=nullptr;}
    ~Trie() {delete chd[0];delete chd[1];}

    void insert(int num,int bit) {
        cnt++;
        if(bit<0) return; 
        if(!chd[(num>>bit)&1]) chd[(num>>bit)&1]=new Trie;
        chd[(num>>bit)&1]->insert(num,bit-1);
    }
    
    int find(int cur,int bit) {
        if(bit<0) return 0;
        int tmp=cur>>bit&1;
        if(K>>bit&1) return (chd[!tmp]?chd[!tmp]->find(cur,bit-1):0)+(chd[tmp]?chd[tmp]->cnt:0);
        else return (chd[tmp]?chd[tmp]->find(cur,bit-1):0);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    Trie T;
    int cur=0;
    T.insert(0,20);

    cin>>N>>K;

    long long ans=0;
    for(int i=0,a;i<N;i++) {
        cin>>a;
        cur^=a;
        ans+=T.find(cur,20);
        T.insert(cur,20);
    }
    cout<<ans;
}