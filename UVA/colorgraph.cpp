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

int m,n,k,a,b,maxs;

bitset<105> visited;
int color[105];
vector<vector<int> > g(105);

vector<int> res;

void solve(int u){
    if(u==n){
        int bl=0;
        forn(i,0,n){
            if(color[i]==1) bl++;
        }
        if(maxs<bl){
            maxs = bl;
            res.clear();
            forn(i,0,n){
                if(color[i] == 1) res.pb(i+1);
            }
        }
        return;
    } else {
        bool canTrav = true;
        forn(i,0,g[u].size()){
            int v = g[u][i];
            if(visited[v] && color[v]==1){
                canTrav = false;
                break;
            }
        }
        visited.set(u);
        if(canTrav){
            color[u] = 1;
            solve(u+1);
        }
        color[u] = 0;
        solve(u+1);
        visited.reset(u);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m;
    while(m--){ 
        cin >> n >> k;
        g.assign(n, vector<int>());
        visited.reset();
        forn(i,0,k){
            cin >> a >> b;
            g[a-1].pb(b-1);
            g[b-1].pb(a-1);
        }
        maxs = -1;
        solve(0);

        cout << maxs << endl;
        forn(i,0,res.size()) cout << res[i] << " ";
        cout << endl;
    }
}