#include <iostream>
using namespace std;

class Queue {
    int q[5];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
        //front = rear =0;
    }

    void enqueue(int x) {
        if (rear == 4) {
            cout << "Queue is full" << endl;
        }
        else {
            if (front == -1)
                front = 0;

            rear++;
            q[rear] = x;

            cout << x << " inserted" << endl;
        }
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
        }
        else {
            cout << q[front] << " deleted" << endl;
            front++;
        }
    }

    void isEmpty() {
        if (front == -1 || front > rear)
            cout << "Queue is empty" << endl;
        else
            cout << "Queue is not empty" << endl;
    }

    void isFull() {
        if (rear == 4)
            cout << "Queue is full" << endl;
        else
            cout << "Queue is not full" << endl;
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
        }
        else {
            cout << "Queue: ";

            for (int i = front; i <= rear; i++)
                cout << q[i] << " ";

            cout << endl;
        }
    }

    void peek() {
        if (front == -1 || front > rear)
            cout << "Queue is empty" << endl;
        else
            cout << "Front element: " << q[front] << endl;
    }
};

int main() {
    Queue q;
    int choice, x;

    do {
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Is Empty";
        cout << "\n4. Is Full";
        cout << "\n5. Display";
        cout << "\n6. Peek";
        cout << "\n7. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> x;
            q.enqueue(x);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.isEmpty();
            break;

        case 4:
            q.isFull();
            break;

        case 5:
            q.display();
            break;

        case 6:
            q.peek();
            break;

        case 7:
            cout << "Exit";
            break;

        default:
            cout << "Invalid choice";
        }

    } while (choice != 7);

    return 0;
}

