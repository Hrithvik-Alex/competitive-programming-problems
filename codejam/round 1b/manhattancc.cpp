#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

void add(vector<int>& arr, int lo, int hi, int val) 
{ 
    arr[lo] += val; 
    if (hi != arr.size() - 1) 
       arr[hi + 1] -= val; 
} 
  
void updateArray(vector<int>& arr) 
{ 
    for (int i = 1; i < arr.size(); i++) 
        arr[i] += arr[i - 1]; 
} 


int maxIndex(vector<int> A){
    int max = INT_MIN;
    int ind = -1;
    for(int i = 0; i < A.size(); i++){
        if(A[i]>max){
            max = A[i];
            ind = i;
        }
    }
    return ind;
}

int main(){
    int t;
    cin >> t;
    vector<pair<int, int> > res;
    while(t--){
        int p, q;
        cin >> p >> q;
        vector<pair<string, pair<int, int> > > people;
        for(int i = 0; i < p; i++){
            int x,y;
            string d;
            cin >> x >> y >> d;
            people.push_back(make_pair(d, make_pair(x,y)));
        }
        vector<int> rows(q+1);
        vector<int> cols(q+1);
        for(int i = 0; i < p;i++){
            string d = people[i].first;
            if(d == "N"){
                add(cols, people[i].second.second+1,q,1);
            } else if(d == "S"){
                add(cols,0, people[i].second.second-1,1);
            } else if(d == "E"){
                add(rows, people[i].second.first+1,q,1);
            } else if(d == "W"){
                add(rows,0, people[i].second.first-1,1);
            }
        }
        updateArray(rows);
        updateArray(cols);
        int cx = maxIndex(rows);
        int cy = maxIndex(cols);

        res.push_back(make_pair(cx, cy));
    }

    for(int i = 0; i < res.size(); i++){
        cout << "Case #" << i+1 << ": " << res[i].first << " " << res[i].second << endl;
    }
}