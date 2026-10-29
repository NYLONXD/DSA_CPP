#include <iostream>
#include <unordered_set>
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

    Node* getHead() {
        return head;
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

Node* findIntersection(Node* headA, Node* headB) {
    unordered_set<Node*> visited;
    Node* temp = headA;

    while (temp) {
        visited.insert(temp);
        temp = temp->next;
    }

    temp = headB;
    while (temp) {
        if (visited.find(temp) != visited.end()) {
            return temp;
        }
        temp = temp->next;
    }

    return nullptr;
}

int main() {
    SLL list1, list2;

    cout << "Creating listA: 4->1->8->5\n";
    list1.insert(4);
    list1.insert(1);
    list1.insert(8);
    list1.insert(5);

    cout << "Creating listB: 5->6->1->8->5 (shares 8->5 with listA)\n";
    SLL tempList;
    tempList.insert(5);
    tempList.insert(6);
    tempList.insert(1);

    Node* headA = list1.getHead();
    Node* headB = tempList.getHead();

    Node* intersection = findIntersection(headA, headB);

    if (intersection) {
        cout << "Intersection found at node with value: " << intersection->data << "\n";
    } else {
        cout << "No intersection found\n";
    }

    return 0;
}
