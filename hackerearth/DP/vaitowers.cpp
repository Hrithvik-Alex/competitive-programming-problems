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

int A[100001];
int main(){
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        int negs = 0;
        int pos = 0;
        forn(i,0,n) {
            cin >> A[i];
            if(A[i] < 0) negs++;
            else pos++;
        }
        if(negs == 0 || pos == 0) {
            cout << 1 << endl;
            continue;
        }
        int minchange = INT_MAX;
        int posbf = 0;
        forn(i,0,n){
            minchange = min(minchange, negs+posbf);
            if(A[i]>0){
                posbf++;
            } else {
                negs--;
            }
        }
        
        cout << minchange << endl;
        
    }
}