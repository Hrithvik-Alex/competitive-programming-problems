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

int n,k,d;
pair<int,vector<int> > graph[12][12];
int dp[12][1005];

int solve(int city,int day,int cur){
    if(day==k-1){
        if(city != n-1 && graph[city][n-1].second[day%graph[city][n-1].first]!=0) return cur+graph[city][n-1].second[day%graph[city][n-1].first];
        else return 1000000000;
    }
    int mini = INT_MAX;
    forn(i,0,n){
        if(i==city) continue;
        if(dp[i][day+1] == -1 || cur+graph[city][i].second[day%graph[city][i].first]<dp[i][day+1]){
            if(graph[city][i].second[day%graph[city][i].first]!=0)
                mini = min(mini,solve(i,day+1,cur+graph[city][i].second[day%graph[city][i].first]));
        }
    }
    dp[city][day] = mini;
    return mini;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream myfile;
    myfile.open("in.txt");
    int cases = 0;
    while(myfile >> n >> k &&(n!=0 || k!=0)){
        setv(dp,-1);
        forn(i,0,n){
            forn(j,0,n){
                if(i==j) continue;
                myfile >> d;
                graph[i][j].first = d;
                graph[i][j].second.clear();
                forn(k,0,d){
                    int x;
                    myfile >> x;
                    graph[i][j].second.pb(x);
                }
            }
        }
        // forn(i,0,n){
        //     forn(j,0,n){
        //         if(i==j) {
        //             cout << "XXX" << " ";
        //             continue;
        //         }
        //         cout << "[" << graph[i][j].first << ", ";
        //         forn(k,0,graph[i][j].first) cout << graph[i][j].second[k] << " ";
        //         cout << "] ";
        //     }
        //     cout << endl;
        // }
        int res = solve(0,0,0);
        printf("Scenario #%d\n",++cases);
        if(res==INT_MAX) printf("No flight possible.\n");
        else printf("The best flight costs %d.\n",res);
        cout << endl;
    }
    myfile.close();
}