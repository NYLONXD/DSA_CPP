#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;

public:
    void push(int value) {
        int size = q.size();

        q.push(value);

        // Move previous elements behind the new element
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is Empty\n";
            return;
        }

        cout << q.front() << " popped from stack.\n";
        q.pop();
    }

    void peek() {
        if (q.empty()) {
            cout << "Stack is Empty\n";
        } else {
            cout << "Top element: " << q.front() << endl;
        }
    }

    void display() {
        if (q.empty()) {
            cout << "Stack is Empty\n";
            return;
        }

        queue<int> temp = q;

        cout << "Stack elements: ";

        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n----- STACK USING ONE QUEUE -----\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            s.display();
            break;

        case 5:
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
