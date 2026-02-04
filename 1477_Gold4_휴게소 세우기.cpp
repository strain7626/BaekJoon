#include <bits/stdc++.h>

using namespace std;

int N,M,L,A[52];

bool check(int x) {
    int cnt=0;
    for (int i=0;i<=N;i++) cnt+=(A[i]-1)/x;
    return cnt<=M;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M>>L;
    for (int i=0;i<N;i++) cin>>A[i]; 
    A[N]=0,A[N+1]=L;
    sort(A,A+N+2);

    for (int i=0;i<=N;i++) A[i]=A[i+1]-A[i];

    int l=1,r=L;
    while (l<r) {
        int m=(l+r)/2;

        if (check(m)) r=m;
        else l=m+1;
    }
    cout << l;
}