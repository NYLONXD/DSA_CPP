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

    void insertFirst(int value) {
        NodeDLL* newNode = new NodeDLL{value, head, nullptr};
        if (head) head->prev = newNode;
        head = newNode;
    }

    void insertLast(int value) {
        NodeDLL* newNode = new NodeDLL{value, nullptr, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        NodeDLL* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertBefore(int value, int beforeValue) {
        if (head && head->data == beforeValue) {
            insertFirst(value);
            return;
        }
        NodeDLL* temp = head;
        while (temp && temp->data != beforeValue) temp = temp->next;
        if (temp) {
            NodeDLL* newNode = new NodeDLL{value, temp, temp->prev};
            if (temp->prev) temp->prev->next = newNode;
            temp->prev = newNode;
        } else {
            cout << "Node not found\n";
        }
    }

    void insertAfter(int value, int afterValue) {
        NodeDLL* temp = head;
        while (temp && temp->data != afterValue) temp = temp->next;
        if (temp) {
            NodeDLL* newNode = new NodeDLL{value, temp->next, temp};
            if (temp->next) temp->next->prev = newNode;
            temp->next = newNode;
        } else {
            cout << "Node not found\n";
        }
    }

    void deleteNode(int value) {
        if (!head) return;
        if (head->data == value) {
            NodeDLL* temp = head;
            head = head->next;
            if (head) head->prev = nullptr;
            delete temp;
            return;
        }
        NodeDLL* temp = head;
        while (temp && temp->data != value) temp = temp->next;
        if (temp) {
            if (temp->next) temp->next->prev = temp->prev;
            if (temp->prev) temp->prev->next = temp->next;
            delete temp;
        } else {
            cout << "Node not found\n";
        }
    }

    void search(int value) {
        NodeDLL* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == value) {
                cout << "Node " << value << " found at position " << pos << "\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found\n";
    }

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        cout << "Forward: ";
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

    void insertFirst(int value) {
        NodeCLL* newNode = new NodeCLL{value, nullptr};
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            NodeCLL* temp = head;
            while (temp->next != head) temp = temp->next;
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }

    void insertLast(int value) {
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

    void insertBefore(int value, int beforeValue) {
        if (!head) return;
        if (head->data == beforeValue) {
            insertFirst(value);
            return;
        }
        NodeCLL* temp = head;
        while (temp->next != head && temp->next->data != beforeValue) {
            temp = temp->next;
        }
        if (temp->next->data == beforeValue) {
            NodeCLL* newNode = new NodeCLL{value, temp->next};
            temp->next = newNode;
        } else {
            cout << "Node not found\n";
        }
    }

    void insertAfter(int value, int afterValue) {
        if (!head) return;
        NodeCLL* temp = head;
        do {
            if (temp->data == afterValue) {
                NodeCLL* newNode = new NodeCLL{value, temp->next};
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found\n";
    }

    void deleteNode(int value) {
        if (!head) return;
        if (head->data == value) {
            if (head->next == head) {
                delete head;
                head = nullptr;
            } else {
                NodeCLL* temp = head;
                while (temp->next != head) temp = temp->next;
                temp->next = head->next;
                NodeCLL* toDelete = head;
                head = head->next;
                delete toDelete;
            }
            return;
        }
        NodeCLL* temp = head;
        while (temp->next != head && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next->data == value) {
            NodeCLL* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        } else {
            cout << "Node not found\n";
        }
    }

    void search(int value) {
        if (!head) return;
        NodeCLL* temp = head;
        int pos = 1;
        do {
            if (temp->data == value) {
                cout << "Node " << value << " found at position " << pos << "\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node not found\n";
    }

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        cout << "List: ";
        NodeCLL* temp = head;
        do {
            cout << temp->data;
            if (temp->next != head) cout << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << " -> " << head->data << "\n";
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
    int choice, type, value, beforeValue;

    while (true) {
        cout << "\n=== DLL and CLL Operations ===\n";
        cout << "1. Doubly Linked List\n";
        cout << "2. Circular Linked List\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 3) break;

        if (choice == 1) {
            DLL dll;
            int dllChoice;
            while (true) {
                cout << "\n--- DLL Operations ---\n";
                cout << "1. Insert First\n";
                cout << "2. Insert Last\n";
                cout << "3. Insert Before\n";
                cout << "4. Insert After\n";
                cout << "5. Delete\n";
                cout << "6. Search\n";
                cout << "7. Display\n";
                cout << "8. Back\n";
                cout << "Enter choice: ";
                cin >> dllChoice;

                switch (dllChoice) {
                    case 1:
                        cout << "Enter value: ";
                        cin >> value;
                        dll.insertFirst(value);
                        break;
                    case 2:
                        cout << "Enter value: ";
                        cin >> value;
                        dll.insertLast(value);
                        break;
                    case 3:
                        cout << "Enter value to insert: ";
                        cin >> value;
                        cout << "Before: ";
                        cin >> beforeValue;
                        dll.insertBefore(value, beforeValue);
                        break;
                    case 4:
                        cout << "Enter value to insert: ";
                        cin >> value;
                        cout << "After: ";
                        cin >> beforeValue;
                        dll.insertAfter(value, beforeValue);
                        break;
                    case 5:
                        cout << "Delete value: ";
                        cin >> value;
                        dll.deleteNode(value);
                        break;
                    case 6:
                        cout << "Search value: ";
                        cin >> value;
                        dll.search(value);
                        break;
                    case 7:
                        dll.display();
                        break;
                    case 8:
                        goto main_menu;
                }
            }
        } else if (choice == 2) {
            CLL cll;
            int cllChoice;
            while (true) {
                cout << "\n--- CLL Operations ---\n";
                cout << "1. Insert First\n";
                cout << "2. Insert Last\n";
                cout << "3. Insert Before\n";
                cout << "4. Insert After\n";
                cout << "5. Delete\n";
                cout << "6. Search\n";
                cout << "7. Display\n";
                cout << "8. Back\n";
                cout << "Enter choice: ";
                cin >> cllChoice;

                switch (cllChoice) {
                    case 1:
                        cout << "Enter value: ";
                        cin >> value;
                        cll.insertFirst(value);
                        break;
                    case 2:
                        cout << "Enter value: ";
                        cin >> value;
                        cll.insertLast(value);
                        break;
                    case 3:
                        cout << "Enter value to insert: ";
                        cin >> value;
                        cout << "Before: ";
                        cin >> beforeValue;
                        cll.insertBefore(value, beforeValue);
                        break;
                    case 4:
                        cout << "Enter value to insert: ";
                        cin >> value;
                        cout << "After: ";
                        cin >> beforeValue;
                        cll.insertAfter(value, beforeValue);
                        break;
                    case 5:
                        cout << "Delete value: ";
                        cin >> value;
                        cll.deleteNode(value);
                        break;
                    case 6:
                        cout << "Search value: ";
                        cin >> value;
                        cll.search(value);
                        break;
                    case 7:
                        cll.display();
                        break;
                    case 8:
                        goto main_menu;
                }
            }
        }
        main_menu:;
    }

    return 0;
}
