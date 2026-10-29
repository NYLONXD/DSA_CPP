#include <iostream>
using namespace std;

struct NodeDLL {
    int data;
    NodeDLL* next;
    NodeDLL* prev;
};

struct NodeCLL {
    int data;
    NodeCLL* next;
};

class DLL {
private:
    NodeDLL* head;

public:
    DLL() : head(nullptr) {}

    void insert(int value) {
        NodeDLL* newNode = new NodeDLL{value, nullptr, nullptr};
        if (!head) {
            head = newNode;
        } else {
            NodeDLL* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    int getSize() {
        int count = 0;
        NodeDLL* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        if (!head) {
            cout << "DLL is empty\n";
            return;
        }
        NodeDLL* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " <-> ";
            temp = temp->next;
        }
        cout << "\n";
    }

    ~DLL() {
        while (head) {
            NodeDLL* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

class CLL {
private:
    NodeCLL* head;

public:
    CLL() : head(nullptr) {}

    void insert(int value) {
        NodeCLL* newNode = new NodeCLL{value, nullptr};
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            NodeCLL* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    int getSize() {
        if (!head) return 0;
        int count = 1;
        NodeCLL* temp = head->next;
        while (temp != head) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        if (!head) {
            cout << "CLL is empty\n";
            return;
        }
        NodeCLL* temp = head;
        do {
            cout << temp->data;
            if (temp->next != head) cout << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "\n";
    }

    ~CLL() {
        if (head) {
            NodeCLL* temp = head;
            while (temp->next != head) {
                NodeCLL* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
            delete head;
        }
    }
};

int main() {
    DLL dll;
    CLL cll;

    cout << "=== Doubly Linked List ===\n";
    cout << "Creating DLL: 10 <-> 20 <-> 30 <-> 40\n";
    dll.insert(10);
    dll.insert(20);
    dll.insert(30);
    dll.insert(40);

    cout << "DLL: ";
    dll.display();
    cout << "Size of DLL: " << dll.getSize() << "\n\n";

    cout << "=== Circular Linked List ===\n";
    cout << "Creating CLL: 5 -> 10 -> 15 -> 20 -> 25\n";
    cll.insert(5);
    cll.insert(10);
    cll.insert(15);
    cll.insert(20);
    cll.insert(25);

    cout << "CLL: ";
    cll.display();
    cout << "Size of CLL: " << cll.getSize() << "\n";

    return 0;
}
