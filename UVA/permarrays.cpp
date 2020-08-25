#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define forn(n) for(int i=0; i<n;i++)

using namespace std;


int main(){
    int t=1;
//    cin >> t;
    while(t--){
        int n;
        vector<int> p;
        vector<float> a;
        string perm;
        string arr;
        getline(cin, perm);
        getline(cin, arr);
        arr.erase(remove_if(arr.begin(), arr.end(), ::isspace), arr.end());
        perm.erase(remove_if(perm.begin(), perm.end(), ::isspace), perm.end());
        forn(perm.length()){
            p.push_back(perm[i] - '0');
            a.push_back(arr[i] - '0');
        }
        n = p.size();
        int array[n];
        forn(2){
            array[p.at(i)-1]=a.at(p.at(i)-1);
        }
        cout << n << endl;
        forn(n){
            cout << array[i] << endl;
        }
    }
    return 0;
}