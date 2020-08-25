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
    long val;
    vector<Node*> children; 
};

void getDescendants(vector<long>&v, Node* root){
    v.push_back(root->val);
    int n = root->children.size();
    if(n > 0){
        getDescendants(v, root->children[0]);
    }
    if(n > 1){
        getDescendants(v, root->children[1]);
    }
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
    long A[n];
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
    int count = 0;
    for(int i = 0; i < n; i++){
        vector<long> v;
        Node* nroot = m[i+1];
        int nn = nroot->children.size();
        if(nn>0) getDescendants(v,nroot->children[0]);
        if(nn>1) getDescendants(v,nroot->children[1]);
        int z = v.size();
        int nrtval = nroot->val;
        for(int j = 0; j < z; j++){
            for(int l = j+1; l < z; l++){
                long amount = nrtval + v[j] + v[l];
                if(amount >= k) count++;
            }
        }
    }

    cleanup(root);
    cout << count << endl;
}