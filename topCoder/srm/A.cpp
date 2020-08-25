#include <vector>
#include <iostream>


using namespace std;

vector<int> findGoodFight(vector<int> power, vector<int> toughness){
    int n = power.size();
    int w = -1, l = -1;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(power[i] >= toughness[j] && power[j] < toughness[i]){
                w = i;
                l = j;
                break;
            } else if(power[j] >= toughness[i] && power[i] < toughness[j]){
                w = j;
                l = i;
                break;
            }
        }
    }
    vector<int> res{};
    if(w == -1) return res;
    res.push_back(w);
    res.push_back(l);
    return res;
}


int main(){

}