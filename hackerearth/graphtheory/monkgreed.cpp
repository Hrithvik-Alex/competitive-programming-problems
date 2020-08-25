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

#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define ll long long
#define forn(i, a, b) for(int i = (int)a; i <(int)b;i++)
#define DEBUG(x) cout << '>' << #x << ':' << x << endl
using namespace std;

int mininum[100001];
int A[100001];
vector<ii> edges[100001];
priority_queue<ii> pq;
unordered_map<int, int> parent;
unordered_set<int> visited;

int calcNodeSum(int n){
    if(parent[n] == -1) return A[n];
    return A[n] + calcNodeSum(parent[n]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,a,b,w,u,v;
    cin >> n >> m;
    memset(mininum, -1, sizeof(mininum));
    forn(i,0,n) cin >> A[i];
    forn(i,0,m){
       cin >> a >> b >> w;
       edges[a].pb(mp(b,w));
       edges[b].pb(mp(a,w));
    }
    cin >> u >> v;
    int x = 0;
    pq.push({INT_MAX,u});
    parent[u] = -1;
    while(!pq.empty){
        int vx = pq.top().second;
        int wei = pq.top().first;
        pq.pop();
        if(visited.count(vx)){
            continue;
        }
        visited.insert(vx);
        forn(i,0,edges[vx].size()){
            if(min(wei, edges[vx][i].second) > mininum[edges[vx][i].first]){
                mininum[edges[vx][i].first] = min(wei, edges[vx][i].second);
                parent[edges[vx][i].first] = vx;
                pq.push({min(wei, edges[vx][i].second),edges[vx][i].first});
            } else if(min(wei, edges[vx][i].second) == mininum[edges[vx][i].first]){
                if(calcNodeSum(vx) > calcNodeSum()){
                    mininum[edges[vx][i].first] = min(wei, edges[vx][i].second);
                    parent[edges[vx][i].first] = vx;
                    pq.push({min(wei, edges[vx][i].second),edges[vx][i].first});
                }
            }
        }
    }


}


// #include <bits/stdc++.h>
// #define f first
// #define s second
// #define mp make_pair
// #define pb push_back
// #define lp(i,a,n) for(int i=(a);i<=(int)(n);++i)
// #define lpd(i,a,n) for(int i=(a);i>=(int)(n);--i)
// #define mem(a,b) memset(a,b,sizeof a)
// #define all(v) v.begin(),v.end()
// #define println(a) cout <<(a) <<endl
// #define sz(x) ((int)(x).size())
// #define readi(x) scanf("%d",&x)
// #define read2i(x,y) scanf("%d%d",&x,&y)
// #define read3i(x,y,z) scanf("%d%d%d",&x,&y,&z)
// #define readll(x) scanf("%I64d",&x)
// #define mod 1000000007
// #define eps 1e-6
// #define infi 1e9
// #define infll 1e18
// using namespace std;
// typedef long long ll;
// typedef pair<int, int> pii;
// typedef pair<ll, ll> pll;
// typedef vector<int> vi;
// typedef vector<vi> vvi;
// typedef vector<ll> vll;
// typedef set<int> si;
// typedef map<int,int> mii;
 
// const int N = 2e5 + 2;
// int n,m,parent[N],u,v;
// ll sumComp[N];
// struct edge {
//     int a,b,w;
//     bool operator < (const edge x) const {
//         return w < x.w;
//     }
// } edges[N];
 
// int find(int a) {return parent[a] == a ? a : parent[a] = find(parent[a]);}
// void merge(int a, int b){
//     sumComp[parent[find(b)]] += sumComp[parent[find(a)]];
//     parent[find(a)] = parent[find(b)];
// }
 
// int main(){
//     read2i(n,m);
//     lp(i,1,n) cin >>sumComp[i];
//     lp(i,1,m){
//         int a,b,w;
//         read3i(a,b,w);
//         edges[i] = {a,b,w};
//     }
//     read2i(u,v);
 
//     sort(edges+1, edges+1+m);
//     lp(i,1,n) parent[i] = i;
 
//     int x = 0;
//     lpd(i,m,1){
//         if(find(edges[i].a) != find(edges[i].b)){
//             x = edges[i].w;
//             merge(edges[i].a, edges[i].b);
//         }
//         if(find(u) == find(v)){
//             while(--i and edges[i].w == x){
//                 if(find(edges[i].a) != find(edges[i].b)) merge(edges[i].a, edges[i].b);
//             }
//             break;
//         }
//     }
 
//     cout <<x <<" " <<sumComp[find(u)];
// }
 
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//ios::sync_with_stdio(0);cin.tie(0);