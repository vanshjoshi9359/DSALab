#include <iostream>
using namespace std;
struct Node {
    int data; Node *left,*right; bool lthread,rthread;
    Node(int x):data(x),left(nullptr),right(nullptr),lthread(false),rthread(false){}
};
void convert(Node* root,Node*& prev) {
    if(!root) return;
    if(!root->lthread) convert(root->left,prev);
    if(root->left==nullptr) { root->lthread=true; root->left=prev; }
    if(prev && prev->right==nullptr) { prev->rthread=true; prev->right=root; }
    prev=root;
    if(!root->rthread) convert(root->right,prev);
}
Node* leftMost(Node* n) {
    if(!n) return nullptr;
    while(!n->lthread) n=n->left;
    return n;
}
void inorderThreaded(Node* root) {
    for(Node* cur=leftMost(root);cur; ) {
        cout<<cur->data<<" ";
        if(cur->rthread) cur=cur->right;
        else cur=leftMost(cur->right);
    }
    cout<<"\n";
}
int main() {
    Node* root=new Node(10);
    root->left=new Node(5); root->right=new Node(20);
    root->left->left=new Node(2); root->left->right=new Node(8);
    root->right->left=new Node(15); root->right->right=new Node(25);
    Node* prev=nullptr; convert(root,prev);
    if(prev && prev->right==nullptr) { prev->rthread=true; prev->right=nullptr; }
    cout<<"Inorder traversal without recursion or stack: ";
    inorderThreaded(root);
    return 0;
}
