/*
yong0315님의 코드를 참고해서 따닥따닥 붙여놓는 코드타입으로 작성했는데 yong0315님의 코드를 확인하니 정상적인 코드였다.
그냥 그날 기분따라 다르게 작성하시는 듯. 참고로 yong0315님은 PQ로 품.
DQ를 이용한 최댓값 트릭, 그중에서도 DP를 제대로 이해할 수 있었던 문제였다.
시작점과 종료점을 마음대로 정할 수 있다는 점을 간과해서 첫 시도를 틀렸다.
게시판을 보고 한 고수분의 게시물을 읽고 맞추었다. 다들 DQ를 (값, 인덱스) 형식으로 pair<int,int>로
작성하는데 나는 pair<int,int>를 사용하면 코드가 길어진다고 생각해서 최대한 인덱스만 활용하는 방식으로
앞으로의 DQ+DP문제를 해결해 나갈 것 같다. 이번 코드에서는 그냥 A[i]값도 쓰기 싫어서
반복문 하나만으로 해결했다.
*/

#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll N,D,DP[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>D;
    deque<int>DQ;DQ.push_back(0);
    for (int i=1;i<=N;i++) {
        ll x;cin>>x;
        if(DQ.front()<i-D)DQ.pop_front();
        DP[i]=x+(DP[DQ.front()]>0?DP[DQ.front()]:0);
        while(!DQ.empty()&&DP[i]>=DP[DQ.back()])DQ.pop_back();
        DQ.push_back(i);
    }
    cout<<*max_element(DP+1,DP+N+1);
}   