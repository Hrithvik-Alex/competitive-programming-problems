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
#define be begin()
#define en end()
using namespace std;

int root(int a, vector<int>& arr){
    while(arr[a] != a){
        arr[a] = arr[arr[a]];
        a = arr[a];
    }
    return a;
}

void unionset(int a, int b, vector<int>& arr){
    arr[root(a, arr)] = root(b, arr);
    // cout << arr[root(a, arr)] << " " << root(b,arr) << endl;

}

bool same(int a, int b, vector<int>& arr){
    // cout << root(a, arr) << " " << root(b,arr) << endl;
    return root(a, arr) == root(b, arr);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc,n,m,u,v,t;
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        unordered_set<int> s;
        vector<int> dj(n);
        forn(i,0,n) dj[i] = i;
        priority_queue<pair<int, ii> > pq;
        forn(i,0,m){
            cin >> u >> v >> t;
            pq.push(mp(t,mp(u,v)));
        }
        ll res = 0;
        int curedges = 0;
        while(!pq.empty() && curedges<n-1){
            ii edge = pq.top().second;
            if(!same(edge.first-1,edge.second-1,dj)){
                res += pq.top().first;
                unionset(edge.second-1, edge.first-1,dj);
                curedges++;
            }
            pq.pop();
        }


        cout << res << endl;
    }
}