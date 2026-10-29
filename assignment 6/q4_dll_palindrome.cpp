#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

class DLL {
private:
    Node* head;
    Node* tail;

public:
    DLL() : head(nullptr), tail(nullptr) {}

    void insert(char value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    bool isPalindrome() {
        if (!head) return true;
        Node* start = head;
        Node* end = tail;

        while (start && end && start != end) {
            if (start->data != end->data) {
                return false;
            }
            start = start->next;
            end = end->prev;
        }
        return true;
    }

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " <-> ";
            temp = temp->next;
        }
        cout << "\n";
    }

    ~DLL() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DLL list1, list2;

    cout << "=== Example 1: Palindrome ===\n";
    cout << "Creating DLL: L <-> E <-> V <-> E <-> L\n";
    list1.insert('L');
    list1.insert('E');
    list1.insert('V');
    list1.insert('E');
    list1.insert('L');

    cout << "List: ";
    list1.display();
    cout << "Is Palindrome: " << (list1.isPalindrome() ? "True" : "False") << "\n\n";

    cout << "=== Example 2: Not Palindrome ===\n";
    cout << "Creating DLL: A <-> B <-> C <-> D\n";
    list2.insert('A');
    list2.insert('B');
    list2.insert('C');
    list2.insert('D');

    cout << "List: ";
    list2.display();
    cout << "Is Palindrome: " << (list2.isPalindrome() ? "True" : "False") << "\n";

    return 0;
}
