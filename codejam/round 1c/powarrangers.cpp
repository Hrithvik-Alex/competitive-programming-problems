#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <climits>
#include <cmath>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define ll long long
#define forn(i, a, b) for(int i = (int)a; i <(int)b;i++)
using namespace std;

int main(){

    int t,f;
    cin >> t >> f;
    while(t--){
        //first 

        
        int a[5] = {0,0,0,0,0};
        vector<string> pairs(119, "     ");
        string next = "     ";
        forn(i,0,119){
            cout << i*5+1 << endl;
            cin >> pairs[i][0];
            a[(int)(pairs[i][0]-'A')]++;
        }
        forn(i,0,5){
            if(a[i] == 23){
                next[0] = (char)(i+'A');
            }
            a[i] = 0;
        }
        
        //second

        forn(i,0,119){
            if(pairs[i][0] == next[0]){
                cout << i*5+2 << endl;
                cin >> pairs[i][1];
                a[(int)(pairs[i][1]-'A')]++;
            } else {
                pairs[i] = "     ";
            }
        }
        forn(i,0,5){
            if(a[i] == 5 && i != next[0]-'A'){
                next[1] = (char)(i+'A');
            }
            a[i] = 0;
        }
        //third


        forn(i,0,119){
            if(pairs[i][1] == next[1] && pairs[i][0] == next[0]){
                cout << i*5+3 << endl;
                cin >> pairs[i][2];
                a[(int)(pairs[i][2]-'A')]++;
            } else {
                pairs[i] = "     ";
            }
        }
        forn(i,0,5){
            if(a[i] == 1 && (i != next[0]-'A' && i != next[1]-'A')){
                next[2] = (char)(i+'A');
            }
            a[i] = 0;
        }

        //fourth
        forn(i,0,119){
            if(pairs[i][2] == next[2] && pairs[i][1] == next[1] && pairs[i][0] == next[0]){
                cout << i*5+4 << endl;
                cin >> pairs[i][3];
                a[(int)(pairs[i][3]-'A')]++;
            } else {
                pairs[i] = "     ";
            }
        }
        forn(i,0,5){
            if(a[i] == 0 && (i != next[0]-'A' && i != next[1]-'A' && i != next[2] - 'A')){
                next[3] = (char)(i+'A');
            }
            a[i] = 0;
        }
        
        //fifth
        int sum = 0;
        forn(i,0,4){
            sum += next[i]-'A'+1;
        }
        next[4] = (char)(14-sum+'A');
        cout << next << endl;
        char verdict;
        cin >> verdict;
        if(verdict == 'N') break;
    }

}