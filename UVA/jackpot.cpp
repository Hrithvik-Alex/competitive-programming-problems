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
int nums[10005];
int temp[10005];
int main(){
  
    while(cin >> n && n!=0){
        forn(i,0,n) cin >> nums[i];
        int mx = 0;
        temp[0] = nums[0];
        mx = max(mx, temp[0]);
        forn(i,1,n){
            temp[i] = max(nums[i], nums[i] + temp[i-1]);
            mx = max(mx, temp[i]);
        }
        if(mx == 0) {
            cout << "Losing streak." << endl;
        } else {
            cout << "The maximum winning streak is "<< mx << "." << endl;
        }
    }
}