#include <bits/stdc++.h>
using namespace std;

int N;
pair<char,char> node[26];

string preorder_traversal(char now) {
    char l = node[now-'A'].first, r = node[now-'A'].second;

    string ans;
    ans += now;
    if (l != '.') ans += preorder_traversal(l);
    if (r != '.') ans += preorder_traversal(r);

    return ans;
}
string inorder_traversal(char now) {
    char l = node[now-'A'].first, r = node[now-'A'].second;

    string ans;
    if (l != '.') ans += inorder_traversal(l);
    ans += now;
    if (r != '.') ans += inorder_traversal(r);

    return ans;
}
string postorder_traversal(char now) {
    char l = node[now-'A'].first, r = node[now-'A'].second;

    string ans;
    if (l != '.') ans += postorder_traversal(l);
    if (r != '.') ans += postorder_traversal(r);
    ans += now;

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        char a, b, c; cin >> a >> b >> c;
        node[a-'A'] = {b,c};
    }

    cout << preorder_traversal('A')  << endl;
    cout << inorder_traversal('A')   << endl;
    cout << postorder_traversal('A') << endl;
}