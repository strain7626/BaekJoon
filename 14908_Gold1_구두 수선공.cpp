#include <bits/stdc++.h>

using namespace std;
using pid = pair<int,double>;

int N;
pid SpT[1000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> N;
    for (int i=0;i<N;i++) {
        double T,S;cin>>T>>S;
        SpT[i]={i+1,S/T};
    }
    sort(SpT,SpT+N,[](pid a,pid b){return (a.second==b.second?a.first<b.first:a.second>b.second);});

    for (int i=0;i<N;i++) cout << SpT[i].first << ' ';
}