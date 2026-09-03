#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    stack<char> s;
    for (char ch : str) {
        s.push(ch);
    }
    cout << "Reversed string: ";
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
    return 0;
}