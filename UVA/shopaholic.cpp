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

int t,n;
int p[20005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    vector<int> res;
    while(t--){
        cin >> n;
        forn(i,0,n){
            cin >> p[i];
        }
        sort(p, p+n);
        int disc = 0;
        for(int i = n-1; i >=0;i--){
            i-=2;
            if(i>=0) disc+=p[i];
        }
        // cout << disc << endl;
        res.pb(disc);
    }
    forn(i,0,res.size()){
        cout << res[i] << endl;
    }
}