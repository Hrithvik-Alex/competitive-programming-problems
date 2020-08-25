#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main(){
    int t, w;
    cin >> t >> w;
    while(t--){
        int nums[6];
        for(int i = 0; i < 6; i++){
            cout << i+1 << endl;
            cin >> nums[i];
        }
        int rings[6];
        rings[0] = (4*nums[0] - 4*nums[1]- 2*nums[2] + nums[5]) / 40;
        rings[1] = (-24*nums[0] +24*nums[1] + 2*nums[2] - nums[5]) / 20;
        rings[2] = (-4*nums[0] - 6*nums[1] + 12*nums[2] - nums[5]) / 10;
        rings[3] = (16*nums[0]-16*nums[1] -8*nums[2]+10*nums[3] - nums[5]) / 10;
        rings[4] = (-8*nums[0] + 8*nums[1] + 4*nums[2] - 5*nums[3] - 2*nums[5] + 5*nums[4]) / 5;
        rings[5] = (12*nums[0] - 2*nums[1] - 6*nums[2]+3*nums[5]-5*nums[4]) / 5;
        for(int i = 0; i < 6; i++){
            cout << rings[i] << " ";
        }
        cout << endl;
        int verdict;
        cin >> verdict;
        if(verdict == -1) break;
    }
}