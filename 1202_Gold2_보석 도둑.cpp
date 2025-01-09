#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
pair<int, int> P1;
int N, K, result;
int M[300000], V[300000], C[300000];

int main(){
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> M[i] >> V[i];
    for (int i = 0; i < K; i++) cin >> C[i]; 
    sort(C, C+K);
    
    for (int i = 0; i < K; i++) 
    {
        int max = 0;
        for (int j = 0; j < N; j++) 
        {
            if (M[j] < C[i] && V[j] > max)
            {
                max = j;
            }

        }
        M[i] = 100000001;
        result += V[max];
    }

    cout << result;

    return 0;
}