#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int t;
    cin >> t;
    vector<long> ans;
    while(t--){
        int l;
        cin >> l;
        string w;
        cin >> w;
        int *scores = new int[l];
        for(int i = 0; i < l;i++){
            scores[i] = w[i] - '0';
        }
       
        cout << endl;
        long m = 0;
        int d = l - l/2;
        for(int i = 0; i <d; i++){
            m += scores[i];
        }
        long curr = m;
        for(int i =d; i < l;i++){
            curr += scores[i] - scores[i-d];
            m = max(curr, m);
        }
        ans.push_back(m);
        delete[] scores;
    }
    for(int i = 0; i < ans.size(); i++){
        cout << "Case #" << i+1 << ": "<< ans[i] << endl;
    }
}