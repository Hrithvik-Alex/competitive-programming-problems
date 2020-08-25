#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <climits>
#include <cmath>
#include <utility>
#include <algorithm>
#include <unordered_map>

#define pb push_back
#define mp make_pair
#define ii pair<int, int>

using namespace std;



int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<pair<int, vector<ii > > > val(n);
    for(int i = 0; i < n; i++){
        vector<ii > v;
        int x;
        cin >> x;
        val[i] = mp(x, v);
    }

    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        val[a-1].second.pb(mp(val[b-1].first,b));
        val[b-1].second.pb(mp(val[a-1].first,a));
    }

    for(int i = 0; i < n; i++){
        sort(val[i].second.begin(), val[i].second.end());
        int res = k>val[i].second.size() ? -1 : val[i].second[val[i].second.size()-k].second;
        cout << res << endl;
    }
}