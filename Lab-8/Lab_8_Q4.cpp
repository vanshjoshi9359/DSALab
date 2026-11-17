#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};
void insert(Node*& root, int x) {
    if (root == nullptr) {
        root = new Node(x);
    } else if (x < root->data) {
        insert(root->left, x);
    } else {
        insert(root->right, x);
    }
}
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main() {
    vector<int> a = {8, 3, 6, 1, 9, 4, 7, 2};
    Node* root = nullptr;
    for (int x : a) insert(root, x);
    cout << "Sorted array: ";
    inorder(root);
    cout << '\n';
    return 0;
}
