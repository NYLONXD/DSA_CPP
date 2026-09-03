#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int evaluatePostfix(string expression) {
    stack<int> s;

    for (char ch : expression) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        }
        else {
            int b = s.top();
            s.pop();

            int a = s.top();
            s.pop();

            switch (ch) {

                case '+':
                    s.push(a + b);
                    break;

                case '-':
                    s.push(a - b);
                    break;

                case '*':
                    s.push(a * b);
                    break;

                case '/':
                    s.push(a / b);
                    break;

                case '^': {
                    int result = 1;
                    for (int i = 0; i < b; i++) {
                        result *= a;
                    }
                    s.push(result);
                    break;
                }
            }
        }
    }

    return s.top();
}

int main() {
    string postfix;

    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    cout << "Result = "
         << evaluatePostfix(postfix) << endl;

    return 0;
}