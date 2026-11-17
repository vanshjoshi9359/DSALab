#include <iostream>
#include <vector>
using namespace std;
struct Node { int data; Node *left,*right; Node(int x):data(x),left(nullptr),right(nullptr){} };
void insert(Node*& root,int x) {
    if(!root) root=new Node(x);
    else if(x<root->data) insert(root->left,x);
    else insert(root->right,x);
}
void inorder(Node* root,vector<int>& sorted) {
    if(!root) return;
    inorder(root->left,sorted); sorted.push_back(root->data); inorder(root->right,sorted);
}
int kthSmallest(const vector<int>& sorted,int k) {
    if(k<1 || k>(int)sorted.size()) return -1;
    return sorted[k-1];
}
int main() {
    Node* root=nullptr;
    int values[]={8,3,10,1,6,14,4,7,13};
    for(int x:values) insert(root,x);
    vector<int> sorted; inorder(root,sorted);
    int queries[]={1,3,5,8};
    cout<<"Answers: ";
    for(int k:queries) {
        int ans=kthSmallest(sorted,k);
        if(ans==-1) cout<<"NULL ";
        else cout<<ans<<" ";
    }
    cout<<"\n"; return 0;
}
