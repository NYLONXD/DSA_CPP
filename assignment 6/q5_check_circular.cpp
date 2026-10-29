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
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void makeCircular(Node* loopNode) {
        if (!head) return;
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = loopNode;
    }

    bool isCircular() {
        if (!head || !head->next) return false;

        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }
        return false;
    }

    void displayLinear() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        cout << "List: ";
        Node* temp = head;
        int count = 0;
        while (temp && count < 10) {
            cout << temp->data;
            if (temp->next && count < 9) cout << " -> ";
            temp = temp->next;
            count++;
        }
        cout << "\n";
    }

    Node* getHead() {
        return head;
    }

    ~SLL() {
        Node* temp = head;
        set<Node*> visited;
        while (temp && visited.find(temp) == visited.end()) {
            visited.insert(temp);
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
    }
};

int main() {
    cout << "=== Example 1: Circular Linked List ===\n";
    SLL list1;

    cout << "Creating list: 2 -> 4 -> 6 -> 7 -> 5 -> 2 (circular)\n";
    list1.insert(2);
    list1.insert(4);
    list1.insert(6);
    list1.insert(7);
    list1.insert(5);

    list1.makeCircular(list1.getHead());

    cout << "Is Circular: " << (list1.isCircular() ? "True" : "False") << "\n\n";

    cout << "=== Example 2: Linear Linked List ===\n";
    SLL list2;

    cout << "Creating list: 1 -> 3 -> 5 -> 7 -> 9 (linear)\n";
    list2.insert(1);
    list2.insert(3);
    list2.insert(5);
    list2.insert(7);
    list2.insert(9);

    cout << "List: ";
    list2.displayLinear();
    cout << "Is Circular: " << (list2.isCircular() ? "True" : "False") << "\n";

    return 0;
}
