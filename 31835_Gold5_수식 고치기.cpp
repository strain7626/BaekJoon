#include <bits/stdc++.h>

using namespace std;

int N;
bool A[1999],R,T;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    char x;
    for(int i=0;i<N;i++) {
        cin>>x;
        A[i]=(i%2?x-'&':x-'F');
    }
    cin>>x;T=x-'F';
    
    R=A[0];
    for(int i=1;i<N;i+=2) R=(A[i]?R|A[i+1]:R&A[i+1]);
    if(R==T) {
        cout<<0;
        return 0;
    }
    
    for(int i=0;i<N;i++) {
        A[i]=!A[i];
        R=A[0];
        for(int i=1;i<N;i+=2) R=(A[i]?R|A[i+1]:R&A[i+1]);
        if(R==T) {
            cout<<1;
            return 0;
        }
        A[i]=!A[i];
    }
    cout<<2;
}