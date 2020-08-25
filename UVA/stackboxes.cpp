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
#include <cstring>
#include <bitset>

#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define ll long long
#define forn(i, a, b) for(int i = (int)a; i <(int)b;i++)
#define setv(arr,i) memset(arr, i, sizeof(arr))
using namespace std;

int k,n;
vector<vector<int> > boxes;

bool compare(pair<vector<int>, int>& a, pair<vector<int>, int>& b){
    int x = a.first.size();
    for(int i = 0; i < x;i++){
        if(a!=b) return a.first[i] < b.first[i];
    }
    return a.second < b.second;
}

bool isBoxed(vector<int>& a, vector<int>& b){
    int x = a.size();
    forn(i,0,x){
        if(a[i] >= b[i]) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> k >> n){
        boxes.clear();
        boxes.resize(k, vector<int>(n));
        forn(i,0,k) forn(j,0,n) cin >> boxes[i][j];
        forn(i,0,k) sort(boxes[i].begin(), boxes[i].end());
        vector<pair<vector<int>, int> > paired;
        forn(i,0,k) paired.pb(mp(boxes[i], i+1));
        sort(paired.begin(), paired.end(), compare);
        int lis[k];
        vector<vector<int> > res(k);
        int mx = 1;
        int mxidx = 0;
        forn(i,0,k) res[i].pb(paired[i].second);
        forn(i,0,k){
            lis[i] = 1;
            forn(j,0,i){
                if(isBoxed(paired[j].first,paired[i].first)){
                    if(lis[j]+1>lis[i]){
                        lis[i]=lis[j]+1;
                        vector<int> cur = res[j];
                        cur.pb(paired[i].second);
                        res[i] = cur;
                    }
                }
            }
            if(lis[i]>mx){
                mx = lis[i];
                mxidx = i;
            }
        }
        cout << mx << endl;
        forn(i,0,mx) cout << res[mxidx][i] << " ";
        cout << endl;

    }
}