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

int t,m,n,q,r,c;
vector<string> grid(102);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        cin >> m >> n >> q;
        forn(i,0,m) cin >> grid[i];
        printf("%d %d %d\n",m,n,q);
        while(q--){
            cin >> r >> c;
            char ch = grid[r][c];
            int flag = 0;
            int ans = -1;
            forn(i,0,min(m,n)){
                forn(a,r-i,r+i+1){
                    forn(b,c-i,c+i+1){
                        if(a<0 || b<0 || a>=m || b>=n || grid[a][b] != ch) {
                            flag = 1;
                            break;
                        }
                    }
                    if(flag) break;
                }
                if(flag) break;
                ans+=2;
            }
            cout << ans << endl;
        }
    }
}