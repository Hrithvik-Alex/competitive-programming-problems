#include <iostream>
#include <string>
#define MAXN 1000
struct Node {
    int start, end;
    int length;
    int insertEdge[26]; 
    int suffixEdge;
};

Node root1, root2; 
  
// stores Node information for constant time access 
Node tree[MAXN]; 
  
// Keeps track the current Node while insertion 
int currNode; 
string s; 
int ptr; 

void insert(int index){

    int tmp = currNode; 
    while (true) 
    { 
        int curLength = tree[tmp].length; 
        if (index - curLength >= 1 and s[index] == s[index-curLength-1]) 
            break; 
        tmp = tree[tmp].suffixEdge; 
    } 
    if(tree[tmp].insertEdge[s[index]-'a'] != 0) 
    { 
        // s[idx] X s[idx] already exists in the tree 
        currNode = tree[tmp].insertEdge[s[index]-'a']; 
        return; 
    }
    ptr++;
}