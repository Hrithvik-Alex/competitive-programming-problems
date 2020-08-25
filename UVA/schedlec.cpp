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

int n,l,c,lecs;
int t[1005];
unordered_map<int,int> dp;

int getDi(int val) {
    if (val == 0) return val;
    if (val <= 10) return -c;
    return (val - 10) * (val - 10);
}

int recur(int curt,int day){
    if(lecs<day) return 1000000000;
    if(curt>=n) return 0;
    if(dp.count(10000*curt+day)) return dp[10000*curt+day];
    int sum = 0, mini = 1000000000;
    forn(i,curt,n){
        sum+=t[i];
        if(sum>l) break;
        mini = min(mini, getDi(l-sum)+recur(i+1,day+1));
    }
    dp[10000*curt+day] = mini;
    return mini;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream myfile;
    myfile.open("in.txt");
    int cases = 0;
    while(cin >> n && n!=0){
        dp.clear();
        cin >> l >> c;
        forn(i,0,n) cin >> t[i];
        lecs = 1;
        int cur = l;
        forn(i,0,n){
            if(t[i]<=cur) cur-=t[i];
            else{
                cur = l-t[i];
                lecs++;
            }
        }
        int DI = recur(0,0);
        printf("Case %d:\n",++cases);
        printf("Minimum number of lectures: %d\n",lecs);
        printf("Total dissatisfaction index: %d\n\n", DI);
    }
    myfile.close();
}