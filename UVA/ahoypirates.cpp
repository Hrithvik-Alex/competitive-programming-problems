// UVA 11402 TO FINISH

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#define SUM 0
#define MIN 1
#define MAX 2

using namespace std;
char A[1024020] = {};
int tree[2048020] = {};
int lazy[2048020] = {};


void buildTree(int node, int start, int end){
    if(start==end){
        tree[node] = A[start]-'0';
        return;
    }
    int mid = (start+end)/2;
    buildTree(2*node+1,start,mid);
    buildTree(2*node+2,mid+1,end);
    tree[node] = tree[2*node+1] + tree[2*node+2];
}

void lazyP(int node, int start, int end){
    if(lazy[node] != 0){
        if(lazy[node] == 1) tree[node] = (end - start + 1);
        else if(lazy[node] == 2) tree[node] = 0;
        else tree[node] = (end - start + 1) - tree[node];
        if(start!=end){
            if(lazy[node] == 3){
                lazy[2*node+1] = 3 - lazy[2*node+1];
                lazy[2*node+2] = 3 - lazy[2*node+2];
            }
            else {
                lazy[2*node+1] = lazy[node];
                lazy[2*node+2] = lazy[node];
            }
        }
        lazy[node] = 0;
    }
}

void updateTree(int node, int start, int end, int l, int r, int val){
    if(start>end) return;
    lazyP(node,start,end);
    if(start > r || end < l) return;
    if(start >= l && r >= end) {
        if(val == 1) tree[node] = (end - start + 1);
        else if(val == 2) tree[node] = 0;
        else tree[node] = (end - start + 1) - tree[node];
        if(start!=end){
            if(val == 3){
                lazy[2*node+1] = 3 - lazy[node*2+1];
                lazy[2*node+2] = 3 - lazy[node*2+2];
            }
            else {
                lazy[2*node+1] = val;
                lazy[2*node+2] = val;
            }
        }
        return;
    }

    int mid = (start+end)/2;
    updateTree(2*node+1, start, mid, l, r, val);
    updateTree(2*node+2, mid+1, end, l,r,val);
    tree[node] = tree[2*node+1] + tree[2*node+2];
}



int queryTree(int node, int start, int end, int l, int r){
    if(end<start) return 0;
    lazyP(node,start,end);
    if(l>end || r<start) return 0;
    if(l<=start && end<=r) return tree[node];
    int mid = (start+end)/2;
    return queryTree(2*node+1,start,mid,l,r) + queryTree(2*node+2,mid+1,end,l,r);
}




int main(){
    int t;
    cin >> t;
    int ot = t;
    while(t--){
        int m;
        cin >> m;
        int j = 0;
        for(int i = 0; i<m;i++){
            int pi;
            string q; 
            cin >> pi >> q;
            for(int a = 0; a < pi;a++){
                for(int b = 0; b<q.length();b++){
                    A[j++] = q[b];
                }
            }
        }
        buildTree(0,0,j);
        int Q;
        cin >> Q;
        int cases=0;
        printf("Case %d:\n", ot-t);
        for(int i = 0; i < Q;i++){
            char a;
            int l,r;
            cin >> a >> l >> r;
            if(a=='F'){
                updateTree(0,0,j,l,r,1);
            } else if(a=='E'){  
                updateTree(0,0,j,l,r,2);
            } else if(a=='I'){
                updateTree(0,0,j,l,r,3);
            } else{
                cases++;
                printf("Q%d: %d\n",cases,queryTree(0,0,j,l,r));
            }
        }
    }
    for(int i = 0; i < 40; i++){
        cout << tree[i] << endl;
    }   
}