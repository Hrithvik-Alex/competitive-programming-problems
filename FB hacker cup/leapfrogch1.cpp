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
#define INF 0x3f3f3f3f
#define forn(i, a, b) for(int i = (int)a; i <(int)b;i++)
#define setv(arr,i) memset(arr, i, sizeof(arr))
using namespace std;

int t,n;
string l;

int main(){
    ifstream fl;
    ofstream ofl;
    fl.open("in.txt");
    ofl.open("out.txt");
    fl >> t;
    int cases = 0;
    while(t--){
        fl >> l;
        n = l.length();
        int beta = 0;
        forn(i,1,n) {
            if(l[i]=='B') beta++;
        }
        if(beta*2<n-2 || beta==n-1) {
            ofl << "Case #" << ++cases << ": N" << endl;
            // printf("Case #%d: N\n", ++cases);
            continue;
        }
        // int curdot = 0, curb = 0;
        // for(int i = n-1; i>0; i--){
        //     if(l[i] == 'B') curb++;
        //     else curdot++;
        //     if(curdot >= curb+2){
        //         ofl << "Case #" << ++cases << ": N" << endl;
        //         continue;
        //     }
        // }
        ofl << "Case #" << ++cases << ": Y" << endl;
    }
    ofl.close();
    fl.close();
}