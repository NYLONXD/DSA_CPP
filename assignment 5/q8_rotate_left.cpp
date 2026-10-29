#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SLL {
private:
    Node* head;

public:
    SLL() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    int getLength() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void rotateLeft(int k) {
        if (!head || !head->next) return;

        int length = getLength();
        k = k % length;

        if (k == 0) return;

        Node* temp = head;
        for (int i = 0; i < k - 1; i++) {
            temp = temp->next;
        }

        Node* newHead = temp->next;
        temp->next = nullptr;

        Node* last = newHead;
        while (last->next) {
            last = last->next;
        }

        last->next = head;
        head = newHead;
    }

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        cout << "List: ";
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL\n";
    }

    ~SLL() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SLL list;

    cout << "Creating list: 10->20->30->40->50\n";
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);

    cout << "Original ";
    list.display();

    cout << "\nRotating left by 4 positions...\n";
    list.rotateLeft(4);

    cout << "After rotation: ";
    list.display();

    return 0;
}
