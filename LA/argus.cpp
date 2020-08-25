#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <unordered_map>

using namespace std;

int main(){
    int Q;
    int period;
    priority_queue< pair<int,int> > que;
    string dum;
    cin >> dum;
    unordered_map<int, int> data;
    while(dum != "#"){
        cin >> Q >> period;
        cin >> dum;
        data[Q] = period;
        que.push(make_pair(-period, -Q));
    }
    int k;
    cin >> k;   
    
    while(k--){
        int d = abs(que.top().first);
        int e = abs(que.top().second);
        cout<<e<<endl;
        d += data[e];
        que.pop();
        que.push(make_pair(-d, -e));
    }
}







