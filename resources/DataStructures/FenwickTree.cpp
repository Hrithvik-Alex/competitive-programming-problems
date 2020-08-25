#include "FenwickTree.h"

FenwickTree::FenwickTree(int* vals, int size){
    array = new int[size+1]();
    for(int i = 1; i <= size; i++){
        update(i, vals[i-1]);
    }
}

FenwickTree::~FenwickTree(){
    delete array;
}

int FenwickTree::getSum(int index){
    int sum = array[index+1];
    int i = index+1;
    while(i>0){
        i = getParent(i);
        sum += array[i];
    }
    return sum;
}

void FenwickTree::update(int index, int val){
    int diff = val - array[index];
    index += 1;
    while(index < size){
        array[index] += diff;
        index = getNext(index);
    }
}

int FenwickTree::getParent(int index){
    return index - (index & -index);
}

int FenwickTree::getNext(int index){
    return index + (index & -index);
}