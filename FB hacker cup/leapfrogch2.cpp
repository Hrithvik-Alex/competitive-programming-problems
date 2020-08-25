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
        if(n==2) ofl << "Case #" << ++cases << ": N" << endl;
        else if(n==3){
            int bs = 0;
            if(l[1] == 'B') bs++;
            if(l[2] == 'B') bs++;
            if(bs&1) ofl << "Case #" << ++cases << ": Y" << endl;
            else ofl << "Case #" << ++cases << ": N" << endl;  
        } else {
            int betas = 0;
            forn(i,1,n){
                if(l[i] == 'B') betas++;
            }
            if(betas<2 || betas==n-1) ofl << "Case #" << ++cases << ": N" << endl;
            else ofl << "Case #" << ++cases << ": Y" << endl;
        }
    }
    fl.close();
    ofl.close();
    }