#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
// #include <fstream>

using namespace std;

int N = 12252240;

int inv(int a, int m){
    int x=0, y=1;
    int m0 = m;
    while(a>1){
        int q = a / m;
        int t = m;
        m = a%m, a = t;
        t = x;
        x = y - q*x;
        y = t;
    }
    if(y<0){
        y += m0;
    }
    return y;
}


int main(){
    // ofstream myfile;
    // myfile.open("out.txt");
    int t, n, m;
    cin >> t >> n >> m;
    while(t--){
        int nums[7] = {5,7,9,11,13,16,17};
        vector<pair<int, int> > mods;
        for(int i = 0; i < 7; i++){
            for(int j = 0; j < 18; j++) cout << nums[i] << " ";
            cout << endl;
            int sum = 0;
            for(int j = 0; j < 18; j++){ 
                int x;
                cin >> x;
                sum += x;
            }
            mods.push_back(make_pair(sum % nums[i], nums[i]));
        }
        int sum = 0;
        // myfile << "Ys and INVERSES: " << endl;
        for(int i = 0; i < 7; i++){
            int y = N/mods[i].second;
            int z = inv(y, mods[i].second);
            // myfile << mods[i].first << " "<< y << " " << z << endl;
            sum += y * z * mods[i].first;
        }
        cout << (sum % N) << endl;
        int verdict;
        cin >> verdict;
        // string ans = (verdict == 1) ? "PASS" : "FAIL";
        // myfile << "VERDICT: " << ans << endl;
    }
    // myfile.close();
}