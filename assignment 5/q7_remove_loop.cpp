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

    void createLoop(Node* loopNode) {
        if (!head) return;
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = loopNode;
    }

    bool detectLoop() {
        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) return true;
        }

        return false;
    }

    void removeLoop() {
        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                break;
            }
        }

        if (!fast || !fast->next) return;

        slow = head;
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        fast->next = nullptr;
    }

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        cout << "List: ";
        Node* temp = head;
        int count = 0;
        while (temp && count < 100) {
            cout << temp->data;
            if (temp->next) cout << " -> ";
            temp = temp->next;
            count++;
        }
        if (count >= 100) cout << " (loop detected)";
        cout << " -> NULL\n";
    }

    Node* getHead() {
        return head;
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

    cout << "Creating list: 1->7->3->6\n";
    Node* node1 = new Node{1, nullptr};
    Node* node2 = new Node{7, nullptr};
    Node* node3 = new Node{3, nullptr};
    Node* node4 = new Node{6, nullptr};

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    list.insert(1);
    list.insert(7);
    list.insert(3);
    list.insert(6);

    cout << "Original ";
    list.display();

    cout << "\nCreating loop (6 points to 7)...\n";
    list.createLoop(node2);

    cout << "Loop detected: " << (list.detectLoop() ? "Yes" : "No") << "\n";

    cout << "Removing loop...\n";
    list.removeLoop();

    cout << "After removing loop: ";
    list.display();

    return 0;
}
