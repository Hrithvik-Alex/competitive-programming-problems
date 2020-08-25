#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <climits>
#include <cmath>
#include <utility>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Node {
    int val;
    vector<Node*> children; 
};



int DFSXOR(Node* root, int val, int target){
    if(root->children.empty()){
        if(val == target){
            return 1;
        } else {
            return 0;
        }
    }
   
    int count = 0;
    if(val == target) count++;
    for(int i = 0; i < root->children.size(); i++){
        count += DFSXOR(root->children[i], val^root->children[i]->val, target, 1);
    }
    return count;
}

void cleanup(Node* root){
    for(int i = 0; i < root->children.size(); i++){
        cleanup(root->children[i]);
    }
    delete root;
}

int main(){
    int n, k;
    cin >> n >> k;
    int A[n];
    unordered_map<int, Node*> m;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    Node* root = new Node;
    root->val = A[0];
    m[1] = root;
    for(int i = 0; i < n-1;i++){
        Node* a = new Node;
        a->val = A[i+1];
        int x;
        cin >> x;
        Node* parent = m[x];
        parent->children.push_back(a);
        m[i+2] = a;
    }
    int res = 0;
    for(int i=0; i <n;i++){
        Node* nroot = m[i+1];
        res += DFSXOR(nroot, nroot->val, k);
    }

    cleanup(root);
    cout << res << endl;
}