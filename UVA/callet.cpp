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

int m,a,b;
double rt;
int siev[100005];
vector<int> primes;

void sieve(){
    for(int i = 2; i*i < 100001; i++){
        if(siev[i]){
            for(int j = i*i; j < 100001; j+=i){
                siev[j] = 0;
            }   
        }
        
    }
    forn(i,2,100001){
        if(siev[i]) primes.pb(i);
    }

}

bool check(int p, int q){
    if(p>q) return false;
    if((double)p*(double)q>m) return false;
    return(a*q<=p*b);
}

vector<ii> res;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    setv(siev, 1);
    primes.pb(1);
    sieve();
    cin >> m >> a >> b;
    while(m!=0){
        int p =2,q=2;
        for(int i = 0; i < primes.size() && primes[i] < m; i++){
            int lo = i;
            int hi = primes.size()-1;
            while(lo<=hi){
                int mid = (lo+hi)/2;
                if(check(primes[i], primes[mid])){
                    if(primes[i]*primes[mid]>p*q){
                        p = primes[i];
                        q = primes[mid];
                    }
                    lo = mid+1;
                } else {
                    hi =mid-1;
                }
            }
        }
        res.pb(mp(p,q));
        cin >> m >> a >> b;
    }
    forn(i,0,res.size()){
        cout << res[i].first << " " << res[i].second << endl;
    }
}