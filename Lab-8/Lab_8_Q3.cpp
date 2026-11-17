#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};
void inorder(Node* root, vector<int>& values) {
    if (root == nullptr) return;
    inorder(root->left, values);
    values.push_back(root->data);
    inorder(root->right, values);
}
void insert(Node*& root, int x) {
    if (root == nullptr) {
        root = new Node(x);
        return;
    }
    if (x < root->data) insert(root->left, x);
    else insert(root->right, x);
}
int main() {
    Node* root = nullptr;
    int values[] = {5, 3, 7, 2, 4, 6, 8};
    for (int x : values) insert(root, x);
    int k = 2;
    vector<int> sorted;
    inorder(root, sorted);
    if (k < 1 || k > (int)sorted.size()) {
        cout << "Invalid k";
    } else {
        cout << k << "-th smallest = " << sorted[k - 1] << '\n';
        cout << k << "-th largest = "
             << sorted[sorted.size() - k] << '\n';
    }
    return 0;
}
