#include <iostream>
#include <fstream>
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

int n;
vector<string> paps(20);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> n && n!=0){
        forn(i,0,n) cin >> paps[i];
        int nums[n];
        forn(i,0,n){
            int num = 0;
            forn(j,0,paps[i].length()){
                int x = paps[i][j] == 'B' ? 1:0;
                num |= x<<j;
            }
            nums[i] = num;
        }
    }
}