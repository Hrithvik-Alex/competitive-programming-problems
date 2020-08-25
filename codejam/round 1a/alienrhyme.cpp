#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_set>

#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define ll long long
#define forn(i, a, b) for(int i = (int)a; i <(int)b;i++)
using namespace std;

struct Node {
    bool word;
    Node* children[26];
    int childcount = 0;
};

Node* createNode(){
    Node* newNode = new Node;
    newNode->word = false;
    newNode->childcount = 0;
    forn(i,0,26){
        newNode->children[i] = nullptr;
    }
    return newNode;
}

void addWord(Node* root, string val){
    std::reverse(val.begin(), val.end());
    Node* cur = root;
    forn(i, 0,val.length()){
        int index = val[i] - 'A';
        if(!cur->children[index]){
            cur->children[index] = createNode();
            cur->childcount++;
        }
        cur = cur->children[index];
    }
    cur->word = true;
}


int getScore(Node* root){
    if(!root->childcount) return 1;
    int sum = root->word ? 1 : 0;
    forn(i,0,26){
        if(root->children[i]) sum += getScore(root->children[i]);
    }
    return sum >=2 ? sum - 2 : sum;
}

int main(){
    int t;
    cin >> t;
    int cases=0;
    while(t--){
        int n;
        cin >> n;
        Node* root = createNode();
        for(int i = 0; i < n; i++){
            string w;
            cin >> w;
            addWord(root, w);
        }
        int s = 0;
        forn(i,0,26){
            if(root->children[i]) s+=getScore(root->children[i]);
        }
        printf("Case #%d: %d\n",++cases,n-s);       
    }
}