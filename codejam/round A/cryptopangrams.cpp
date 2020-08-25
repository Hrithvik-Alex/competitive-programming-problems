#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main(){
    int t;
    cin >> t;
    vector<string> res;
    while(t--){
        int n,l;
        cin >> n >> l;
        vector<string> vals(l);
        for(int i = 0; i < l; i++){
            cin >> vals[i];
        }
        

    }

    for(int i = 0; i < res.size(); i++){
        cout << "Case #" << i + 1 << ": " << res[i] << endl;
    }
}