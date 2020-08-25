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
int matrix[80][80];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    vector<int> res;
    while(t--){
        cin >> n;
        forn(i,0,n) forn(j,0,n) cin >> matrix[i][j];

        int mx = INT_MIN;
        forn(i,0,n){
            int temp[n];
            setv(temp,0);
            forn(j,i,n+i){
                forn(k,0,n){
                    temp[k] += matrix[j%n][k];
                }
                int sum[n];
                int curmx = INT_MIN;
                forn(k,0,n){
                    sum[k] = temp[k];
                    curmx = max(curmx, sum[k]);
                    forn(l,k+1,k+n){
                        sum[l%n] = max(temp[l%n],sum[(l-1)%n]+temp[l%n]);
                        curmx = max(curmx, sum[l%n]);
                    }
                }
                mx = max(mx,curmx);
            }
        }
        res.pb(mx);
    }
    forn(i,0,res.size()) cout << res[i] << endl;
}