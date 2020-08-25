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



vector<int> table(11000000, 0);

bool weirdComp(pair<int, int>&i, pair<int, int>&j){
    if(i.second==j.second && i.second==1) return i.first < j.first;
    else if(i.second == j.second) return i.first > j.first;
    return i.second < j.second;
}

int phash(int x){
    int dig = 0;
    int cx = x;
    while(cx>0){
        dig += cx%10;
        cx/=10;
    }
    return x ^ dig;
}

void insert(int x){
    int slot = phash(x);
    table[slot]++;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        insert(x);
    }
    vector<ii> bois;
    int col = 0;
    for(int i = 0; i < 11000000; i++){
        if(table[i] != 0){
            bois.pb(mp(i,table[i]));
            col += table[i]-1;
        }
    }
    std::sort(bois.begin(), bois.end(), weirdComp);
    cout << bois[bois.size()-1].first << " " << col << endl;
}