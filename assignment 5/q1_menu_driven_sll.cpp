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

    void insertBeginning(int value) {
        Node* newNode = new Node{value, head};
        head = newNode;
    }

    void insertEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void insertBefore(int value, int beforeValue) {
        if (head && head->data == beforeValue) {
            insertBeginning(value);
            return;
        }
        Node* temp = head;
        while (temp && temp->next && temp->next->data != beforeValue) {
            temp = temp->next;
        }
        if (temp && temp->next) {
            Node* newNode = new Node{value, temp->next};
            temp->next = newNode;
        } else {
            cout << "Node " << beforeValue << " not found\n";
        }
    }

    void insertAfter(int value, int afterValue) {
        Node* temp = head;
        while (temp && temp->data != afterValue) temp = temp->next;
        if (temp) {
            Node* newNode = new Node{value, temp->next};
            temp->next = newNode;
        } else {
            cout << "Node " << afterValue << " not found\n";
        }
    }

    void deleteBeginning() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteNode(int value) {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        if (head->data == value) {
            deleteBeginning();
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != value) temp = temp->next;
        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        } else {
            cout << "Node " << value << " not found\n";
        }
    }

    void search(int value) {
        Node* temp = head;
        int position = 1;
        while (temp) {
            if (temp->data == value) {
                cout << "Node " << value << " found at position " << position << "\n";
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "Node " << value << " not found\n";
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
    int choice, value, beforeValue, option;

    while (true) {
        cout << "\n=== Menu Driven SLL ===\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before a node\n";
        cout << "4. Insert after a node\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete a specific node\n";
        cout << "8. Search a node\n";
        cout << "9. Display list\n";
        cout << "10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter value before which to insert: ";
                cin >> beforeValue;
                list.insertBefore(value, beforeValue);
                break;
            case 4:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter value after which to insert: ";
                cin >> beforeValue;
                list.insertAfter(value, beforeValue);
                break;
            case 5:
                list.deleteBeginning();
                break;
            case 6:
                list.deleteEnd();
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;
            case 9:
                list.display();
                break;
            case 10:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}
