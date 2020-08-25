#include "SegmentTree.h"
#include <cmath>
// #include <iostream>

#define SUM 0
#define MIN 1
#define MAX 2

SegmentTree::SegmentTree(std::vector<int> vals, int c){
    int length = 2*pow(2.0, ceil(log2((double)vals.size())));
    values = vals;
    code = c;
    array.resize(length, 0);
    buildTree(1, 0, vals.size()-1);
}

void SegmentTree::buildTree(int root, int lo, int hi){
    if(lo==hi){
        if(code == SUM) array[root] = values[lo];
        else array[root] = lo;
    }

    else {
        int lchild = 2*root, rchild = 2*root + 1;
        buildTree(lchild, lo, (lo + hi)/2);
        buildTree(rchild, (lo+hi)/2+1,hi);
        int lval = array[lchild], rval = array[rchild];
        if(code == SUM) array[root] = lval + rval;
        else {
            int lc = values[lval];
            int rc = values[rval];
            if(code == MIN) array[root] = lc<=rc ? lval : rval;
            else array[root] = lc>=rc ? lval : rval;
        }
    }
}

int SegmentTree::query(int start, int end){
    return QueryHelper(1, start, end, 0, values.size()-1);
    
}

int SegmentTree::QueryHelper(int root, int start, int end, int astart, int aend){
    if(astart > end || start > aend) return -1;
    if(astart >= start && end >= aend) return array[root];

    int p1 = QueryHelper(2*root, start, end, astart, (astart+aend)/2);
    int p2 = QueryHelper(2*root + 1, start, end, (astart+aend)/2+1,aend);

    if(p1 == -1) return p2;
    if(p2 == -1) return p1;

    if(code == SUM) return p1 + p2;
    else if(code == MIN) return (values[p1]<=values[p2]) ? p1 : p2;
    else return (values[p1]>=values[p2]) ? p1 : p2;
}

void SegmentTree::update(int index, int val){
    int a = updateHelper(1, 0, values.size()-1, index, val); // pretty sus ngl
    if(code == SUM) values[index] = val;
}

int SegmentTree::updateHelper(int root, int start, int end, int index, int value){
    if(index < start || index > end) return -1;
    
    if(start==end){
        
        if(code == SUM) array[root] = value;
        else {
            values[index] = value;
            array[root] = index;
            }
    } else{
        int p1 = updateHelper(2*root, start, (start+end)/2, index, value);
        int p2 = updateHelper(2*root+1, (start+end)/2+1, end, index, value);
        if(code == SUM) array[root] += value - values[index];
        else {
            if(p1 == -1) array[root] = array[2*root+1];
            else if(p2 == -1) array[root] = array[2*root];
            else{
                if(code == MIN) array[root] = values[array[2*root+1]] <= values[array[2*root]] ? array[2*root+1] : array[2*root];
                else array[root] = values[array[2*root+1]] >= values[array[2*root]] ? array[2*root+1] : array[2*root];
            }
        }
    }
    return 1;
}

// void SegmentTree::updateRangeHelper(int root, int start, int end, int index, int value){
//     if(index < start || index > end) return;
   
//     if(start!=end){
//         int mid = (start+end)/2;
//         updateRangeHelper(2*root, start, mid, index, value);
//         updateRangeHelper(2*root+1, mid+1, end, index, value);
//         if()
//     }
// }

// int main(){
//     std::vector<int> v{1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0};
//     SegmentTree S(v, SUM);
//     for(int i = 0; i < 18; i++){
//         S.update(i, 1);
//     }
//     std::cout << S.query(1, 10) << std::endl;
// }