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
string par;
int A[16];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        cin >> par >> n;
        forn(i,0,n) cin >> A[i];
        int maxoxa = -1;
        int s = par == "Odd" ? 1 : 0;
        forn(i,0,pow(2,n)){
            int cur = -1;
            int op = 0;
            forn(j,0,16){
                if(i&(1<<j)){
                    if(cur == -1) cur = A[j];
                    else {
                        if(op%3 == 0) cur |= A[j];
                        else if(op%3==1) cur ^= A[j];
                        else cur += A[j];
                        op++;
                    }
                }
            }
            maxoxa = max(maxoxa,cur);
        }
        if(s&maxoxa || (s==0 && (maxoxa&1)==0)) cout << "Monk";
        else cout << "Mariam";
        cout << endl;
    }
}