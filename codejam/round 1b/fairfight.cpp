#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;


int maxI(vector<int> v, int lo, int hi){
    int mx = -1;
    for(int i = lo; i <=hi;i++){
        mx = max(mx, v[i]);
    }
    return mx;
}

int main(){
    int t;
    cin >> t;
    vector<int> res;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> c(n);
        vector<int> d(n);
        for(int i = 0; i < n; i++){
            cin >> c[i];
        }
        for(int i = 0; i < n; i++){
            cin >> d[i];
        }
        
        int ff = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int cmax = maxI(c,i,j);
                int dmax = maxI(d,i,j);
                if(abs(cmax-dmax) <= k){
                    ff++;
                }
            }
        }
        res.push_back(ff);
    }

    for(int i = 0; i < res.size(); i++){
        cout << "Case #" << i+1 << ": " << res[i] << endl;
    }

}