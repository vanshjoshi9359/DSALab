#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <sstream>
#include <string>
using namespace std;
struct Node { int val; Node *left,*right; Node(int x):val(x),left(nullptr),right(nullptr){} };
Node* buildLevelOrder(const vector<int>& a) {
    if(a.empty() || a[0]==-1) return nullptr;
    Node* root=new Node(a[0]); queue<Node*> q; q.push(root);
    int i=1;
    while(!q.empty() && i<(int)a.size()) {
        Node* cur=q.front(); q.pop();
        if(i<(int)a.size() && a[i]!=-1) { cur->left=new Node(a[i]); q.push(cur->left); } i++;
        if(i<(int)a.size() && a[i]!=-1) { cur->right=new Node(a[i]); q.push(cur->right); } i++;
    }
    return root;
}
void parentMap(Node* root,unordered_map<Node*,Node*>& parent,
               unordered_map<int,Node*>& byValue) {
    if(!root) return;
    byValue[root->val]=root;
    if(root->left) { parent[root->left]=root; parentMap(root->left,parent,byValue); }
    if(root->right) { parent[root->right]=root; parentMap(root->right,parent,byValue); }
}
vector<int> distanceK(Node* root,int target,int k) {
    unordered_map<Node*,Node*> parent;
    unordered_map<int,Node*> byValue;
    parentMap(root,parent,byValue);
    vector<int> ans;
    if(!byValue.count(target)) return ans;
    queue<Node*> q; unordered_map<Node*,bool> seen;
    Node* start=byValue[target]; q.push(start); seen[start]=true;
    int dist=0;
    while(!q.empty()) {
        int sz=q.size();
        if(dist==k) { while(!q.empty()) { ans.push_back(q.front()->val); q.pop(); } return ans; }
        while(sz--) {
            Node* n=q.front(); q.pop();
            Node* next[3]={n->left,n->right,parent.count(n)?parent[n]:nullptr};
            for(Node* x:next) if(x && !seen[x]) { seen[x]=true; q.push(x); }
        }
        dist++;
    }
    return ans;
}
int main() {
    vector<int> a={3,5,1,6,2,0,8,-1,-1,7,4};
    int target=5,k=2;
    for(int x:distanceK(buildLevelOrder(a),target,k)) cout<<x<<" ";
    cout<<"\n"; return 0;
}
