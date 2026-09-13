#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:
    void push(int value) {
        // Put new element in q2
        q2.push(value);

        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is Empty\n";
            return;
        }

        cout << q1.front() << " popped from stack.\n";
        q1.pop();
    }

    void peek() {
        if (q1.empty()) {
            cout << "Stack is Empty\n";
        } else {
            cout << "Top element: " << q1.front() << endl;
        }
    }

    void display() {
        if (q1.empty()) {
            cout << "Stack is Empty\n";
            return;
        }

        queue<int> temp = q1;

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
        cout << "\n----- STACK USING TWO QUEUES -----\n";
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
