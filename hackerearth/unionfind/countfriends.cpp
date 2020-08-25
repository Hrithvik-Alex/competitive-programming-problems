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

using namespace std;

int root(vector<int>& arr, int i) {
    while(arr[i] != i){
        arr[i] = arr[arr[i]]; 
        i = arr[i]; 
    }
    return i;
}

void setunion(vector<int>& arr, int i, int j){
    arr[root(arr, i)] = root(arr, j);
}

bool find(vector<int>& arr, int i, int j){
    return root(arr, i) == root(arr, j);
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> dj(n);
    for(int i = 0; i<n;i++){
        dj[i] = i;
    }
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        setunion(dj,a-1,b-1);
    }
    
    vector<int> freq(n, 0);
    for(int i = 0; i < n;i++){
        freq[root(dj, i)]++;
    }

    // for(int i = 0; i < n; i++){
    //     cout << dj[i] << " ";
    // }
    // cout << endl;
    for(int i = 0; i < n;i++){
        cout << freq[root(dj, i)] - 1 << " ";
    }
    cout << endl;
}