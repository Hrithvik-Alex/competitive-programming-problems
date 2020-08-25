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
int n,q, qi;
int ni[1005];

int main(){
    ios:: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    int cases = 0;
    while(n!=0 || q!=0){
        cout << "CASE# " << ++cases << ":" << endl;
        forn(i,0,n) cin >> ni[i];
        sort(ni, ni+n);
        forn(i,0,q){
            cin >> qi;
            auto res = lower_bound(ni, ni+n, qi);
            if(ni[res-ni]==qi) cout << qi << " found at " << res-ni+1 << endl;
            else cout << qi << " not found" << endl;
        }


        cin >> n >> q;
    }
}