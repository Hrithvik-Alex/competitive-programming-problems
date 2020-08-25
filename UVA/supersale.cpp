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

int t,n,g;
int p[1001],w[1001],mw[101];
int dp[1001][31];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // ifstream myfile;
    // myfile.open("in.txt");
    cin >> t;
    vector<int> res;
    while(t--){
        cin >> n;
        int sum = 0;
        forn(i,1,n+1) {
            cin >> p[i] >> w[i];
            sum += p[i];
        }
        cin >> g;
        forn(i,0,g) cin >> mw[i];
        forn(i,0,sum){
            dp[0][i] = 0;
        }
        forn(i,1,n+1){
            forn(j,0,31){
                if(j==0){
                    dp[i][j] = 0;
                } else if(j-w[i]>=0){
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+p[i]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }

            }
        }
        int mx = 0;
        forn(i,0,g){
            mx += dp[n][mw[i]];
        }
        res.pb(mx);
    }
    forn(i,0,res.size()) cout << res[i] << endl;
    // myfile.close();
}