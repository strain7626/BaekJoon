#include <iostream>

using namespace std;

int stack[10000];
int top = 0;

int main() {
    int N;
    cin >> N;
    string manual;
    for (int i = 0; i < N; i++) {
        cin >> manual;
        if (manual == "push") {cin >> stack[top++];continue;}
        else if (manual == "pop") {
            if (top == 0) cout << -1;
            else {cout << stack[--top];stack[top]=0;} }
        else if (manual == "size") cout << top;
        else if (manual == "empty") cout << (top == 0 ? 1:0);
        else if (manual == "top") cout << (top == 0 ? -1:stack[top-1]);
        cout << endl;
    }

    return 0;
}