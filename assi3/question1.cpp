#include <iostream>
using namespace std;

const int MAX = 100;

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == MAX - 1;
    }

    // Push element
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Stack is full.\n";
            return;
        }

        arr[++top] = value;
        cout << value << " pushed into stack.\n";
    }

    // Pop element
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Stack is empty.\n";
            return;
        }

        cout << arr[top--] << " popped from stack.\n";
    }

    // Peek element
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Top element is: " << arr[top] << endl;
    }

    // Display stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack elements are:\n";

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n===== STACK MENU =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
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
                if (s.isEmpty())
                    cout << "Stack is Empty.\n";
                else
                    cout << "Stack is NOT Empty.\n";
                break;

            case 4:
                if (s.isFull())
                    cout << "Stack is Full.\n";
                else
                    cout << "Stack is NOT Full.\n";
                break;

            case 5:
                s.display();
                break;

            case 6:
                s.peek();
                break;

            case 7:
                cout << "Program terminated.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}