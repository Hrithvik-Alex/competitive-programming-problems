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
int trns[2005];

vector<int> temp,lis,lds;
void LIS(vector<int>& a){
    temp.clear();
    forn(i,0,n){
        int pos = lower_bound(temp.begin(),temp.end(),trns[i])-temp.begin();
        if(pos == temp.size()){
            temp.pb(trns[i]);
        } else {
            temp[pos] = trns[i];
        }
        a[i] = pos+1;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    vector<int> res;
    while(t--){
        cin >> n;
        lis.resize(n);
        lds.resize(n);
        forn(i,0,n) cin >> trns[i];
        // LIS(lis);
        forn(i,0,n){
            lis[i] = 1;
            forn(j,0,i){
                if(trns[i]>trns[j]) lds[i] = max(lis[i],lis[j]+1);
            }
        }
        forn(i,0,n){
            lds[i] = 1;
            forn(j,0,i){
                if(trns[i]<trns[j]) lds[i] = max(lds[i],lds[j]+1);
            }
        }
        int mx=1;
        forn(i,0,n){
            mx = max(lis[i]+lds[i]-1,mx);
        }
        // cout << mx << endl;
        res.pb(mx);
    }
    cout << endl;
    forn(i,0,res.size()){
        cout << res[i]<< endl;    }
}