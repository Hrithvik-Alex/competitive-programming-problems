#include <iostream>
#include <fstream>
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
#define INF 0x3f3f3f3f
#define forn(i, a, b) for(int i = (int)a; i <(int)b;i++)
#define setv(arr,i) memset(arr, i, sizeof(arr))
using namespace std;

int c,l,a,b,s,e,d;
int graph[102][102];
int dp[102][205];

bool solve(int city, int day){
    if(day==d && city!=e){
        dp[city][day] = 0;
        return false;
    } else if(day == d && city==e){
        dp[city][day] = 1;
        return true;
    }
    if(dp[city][day]!=-1) return dp[city][day];
    forn(i,1,c+1){
        if(graph[city][i]) {
            if(solve(i,day+1)){
                dp[city][day] = 1;
                return true;
            }
        }
    }
    dp[city][day] = 0;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // ifstream f;
    // f.open("in.txt");
    while(cin >> c >> l && (c!=0||l!=0)){
        setv(dp,-1);
        setv(graph,0);
        forn(i,0,l){
            cin >> a >> b;
            graph[a][b] = 1;
            graph[b][a] = 1;
        } 
        cin >> s >> e >> d;
        bool res = solve(s,0);
        string ans = res ? "Yes, Teobaldo can travel." : "No, Teobaldo can not travel.";
        cout << ans << endl;
    }
    // f.close();
}