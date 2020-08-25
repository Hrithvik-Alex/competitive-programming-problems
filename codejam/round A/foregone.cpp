#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main(){
    int t;
    cin >> t;
    vector<pair<string, string> > ans;
    while(t--){
        int n;
        cin >> n;
        string a = to_string(n);
        string b = "";
        for(int i = 0; i < a.size(); i++){
            if(a[i] == '0' + 4){
                a[i] = '3';
                b += "1";
            } else {
                if(b.size() > 0){
                    b += "0";
                }
            }
        }


        ans.push_back(make_pair(a,b));

    }

    for(int i = 0; i < ans.size(); i++){
        cout << "Case #" << i + 1 << ": " << ans[i].first << " " << ans[i].second << endl;
    }
}