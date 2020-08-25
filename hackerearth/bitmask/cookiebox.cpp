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

int t,n,a;
int pos[32];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        setv(pos,0);
        cin >> n;
        forn(i,0,n) {
            cin >> a;
            forn(j,0,32){
                if(a&(1<<j)) pos[j]++;
            }
        }
        int max = 0;
        forn(i,1,32){
            if(pos[i]>pos[max]) max = i;
        }
        cout << max << endl;
    }
}