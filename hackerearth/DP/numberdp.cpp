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

#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define ll long long
#define forn(i, a, b) for(int i = (int)a; i <(int)b;i++)
using namespace std;

int l,n,x,y,q,m;
char inq;
int num[101];
int can_reach[10001];

void dp(int a){
    queue<int> q;
    q.push(a);
    forn(i,0,n){
        unordered_set<int> s;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(cur + num[i] <= y) s.insert(cur + num[i]);
            if(cur-num[i] >= x) s. insert(cur - num[i]);
        }
        if(i == n-1){
            for(auto j : s){
                can_reach[j] = 1;
            }
        } else {
            for(auto j : s){
                q.push(j);
            }
        }
    }
    
}

int main(){
    cin >> l >> n >> x >> y;
    forn(i,0,n) cin >> num[i];
    cin >> q;
    memset(can_reach, 0, sizeof(can_reach));
    dp(l);
    while(q--){
        cin >> inq >> m;
        if(inq == '<'){
            bool fl = false;
            for(int i = m; i >=x; i--){
                if(can_reach[i]) {
                    cout << "YES" << endl;
                    fl = true;
                    break;
                }
            }
            if(!fl) cout << "NO" << endl;
        } else {
            bool fl = false;
            forn(i,m,y+1){
                if(can_reach[i]) {
                    cout << "YES" << endl;
                    fl = true;
                    break;
                }
            }
            if(!fl) cout << "NO" << endl;
        }
    }
}