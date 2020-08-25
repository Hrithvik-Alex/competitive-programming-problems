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


string map[15];

int safeh[15][15];
int safev[15][15];

int play(int x1, int y1, int x2, int y2, int dp[16][16][16][16]){
    if(x1>=x2 || y1>=y2) return 0;
    if(dp[x1][y1][x2][y2]>=0) return dp[x1][y1][x2][y2];
    unordered_set<int> s;
    forn(i,x1,x2){
        if(y1 >= safev[y2-1][i]) s.insert(play(x1,y1,i,y2,dp)^play(i+1,y1,x2,y2,dp));
    }
    forn(i,y1,y2){
        if(x1 >= safeh[i][x2-1]) s.insert(play(x1,y1,x2,i,dp)^play(x1,i+1,x2,y2,dp));
    }
    dp[x1][y1][x2][y2] = 0;
    while(s.count(dp[x1][y1][x2][y2])) dp[x1][y1][x2][y2]++;
    return dp[x1][y1][x2][y2];
}


int main(){
    int t,r,c;
    cin >> t;
    int cases = 0;
    while(t--){
        cin >> r >> c;
        forn(i,0,r){
            cin >> map[i];
        }
        forn(i,0,r){
            int past=0;
            forn(j,0,c){
                if(map[i][j] == '#') past=j+1;
                safeh[i][j] = past;
            }
        }
        forn(i,0,c){
            int past=0;
            forn(j,0,r){
                if(map[j][i] == '#') past=j+1;
                safev[j][i] = past;
            }
        }
        int res = 0;
        int dp[16][16][16][16];
        memset(dp, -1, sizeof(dp));
        forn(i,0,c){
            if(0 >= safev[r-1][i] && (play(0,0,i,r,dp)^play(i+1,0,c,r,dp))==0) res += r;
        }
        forn(i,0,r){
            if(0 >= safeh[i][c-1] && (play(0,0,c,i,dp)^play(0,i+1,c,r,dp))==0) res += c;
        }

        printf("Case #%d: %d\n",++cases,res);

    }
}