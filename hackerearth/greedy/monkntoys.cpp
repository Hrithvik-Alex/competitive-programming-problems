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
    int n, ans = 0, inc = 1;
    cin >> n;
    vector<int> w(n);
    forn(i,0,n) cin >> w[i];
    while(n>=inc) {
        n-=inc++; 
        ans++;
    }
    cout << ans << endl;
}