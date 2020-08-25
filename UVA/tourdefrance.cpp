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

int f,r;
double fi[11], ri[11];
double d[125]; 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        cin >> f;
        if(f==0)break;
        cin >> r;
        forn(i,0,f) cin >> fi[i];
        forn(i,0,r) cin >> ri[i];
        int k = 0;
        forn(i,0,f){
            forn(j,0,r){
                d[k] = ri[j]/fi[i];
                k++;
            }
        }
        sort(d, d+k);
        double mx = 0.0;
        forn(i,1,k){
            mx = max(mx,d[i]/d[i-1]);
        }
        printf("%.2f\n", mx);
    }
}