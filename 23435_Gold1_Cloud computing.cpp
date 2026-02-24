#include <bits/stdc++.h>

using namespace std;

int N,A[100000];
vector<int> B[100000];

bool Q(int I,int J) {
    cout<<"? "<<I<<' '<<J<<endl;
    char C;cin>>C;
    return C=='<';
}

int main() {
    cin>>N;
    for (int i=0;i<N;i++) A[i]=i;
    
    while (N>1) {
        for (int i=0;i+1<N;i+=2) {
            if (Q(A[i],A[i+1])) {
                B[A[i]].push_back(A[i+1]);
                A[i/2]=A[i];
            } else {
                B[A[i+1]].push_back(A[i]);
                A[i/2]=A[i+1];
            }
        }
        if (N%2) A[N/2]=A[N-1];
        N=(N+1)/2;
    }
    
    N=B[A[0]].size();
    while (N>1) {
        for (int i=0;i+1<N;i+=2) B[A[0]][i/2]=(Q(B[A[0]][i],B[A[0]][i+1])?B[A[0]][i]:B[A[0]][i+1]);
        if (N%2) B[A[0]][N/2]=B[A[0]][N-1];
        N=(N+1)/2;
    }

    cout<<"! "<<B[A[0]][0];
}