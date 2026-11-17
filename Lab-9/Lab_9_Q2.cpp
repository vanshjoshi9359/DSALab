#include <iostream>
using namespace std;
struct Node { int data; Node *left,*right; Node(int x):data(x),left(nullptr),right(nullptr){} };
void findSwapped(Node* root,Node*& prev,Node*& first,Node*& second) {
    if (!root) return;
    findSwapped(root->left,prev,first,second);
    if (prev && prev->data>root->data) {
        if (!first) first=prev;
        second=root;
    }
    prev=root;
    findSwapped(root->right,prev,first,second);
}
void recoverBST(Node* root) {
    Node *prev=nullptr,*first=nullptr,*second=nullptr;
    findSwapped(root,prev,first,second);
    if (first && second) swap(first->data,second->data);
}
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left); cout<<root->data<<" "; inorder(root->right);
}
int main() {
    Node* root=new Node(6);
    root->left=new Node(3); root->right=new Node(8);
    root->left->left=new Node(1); root->left->right=new Node(7);
    root->right->left=new Node(4); root->right->right=new Node(9);
    cout<<"Before recovery: "; inorder(root);
    recoverBST(root);
    cout<<"\nAfter recovery: "; inorder(root);
    return 0;
}
