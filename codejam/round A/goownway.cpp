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
        int n;
        cin >> n;
        string p;
        cin >> p;
        string r;
        for(int i = 0; i < p.size(); i++){
            if(p[i] == 'E'){
                r += "S";
            } else {
                r += "E";
            }
        }
        res.push_back(r);
    }

    for(int i = 0; i < res.size(); i++){
        cout << "Case #" << i + 1 << ": " << res[i] << endl;
    }
}