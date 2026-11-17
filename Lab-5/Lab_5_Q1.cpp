#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};
void insertAtStart(Node*& head, int value) {
    Node* node = new Node(value);
    if (head == nullptr) {
        head = node;
        node->next = head;
        return;
    }
    Node* last = head;
    while (last->next != head)
        last = last->next;
    node->next = head;
    last->next = node;
    head = node;
}
void insertAtEnd(Node*& head, int value) {
    Node* node = new Node(value);
    if (head == nullptr) {
        head = node;
        node->next = head;
        return;
    }
    Node* last = head;
    while (last->next != head)
        last = last->next;
    last->next = node;
    node->next = head;
}

void insertAtPosition(Node*& head, int value, int position) {
    if (position <= 1) {
        insertAtStart(head, value);
        return;
    }
    if (head == nullptr) {
        cout << "Invalid position\n";
        return;
    }
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; i++)
        temp = temp->next;
    if (position > 1 && temp->next == head && position > 2) {
        cout << "Invalid position\n";
        return;
    }
    Node* node = new Node(value);
    node->next = temp->next;
    temp->next = node;
}
void deleteAtStart(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }
    Node* last = head;
    while (last->next != head)
        last = last->next;
    Node* temp = head;
    head = head->next;
    last->next = head;
    delete temp;
}
void deleteAtEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    if (head->next == head) {

        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != head)
        temp = temp->next;
    delete temp->next;
    temp->next = head;
}
void deleteAtPosition(Node*& head, int position) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    if (position <= 1) {
        deleteAtStart(head);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; i++)
        temp = temp->next;
    if (temp->next == head) {
        cout << "Invalid position\n";
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}
void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to head)\n";
}
void freeList(Node*& head) {
    if (head == nullptr) return;

    Node* temp = head->next;
    while (temp != head) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    delete head;
    head = nullptr;
}
int main() {
    Node* head = nullptr;
    insertAtStart(head, 20);
    insertAtStart(head, 10);
    insertAtEnd(head, 40);
    insertAtPosition(head, 30, 3);
    cout << "After insertions: ";
    display(head);
    deleteAtStart(head);
    cout << "After deleting first node: ";
    display(head);
    deleteAtPosition(head, 2);
    cout << "After deleting position 2: ";
    display(head);
    deleteAtEnd(head);
    cout << "After deleting last node: ";
    display(head);
    freeList(head);
    return 0;
}
