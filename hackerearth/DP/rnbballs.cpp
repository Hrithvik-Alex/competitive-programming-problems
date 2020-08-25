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
using namespace std;



string rows[105];

int dp[101][101];
int n,x,y,q;

int maxRows(int x, int y, int start){
    if(x<0 || y<0) return -1;
    if(dp[x][y] != -1) return dp[x][y];
    int ans = 0;
    int r,b;
    forn(i,start+1,n){ 
        r = 0;
        b = 0;
        forn(j,0,rows[i].size()){
            if(rows[i][j] == 'R') r++;
            else b++;
        }
        
        ans = max(ans, 1+maxRows(x-r,y-b,i));
    }
    return dp[x][y] = ans;
}

int main(){
    cin >> n;
    forn(i,0,n) cin >> rows[i];
    cin >> q;
    memset(dp,-1,sizeof(dp));
    while(q--){  
        cin >> x >> y;
        cout << maxRows(x,y,-1) << endl;
    }
}

