#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CLL {
private:
    Node* head;

public:
    CLL() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << ".\n";
    }

    ~CLL() {
        if (head) {
            Node* temp = head;
            while (temp->next != head) {
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
            delete head;
        }
    }
};

int main() {
    CLL list;

    cout << "Creating CLL: 20 -> 100 -> 40 -> 80 -> 60\n";
    list.insert(20);
    list.insert(100);
    list.insert(40);
    list.insert(80);
    list.insert(60);

    cout << "Output: ";
    list.display();

    return 0;
}
