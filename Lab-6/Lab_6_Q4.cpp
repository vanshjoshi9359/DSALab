#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int value) : data(value), prev(this), next(this) {}
};
void insertAtEnd(Node*& head, int value) {
    Node* node = new Node(value);
    if (head == nullptr) {
        head = node;
        return;
    }
    Node* last = head->prev;
    node->next = head;
    node->prev = last;
    last->next = node;
    head->prev = node;
}
Node* reverseList(Node* head) {
    if (head == nullptr) return nullptr;
    Node* curr = head;
    do {
        Node* oldNext = curr->next;
        curr->next = curr->prev;
        curr->prev = oldNext;
        curr = oldNext;
    } while (curr != head);
    return head->next;
}
void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    Node* curr = head;
    do {
        cout << curr->data << " <-> ";
        curr = curr->next;
    } while (curr != head);
    cout << "(back to head)\n";
}
int main() {
    Node* head = nullptr;
    insertAtEnd(head, 10);

    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    cout << "Original list: ";
    display(head);
    head = reverseList(head);
    cout << "Reversed list: ";
    display(head);
    return 0;
}
