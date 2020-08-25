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

int n,a,b;
int programs[500005];
vector<string> ress;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> n && n!=0){
        setv(programs, 0);
        int mx = -1;
        forn(i,0,n){
            cin >> a >> b;
            mx = max(mx, max(a,b));
            programs[a]--;
            programs[b]++;
        }
        bool fl=true;
        forn(i,0,mx+1){
            if(programs[i]!=0){
                fl = false;
                break;
            }
        }

        string res = fl ? "YES" : "NO";
        ress.pb(res);
        // cout << res << endl;
    }
    forn(i,0,ress.size()){
        cout << ress[i] << endl;
    }
}