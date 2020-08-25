#include <iostream>
#include <cstdio>

using namespace std;
int main(){
    int t, a, b, n;
    string verdict = "";
    cin >> t;
    while(t--){
        cin >> a >> b;
        cin >> n;
        int p;
        while(verdict != "CORRECT" || n==0){
            p = a+(b-a)/2+1;
            cout << p << endl;
            cin >> verdict;
            if(verdict == "TOO_SMALL"){
                a = p;
            } else if(verdict == "TOO_BIG"){
                b = p-1;
            }
            n--;
        }
        verdict = "";
    }

    
};