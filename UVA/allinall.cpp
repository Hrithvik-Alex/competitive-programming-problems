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

string s,t;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> s >> t){
        int ind = 0;
        forn(i,0,t.size()){
            if(s[ind] == t[i]){
                ind++;
            }
            if(ind == s.size()) break;
        }
        string ans = ind==s.size() ? "Yes" : "No";
        cout << ans << endl;
    }
}