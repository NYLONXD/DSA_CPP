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

    Node* reverseKGroup(Node* head, int k) {
        Node* current = head;
        int count = 0;

        Node* temp = current;
        while (temp && count < k) {
            temp = temp->next;
            count++;
        }

        if (count < k) return current;

        Node* prev = nullptr;
        current = head;
        count = 0;

        while (current && count < k) {
            Node* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        head->next = reverseKGroup(current, k);
        return prev;
    }

    void reverse(int k) {
        head = reverseKGroup(head, k);
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

    cout << "Example 1: List 1->2->3->4->5->6->7->8->9, K=3\n";
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.insert(7);
    list.insert(8);
    list.insert(9);

    cout << "Original ";
    list.display();

    list.reverse(3);

    cout << "After reversing groups of 3: ";
    list.display();

    SLL list2;
    cout << "\nExample 2: List 1->2->3->4->5->6->7->8, K=3\n";
    list2.insert(1);
    list2.insert(2);
    list2.insert(3);
    list2.insert(4);
    list2.insert(5);
    list2.insert(6);
    list2.insert(7);
    list2.insert(8);

    cout << "Original ";
    list2.display();

    list2.reverse(3);

    cout << "After reversing groups of 3: ";
    list2.display();

    return 0;
}
