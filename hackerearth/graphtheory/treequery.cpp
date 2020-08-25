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
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,x,y;
    cin >> n >> m;
    vector<int> g[n];
    int indeg[n];
    forn(i,0,m){
        cin >> x >> y;
        g[x-1].pb(y-1);
    }
    int backwards = 0;
    forn(i,0,n){
        indeg[i] = 0;  
    }
    forn(i,0,n){
        if(g[i].size() == 0) backwards++;
        forn(j,0,g[i].size()) indeg[g[i][j]]++;  
    }
    int forwards = 0;
    forn(i,0,n){
        if(!indeg[i]) forwards++;
    }
    cout << max(backwards, forwards) << endl;
}