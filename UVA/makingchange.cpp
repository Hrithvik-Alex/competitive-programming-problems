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

int coins[6] = {1, 2, 4, 10, 20, 40};
int a[6];
int amount;
int dp[105];

int occ[205];
int cc[205][7];
void coinchange(){
    setv(cc, 10000);
    cc[0][0] = 0;
    forn(i,1,7){
        cc[0][i] = a[i-1];
    }
    forn(i,0,200){
        forn(j,0,6){
            if(i-coins[j]>=0 && cc[i-coins[j]][j+1]>0){
                if(cc[i-coins[j]][0]+1<cc[i][0]){
                    cc[i][0] = cc[i-coins[j]][0]+1;
                    forn(k,0,6){
                        cc[i][k+1] = cc[i-coins[j]][k+1];
                    }
                    cc[i][j+1]--;
                }
            }
        }
        // printf("%dth change: %d\n",i,cc[i][0]);
    }
}




int main(){
    setv(occ, 10000);
    occ[0] = 0;
    forn(i,0,200){
        forn(j,0,6){
            if(i-coins[j]>=0 && occ[i-coins[j]]+1<occ[i]){
                occ[i] = occ[i-coins[j]]+1;
            }
        }
        // printf("%dth change: %d\n",i,occ[i]);
    }
    vector<int> res;
    while(cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] && (a[0] != 0 || a[1] != 0 || a[2] != 0 || a[3] != 0 || a[4] != 0 || a[5] != 0)){
        double x;
        cin >> x;
        amount = (int)(x*20);
        // forn(i,0,6) cout << a[i] << "   ";

        // cout << "\n" << amount << " \n";
        coinchange();
        int minchange = INT_MAX;
        forn(i,0,100){
            minchange = min(minchange,occ[i] + cc[amount+i][0]);
        }
        // cout << minchange << endl;
        res.pb(minchange);
    }
    forn(i,0,res.size()) cout << "  " << res[i] << endl;
}