#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    int result = 0;
    int lst[1000];

    for (int i = 0; i < N; i++) cin >> lst[i];
    sort(lst, lst+N);
    
    for (int i = 0; i < N; i++) result += lst[i]*(N-i);
    cout << result;
}