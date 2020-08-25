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




int tc,m,l,r;
vector<ii> lr;



bool comp(ii& a,ii& b){
    return a.first<b.first || (a.first==b.first&&a.second>b.second);
}

int main(){
    ios:: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> tc;
    while(tc--){
        while(scanf("%d %d",&l,&r) && l!=0 || r!=0){
            if(r>0 || l<=m)
            lr.pb(mp(l,r)); 
        }
        if(lr.size() == 0){
            cout << 0 << endl << endl;
            continue;
        }
        sort(lr.begin(),lr.end(),comp);
        vector<ii> soln;
        int start = 0;
        int ind = 0;
        ii cur;
        while(start<m){
            int chek = start;
            while(ind<lr.size() && lr[ind].first<start){
                if(lr[ind].second>chek){
                    chek = lr[ind].second;
                    cur = lr[ind];
                }
                ind++;
            }
            if(chek==start) break;
            start = chek;
            soln.pb(cur);
        }

    }
    
}