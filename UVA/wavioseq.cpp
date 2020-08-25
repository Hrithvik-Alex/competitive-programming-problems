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

int n;
vector<int> arr;

vector<int> temp;

void LIS(vector<int>& a){
    temp.clear();
    forn(i,0,n){
        int pos = lower_bound(temp.begin(), temp.end(),arr[i]) - temp.begin();
        if(pos==temp.size()){
            temp.pb(arr[i]);
        } else {
            temp[pos] = arr[i];
        }
        a[i] = pos+1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> n){
        arr.clear();
        arr.resize(n);
        forn(i,0,n) cin >> arr[i];
        vector<int> lis(n), lds(n);
        LIS(lis);
        reverse(arr.begin(), arr.end());
        LIS(lds);
        int best = 1;
        forn(i,0,n){
            int cur = min(lis[i], lds[n-1-i]);
            best = max(best, cur*2-1);
        }
        cout << best << endl;
    }
}