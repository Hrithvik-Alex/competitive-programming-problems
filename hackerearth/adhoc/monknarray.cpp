#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int m, n;
    cin >> n >> m;
    vector<vector<int> > mat(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        sort(mat[i].begin(), mat[i].end());
    }
    int ans = INT_MAX;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m; j++){
            auto it = lower_bound(mat[i+1].begin(), mat[i+1].end(), mat[i][j]);
            if(it==mat[i+1].end()){
                it--;
                int temp = abs(mat[i][j] - (*it));
                ans = min(ans, temp);
            } else {
                int temp = abs(mat[i][j] - (*it));
                ans = min(ans, temp);
                if(it!=mat[i+1].begin()){
                    it--;
                    int temp = abs(mat[i][j] - (*it));
                    ans = min(ans, temp);
                }
            }
            if(ans == 0){
                break;
            }
        }
        if(ans == 0){
            break;
        }
    }
    cout << ans << endl;
}