#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
    int key; Node *left,*right; bool lthread,rthread;
    Node(int x):key(x),left(nullptr),right(nullptr),lthread(true),rthread(true){}
};
Node* insert(Node* root,int key) {
    if(!root) return new Node(key);
    Node* cur=root;
    while(true) {
        if(key==cur->key) return root;
        if(key<cur->key) {
            if(!cur->lthread) cur=cur->left;
            else {
                Node* n=new Node(key); n->left=cur->left; n->right=cur;
                cur->lthread=false; cur->left=n; return root;
            }
        } else {
            if(!cur->rthread) cur=cur->right;
            else {
                Node* n=new Node(key); n->right=cur->right; n->left=cur;
                cur->rthread=false; cur->right=n; return root;
            }
        }
    }
}
Node* leftMost(Node* n) {
    if(!n) return nullptr;
    while(!n->lthread) n=n->left;
    return n;
}
Node* rightMost(Node* n) {
    if(!n) return nullptr;
    while(!n->rthread) n=n->right;
    return n;
}
Node* search(Node* root,int key) {
    while(root) {
        if(key==root->key) return root;
        if(key<root->key) { if(root->lthread) return nullptr; root=root->left; }
        else { if(root->rthread) return nullptr; root=root->right; }
    }
    return nullptr;
}
Node* successor(Node* n) {
    if(!n) return nullptr;
    if(n->rthread) return n->right;
    return leftMost(n->right);
}
Node* predecessor(Node* n) {
    if(!n) return nullptr;
    if(n->lthread) return n->left;
    return rightMost(n->left);
}
void convertToThreads(Node* root,Node*& prev) {
    if(!root) return;
    if(!root->lthread) convertToThreads(root->left,prev);
    if(!root->left) { root->lthread=true; root->left=prev; }
    if(prev && !prev->right) { prev->rthread=true; prev->right=root; }
    prev=root;
    if(!root->rthread) convertToThreads(root->right,prev);
}
void rangePrint(Node* root,int L,int R) {
    Node* cur=leftMost(root);
    while(cur && cur->key<L) cur=successor(cur);
    while(cur && cur->key<=R) { cout<<cur->key<<" "; cur=successor(cur); }
    cout<<"\n";
}
int main() {
    int a[]={40,20,60,10,30,50,70};
    Node* root=nullptr;
    for(int x:a) {
        if(!root) root=new Node(x),root->lthread=false,root->rthread=false;
        else {
            Node* cur=root;
            while(true) {
                if(x<cur->key) {
                    if(cur->left) cur=cur->left;
                    else { cur->left=new Node(x); cur=cur->left; break; }
                } else {
                    if(cur->right) cur=cur->right;
                    else { cur->right=new Node(x); cur=cur->right; break; }
                }
            }
            cur->lthread=false; cur->rthread=false;
        }
    }
    Node* prev=nullptr;
    vector<Node*> st; if(root) st.push_back(root);
    while(!st.empty()) {
        Node* n=st.back(); st.pop_back();
        n->lthread=false; n->rthread=false;
        if(n->left) st.push_back(n->left);
        if(n->right) st.push_back(n->right);
    }
    convertToThreads(root,prev);
    if(prev && !prev->right) { prev->rthread=true; prev->right=nullptr; }
    Node* n=search(root,30);
    Node* nx=successor(n); Node* pr=predecessor(n);
    cout<<"NEXT 30 = "; if(nx) cout<<nx->key; else cout<<"NULL";
    cout<<"\nPREV 30 = "; if(pr) cout<<pr->key; else cout<<"NULL";
    cout<<"\nRANGE 25 60 = "; rangePrint(root,25,60);
    cout<<"KTH 5 = ";
    int k=5,count=0; Node* cur=leftMost(root);
    while(cur && ++count<k) cur=successor(cur);
    if(cur && count==k) cout<<cur->key; else cout<<"NULL";
    cout<<"\n"; return 0;
}
