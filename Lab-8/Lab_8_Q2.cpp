#include <iostream>
#include <queue>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};
int minDepth(Node* root) {
    if (root == nullptr) return 0;
    queue<pair<Node*, int>> q;
    q.push({root, 1});
    while (!q.empty()) {
        Node* node = q.front().first;
        int depth = q.front().second;
        q.pop();
        if (node->left == nullptr && node->right == nullptr)
            return depth;
        if (node->left != nullptr)
            q.push({node->left, depth + 1});
        if (node->right != nullptr)
            q.push({node->right, depth + 1});
    }
    return 0;
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << "Minimum depth = " << minDepth(root);
    return 0;
}
