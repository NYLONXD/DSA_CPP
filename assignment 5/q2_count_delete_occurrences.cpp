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

    int countOccurrences(int key) {
        int count = 0;
        Node* temp = head;
        while (temp) {
            if (temp->data == key) count++;
            temp = temp->next;
        }
        return count;
    }

    void deleteAllOccurrences(int key) {
        while (head && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        Node* temp = head;
        while (temp && temp->next) {
            if (temp->next->data == key) {
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
            } else {
                temp = temp->next;
            }
        }
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

    cout << "Creating list: 1->2->1->2->1->3->1\n";
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(3);
    list.insert(1);

    cout << "Original ";
    list.display();

    int key = 1;
    int count = list.countOccurrences(key);
    cout << "\nCount of " << key << ": " << count << "\n";

    list.deleteAllOccurrences(key);
    cout << "After deleting all occurrences of " << key << ":\n";
    list.display();

    return 0;
}
