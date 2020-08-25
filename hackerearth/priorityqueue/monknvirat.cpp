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

int main(){
    int n;
    scanf("%d", &n);
    long a[n];
    priority_queue<long,vector<long>,std::greater<long> > pq;
    forn(i,0,n){
        scanf("%ld",&a[i]);
    }
    forn(i,0,n){
        long x;
        scanf("%ld",&x);
        a[i] += x;
    }
    forn(i,0,n){
        long x;
        scanf("%ld",&x);
        a[i] += x;
    }
    forn(i,0,n){
        pq.push(a[i]);
    }
    int q;
    scanf("%d", &q);
    forn(i,0,q){
        int qi;
        scanf("%d",&qi);
        if(qi>pq.size()){
            printf("%d", -1);
        } else {
            int oqi = qi;
            vector<long> bois;
            while(qi--){
                bois.push_back(pq.top());
                pq.pop();
            }
            printf("%ld", bois[oqi-1]);
            forn(j,0,oqi-1){
                pq.push(bois[j]);
            }
        }
        printf("\n");
    }
}