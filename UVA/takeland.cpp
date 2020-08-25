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

int m,n;
int matrix[105][105];

int main(){
    vector<int> res;
    while(cin >> m >> n && (m!=0 || n!=0)){
        forn(i,0,m) forn(j,0,n) {
            int x;
            cin >> x;
            matrix[i][j] = x==1 ? -10001 : 1;
        }
        int mxx = -1;
        forn(i,0,m){
            int temp[n];
            setv(temp,0);
            forn(j,i,m){
                forn(k,0,n){
                    temp[k] += matrix[j][k];
                }
                int mx=-1;
                int sum[n];
                sum[0] = temp[0];
                mx = max(sum[0],mx);
                forn(k,1,n){
                    sum[k] = max(temp[k],sum[k-1]+temp[k]);
                    mx = max(sum[k],mx);
                }
                mxx = max(mx, mxx);
            }
        }
        // int res = mxx==-1 ? 0 : mxx;
        // cout << res << endl;
        res.pb(mxx==-1 ? 0 : mxx);
    }
    forn(i,0,res.size()) cout << res[i] << endl;
}