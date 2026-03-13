#include <bits/stdc++.h>

using namespace std;

struct Node{
    map<int,Node*> chd;

    ~Node(){for(auto &[a,b]:chd) delete b;}
    
    void insert(int bit,int n) {
        if(!chd[n>>bit&1]) chd[n>>bit&1]=new Node;
        if(bit) chd[n>>bit&1]->insert(bit-1,n);
    }
};

int solve(int bit,Node &A,Node &B) {
    int res=0;
    if(A.chd[0]&&B.chd[1]) res=max(res,(1<<bit)+solve(bit-1,*A.chd[0],*B.chd[1])); 
    if(A.chd[1]&&B.chd[0]) res=max(res,(1<<bit)+solve(bit-1,*A.chd[1],*B.chd[0])); 
    if(res) return res;
    if(A.chd[0]&&B.chd[0]) res=max(res,solve(bit-1,*A.chd[0],*B.chd[0])); 
    if(A.chd[1]&&B.chd[1]) res=max(res,solve(bit-1,*A.chd[1],*B.chd[1])); 
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    Node trie;

    int N;cin>>N;
    for(int i=0;i<N;i++) {
        int A;cin>>A;
        trie.insert(31,A);
    }

    cout<<solve(31,trie,trie);
}