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
#define INF 0x3f3f3f3f
#define forn(i, a, b) for(int i = (int)a; i <(int)b;i++)
#define setv(arr,i) memset(arr, i, sizeof(arr))
using namespace std;

int t,n,m,q;
string quer;
struct sw{
    int num;
    int togg[20];
} swchs[45];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n >> m;
        forn(i,0,m){
            cin >> swchs[i].num;
            forn(j,0,swchs[i].num){
                int x;
                cin >> x;
                swchs[i].togg[x] = 1;
            }
        }
        cin >> q;
        while(q--){
            cin >> quer;
            reverse(quer.begin(),quer.end());
        

        }
    }
}