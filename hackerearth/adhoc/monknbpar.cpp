#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <climits>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> vals(n);
    for(int i = 0; i < n; i++){
        cin >> vals[i];
    }
    stack<pair<int, int> > s;
    s.push(make_pair(0,-1));
    int maxbal = 0;
    for(int i = 0; i < n; i++){
        if(vals[i] > 0){
            s.push(make_pair(vals[i], i));
        } else {
            if(s.top().first == -vals[i]){
                s.pop();

                if(!s.empty()){
                    maxbal = max(maxbal, i - s.top().second);
                } else {
                    s.push(make_pair(0,i));
                }
            } else {
                s.pop();
                s.push(make_pair(0,i));
            }
        }
    }
    cout << maxbal << endl;
}