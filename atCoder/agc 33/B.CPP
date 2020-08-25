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
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w,n,sr,sc;
    cin >> h >> w >> n >> sr >> sc;
    string s,t;
    cin >> s >> t;
    
    unordered_map<char, ii> dir;
    dir['L'] = mp(-1,0);
    dir['R'] = mp(1,0);
    dir['U'] = mp(0,-1);
    dir['D'] = mp(0,1);

}