#include <iostream>
using namespace std;

struct Node {
    int coefficient;
    int power;
    Node* next;
};

class Polynomial {
private:
    Node* head;

public:
    Polynomial() : head(nullptr) {}

    void insert(int coeff, int pow) {
        Node* newNode = new Node{coeff, pow, nullptr};
        if (!head) {
            head = newNode;
            return;
        }

        if (pow > head->power) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->power > pow) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    Node* getHead() {
        return head;
    }

    void display() {
        if (!head) {
            cout << "Empty polynomial\n";
            return;
        }
        cout << "Polynomial: ";
        Node* temp = head;
        bool first = true;
        while (temp) {
            if (!first && temp->coefficient > 0) cout << "+ ";
            cout << temp->coefficient << "x^" << temp->power;
            if (temp->next) cout << " ";
            temp = temp->next;
            first = false;
        }
        cout << "\n";
    }

    ~Polynomial() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

Node* addPolynomials(Node* head1, Node* head2) {
    Node* result = nullptr;
    Node* tail = nullptr;

    Node* p1 = head1;
    Node* p2 = head2;

    while (p1 && p2) {
        Node* newNode = nullptr;

        if (p1->power > p2->power) {
            newNode = new Node{p1->coefficient, p1->power, nullptr};
            p1 = p1->next;
        } else if (p1->power < p2->power) {
            newNode = new Node{p2->coefficient, p2->power, nullptr};
            p2 = p2->next;
        } else {
            newNode = new Node{p1->coefficient + p2->coefficient, p1->power, nullptr};
            p1 = p1->next;
            p2 = p2->next;
        }

        if (!result) {
            result = newNode;
            tail = result;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    while (p1) {
        Node* newNode = new Node{p1->coefficient, p1->power, nullptr};
        tail->next = newNode;
        tail = newNode;
        p1 = p1->next;
    }

    while (p2) {
        Node* newNode = new Node{p2->coefficient, p2->power, nullptr};
        tail->next = newNode;
        tail = newNode;
        p2 = p2->next;
    }

    return result;
}

void displayResult(Node* head) {
    if (!head) {
        cout << "Result: Empty\n";
        return;
    }
    cout << "Result: ";
    Node* temp = head;
    bool first = true;
    while (temp) {
        if (!first && temp->coefficient > 0) cout << "+ ";
        cout << temp->coefficient << "x^" << temp->power;
        if (temp->next) cout << " ";
        temp = temp->next;
        first = false;
    }
    cout << "\n";
}

int main() {
    Polynomial p1, p2;

    cout << "Polynomial 1: 5x^2 + 4x^1 + 2x^0\n";
    p1.insert(5, 2);
    p1.insert(4, 1);
    p1.insert(2, 0);
    p1.display();

    cout << "\nPolynomial 2: 5x^1 + 5x^0\n";
    p2.insert(5, 1);
    p2.insert(5, 0);
    p2.display();

    Node* result = addPolynomials(p1.getHead(), p2.getHead());

    cout << "\n";
    displayResult(result);

    Node* temp = result;
    while (temp) {
        Node* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }

    return 0;
}
