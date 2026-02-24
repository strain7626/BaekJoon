#include <bits/stdc++.h>

using namespace std;

int N,l,r,a,b,A[100000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];
    
    l=a=0,r=b=N-1;
    while(l<r) {
        if(abs(A[l]+A[r])<abs(A[a]+A[b])) a=l,b=r;
        abs(A[l])>abs(A[r])?l++:r--;
    }
    cout<<A[a]<<' '<<A[b];
}