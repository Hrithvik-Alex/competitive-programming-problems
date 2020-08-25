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
int matrix[105][105];

int main(){
    cin >> n;
    forn(i,0,n){
        forn(j,0,n){
            cin >> matrix[i][j];
        }
    }
    int mx = INT_MIN;
    forn(i,0,n){
        int temp[n];
        setv(temp,0);
        forn(j,i,n){
            forn(k,0,n){
                temp[k] += matrix[j][k];
            }
            int curmx = INT_MIN;
            int mxs[n];
            mxs[0] = temp[0];
            forn(k,1,n){
                mxs[k] = max(temp[k], temp[k]+mxs[k-1]);
                curmx = max(curmx, mxs[k]);
            }
            mx = max(mx, curmx);
        }
    }
    cout << mx << endl;
}