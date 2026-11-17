#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>
using namespace std;
struct Node { int data; Node *left,*right; Node(int x):data(x),left(nullptr),right(nullptr){} };
void initStacks(Node* root,int x,stack<Node*>& pred,stack<Node*>& succ) {
    while (root) {
        if (root->data<=x) { pred.push(root); root=root->right; }
        else { succ.push(root); root=root->left; }
    }
}
Node* nextPred(stack<Node*>& st) {
    Node* n=st.top(); st.pop();
    Node* p=n->left;
    while (p) { st.push(p); p=p->right; }
    return n;
}
Node* nextSucc(stack<Node*>& st) {
    Node* n=st.top(); st.pop();
    Node* p=n->right;
    while (p) { st.push(p); p=p->left; }
    return n;
}
vector<int> closestK(Node* root,int x,int k) {
    stack<Node*> pred,succ; initStacks(root,x,pred,succ);
    vector<int> ans;
    while (k-- > 0 && (!pred.empty() || !succ.empty())) {
        if (pred.empty()) ans.push_back(nextSucc(succ)->data);
        else if (succ.empty()) ans.push_back(nextPred(pred)->data);
        else {
            int a=abs(pred.top()->data-x), b=abs(succ.top()->data-x);
            if (a<=b) ans.push_back(nextPred(pred)->data);
            else ans.push_back(nextSucc(succ)->data);
        }
    }
    return ans;
}
int main() {
    Node* r=new Node(10); r->left=new Node(5); r->right=new Node(15);
    r->left->left=new Node(2); r->left->right=new Node(7);
    r->right->left=new Node(12); r->right->right=new Node(20);
    r->left->right->left=new Node(6); r->left->right->right=new Node(8);
    for(int v:closestK(r,9,4)) cout<<v<<" ";
    cout<<"\n"; return 0;
}
