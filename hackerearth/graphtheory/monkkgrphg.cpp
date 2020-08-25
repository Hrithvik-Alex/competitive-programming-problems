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
    int n,m;
    scanf("%d %d", &n,&m);
    vector<vector<int> > graph(n, vector<int>());
    forn(i,0,m){
        int a,b;
        scanf("%d %d", &a,&b);
        graph[a-1].pb(b-1);
        graph[b-1].pb(a-1);
    }
    int a,b;
    scanf("%d %d", &a,&b);
    queue<ii> q;
    vector<int> res;
    int minlen = INT_MAX;
    q.push(mp(a-1,0));
    unordered_map<int, int> parent;
    unordered_set<int> visited;
    while(!q.empty()){
        ii top = q.front();
        visited.insert(top.first);
        if(res.size() && top.second > minlen){
            break;
        }
        if(top.first == b-1){
            int child = parent[top.first];
            minlen = top.second;
            while(child != a-1){
                res.pb(child);
                child = parent[child];
            }
            
        }
        q.pop();
        forn(i,0,graph[top.first].size()){
            if(visited.find(graph[top.first][i]) == visited.end()){
                q.push(mp(graph[top.first][i],top.second+1)); 
                parent[graph[top.first][i]] = top.first; 
            }   
        }
    }

    sort(res.begin(), res.end());
    if(res.size()==0){
        printf("-1\n");
    } else if(minlen == 1){
        printf("-1\n");
    } else {
        printf("%d\n", res[0]+1);
    }

}