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

int n;
int arr[105];
long dp[105][105];

long solve(int l, int r){
    if(l>r) return 0;
    if(dp[l][r] != INT_MIN) return dp[l][r];
    long maxi = INT_MIN;
    long acc = 0;
    forn(i,l,r){
        acc+=arr[i];
        maxi = max(maxi, acc-solve(i+1,r));
    }
    acc = 0;
    for(int i=r;i>=l;i--){
        acc += arr[i];
        maxi = max(maxi,acc-solve(l,i-1));
        
    }
    dp[l][r] = maxi;
    return dp[l][r];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // ifstream myfile;
    // myfile.open("in.txt");
    vector<long> res;
    while(cin >> n && n!=0){
        forn(i,0,n){
            forn(j,0,n) dp[i][j] = INT_MIN;
        }
        forn(i,0,n) cin >> arr[i];
        long diff = solve(0,n-1);
        res.pb(diff); 
    }
    forn(i,0,res.size()) cout << res[i] << endl;
    // myfile.close();
}