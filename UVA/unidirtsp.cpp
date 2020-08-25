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
#define forn(i, a, b) for(int i = (int)a; i <(int)b;i++)
#define setv(arr,i) memset(arr, i, sizeof(arr))
using namespace std;

int m,n;
int matrix[105][105];
int dp[105][105];
vector<vector<int> > path;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<int, vector<int> > > res;
    while(cin >> m >> n){
        setv(dp,INT_MAX);
        forn(i,0,m) forn(j,0,n){
            cin >> matrix[i][j];
            dp[i][j] = INT_MAX;
        }
        path.resize(m);
        path.clear();
        int cur = INT_MAX;
        int minind;
        for(int i=m-1;i>=0;i--){
            cur = min(matrix[i][0],cur);
            dp[i][0] = matrix[i][0];
        }
        forn(j,1,n){
            int mn = INT_MAX;
            vector<vector<int> > npath(m);
            forn(i,0,m){
                int x = min(dp[i][j-1], min(dp[(i-1+m)%m][j-1],dp[(i+1)%m][j-1]));
                if(dp[i][j] > matrix[i][j]+x){
                    dp[i][j] = matrix[i][j]+x;
                    int ind;
                    if(i==0){
                        ind = x == dp[i][j-1] ? i : x == dp[(i-1+m)%m][j-1] ? (i-1+m)%m : (i+1)%m;
                    } else if(i==m-1){
                        ind = x == dp[(i+1)%m][j-1] ? (i+1)%m : x == dp[(i-1+m)%m][j-1] ? (i-1+m)%m : i;
                    } 
                    else {
                        ind = x == dp[(i-1+m)%m][j-1] ? (i-1+m)%m : x == dp[i][j-1] ? i : (i+1)%m;
                    }
        
                    npath[i] = path[ind];
                    npath[i].pb(ind+1);
                }
                if(dp[i][j] < mn){
                    minind = i;
                    mn = dp[i][j];
                }
            }
            path = npath;
            cur = mn;
        }
        cout << endl;
        // forn(i,0,m){
        //     forn(j,0,n){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        path[minind].pb(minind+1);
        res.pb(mp(cur,path[minind]));
    }
    forn(i,0,res.size()) {
        forn(j,0,res[i].second.size()) cout << res[i].second[j] << " ";
        cout <<  endl << res[i].first << endl;
    }
}