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

int tc,d,n;

int pos[525000];
int ball[525000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> tc;
    pos[0] = 1;
    pos[1] = 2;
    forn(i,2,20){
        forn(j,pow(2,i)/2,pow(2,i)){
            pos[j] = pos[j-(int)(pow(2,i)/2)] + 1;
            pos[j-((int)(pow(2,i)/2)+1)]*=2;
        }
    }
    int x = pow(2,19);
    forn(i,0,x){
        ball[pos[i]-1] = i+1;
    }
    while(tc--){
        cin >> d >> n;
        int divisor = 0;
        int i = d-1;
        while(pos[n-1]+pow(2,d-1)<pow(2,i)){
            divisor++;
            i--;
        }
        cout << (pos[n-1]/divisor) << endl;

    }

}