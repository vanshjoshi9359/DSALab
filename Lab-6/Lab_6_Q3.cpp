#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};
Node* reverseList(Node* head) {
    Node* curr = head;
    Node* newHead = nullptr;
    while (curr != nullptr) {
        Node* nextNode = curr->next;
        curr->next = curr->prev;
        curr->prev = nextNode;
        newHead = curr;
        curr = nextNode;
    }
    return newHead;
}
void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL\n";
}
int main() {
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    a->next = b; b->prev = a;
    b->next = c; c->prev = b;
    c->next = d; d->prev = c;
    cout << "Original list: ";
    display(a);
    Node* head = reverseList(a);
    cout << "Reversed list: ";
    display(head);
    return 0;
}
