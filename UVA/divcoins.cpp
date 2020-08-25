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

int t,n;
int coins[105];
int dp[105][50005];
int main(){
    ifstream myfile;
    myfile.open("in.txt");
    myfile >> t;
    while(t--){
        myfile >> n;
        int sum = 0;
        forn(i,1,n+1){ 
            myfile >> coins[i];
            sum += coins[i];
        }

        forn(i,1,n+1){
            forn(j,0,sum/2+1){
                if(j==0){
                    dp[i][j] = 0;
                } else if(j-coins[i]>=0){
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-coins[i]]+coins[i]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        int val = dp[n][sum/2];
        cout << sum - (val*2) << endl;
        
    }
    myfile.close();
}