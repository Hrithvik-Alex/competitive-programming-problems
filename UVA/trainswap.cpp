#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define forn(n) for(int i=0; i<n;i++)

using namespace std;
int sort(int end, int a[]){
    int c = 0;
    forn(end-1){
        forn(end-1){
            if(a[i] > a[i+1]){
                a[i] ^= a[i+1];
                a[i+1] ^= a[i];
                a[i] ^= a[i+1];
                c++;
            }
        }
    }
    return c;
}
int main(){
    int t;
    int l, templ;
    int x;
    int tests[50];
    vector<int> ans;
    cin >> t;
    while(t--){
        cin >> l;
        templ = l;
        while(l--){
            cin >> x;
            tests[templ - l - 1] = x;
        }
        ans.push_back(sort(templ, tests));
    }
    forn(ans.size()){
        cout << "Optimal train swapping takes " << ans.at(i) << " swaps." << endl;
    }
}