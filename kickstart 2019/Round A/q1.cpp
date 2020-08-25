#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> ans;
    while(t--){
        int n, p;
        cin >> n >> p;
        vector<int> S;
        int si;
        for(int i = 0; i < n; i++){
            cin >> si;
            S.push_back(si);
        }
        sort(S.begin(), S.end());
        int hours = 0;
        for(int i = 0; i < p; i++){
            hours += S[p-1] - S[i];
        }

        int currhours = hours;
        for(int i = p; i < n; i++){
            currhours += (S[i] - S[i-1])*(p-1) - (S[i-1] - S[i-p]);
            hours = min(currhours, hours);
        }
        ans.push_back(hours);
    }
    for(int i = 0; i<ans.size(); i++){
        cout << "Case #" << i+1 << ": " << ans[i] << endl;
    }
}

