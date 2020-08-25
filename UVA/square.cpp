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

int t,n,sum;
int nums[25];
int dp[1<<20];

int solve(int l, int bit){
    if(l>sum/4) return 0;
    if(dp[bit] != -1) return dp[bit];
    if(l==sum/4){
        l=0;
        if(bit == (1<<n)-1) return 1;
    }
    forn(i,0,n){
        if((bit & 1<<i) == 0 && solve(l+nums[i],bit | 1<<i)){
            return 1;
        }
    }
    return dp[bit] = 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // ifstream myfile;
    // myfile.open("in.txt");
    cin >> t;
    while(t--){
        cin >> n;
        setv(dp,-1);
        sum = 0;
        forn(i,0,n){ 
            cin >> nums[i];
            sum += nums[i];
        }
        if(sum%4!=0){
            cout << "no" << endl;
            continue;
        }
        int res = solve(0,0);
        
        cout << (res ? "yes" : "no") << endl;
        
    }
    // myfile.close();
}