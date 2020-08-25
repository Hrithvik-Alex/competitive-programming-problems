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

int curr[21];
int n;
long long amount[10005];

int main(){
    ios:: sync_with_stdio(false);
    cin.tie(NULL);
    forn(i,0,21){
        curr[i] = pow((i+1),3);
    }
    setv(amount,0);
    amount[0] = 1;
    forn(i,0,21){
        forn(j,curr[i],10001){
            amount[j]+=amount[j-curr[i]];
        }
    }
    
    while(cin >> n){
        cout << amount[n] << endl;
    }

}