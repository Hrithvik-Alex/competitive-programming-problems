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

#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define ll long long
#define forn(i, a, b) for(int i = (int)a; i <(int)b;i++)
using namespace std;

int root(vector<int>& arr, int x){
    while(x!=arr[x]){
        arr[x] = arr[arr[x]];
        x = arr[x];
    }
    return x;
}

void setunion(vector<int>& arr, int x, int y){
    arr[root(arr, x)] = root(arr, y);
}

bool find(vector<int>& arr, int x, int y){
    return root(arr, x) == root(arr, y);
}

int main(){
    int x,y;
    cin >> x >> y;
    vector<int> dj(x+y);
    for(int i = 0; i < x+y; i++){
        dj[i] = i;
    }
    int q1;
    cin >> q1;
    forn(i,0,q1){
        int a,b;
        cin >> a >> b;
        setunion(dj, a-1, b-1);
    }
    int q2;
    cin >> q2;
    forn(i,0,q2){
        int a,b;
        cin >> a >> b;
        setunion(dj,x+a-1,x+b-1);
    }
    int q3;
    cin >> q3;
    forn(i,0,q3){
        int a,b;
        cin >> a >> b;
        setunion(dj,a-1,x+b-1);
    }

    vector<int> freqm(x+y,0);
    forn(i,0,x){
        freqm[root(dj,i)]++;
    }

    vector<int>freqw(x+y,0);
    forn(i,x,x+y){
        freqw[root(dj,i)]++;
    }

    ll res = 0;
    forn(i,0,x+y){
        res += (long)freqm[i]*(long)(y-freqw[i]);
    }

    // forn(i,0,x+y){
    //     cout << dj[i] << " ";
    // }
    // cout << endl;

    // forn(i,0,x+y){
    //     cout << "(" <<freqm[i] << "," << freqw[i] << ")" << " ";
    // }
    // cout << endl;

    cout << res << endl;
}