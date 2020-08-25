#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <climits>
#include <cmath>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define ll long long
#define forn(i, a, b) for(int i = (int)a; i <(int)b;i++)
using namespace std;

class Compare{
    public:
    bool operator() (ii& a, ii& b){
        if(a.first==b.first) return a.second > b.second;
        return a.first < b.first;
    }
};

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    priority_queue<ii, vector<ii>, Compare> pq;
    forn(i,0,n){
        int x;
        scanf("%d",&x);
        pq.push(mp(x,i+1));
    }
    forn(i,0,k){
        ii top = pq.top();
        printf("%d ", top.second);
        top.first--;
        pq.pop();
        pq.push(top);
    }
    printf("\n");
}