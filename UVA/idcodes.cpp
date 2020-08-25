#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define forn(n) for(int i=0; i<n;i++)

using namespace std;

int main(){
    string n;
    vector<string> in;
    cin >> n;
    while(n!="#"){
        in.push_back(n);
        cin >> n;
    }
    forn(in.size()){
        bool out = next_permutation(in.at(i).begin(), in.at(i).end());
        if(!out){
            cout << "No Successor";
        } else {
            cout << in.at(i);
        }
        cout << endl;
    }

}