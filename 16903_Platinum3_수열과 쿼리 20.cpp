#include <bits/stdc++.h>

using namespace std;

struct nod{
    int nxt[2],cnt,val;
    nod(){nxt[0]=nxt[1]=val=-1;cnt=0;}
};

nod tri[6060606];
queue<int> que;

int rot;

int nnd(){
    int res=que.front();que.pop();
    tri[res]=nod();
    return res;
}

void add(int val){
    int cur=rot;
    for(int i=29;i>=0;i--){
        int bit=(val>>i)&1;
        if(tri[cur].nxt[bit]==-1) tri[cur].nxt[bit]=nnd();
        cur=tri[cur].nxt[bit];
        tri[cur].cnt++;
        if(i==0) tri[cur].val=val;
    }
}

void del(int val){
    int cur=rot;
    for(int i=29;i>=0;i--){
        int bit=(val>>i)&1;
        int son=tri[cur].nxt[bit];
        if(--tri[son].cnt==0){
            tri[cur].nxt[bit]=-1;
            tri[son].val=-1;
            que.push(son);
        }
        cur=son;
    }
}

int qry(int val){
    int cur=rot;
    for(int i=29;i>=0;i--){
        int bit=(val>>i)&1;
        if(tri[cur].nxt[!bit]!=-1) cur=tri[cur].nxt[!bit];
        else cur=tri[cur].nxt[bit];
    }
    return val^tri[cur].val;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    for(int i=1;i<6060606;i++) que.push(i);
    rot=nnd();
    add(0);
    int req;cin>>req;
    while(req--){
        int cmd,val;cin>>cmd>>val;
        if(cmd==1) add(val);
        else if(cmd==2) del(val);
        else cout<<qry(val)<<'\n';
    }
}