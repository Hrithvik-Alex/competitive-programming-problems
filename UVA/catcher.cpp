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

vector<int> missiles;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cases = 0;
    while(true){
        missiles.clear();
        int x;
        cin >> x;
        if(x == -1) break;
        while(x!=-1){  
            missiles.pb(x);
            cin >> x;
        }
        int n = missiles.size();
        int lds[n];
        int mx = 1;
        forn(i,0,n){
            lds[i] = 1;
            forn(j,0,i){
                if(missiles[i]<=missiles[j]){
                    lds[i] = max(lds[i],lds[j]+1);
                }
            }
            mx = max(mx, lds[i]);
        }
        printf("Test #%d:\n", ++cases);
        printf("  maximum possible interceptions: %d\n\n", mx);

    }
}