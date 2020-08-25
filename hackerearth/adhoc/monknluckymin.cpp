#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int main(){
    int t;
    cin >> t;
     vector<string> res;

    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int min = INT_MAX;
        for(int i = 0; i < n;i++){
            if(min > a[i]) min = a[i];
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == min) count++;
        }
        res.push_back(count%2==1 ? "Lucky" : "Unlucky");
    }
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }
}