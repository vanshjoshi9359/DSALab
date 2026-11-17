#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
struct Node { int data; Node *left,*right; Node(int x):data(x),left(nullptr),right(nullptr){} };
struct Info { bool isBST; long long sum; int mn,mx; };
long long bestSum=LLONG_MIN;
Info solve(Node* root) {
    if (!root) return {true,0,INT_MAX,INT_MIN};
    Info L=solve(root->left), R=solve(root->right);
    if (L.isBST && R.isBST && L.mx<root->data && root->data<R.mn) {
        long long s=L.sum+R.sum+root->data;
        bestSum=max(bestSum,s);
        return {true,s,min(root->data,L.mn),max(root->data,R.mx)};
    }
    return {false,0,INT_MIN,INT_MAX};
}
int main() {
    Node* r=new Node(5); r->left=new Node(4); r->right=new Node(8);
    r->left->left=new Node(3); r->left->right=new Node(6);
    r->right->left=new Node(7); r->right->right=new Node(9);
    solve(r);
    cout<<"Maximum BST subtree sum = "<<bestSum<<"\n";
    return 0;
}
