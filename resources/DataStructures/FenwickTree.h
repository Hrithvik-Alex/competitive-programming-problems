
#ifndef FENWICKTREE_H
#define FENWICKTREE_H

class FenwickTree {
    public:
    void update(int index, int val); // O(logn)
    int getSum(int index); // O(logn)
    FenwickTree(int* vals, int size); // O(nlogn)
    ~FenwickTree();
    private:
    int getParent(int index); // O(1)
    int getNext(int index); // O(1)
    int* array;
    int size;
};

#endif