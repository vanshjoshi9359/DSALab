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
    node->next = head;
    head = node;
}
void insertAtEnd(Node*& head, int value) {
    Node* node = new Node(value);
    if (head == nullptr) {
        head = node;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = node;
}
void insertAtPosition(Node*& head, int value, int position) {
    if (position <= 1) {
        insertAtStart(head, value);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++)
        temp = temp->next;
    if (temp == nullptr) {
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
    Node* temp = head;
    head = head->next;
    delete temp;
}
void deleteAtEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
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
    for (int i = 1; i < position - 1 && temp != nullptr; i++)
        temp = temp->next;
    if (temp == nullptr || temp->next == nullptr) {
        cout << "Invalid position\n";
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty";
    }
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}
void freeList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
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
    cout << "After deleting at start: ";
    display(head);
    deleteAtEnd(head);
    cout << "After deleting at end: ";
    display(head);
    deleteAtPosition(head, 2);
    cout << "After deleting at position 2: ";
    display(head);
    freeList(head);
    return 0;
}
