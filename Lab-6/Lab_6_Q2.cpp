#include <iostream>
using namespace std;
const int SIZE = 5;
class ArrayStack {
    int arr[SIZE];
    int top;
public:
    ArrayStack() : top(-1) {}
    void push(int x) {
        if (top == SIZE - 1) {
            cout << "Array stack overflow\n";
            return;
        }
        arr[++top] = x;
    }
    void pop() {
        if (top == -1) {
            cout << "Array stack underflow\n";
            return;
        }
        cout << "Array stack popped: " << arr[top--] << '\n';
    }
    void display() {
        cout << "Array stack (top to bottom): ";
        for (int i = top; i >= 0; i--) cout << arr[i] << " ";
        cout << '\n';
    }
};
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};
class LinkedStack {
    Node* top;
public:
    LinkedStack() : top(nullptr) {}
    void push(int x) {
        Node* node = new Node(x);
        node->next = top;
        top = node;
    }
    void pop() {

        if (top == nullptr) {
            cout << "Linked stack underflow\n";
            return;
        }
        Node* temp = top;
        cout << "Linked stack popped: " << temp->data << '\n';
        top = top->next;
        delete temp;
    }
    void display() {
        cout << "Linked stack (top to bottom): ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << '\n';
    }
    ~LinkedStack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};
int main() {
    ArrayStack a;
    a.push(10);
    a.push(20);
    a.push(30);
    a.display();
    a.pop();
    a.display();
    LinkedStack l;
    l.push(10);
    l.push(20);
    l.push(30);
    l.display();
    l.pop();
    l.display();
    return 0;
}
