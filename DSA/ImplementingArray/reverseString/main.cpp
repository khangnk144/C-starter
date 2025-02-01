#include <bits/stdc++.h>
using namespace std;
string reverse1(string str) {
    if (str.empty() || str.length() < 2) return str;

    string backwards;
    for (int i = str.length() - 1; i >= 0; i--) {
        backwards.push_back(str[i]);
    }
    return backwards;
}

string reverse2(string str) {
    string rev_str = str;
    reverse(rev_str.begin(), rev_str.end());
    return rev_str;
}
int main() {
    cout << reverse1("Hi everyone") << endl;
    cout << reverse2("Hi everyone") << endl;
    return 0;
}