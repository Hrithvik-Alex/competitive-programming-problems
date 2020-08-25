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

int l,m,n,h;

vector<vector<int> > game;


bool comp(vector<int>&a, vector<int>&b){
    return a.size() < b.size();
}

int max = 0;



int main(){
    cin >> l >> n >> m;
    priority_queue<ii> pq;
    forn(i,0,l){
        cin >> h;
        vector<int> input;
        pq.push({-h,l});
        forn(j,0,h){
            int k;
            cin >> k;
            input.pb(k);
        }
        game.pb(input);
    }

    int ans = 0;
    bitset<20> b;
    while(!pq.empty()){
        ii top = pq.top();
        pq.pop();
        int count = game[top.second].size();
        forn(i,0,game[top.second].size()){
            
        }
    }
    cout << game[2].size() << endl;

    cout << ans << endl;
}