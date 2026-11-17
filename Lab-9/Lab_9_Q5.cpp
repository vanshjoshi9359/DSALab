#include <iostream>
#include <sstream>
#include <string>
using namespace std;
struct Node { int data; Node *left,*right; Node(int x):data(x),left(nullptr),right(nullptr){} };
void serialize(Node* root,ostringstream& out) {
    if (!root) { out<<"# "; return; }
    out<<root->data<<" ";
    serialize(root->left,out); serialize(root->right,out);
}
string serialize(Node* root) {
    ostringstream out; serialize(root,out); return out.str();
}
Node* deserialize(istringstream& in) {
    string token;
    if (!(in>>token)) return nullptr;
    if (token=="#") return nullptr;
    Node* root=new Node(stoi(token));
    root->left=deserialize(in); root->right=deserialize(in);
    return root;
}
Node* deserialize(const string& data) {
    istringstream in(data); return deserialize(in);
}
void preorder(Node* root) {
    if (!root) { cout<<"# "; return; }
    cout<<root->data<<" "; preorder(root->left); preorder(root->right);
}
int main() {
    Node* root=new Node(1); root->left=new Node(2); root->right=new Node(3);
    root->right->left=new Node(4); root->right->right=new Node(5);
    string data=serialize(root);
    cout<<"Serialized: "<<data<<"\nReconstructed preorder: ";
    preorder(deserialize(data)); cout<<"\n";
    return 0;
}
