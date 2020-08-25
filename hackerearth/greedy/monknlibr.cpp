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

#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define ll long long
#define forn(i, a, b) for(int i = (int)a; i <(int)b;i++)
#define be begin()
#define en end()
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> b(n);
    vector<int> s(n);
    forn(i,0,n) cin >> b[i];   
    forn(i,0,n) cin >> s[i];
    ll res = 0;
    sort(b.be, b.en);
    sort(s.be, s.en);
    forn(i,0,n) res += abs(b[i]-s[i]);

    cout << res << endl;
}