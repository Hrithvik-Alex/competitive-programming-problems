#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H
#include<vector>
#include <string>

class SegmentTree{
    public:
        SegmentTree(std::vector<int> vals, int code);
        void update(int index, int val);
        int query(int start, int end);
    private:
        void buildTree(int root, int lo, int hi);
        int QueryHelper(int root, int start, int end, int astart, int aend);
        int updateHelper(int root, int start, int end, int index, int value);
        int code;
        std::vector<int> array;
        std::vector<int> values;
};

#endif